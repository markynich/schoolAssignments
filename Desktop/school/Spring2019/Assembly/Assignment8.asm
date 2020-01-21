
;Title Assignment 8

COMMENT !
*****************
date: 06/19/2019
Info:
	User decides how many elements in the array
	User decides how many elements in each row
	User decides what type the array is: byte, word, double word
	User enters up to 40 unsigned number that is saved into an array
	User picks which row he/she wants to add together and print onto screen
*****************
!

include irvine32.inc
; ===============================================
.data

  strBegin byte "Welcome to Assignment 8", \
				10,13,"Enter how many elements in your array: ",0
  strR  byte 10,13,"Enter the row size: ",0
  strT  byte 10,13,"1 for byte", \
			 10,13,"2 for word", \
			 10,13,"4 for doubleword", \
			 10,13,"Enter the type of your array with the options above: ",0
  strE  byte	   "Enter an element in your array: ",0
  strS1 byte 10,13,"Enter row number that you want to sum: ",0
  strS2 byte 10,13,"The sum is: ",0
  strF  byte 10,13,"User has enter an invalid input, exiting program",10,13,0
  arrB byte 40 dup(?)
  arrW word 40 dup(?)
  arrD dword 40 dup(?)
  rowSize dword ?
  elements dword ?
  arrType dword ?
;=================================================
.code
main proc
		mov edx, OFFSET strBegin		;start
		call writeString
		xor eax, eax
		call readDec					;how many elements in array
		cmp eax, 40						;eax cannot be more than 40
		ja exitF
		mov elements, eax

		mov edx, OFFSET strR			;how many elements per row
		call writeString
		call readDec
		mov rowSize, eax

		mov edx, OFFSET strT			;what type of array
		call writeString		
		call readDec
		cmp eax, 1						;check user input
		je move01						;if it's 1,2, or 4
		cmp eax, 2
		je move01
		cmp eax, 4
		je move01
		jmp exitF						;exit if not

move01:	mov arrType, eax
		push elements				;adding elements into array
		push arrType
		push OFFSET strE
		push OFFSET arrB
		push OFFSET arrW
		push OFFSET arrD
		call enter_elem				;enter_elem procedure


		mov edx, OFFSET strS1		;user input for row
		call writeString			;selection and sum
		call readDec
		xor edx, edx				;calculating user input
		mul rowSize
		add eax, edx
		xor edx, edx
		mul arrType
		add eax, edx


		sub esp, 4					;space for return value
		push rowSize
		push arrType
		push eax
		push OFFSET arrB
		push OFFSET arrW
		push OFFSET arrD
		call calcRowSum				;calcRowSum proc
		pop eax						;return value
		mov edx, OFFSET strS2
		call writeString
		call writeDec
		call crlf
		jmp exitP
exitF:	mov edx, OFFSET strF		;exit if user input is wrong
		call writeString
exitP:	exit
main endp

; ================================================
; void enter_elem(addr arr, arrAmount)


enter_elem proc

	push ebp
	mov ebp, esp
	pushAD
	xor ebx, ebx					;counter
	mov ecx, [ebp+28]
	mov edx, [ebp+24]
	cmp edx, 1
	je byte01
	cmp edx, 2
	je word01
	jmp dword01

byte01:	mov esi, [ebp+16]			;byte array
		mov edx, [ebp+20]
L1:		cmp ebx, ecx				;while loop
		je exit01					;while (ebx != ecx)
		call writeString			
		call readDec
		mov [esi], al				;insert al into array
		inc ebx
		add esi, 1
		jmp L1

word01:	mov esi, [ebp+12]			;word array
		mov edx, [ebp+20]
L2:		cmp ebx, ecx				;while loop
		je exit01					;while (ebx != ecx)
		call writeString
		call readDec
		mov [esi], ax				;insert ax into array
		inc ebx
		add esi, 2
		jmp L2

dword01:	mov esi, [ebp+8]			;dword array
			mov edx, [ebp+20]
L3:			cmp ebx, ecx			;while loop
			je exit01				;while (ebx != ecx)
			call writeString
			call readDec
			mov [esi], eax			;insert eax into array
			inc ebx
			add esi, 4
			jmp L3
exit01:	
		popAD
		pop ebp
		ret 24
enter_elem endp

; ================================================
; void calcRowSum(int *array, int rowSize, int type, int rowIndex)


calcRowSum proc

	push ebp
	mov ebp, esp
	pushAD
	mov esi, [ebp+28]			;rowSize
	mov edx, [ebp+24]
	xor eax, eax
	xor ecx, ecx
	xor edi, edi
	cmp edx, 1
	je byte02
	cmp edx, 2
	je word02
	jmp dword02
byte02:	mov ebx, [ebp+16]		;array offset
		add ebx, [ebp+20]		;add user input
		xor edx, edx
L1:		cmp eax, esi			;while loop
		je exit02
		mov dl, [ebx+edi]
		add cl, dl
		inc eax
		add edi, 1
		jmp L1

word02:	mov ebx, [ebp+12]		;array offset
		add ebx, [ebp+20]		;add user input
		xor edx, edx
L2:		cmp eax, esi			;while loop
		je exit02
		mov dx, [ebx+edi]
		add cx, dx
		inc eax
		add edi, 2
		jmp L2

dword02:	mov ebx, [ebp+8]		;array offset
			add ebx, [ebp+20]		;add user input
			xor edx, edx
L3:			cmp eax, esi			;while loop
			je exit02
			mov edx, [ebx + edi]
			add ecx, edx
			inc eax
			add edi, 4
			jmp L3

exit02:	mov [ebp+32], ecx			;put return value into stack
		popAD
		pop ebp
		ret 24
calcRowSum endp



end main


comment $

run:

Welcome to Assignment 8
Enter how many elements in your array: 6

Enter the row size: 2

1 for byte
2 for word
4 for doubleword
Enter the type of your array with the options above: 4
Enter an element in your array: 1
Enter an element in your array: 2
Enter an element in your array: 3
Enter an element in your array: 4
Enter an element in your array: 5
Enter an element in your array: 6

Enter row number that you want to sum: 2

The sum is: 11
Press any key to continue . . .

$