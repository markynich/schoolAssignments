;Assignment 5
comment #
Date : 05/22/2019
This program gets 2 signed numbers from the user then does the following:
	1. Adds the two numbers
	2. Substracts the two numbers
	3. Waits for user to press any key to continue
	4. Loops the same process 2 more times, 3 loops in total
#
;import library
include irvine32.inc 

.data
	strBegin byte "Sum & Diff of two signed numbers",10,13,0
	strUI byte "Please Enter a Number: ",0
	strSum byte "The Sum of two numbers: ",0
	strDiff byte "The Difference of two numbers: ",0
	strKey byte "Press any key...",08,0
	strEnd byte "End of Assignment 5",10,13,0
	twoNum sdword 2 dup(?)

.code
;----------------------- start of main -----------------------
main proc
	mov dh, 13					;Beginning Line
	call Locate						;center
	mov edx, OFFSET strBegin
	call writeString
	mov ecx, 3						;ecx = 3
Loop1:	mov esi, OFFSET twoNum		;pointer
		mov dh, 14				;Second Line
		call Input					;user input
		mov dh, 15				;Third Line
		call Input					;user input
		mov dh, 16				;Fourth Line
		call DisplaySum				;calculate sum
		mov dh, 17				;Fifth Line
		call DisplayDiff			;calculate diff
		mov dh, 18				;Sixth Line
		call WaitForKey				;wait for key press
		call ClrScr					;clear screen
		mov dh, 13				;Back to Beginning
		call Locate					;center cursor
loop Loop1
	mov edx, OFFSET strEnd
	call writeString
	mov dh, 14					;End Line
	call Locate
exit									;exit process
main endp								;end process

;----------------------- end of main -----------------------
;----------------------- procs below -----------------------

comment #
Input:
	Centers the cursor and gets first user input number
	and saves the number into an array called twoNum
#
Input proc
		call Locate
		sub eax, eax
		mov edx, OFFSET strUI
		call writeString
		call readInt
		mov [esi], eax
		add esi, TYPE twoNum
		call Crlf
ret
Input endp
;------------------------------------------------------------

comment #
DisplaySum:
	Centers the cursor and Adds the two numbers that are stored
	in the array twoNum
#
DisplaySum proc
		call Locate
		mov eax, [twoNum]
		add eax, [twoNum + (LENGTHOF twoNum - 1)* TYPE twoNum]
		mov edx, OFFSET strSum
		call writeString
		call writeInt
ret
DisplaySum endp

;------------------------------------------------------------
comment #
DisplayDiff:
	Centers the cursor and subtracts the two numbers that are stored
	in the array twoNum
#
DisplayDiff proc
		call Locate
		mov eax, [twoNum]
		sub eax, [twoNum + (LENGTHOF twoNum - 1)* TYPE twoNum]
		mov edx, OFFSET strDiff
		call writeString
		call writeInt
		call Crlf
ret
DisplayDiff endp

;------------------------------------------------------------
comment #
WaitForKey:
	Centers the cursor and displays the message "Press any key..."
	while waiting for the user to press any key to continue
#
WaitForKey proc
		call Locate
		mov edx, OFFSET strKey
		call writeString
		call readChar
ret
WaitForKey endp

;------------------------------------------------------------
; Locate: centers the cursor

Locate proc
		mov dl, 42
		call Gotoxy
ret
Locate endp


end main								;end whole code


comment $

The run of my program

Sum & Diff of two signed numbers
Please Enter a Number: 12
Please Enter a Number: -3
The Sum of two numbers: +9
The Difference of two numbers: +15
Press any key...

Please Enter a Number: 13
Please Enter a Number: 5
The Sum of two numbers: +18
The Difference of two numbers: +8
Press any key...

Please Enter a Number: -4
Please Enter a Number: 12
The Sum of two numbers: +8
The Difference of two numbers: -16
Press any key...

End of Assignment 5
Press any key to continue . . .
$