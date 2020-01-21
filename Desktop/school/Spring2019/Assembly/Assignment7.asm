
;Title Assignment 7

COMMENT !
*****************
date: 06/13/2019
Info:
	User enters up to 40 unsigned number that is saved into an array
	To exit, user enters 0 to stop adding numbers into array
	After, array will be printed and then printed again after sorted
*****************
!

include irvine32.inc
; ===============================================
.data

  ; Fill your data here
  strBegin byte "Enter up to 40 unsigned dword integers. To end the array, enter 0.",10,13,0
  strStart byte "After each element press enter:",10,13,10,13,0
  strArr1 byte "Printing unsorted Array: ",10,13,0
  strArr2 byte "Printing sorted Array: ",10,13,0
  arr dword 40 dup(?)
  counter = lengthof arr
;=================================================
.code
main proc
		mov edx, OFFSET strBegin
		call writeString
		mov edx, OFFSET strStart
		call writeString				
		sub esp, 4
		push counter
		push OFFSET arr
		call enter_elem					;Enter Element
		pop ebx
		mov edx, OFFSET strArr1
		call writeString
		push OFFSET arr
		push ebx
		call print_arr					;print unsort array
		call crlf
		push OFFSET arr
		push ebx
		call sort_arr					;sort array
		mov edx, OFFSET strArr2
		call writeString
		push OFFSET arr
		push ebx
		call print_arr					;print sorted array
		call crlf
   exit
main endp

; ================================================
; void enter_elem(addr arr, arrAmount)
;
; Input:
;   Address of the array and the size of the array
; Output:
;   Amount of numbers the user added into the array
; Operation:
;  Stores user input unsigned numbers
;

enter_elem proc

	push ebp
	mov ebp, esp
	push esi
	push ebx
	push edx
	push eax
	xor ebx, ebx
	mov edx, [ebp+12]
	mov esi, [ebp+8]
read1:	xor eax, eax				;eax = 0
		call readDec
		cmp eax, 0				
		je done1					;exit if 0
	mov [esi], eax					;insert element into array
	inc ebx
	cmp ebx, edx					;Check if loop is 40
	jge done1
	add esi, 4
	jmp read1
done1:	mov [ebp+16], ebx
		pop eax
		pop edx
		pop ebx
		pop esi
		pop ebp
		ret 8
enter_elem endp

; ================================================
; void print_arr(arr_addr,arr_len)
;
; Input:
;   array address and amount of numbers inside array
; Output:
;   prints out array onto screen
; Operation:
;  print out the array
;

print_arr proc

  ; FILL YOUR CODE HERE
	push ebp
	mov ebp, esp
	push eax
	push ebx
	push ecx
	push edx
	mov edx, [ebp+12]
	mov ebx, [ebp+8]
	xor ecx, ecx
pLoop:
	cmp ecx, ebx
	je done1				;exit after ecx=ebx
	mov eax, [edx]
	call writeDec
	mov eax, ' '
	call writeChar
	add edx, 4
	inc ecx
	jmp pLoop
done1:	
	pop edx
	pop ecx
	pop ebx
	pop eax
	pop ebp
	ret 8
print_arr endp

; ================================================
; void sort_arr(arr_addr,arr_len)
;
; Input:
;   address of array and amount of numbers in array
; Output:
;   rearranges array from highest to lowest
; Operation:
;   sort the array from highest to lowest
;

sort_arr proc

   ; FILL YOUR CODE HERE
   ; YOU NEED TO CALL COMPARE_AND_SWAP PROCEDURE 
	push ebp
	mov ebp, esp
	push eax
	push ebx
	push edx
	mov edx, [ebp+12]
	mov eax, [ebp+12]
	add eax, 4
	mov ebx, [ebp+8]
	dec ebx
sLoop:
	cmp ebx, 0
	je done2
	push ebx
	push edx
	push eax
	call compare_and_swap
	dec ebx
	jmp sLoop
done2:	
	pop edx
	pop ebx
	pop eax
	pop ebp
	ret 8
sort_arr endp

; ===============================================
; void compare_and_swap(x_addr,y_addr)
;
; Input:
;   address of arr[x] and address of arr[x+1]
; Output:
;   swaps elements if arr[x+1] is greater than arr[x]
; Operation:
;  compare and call SWAP ONLY IF Y > X 
;

compare_and_swap proc

   ; FILL YOUR CODE HERE
   ; YOU NEED TO CALL SWAP PROCEDURE 
   push ebp
   mov ebp, esp
   push eax
   push ebx
   push edx
   push ecx
   push esi
   mov ebx, [ebp+16]
   mov edx, [ebp+12]
   mov eax, [ebp+8]
cLoop:
		cmp ebx, 0
		je done3
		mov ecx, [eax]
		mov esi, [edx]
		cmp ecx, esi
		jbe noSwap
		push edx
		push eax
		call swap
noSwap:	dec ebx
		add eax, 4
		add edx, 4
		jmp cLoop
done3:	
		pop esi
		pop ecx
		pop edx
		pop ebx
		pop eax
		pop ebp
		ret 12
compare_and_swap endp

; =================================================
; void swap(x_addr,y_addr)
;
; Input:
;   address of arr[x] and address of arr[x+1]
; Output:
;   swaps elements arr[x+1] and arr[x]
; Operation:
;  SWAP y and x
;

swap proc

   ; FILL YOUR CODE HERE
   push ebp
   mov ebp, esp
   push edx
   push ecx
   push eax
   mov edx, [ebp+12]
   mov eax, [ebp+8]
   mov ecx, [eax]
   xchg ecx, [edx]
   mov [eax], ecx
	pop eax
	pop ecx
	pop edx
	pop ebp
	ret 8
swap endp

end main


comment $

run:

Enter up to 40 unsigned dword integers. To end the array, enter 0.
After each element press enter:

1
2
3
4
5
6
7
8
9
0
Printing unsorted Array:
1 2 3 4 5 6 7 8 9
Printing sorted Array:
9 8 7 6 5 4 3 2 1
Press any key to continue . . .


$