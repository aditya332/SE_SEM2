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

%macro fopen 1
    mov rax,02;     //SYS_OPEN
    mov rdi,%1;     //file-name
    mov rsi,02;     //O_RDWR
    mov rdx,0777o;  //File-Permission
    syscall;
%endmacro

%macro fclose 1
    mov rax,03;     //SYS_CLOSE
    mov rdi,%1;     //File-Descriptor
    syscall;
%endmacro

%macro fread 3
    mov rax,00;     //SYS_READ
    mov rdi,%1;     //File-Descriptor
    mov rsi,%2;     //Buffer
    mov rdx,%3;     //Count
    syscall;
%endmacro

%macro fwrite 3
    mov rax,01;     //SYS_WRITE
    mov rdi,%1;     //File-Descriptor
    mov rsi,%2;     //Buffer
    mov rdx,%3;     //Count
    syscall;
%endmacro

section .data
    dash: db 10,"----------------------------------------------------------",10;
    lenDash: equ $-dash;

	reqFile: db "Enter File Name (with Extension): ";
	lenReqFile: equ $-reqFile;
	
	errMsg: db "File Opening Error!";
	lenErrMsg: equ $-errMsg;
	
	sortMsg: db 10,"Sorted List: ",10;
	lenSortMsg: equ $-sortMsg;
	
	newLine: db 10d;
	space: db " ";

section .bss
	buffer: resb 8192;
	lenBuffer: equ $-buffer;

	fileName: resb 64;
	fileDescriptor: resq 1;
	lenText: resq 1;

	count: resq 1;
	array: resb 20;
	temp: resb 1;
	
	inAscii: resb 16;
	outAscii: resb 4;
	
	
	
section .text
	global _start
	_start:
		print dash,lenDash;
		
		print reqFile,lenReqFile;
		read fileName,64;
		
		dec rax;
		mov byte[fileName+rax],0;
		
		fopen fileName;
		cmp rax,-1d;
		jle error;
		mov [fileDescriptor],rax;
		
		fread [fileDescriptor],buffer,lenBuffer;
		mov [lenText],rax;
		call _ProcessBuffer;
		call _BubbleSort;
		call _ProcessArray;
		print sortMsg,lenSortMsg;
		print buffer,[lenText]
		
		fwrite [fileDescriptor],sortMsg,lenSortMsg;
		fwrite [fileDescriptor],buffer,[lenText];
		jmp exit;
		
		
		
		error:
		print errMsg,lenErrMsg;
		
		exit:
		print dash,lenDash;
		fclose [fileDescriptor];
		mov rax,60;
		mov rdi,00;
		syscall;
		
		
_ProcessBuffer:	
	mov rcx,[lenText];
	mov rsi,buffer;
	mov rdi,array;
	
	begin0:
	mov al,[rsi];
	mov [rdi],al;
	
	update0:
	inc rsi;	//Number
	inc rsi;	//space
	inc rdi;
	inc byte[count];
	dec rcx;
	dec rcx;
	jnz begin0;

	ret;		
	
_BubbleSort:
	mov rsi,0h;		//i=0
	mov rcx,[count];
	dec rcx;
	outerLoop:
	mov rdi,0h;		//j=0
	
		innerLoop:
		mov rax,rdi;		//j in RDI
		inc rax;		//j+1 in RAX
		
		mov bl,byte[array+rdi];		//array[j]
		mov dl,byte[array+rax];		//array[j+1]
		
		cmp bl,dl;
		jbe updateInnerLoop
		
		swap:
		mov byte[array+rdi],dl;
		mov byte[array+rax],bl;
		
		updateInnerLoop:
		inc rdi;
		cmp rdi,rcx
		jb innerLoop
	
	updateOuterLoop:
	inc rsi;
	cmp rsi,rcx;
	jb outerLoop;
	
	ret;	
;																									void Database::bubbleSort(){
;																										for(int i=0;i<n-1;i++){
;																											for(int j=0;j<n-i-1;j++){
;																												if(array[j+1]<array[j])
;																													swap(&array[j],&array[j+1]);
;																											}
;																										}
;																									}	
	
	
	
	
_ProcessArray:
	
	mov rsi,array;
	mov rdi,buffer;
	mov rcx,[count];
	
	begin1:
	mov al,[rsi];
	mov [rdi],al;
	
	update1:
	inc	rsi;
	inc rdi;
	inc rdi;
	dec rcx;
	jnz begin1
	
	ret;

