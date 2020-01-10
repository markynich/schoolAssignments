from numpy.random import choice # to to use weighted choice
from random import randrange    # to get randrange function
import random                   # to randomize number 0-9
import string                   # to use ascii string

# Dictionary to create program
dict = {
    "prog" : "int main() {\n<stat_list>return 0;\n }",
    "stat_list" : "<stat>|<stat_list>\n <stat>",
    "stat" : "<cmpd_stat>|<if_stat>|<iter_stat>|<assgn_stat>|<decl_stat>",
    "cmpd_stat" : "<stat_list>",
    "if_stat"  : "if ( <exp> )\n <stat>|if ( <exp> )\n <cmpd_stat>|if ( <exp> )\n <stat>\nelse\n <stat>|if ( <exp> )\n <cmpd_stat>\nelse\n <stat>|if ( <exp> )\n <stat>\nelse\n <cmpd_stat> |if ( <exp> )\n <cmpd_stat>\nelse\n <cmpd_stat>",
    "iter_stat" : "while ( <exp> )\n <stat>|while ( <exp> )\n <cmpd_stat>",
    "assgn_stat" : " <id> = <exp>;\n",
    "decl_stat"  : "<type> <id>;\n|<type> <assgn_stat>",
    "exp" : "<exp> <op> <exp>|<id>|<const>",
    "op" : "+|-|*|/",
    "type" : "int|double",
    "id" : "<char><char_digit_seq>",
    "const" : "<digit><digit_seq>",
    "char_digit_seq" : "[empty]|<char><char_digit_seq>|<digit><char_digit_seq>",
    "digit_seq" : "<digit><digit_seq>|[empty]",
    "char" : "[A-Z]|[a-z]|_",
    "digit" : "[0-9]"
};
#                                       Weights
wStatList = [0.7, 0.3]                  #stat_list
wStat = [0.1, 0.3, 0.2, 0.2, 0.2]     #stat
wIf = [0.3, 0.15, 0.25, 0.1, 0.1, 0.1]    #if_stat
wExp = [0.1, 0.5, 0.4]                  #expressions
wOp = [0.3,0.3,0.2,0.2]                 #operator
wCharS = [0.1,0.45,0.45]                #char sequence
wCharS2 = [1,0,0]                       #char sequence after first call
wChar = [0.3,0.6,0.1]                   #char
wType = [0.5,0.5]                       #type
wDig = [0.8,0.2]                        #digit sequence
wDig2 = [0,1]                           #digit sequence after first calls

#Functions
#
#
def createProgram(string):
    #Keep reading until there are no more "<" or dictionary keys
    while string in dict.keys() or "<" in string:
        if "<" in string:
            string0,strip0 = string.split('<',1)
            string,string1 = strip0.split('>',1)
            if string in dict.keys():
                if "|" in dict.get(string):
                    string = strSeperator(string) #pick one of the options from key
                else:
                    string = dict.get(string)     #if only one option
            if string0 != "":                         #Add string if not empty
                string = string0 + string
            if string1 != "":                         #Add string if not empty
                string = string + string1
    string = string.replace("[0-9]",str(randrange(10))) #Replce[0-9] with numbers
    string = string.replace("[empty]","")
    file = open("output.txt","w")
    file.write(string)
    file.close()
    print(string)                 #print program


def strSeperator(str0):
    strC = dict.get(str0)               #get data from key
    arr = []                            #dynamic array to store options
    while "|" in strC:                  #store options into array
        str1,strC = strC.split('|',1)
        arr.append(str1)
    arr.append(strC)
#make choice option based on key and use correct weight
    if str0 == "stat_list" or str0 == "iter_stat" or str0 == "decl_stat":
        select = choice(arr, p=wStatList)
    elif str0 == "stat":
        select = choice(arr, p=wStat)
    elif str0 == "if_stat":
        select = choice(arr, p=wIf)
    elif str0 == "exp":
        select = choice(arr, p=wExp)
    elif str0 == "op":
        select = choice(arr, p=wOp)
    elif str0 == "char_digit_seq":
        select = choice(arr, p=wCharS)
#To ensure that the variables do not grow too big
        if select != "[empty]":
            string0,strip0 = select.split('<',1)
            select,string1 = strip0.split('>',1)
            select = strSeperator(select)
            while "<" in string1:
                string2,strip1 = string1.split('<',1)
                string1,string3 = strip1.split('>',1)
                string1 = choice(arr, p=wCharS2)
            select = string0 + select + string2 + string1 + string3
    elif str0 == "char":
        select = choice(arr, p=wChar)
    elif str0 == "type":
        select = choice(arr, p=wType)
    elif str0 == "digit_seq":
        select = choice(arr, p=wDig)
#To ensure that the variables do not grow too big
        if select != "[empty]":
            string0,strip0 = select.split('<',1)
            select,string1 = strip0.split('>',1)
            select = strSeperator(select)
            while "<" in string1:
                string2,strip1 = string1.split('<',1)
                string1,string3 = strip1.split('>',1)
                string1 = choice(arr, p=wDig2)
            select = string0 + select + string2 + string1 + string3
    else:
        select = strC
    if select == "[A-Z]":                               #get an uppercase letter
        select = random.choice(string.ascii_uppercase)
    elif select == "[a-z]":                             #get a lowercase letter
        select = random.choice(string.ascii_lowercase)
    return select

#####################################
#   Main
#####################################
createProgram("<prog>")
