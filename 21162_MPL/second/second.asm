section  .text
global _start
_start:

;writing name aditya somani
mov edx,13
mov ecx,name
mov ebx,1
mov eax,4
int 0x80

mov [name],dword 'qwry'

;writing name adi somani
mov edx,11
mov ecx,name
mov ebx,1
mov eax,4
int 0x80
mov eax,1
int 0x80

section  .data
name db 'aditya somani'

