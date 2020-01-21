;Assignment 3
comment #
Date : 04/30/2019
((num1 ^ 3) * num2 + 5 * ( num2 ^ 2)) / num3 = " " R " "
This program does the equation above.
It prints out the result of the equation
Example "7 R 1" meaning 7 remainder 1
#

include irvine32.inc 

.data
	stringNum1 byte 13,10,"For equation above, Enter your num1: ",0
	stringNum2 byte "Enter your num2: ",0
	stringNum3 byte "Enter your num3: ",0
	strEqEx byte "Equation : ((num1^3)*num2+5*(num2^2))/num3 = output",0
	stringEq byte 13,10,"((num1^3)*num2+5*(num2^2))/num3 = ",0
	stringR byte " R ",0
	newLine byte 13,10,0
	num2DWord dword ?
	num3DWord dword ?
	fiveDWord dword 5
.code
	main proc
		mov edx, offset strEqEx
		call writeString		;print equation example
		mov edx, offset stringNum1
		call writeString
		call readInt			; user input for num1
		mov ebx, eax
		mov edx, offset stringNum2
		call writeString
		call readInt			; user input for num2
		mov num2DWord, eax
		mov edx, offset stringNum3
		call writeString		
		call readInt			; user input for num3
		mov num3DWord, eax
		mov eax, ebx			; end of user input
		
; -------------- start of calculations here --------------
		mov ecx, 3				;loop variable
		userLoop:				; (num1^3)
				mul eax
				loop userLoop
		sub edx, edx			; zero out
		mul num2DWord			; (num1^3)*num2
		sub edx, edx			; zero out
		mov ebx, eax			; ebx = (num1^3)*num2
		mov eax, num2DWord		; eax=num2
		mul eax					; (num2^2)
		sub edx, edx			; zero out
		mul fiveDWord			; (num2^2)*5
		add eax, ebx			; ebx + eax
		div num3DWord			; division
		mov ebx, edx
		mov edx, offset stringEq
		call writeString		;print equation
		call writeInt			;print answer
		mov eax, ebx
		mov edx, offset stringR
		call writeString		;print " R "
		call writeInt			;print remainder
		mov edx, offset newLine
		call writeString		;print new line
	exit						;exit process
	main endp					;end process
end main						;end whole code

comment $

The run of my program

Equation : ((num1^3)*num2+5*(num2^2))/num3 = output
For equation above, Enter your num1: 1
Enter your num2: 2
Enter your num3: 3

((num1^3)*num2+5*(num2^2))/num3 = +7 R +1

$