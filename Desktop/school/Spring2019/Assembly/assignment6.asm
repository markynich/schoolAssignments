;Assignment 6
comment #
Date : 05/30/2019
This program does the following:
	1. Takes user input of an unsigned number
	2. Finds all prime numbers less than the user input
	3. Prints out all the prime numbers
	4. Returns 1 or 0 within edi register
	5. returns 1 or 0 within esi register to exit program
#
;import library
include irvine32.inc 

.data
	strBegin byte "Start of Assignment 6",10,13,10,13,0
	strUI byte "Please Enter an Unsigned Number: ",0
	strFind byte "Displaying all Prime numbers: ",0
	strNone byte "No Prime Numbers",10,13,0
	strEnd byte 10,13,10,13,"End of Assignment 6",10,13,10,13,0
	strSpace byte " ",0

.code
;----------------------- start of main -----------------------
main proc

Start:	sub eax, eax
		mov edx, OFFSET strBegin		;start Str
		call writeString
		mov edx, OFFSET strUI			;userInput Str
		call writeString
		call readDec					;get user input
		call crlf
		push eax
		call uiCheck					;check userInput
		cmp esi, 1
		je EndError						;end program w/error
		pop	eax							;clear stack
		mov ebx, eax					;ebx = user input
		mov eax, 2
		mov edx, OFFSET strFind			
		call writeString

;-------- Start of prime finding --------
Find1:  push eax						;eax into stack
		mov ecx, 2						;counter for div
		call isPrime
		pop eax							;clear stack
		cmp edi, 0						;if (edi = 0) return 0;
		je notPrime						;jump to notPrime

;-------- If edi = 1 --------
Prime: 	    call writeDec				;print num
			mov edx, OFFSET strSpace	
			call writeString

;-------- If edi = 0 --------
notPrime:	inc eax
			call numCheck
			cmp esi, 1
			je EndProgram				;end program
			jmp Find1

;-------- exit if userInput <=1 --------			
EndError:	mov edx, OFFSET strNone
			call writeString

;-------- Standard exit --------	
EndProgram: mov edx, OFFSET strEnd
			 call writeString
			 exit						;exit process

main endp								;end process

;----------------------- end of main -----------------------
;-----------------------------------------------------------


;----------------------- procs below -----------------------
comment #
isPrime:
	Procedure receives values of eax within stack & ecx directly
	then uses register "edi" to return value:
		- "0" which means eax is not prime
		- "1" which means eax is prime
#
isPrime proc
Comp:		xor edx, edx			; for (ecx = 2; i < eax; i++)
			mov eax, [esp+4]
			cmp eax, ecx
			je return1
			div ecx
			inc ecx
			cmp edx, 0				;if (edx = 0) return 0;
			je return0				;else return 1;
			jmp Comp
return1:	mov edi, 1
			ret
return0:	xor edi, edi
			ret
isPrime endp

;------------------------------------------------------------

comment #
uiCheck:
	Checks if user input is 0 or 1
	If it is, the program will end, saying no prime numbers
#
uiCheck proc
		mov eax, [esp+4]			;if (eax <= 1)
		cmp eax, 1					;cout << "No Prime Numbers"
		jle inputError				; exit(1);
		mov esi, 0
		ret
inputError:
		mov esi, 1
		ret
uiCheck endp

;------------------------------------------------------------

comment #
numCheck:
	Checks if number is greater than user input
	If so, program will end, which means all numbers
	have been checked
#
numCheck proc
		cmp eax, ebx				;if (eax > ebx)
		jg greater					; exit(0);
		mov esi, 0
		ret
greater:
		mov esi, 1
		ret
numCheck endp

end main								;end whole code


comment $

The run of my program

Start of Assignment 6

Please Enter an Unsigned Number: 40

Displaying all Prime numbers: 2 3 5 7 11 13 17 19 23 29 31 37

End of Assignment 6

Press any key to continue . . .


PS: If user enters 0 or 1
---------------------------------------------------------------------------------

Start of Assignment 6

Please Enter an Unsigned Number: 1

No Prime Numbers


End of Assignment 6

Press any key to continue . . .
$