#!/usr/bin/perl
#
# file_upload.pl - script for file uploads over HTML form.
#
# Author: Kyle Dent
# Date: 3/15/01
# Modified 2/13/2015 D. Topham

use CGI;
use strict;
use File::Copy;

my $PROGNAME = "file_upload.pl";

my $cgi = new CGI();
print "Content-type: text/html\n\n";

#
# If we're invoked directly, display the form and get out.
#
if (! $cgi->param("button") ) {
	DisplayForm();
	exit;
}

#
# We're invoked from the form. Get the filename/handle.
#
my $upfile = $cgi->param('upfile');

#
# Get the basename in case we want to use it.
#
my $basename = GetBasename($upfile);

#
# At this point, do whatever we want with the file.
#
# We are going to use the scalar $upfile as a filehandle,
# but perl will complain so we turn off ref checking.
# The newer CGI::upload() function obviates the need for
# this. In new versions do $fh = $cgi->upload('upfile'); 
# to get a legitimate, clean filehandle.
#
no strict 'refs';
#my $fh = $cgi->upload('upfile'); 
#if (! $fh ) {
#	print "Can't get file handle to uploaded file.";
#	exit(-1);
#}

#######################################################
# Choose one of the techniques below to read the file.
# What you do with the contents is, of course, applica-
# tion specific. In these examples, we just write it to
# a temporary file. 
#
# With text files coming from a Windows client, probably
# you will want to strip out the extra linefeeds.
########################################################

#
# Get a handle to some file to store the contents
#
if (! open(OUTFILE, ">/home/debian/newfile") ) {
	print "Can't open /home/debian/newfile for writing - $!";
	exit(-1);
}

# give some feedback to browser
move("/home/debian/newfile", "/home/debian/$basename");
print "Saving the file to /home/debian<br>\n";

#
# 1. If we know it's a text file, strip carriage returns
#    and write it out.
#
#while (<$upfile>) {
# or 
#while (<$fh>) {
#	s/\r//;
#	print OUTFILE "$_";
#}

#
# 2. If it's binary or we're not sure...
#
my $nBytes = 0;
my $totBytes = 0;
my $buffer = "";
# If you're on Windows, you'll need this. Otherwise, it
# has no effect.
binmode($upfile);
#binmode($fh);
while ( $nBytes = read($upfile, $buffer, 1024) ) {
#while ( $nBytes = read($fh, $buffer, 1024) ) {
	print OUTFILE $buffer;
	$totBytes += $nBytes;
}

close(OUTFILE);

#
# Turn ref checking back on.
#
use strict 'refs';

# more lame feedback
print "thanks for uploading $basename ($totBytes bytes)<br>\n";	


##############################################
# Subroutines
##############################################

#
# GetBasename - delivers filename portion of a fullpath.
#
sub GetBasename {
	my $fullname = shift;

	my(@parts);
	# check which way our slashes go.
	if ( $fullname =~ /(\\)/ ) {
		@parts = split(/\\/, $fullname);
	} else {
		@parts = split(/\//, $fullname);
	}

	return(pop(@parts));
}

#
# DisplayForm - spits out HTML to display our upload form.
#
sub DisplayForm {
print <<"HTML";
<html>
<head>
<title>Upload file to Debian</title>
<body>
<h1>Upload file to Debian</h1>
<form method="post" action="$PROGNAME" enctype="multipart/form-data">
<center>
Enter a file to upload: <input type="file" name="upfile"><br>
<input type="submit" name="button" value="Upload File">
</center>
</form>

HTML
}
