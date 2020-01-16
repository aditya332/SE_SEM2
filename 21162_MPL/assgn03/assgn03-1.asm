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

	dhex4 : db "4-digit Hexadecimal A1B2 to "
	dhex4len : equ $-dhex4
	dbcd4 : db "BCD Conversion : "
	dbcd4len : equ $-dbcd4
	dbcd5 : db "5-digit BCD number : "
	dbcd5len : equ $-dbcd5
	dhex5 : db "HEX Conversion : "
	dhex5len : equ $-dhex5
	
	bcd5 : dw 10101
	bcd5len : equ $-bcd5
	space: db " "
	newLine: db 10
	tab: db "    "

section .bss
	choice: resb 01
	hex4 : resb 100

section .text
	global _start
	_start:
	
	mov rax,0xa1b2
	mov [hex4],rax

	print title,titlelen
	read choice,2		;* 2 bytes for read statement to execute each time
	print newLine,1
	
	cmp byte[choice],31h
	je label1

	cmp byte[choice],32h
	je label2
	
	mov rax,60
	mov rdi,00
	syscall

	label1:
		print dhex4,dhex4len
		print dbcd4,dbcd4len
		mov rax,hex4
		xor rcx,rcx
		xor dx,dx
		begin:
			mov dx,10
			div dx
			push dx
			inc rcx
			cmp rax,0
			jne begin
		loop2:
			xor rdx,rdx
			pop rdx
			print rdx,1
			dec rcx
			jnz loop2
		ret

	label2:
		ret

