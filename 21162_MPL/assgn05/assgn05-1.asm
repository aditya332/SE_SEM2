global fileDescriptor,char,buffer,lenText;
extern _TextCount;

%macro print 2
    mov rax,01;
    mov rdi,01;
    mov rsi,%1;
    mov rdx,%2;
    syscall;
%endmacro

%macro read 2
    mov rax,00;
    mov rdi,00;
    mov rsi,%1;
    mov rdx,%2;
    syscall;
%endmacro

section .data
    dash: db 10,"----------------------------------------------------------",10;
    lenDash: equ $-dash;

    reqFile: db "Enter File Name (with extension): ";
    lenReqFile: equ $-reqFile;

    reqChar: db "Enter Character to Search: ";
    lenReqChar: equ $-reqChar;

    errMsg: db "File Opening Error!";
    lenErrMsg: equ $-errMsg;

    space: db " ";
    newLine: db 10d;

section .bss
    buffer: resb 8192;
    lenBuffer: equ $-buffer;

    fileName: resb 64;
    char: resb 2;
    fileDescriptor: resq 1;
    lenText: resq 1;

section .text
    global _start
    _start:
        print dash,lenDash;

        print reqFile,lenReqFile;
        read fileName,64;

        dec rax;    //String Length in RAX on SYS_READ call
        mov byte[fileName+rax],0;

        print reqChar,lenReqChar;
        read char,2;

        fileopen:
	    mov rax,02;     //SYS_OPEN
	    mov rdi,fileName
	    mov rsi,02
	    mov rdx,0777o
	    syscall;
        cmp rax,-1d;        //-1 is returned to RAX in Case of File Opening Error
        jle error;          // jle is used for Signed Comparison
        mov [fileDescriptor],rax;

	fread:
	    mov rax,00;     //SYS_READ
	    mov rdi,[fileDescriptor]
	    mov rsi,buffer
	    mov rdx,lenBuffer
	    syscall;
        mov [lenText],rax;      //String Length in RAX on SYS_READ call

        call _TextCount;
        jmp exit

        error:
        print errMsg,lenErrMsg;

        exit:
        print dash,lenDash;
	fclose:
	    mov rax,03;     //SYS_CLOSE
	    mov rdi,[fileDescriptor]
	    syscall;
        mov rax,60;
        mov rdi,0;
        syscall;

