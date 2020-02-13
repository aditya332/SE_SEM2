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
	title : db "Multiplication",10,"Press",10,"1 for Multiplication through successive addititon",10,"2 for Multiplication by Add and Shift method ",10,"Choice -" 
	titlelen : equ $-title
	plier : db "Enter Multiplier : "
	plierlen : equ $-plier
	plicand : db "Enter Multiplicand : "
	plicandlen : equ $-plicand
	newLine: db 10d

section .bss
	choice : resb 2
	mplier : resb 2
	mplicand : resb 2
	ans : resb 4
	inAscii: resb 16;
	outAscii: resb 16;

section .text
	global _start
	_start:

	menu:
		print title,titlelen
		read choice,2

		cmp byte[choice],31h
		je label1

		cmp byte[choice],32h
		je label2

	mov rax,60
	mov rdi,00
	syscall


	label1:
		call Input
		xor rax,rax
		multiply :
			add rax,rbx
			dec rcx
			jnz multiply
	
		call _HexToAscii		
		print outAscii,12
		print newLine,1
		jmp menu

	label2 :
		call Input
		xor rax,rax;
		
		shiftAdd:
		shr rbx,1;
		jnc skip
		add rax,rcx
		skip:
		shl rcx,1;
		add rbx,0h
		jnz shiftAdd
		
		call _HexToAscii;
		print outAscii,12
		print newLine,1

		jmp menu

Input :
	print plier,plierlen
	read inAscii,16
	call _AsciiToHex
	mov [mplier],rax
	print plicand,plicandlen
	read inAscii,16
	call _AsciiToHex
	mov [mplicand],rax
	
	xor rbx,rbx
	mov rbx,[mplier]
	xor rcx,rcx
	mov rcx,[mplicand]
	
	ret


_AsciiToHex:		;//ASCII in inAscii ----> HEX in RAX
	    mov rsi,inAscii
	    xor rax,rax
	    begin1:
		    cmp byte[rsi],0xA;	//Compare With New Line
		    je done
		    rol rax,04d
		    mov bl,byte[rsi]
		    cmp bl,39h
		    jbe sub30
		    sub bl,07h
	    sub30:
		    sub bl,30h
		    add al,bl
		    inc rsi
		    jmp begin1

		done:
    		ret

_HexToAscii:		;// HEX in RAX -----> ASCII in outAscii
    mov rsi,outAscii+15d
    mov rcx,16d

    begin2:
		xor rdx,rdx
		mov rbx,10h
		div rbx
		cmp dl,09h
		jbe add30
		add dl,07h
    add30:
		add dl,30h
		mov byte[rsi],dl

    update:
		dec rsi
		dec rcx
		jnz begin2

    ret
