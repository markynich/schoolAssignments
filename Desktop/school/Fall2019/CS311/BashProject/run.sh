#!/bin/bash
####################################################################
# Program creates a directory if it doesn't exist and populates it
# with files if they don't exist inside the directory.
# Program will ask user to select a file and a line to replace
# and then ask the user to input a new line to repleace it
# Program will not end until user quits from file selection
####################################################################
#enter current directory
cd $(pwd)
###############################
#variables
###############################
dir=$(pwd)
backDir=${dir%/*}
loopShell=true
declare -a arr
###############################
#sourcing the functions
###############################
. ${dir}/functions.h
###############################
#create files/directory if DNE
###############################
createDir ${dir}
folderDir="${dir}/filesDir"
createFiles "${folderDir}"
###############################
#populate array with file names
###############################
cd $folderDir
fileAmount=0
for file in *; do
	arr[fileAmount]=${file}
	let fileAmount="++fileAmount"
done
###############################
#main function
###############################
cd $dir
while [[ ${loopShell} == true ]]; do
	clear
	#print out files from $(pwd)/filesDir
	printFiles "${folderDir}" "${dir}" "${arr}"
	loopChoice=true
	###########################################
	#select which file user wants to use
	###########################################
	while [[ ${loopChoice} == true ]]; do
		read -p "Please choose an option from 0 - 3 to select a file
		or [q/Q] to quit: " option
		if [ ${option} == "q" ] || [ ${option} == "Q" ]; then
			echo -e "\n-----Exiting Program Goodbye-----\n"
			exit 1
		elif [[ ${option} -le 3 ]] && [[ ${option} -ge "0" ]]; then
			fileOption=${arr[option]}
			loopChoice=false
			echo $choice
		else
			echo -e "\nOption does not exist, please choose a correct option\n"
		fi
	done
	###########################################
	#select which line user wants to replace
	###########################################
	clear
	loopChoice2=true
	while [[ ${loopChoice2} == true ]]; do
		option=$(menuOption)
		if [[ $option == 99 ]]; then
			clear
			loopChoice2=false
			echo -e "\n-----Restarting selection-----\n"
		elif [[ $option == 13 ]]; then
			clear
			echo -e "Option does not exist, please choose another option\n"
		else
			loopChoice2=false
			lineOption=${option}
			#replace line with user input  into selected file
			lineReplacement "${fileOption}" "${lineOption}" "${folderDir}"
		fi
	done
done