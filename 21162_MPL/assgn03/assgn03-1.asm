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
	
	req1: db "Enter HEX: "
	lenReq1: equ $-req1
	req2: db "Enter BCD: "
	lenReq2: equ $-req2
	msg1: db "BCD Equivalent: "
	lenMsg1: equ $-msg1
	msg2: db "HEX Equivalent: "
	lenMsg2: equ $-msg2

	space: db " "
	newLine: db 10

section .bss
	hex: resb 100;
	inAscii: resb 16;
	outAscii: resb 16;
   	digit: resb 1;
	choice: resb 1;
	count: resb 1;
	unit: resd 1;
	ten: resd 1;

section .text
	global _start
	_start:
	
	menu:
		print title,titlelen
		read choice,2		;* 2 bytes for read statement to execute each time
	
		cmp byte[choice],31h
		je label1

		cmp byte[choice],32h
		je label2
	
	mov rax,60
	mov rdi,00
	syscall

	label1:	
		print req1,lenReq1;
		read inAscii,10
        print msg1,lenMsg1;
		call _AsciiToHex;     //hex in RAX

        ;//Hex To BCD
        xor rdx,rdx;
        mov rbx,10d;
        push rbx;   //to flag the end of the stack

        pushDigits:
		    div rbx;
		    push rdx;
		    xor rdx,rdx;
		    add rax,0h;
		    jnz pushDigits;

        popDigits:
		    xor rbx,rbx;
		    pop rbx;
		    cmp rbx,10d
		    je endOfStack;
		    add rbx,30h;
		    mov [digit],rbx;
		    print digit,1;
		    jmp popDigits;

        endOfStack:
		    print newLine,1;
		    jmp menu;

	label2:

        print req2,lenReq2;
        read inAscii,10;
        call _AsciiToHex;
        mov qword[unit],1d;
        mov byte[ten],10d;
        mov rbx,10h
        xor rcx,rcx;

        multiply:
		    xor rdx,rdx;
		    div rbx;
		    push rax;
		    mov rax,rdx;
		    mul dword[unit];
		    add rcx,rax;
		    xor rax,rax;
		    mov eax,dword[unit];
		    mul dword[ten];
		    mov dword[unit],eax;
		    pop rax;
		    add rax,0h;
		    jnz multiply;

        mov rax,rcx;
        call _HexToAscii;
        print msg2,lenMsg2;
        print outAscii,16;
        print newLine,1

        jmp menu;

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
