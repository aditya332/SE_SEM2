%macro print 2
	mov rax,01
	mov rdi,01 
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro

%macro read 2
	mov rax,00
	mov rdi,00
	mov rsi,%1
	mov rdx,%2
	syscall
%endmacro

section .data
	title : db "Conversion",10,"1 for HEX to BCD",10,"2 for BCD to HEX",10,"3 for Exit",10,"Enter Choice: ",10,
	titlelen : equ $-title
	
	space: db " "
	newLine: db 10
	tab: db "    "

section .bss
	choice: resb 01

section .text
	global _start
	_start:
	
	print title,titlelen
	
	
	mov rax,60
	mov rdi,00
	syscall




