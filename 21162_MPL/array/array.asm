;Aditya Somani
;MPL
;H1
;21162


%macro print 2                                      ;Macro for Printing 
	mov rax,1
	mov rdi,1
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro print
	
section .data
	pmsg: db "Number of Positive Numbers: "
	plen: equ $-pmsg
	nmsg: db "Number of Negative Numbers: "
	nlen: equ $-nmsg
	newLine: db 10
	array: dq 90h,68,84,2,-63,21,45,65,78,12    ;Array Definition
	n:equ 10                                    ;Array Length
	ten: db "10"	

section .bss
	digit: resb 1		                    ;variable for converting into digit
	
section .data
	global _start
	_start:
		mov rsi,array			    ;mov base address to rsi
		mov r8,0h			    ;Positive Count
		mov r9,0h                           ;Negative count
		mov rdi,n 		            ;No. of elements in array
		
		beginLoop:
		mov rax,[rsi]                       ;mov array element to rax
		add rax,0h			    ;add rax with 0h
		js negative
		inc r8
		jmp update
		
		negative:
		inc r9
		
		update:
		add rsi,8
		dec rdi
		jnz beginLoop
		
		print pmsg,plen
		mov rax,r8
		call printRAXDigit
		
		print newLine,1
		
		print nmsg,nlen
		mov rax,r9
		call printRAXDigit
		
		print newLine,1
		
		mov rax,60
		mov rdi,0
		syscall
		
			
	
printRAXDigit:
	cmp rax,10
	je for10
	add rax,30h
	mov [digit],rax
	mov rax,1
	mov rdi,1
	mov rsi,digit
	mov rdx,1
	syscall
	ret

	for10:
	print ten,2
	ret

