org 100h


jmp start


clearScreen:
mov ah, 07h		;scroll down ftn
xor al, al		;no of lines by which to scroll down(00h=entire window)
xor cx, cx		;upper left corner
mov dx,174fh		;lower right corner ==> 23 rows & 79 col

mov bh, 00h		;Black on Black
int 10h

ret


ptr1:

	mov dx, input1
	mov ah, 09
	int 21h
	
	mov dx, string1
	mov ah, 0x0a
	int 21h
ret

ptr2:

	mov dx, input2
	mov ah, 09
	int 21h
	
	mov dx, string2
	mov ah, 0x0a
	int 21h
ret

print:
	
	mov dl, [string3+ch]
	mov ah, 02
	int 21h
	

check:
	mov bh,2
	mov ah,2
	mov ch,2
	
	inn:
		mov bl,[string1+bh]
		mov al,[string2+ah]
		
		cmp bl,al
		
		add ah,1
		jne inn
		
	nothing:
		mov [string3+ch],[string1+bh]
		call print
		add bh,1
		add ch,1
		mov ah,2
		jmp inn
ret


start:

call clearScreen
call ptr1
call ptr2
call check 

mov ax,4c00h
int 21h


section.data

input1  db "Enter 1st Array:  ", 0x0d, 0x0a, '$'
string1 db 20, 0

input2  db "Enter 2nd Array:  ", 0x0d, 0x0a, '$'
string2 db 20, 0

string3 db 20, 0

