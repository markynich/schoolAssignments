import re           #Regex functions
import string       # str() function

# Dictionary for key elements in scanner
dict = {
    #keyword ::= if | then | else | begin | end
    #end+|begin+|if+|else+|then+
    "keyword" : {"if" : 0, "then" : 0, "else" : 0, "begin" : 0, "end" : 0},
    #identifier -> character | character identifier
    #[a-zA-Z]
    "identifier" : 0,
    #integer -> digit | digit integer
    #[0-9]+
    "integer" : 0,
    #real -> integer.integer
    #[0-9]+[.][0-9]+
    "real" : 0,
    #special -> ( | ) | [ | ] | + | - | = | , | ;
    "special" : {'(' : 0, ')' : 0, '[' : 0, ']' : 0, '+' : 0, '-' : 0, '=' : 0, ',' : 0, ';' : 0},
};
#
#   Finding special characters, store them into list & remove chars from string
#
def specialCheck(string):
    while re.search("\(|\)|\[|\]|\+|\-|\=|\,|\;",string):
        x = re.search("\(|\)|\[|\]|\+|\-|\=|\,|\;",string)
        special.append(x.group())
        y = "\\" + x.group()
        for var3 in dict["special"].keys():
            if var3 == x.group():
                dict["special"][var3] = dict["special"].get(var3) + 1
        string = re.sub("{0}".format(y),"",string,1)
    return string

#
#   Find keywords,real,integer,identifier & store them into lists
#
def dictCheck(input):
    for var1 in dict["keyword"].keys():
        for var2 in input:
#keyword finding
            if re.match("(?i){0}".format(var1),var2):
                keyword.append(str(re.findall("(?i){0}".format(var1),var2))[2:-2])
                z = re.sub("(?i){0}".format(var1),"",var2)
                dict["keyword"][var1] = dict["keyword"].get(var1) + 1
    for var2 in input:
#real finding
        if re.match("[0-9]+[.][0-9]+",var2):
            real.append(str(re.findall("[0-9]+[.][0-9]+",var2))[2:-2])
            var2 = re.sub("[0-9]+[.][0-9]+","",var2)
            dict["real"] = dict.get("real") + 1
#integer finding
        if re.match("[0-9]+",var2):
            integer.append(str(re.findall("[0-9]+",var2))[2:-2])
            var2 = re.sub("[0-9]+","",var2)
            dict["integer"] = dict.get("integer") + 1
#identifier finding
        if re.match("[a-zA-Z]+",var2) and re.match("(?i)else|if|then|end|begin",var2) == None:
            identifier.append(str(re.findall("[a-zA-Z]+",var2))[2:-2])
            var2 = re.sub("[a-zA-Z]+","",var2)
            dict["identifier"] = dict.get("identifier") + 1
#
#   To write into output file summary.txt
#
def writeList():
    file = open("summary.txt", "w")
    if file.mode == 'w':
        file.write("------------Keywords------------\nList of Inputs\n")
        sentF = ' | '.join(map(str,keyword))
        sentF = sentF + "\n------Keyword Counters------\n"
        for x in dict["keyword"].keys():
            sentF = sentF + x + " : " + str(dict["keyword"].get(x)) + "\n"
        file.write(sentF)
        file.write("\n------------Identifiers------------\nList of Inputs\n")
        sentF = ' | '.join(map(str,identifier))
        sentF = sentF + "\n------Identifiers Counters------\n"
        sentF = sentF + "identifier : " + str(dict.get("identifier"))
        file.write(sentF)
        file.write("\n\n------------Integers------------\nList of Inputs\n")
        sentF = ' | '.join(map(str,integer))
        sentF = sentF + "\n------Integers Counters------\n"
        sentF = sentF + "integers : " + str(dict.get("integer"))
        file.write(sentF)
        file.write("\n\n------------Real------------\nList of Inputs\n")
        sentF = ' | '.join(map(str,real))
        sentF = sentF + "\n------Real Counters------\n"
        sentF = sentF + "real : " + str(dict.get("real"))
        file.write(sentF)
        file.write("\n\n------------Special------------\nList of Inputs\n")
        sentF = ' | '.join(map(str,special))
        sentF = sentF + "\n"
        for x in dict["special"].keys():
            sentF = sentF + x + " : " + str(dict["special"].get(x)) + "\n"
        file.write(sentF)
    file.close()
#Dynamic lists
keyword = []
identifier = []
integer = []
real = []
special = []

#####################################
#   Main
#####################################
file = open("input.txt", "r")
if file.mode == 'r':
    fileLines = file.readlines()
    for str1 in fileLines:
        str2 = specialCheck(str1)
        str3 = re.split("\s",str2)
        dictCheck(str3)
file.close()
writeList()
