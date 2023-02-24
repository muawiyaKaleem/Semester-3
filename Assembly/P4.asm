[org 0x100]
jmp start

clearScreen:
	mov ah, 07h		;scroll down ftn
	xor al, al		;no of lines by which to scroll down(00h=entire window)
	xor cx, cx		;upper left corner
	mov dx,174fh		;lower right corner ==> 23 rows & 79 col

	mov bh, 00h		;Black on Black
	int 10h

	ret

check:

	mov al,0
	mov bl,0
	mov flag,0
	inn:
		cmp [string1+al],[string1+bl]
		add bl,1
		
		jne inn
		
		mov flag,1
		
		add al,1
		mov bl,0
		jmp inn


ret

start:

call clearScreen
call check

cmp flag,0
;if not equal it means they are anagram


mov ax,0x4c00
int 21h

section.data

string1 db "mary", 0x0d, 0x0a, '$'
string2 db "army", 0x0d, 0x0a, '$'
flag: 0
