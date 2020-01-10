#Assignment 4
#####################################################
#           Index
# Interpretation                                    line 17
# Indentation                                       line 25
# Type Binding                                      line 34
# Boolean expressions & Short Circuit Evaluations   line 41
# Numeric Types and Strings                         line 65
# Arrays, Lists, and For Loops                      line 85
# Tuples and Slicing                                line 109
# Index Range Checking and While Loops              line 124
# Dictionaries & Switch Statement & Functions       line 142
# Type Checking & Subprocess                        line 178


#####################################################
#Interpretation
#####################################################
#Python is a high-level programming language that is interpreted
#During interpretation, it creates a .pyc compiled file which happens internally
#to be executed when the regular .py is ran
#It is compiled during runtime, not like C or C++

#####################################################
#Indentation to denote code blocks
#####################################################
# Indentation is very important in Python. It defines which code block goes where
# For instance, when using an if statement, all lines that are indented with the
# if statement will be within the if code block
# Nothing like C++, Java, etc as they read indentations as white space and it is
# not really needed

#####################################################
# Type Binding
#####################################################
# Type Binding for Python is dynamic binding
# For instance, all variables are actually statements that are made dynamically
# Not like C++, variables are static binded, which are made during compile time

#####################################################
# Boolean expressions & Short Circuit Evaluations
#####################################################
# Boolean expressions are very similar to other languages except that
# true and false have uppercase T(rue) & F(alse)
# Very similar to C++
#
# Short Circuit Evaluations are boolean expressions that are called during
# print or other functions to let the program know if it should print or not
# C++ has short Circuit aka "&&" while Python uses "and", but python can also
# print the boolean value of SC Evaluations

print "\nBoolean Expressions | Short Circuit Evaluations\n"
printN = True
if printN == True:
    print("Boolean printN is " + str(printN))
elif printN == False and printN == True:
    print("Boolean printN is False")
if printN != False:
    print("Boolean printN is not False")

b = 12
print "b equals to 12:", b == 12
print "b equals to 14:", b == 14
#####################################################
# Numeric Types and Strings
#####################################################
# Python has 4 different numeric types: int, long, float, & complex
# I am using the constructors to change the value of num to the different types
# with the exception of complex numbers
# C++ has similar types with double, but python uses the numeric types dynamically
#
# Python has a strong sense of strings as it can convert values to string with
# the constructor function of str(). Strings can also be immediately be used for
# variables without needed to declare the string type
# C++ has very similar thing with the str() function, but C++ needs to include
# the string library

print "\nNumeric Types | Strings\n"
num = 12.13456
print "original value for " + str(num)
print "num is now an int: " + str(int(num))
print "num is now a long: " + str(long(num))
print "num is now a float: " + str(float(num))
#####################################################
# Arrays, Lists, and For Loops
#####################################################
# Arrays need to be declared which takes an extra step, but is good for arithmetic
# problems such as dividing the whole array with 3. Also stores data efficiently
# need to import array and declare which type the array will be.
# Very similar to C++, arrays need to be declared, but it's built in C++ STL
#
# Lists do not need to be declared as it is already built in the Python syntax.
# They are more commonly used for scripts and programs
# elements do not need to be the same type
# C++ does not have this capability of having different elements within a list
#
# For Loops are similar to range based loops in c++11
# C++ has something similar but called range based loops in C++11
import array as arr #Needed for arrays
print "\nArrays | Lists | For Loops\n"
a = arr.array('f',[10,15,22,90,18]) #array type will be float == 'f'
list = [10,15,22,"Hello I'm 90",18] #list declaration
print a
print list
print "Initiating for loop to print list"
for i in list:
    print i
#####################################################
# Tuples and Slicing
#####################################################
# Tuples are similar to lists except they cannot be modified after being defined
# C++ does not have tuples
#
# Slicing are cutting lists, strings, etc into seperate sub lists/strings
# C++ can cut strings also
#
print "\nTuples | Slicing\n"
myTuple = ("hello", "I", "am", "unchangeable", "that's", "a", "fact")
print "Printing tuple"
print myTuple
print "Printing tuple backwards" + str(myTuple[::-1])
print "Printing tuple from 1-4(Slicing)" + str(myTuple[1:4])
#####################################################
# Index Range Checking and While Loops
#####################################################
# Index Range Checking is used to get the correct length of list/array/etc
# Very useful for loops, or checking to not get out of bounds
# C++ has range based for loops which is lke index range checking
#
# While loops are very similar to other languages except they have different syntax
# C++ has the exact same thing except different syntax
print "\nIndex Range Checking | While Loops\n"
index = [0,1,2,3,4,5,6,7,8]
x = 0
print "x value is " + str(x) + " & length of index is " + str(len(index))
if 0 <= x < len(index):
    print "x is less than length of index"
while x in range(0,len(index)):
    x = x + 1
print "After while loop, x value is now " + str(x)
#####################################################
# Dictionaries & Switch Statement & Functions
#####################################################
#
# Switch Statements are not built in python, but they can be coded in multiple
# ways, I'll be using dictionaries to code a switch statement
# C++ has built in switch statements
#
# Functions are preset code blocks to be executed when called.
# syntax to define & create a function is using def and :
# it is also tab sensitive
# C++ has functions except it needs to be type defined ex: void, int, etc.
#
# Dictionaries are like hash tables, They have keys and keys have data.
# C++ does not have dictionaries, but it has hash tables

print "\nDictionary | SwitchStatement | Functions\n"
def one():
    return "first case"
def two():
    return "second case"
def three():
    return "third case"

dict = {
    1: one,
    2: two,
    3: three
};

def switchCase(argument):
    func = dict.get(argument, "nothing")
    return func()

print "Calling second case: " + str(switchCase(2))
print "Calling first case: " + str(switchCase(1))
#####################################################
# Type Checking & Subprocess
#####################################################
# Python has two built in functions to tell the use what type the variable is
# during runtime. Great way to debug
# C++ has both static and dynamic checking by using cast<>
#
# Python has the ability to use unix/linux commands by importing subprocess
# C++ can also use linux commands by using function system() and including
# stdlib.h

print "\nType Checking\n"
print type(dict)
print type(myTuple)
print type(a)
print type(b)
print type(num)

import subprocess
print "Using Unix command ls"
subprocess.call("ls")
print "\nEnd of Program\n"
