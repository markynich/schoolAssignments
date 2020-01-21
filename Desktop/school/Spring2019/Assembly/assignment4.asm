;Assignment 4
comment #
Date : 05/14/2019
This program gets 10 numbers from the user then does the following:
	1. It prints out the 10 numbers the user input
	2. It prints out the sum of the 10 numbers
	3. It prints out the average of the 10 numbers
	4. It prints out the reverse order of the 10 numbers
#
;imort library
include irvine32.inc 

.data
	strBegin byte "Hello, you will be asked to enter a number 10 times",13,10,0
	strInput byte "Enter a number: ",0
	strPrint byte "Printing out the 10 numbers",13,10,0
	strSum byte 13,10,"Sum of the 10 numbers : ",0
	strMean byte 13,10,"Mean of the 10 numbers : ",0
	strRot byte 13,10,"After Rotation: "
	strRemainder byte "/10",0
	storageArr dword 10 dup(?)
	arrSize = ($ - storageArr) / 4

.code
	main proc
		mov edx, OFFSET strBegin			;print beginning
		call writeString			
		mov ecx, arrSize					;10 loops
		sub eax, eax						;zero eax
		mov esi, OFFSET storageArr			;esi = number array
		mov edx, OFFSET strInput			;"please enter num"

;		--------------------- user input into array ---------------------

	L1:	call writeString					;enter a number string
		call readDec						;read user input
		mov [esi], eax						;store num in array
		add esi, TYPE storageArr			;move to next element
		sub eax, eax						;zero out eax
		Loop L1								;end of user input
				
		call Crlf
		mov esi, OFFSET storageArr			;reset pointer
		mov ecx, arrSize					;10 loops

;		--------------------- print original array ---------------------

		mov edx, OFFSET strPrint
		call writeString
	L2: 					
		mov eax, [esi]						;eax = element
		call writeDec						;output element
		mov eax, ' '
		call writeChar						;print space
		add esi, TYPE storageArr			;move to next element
		Loop L2								;end of printing array
		mov esi, OFFSET storageArr			;reset pointer
		sub eax, eax						;zero out eax
		mov ecx, arrSize					;10 loops
		call Crlf							;new line
		mov edx, OFFSET strSum				;"sum of 10 nums"
		call writeString					;print out

;		--------------------- start of sum function ---------------------

	L3:	add eax, [esi]						;eax + element
		add esi, TYPE storageArr			;move to next element
		Loop L3								;end of summing
		call writeDec						;print sum
		call Crlf							;new line

;		--------------------- start of mean function ---------------------

		mov edx, OFFSET strMean				;"mean of 10 nums"
		call writeString					;print out
		sub edx, edx						;zero out edx
		mov ebx, arrSize					;ebx = arrSize
		div ebx								;eax / ebx
		call writeDec						;print mean
		mov eax, ' '
		call writeChar						;print space
		mov eax, edx						; eax = edx
		call writeDec						;print remainder
		mov edx, OFFSET strRemainder
		call writeString					;"/10"
		call Crlf							;new line

;		--------------------- start of switching array ---------------------

		mov ecx, arrSize					;10 loops
	L4:	mov ebx, ecx
		dec ecx
		mov edi, OFFSET storageArr

;		--------------------- inner loop to move element ---------------------

		switch:								
				mov eax, [edi]				;eax = [edi]
				add edi, TYPE storageArr	;move pointer up
				xchg eax, [edi]				;trade elements
				sub edi, TYPE storageArr	;mov pointer down
				xchg eax, [edi]				;trade elements
				add edi, TYPE storageArr	;mov pointer up
				loop switch					;end of loop
		mov ecx, arrSize					;10 loops
		mov esi, OFFSET storageArr			;pointer
		call Crlf							;new line

;		--------------------- print out new sorted array ---------------------
		print:	
				mov eax, [esi]
				call writeDec				;print number
				mov eax, ' '				
				call writeChar				;print space
				add esi, TYPE storageArr	;mov element
				loop print					;end of loop
		mov ecx, ebx
		Loop L4								;end of switching
		call Crlf
	exit									;exit process
	main endp								;end process
end main									;end whole code

comment $

The run of my program

Hello, you will be asked to enter a number 10 times
Enter a number: 10
Enter a number: 9
Enter a number: 8
Enter a number: 7
Enter a number: 6
Enter a number: 5
Enter a number: 4
Enter a number: 3
Enter a number: 2
Enter a number: 1

Printing out the 10 numbers
10 9 8 7 6 5 4 3 2 1

Sum of the 10 numbers : 55

Mean of the 10 numbers : 5 5/10

9 8 7 6 5 4 3 2 1 10
8 7 6 5 4 3 2 1 9 10
7 6 5 4 3 2 1 8 9 10
6 5 4 3 2 1 7 8 9 10
5 4 3 2 1 6 7 8 9 10
4 3 2 1 5 6 7 8 9 10
3 2 1 4 5 6 7 8 9 10
2 1 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 9 10

$