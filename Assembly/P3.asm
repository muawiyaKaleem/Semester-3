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

done:
	mov ax,0x4c00
	int 21h
ret

goToNewLine:
	mov dx, newLine
	mov  ah, 9          ; DOS print-string function
	int  0x21
    ret


printstr:
mov cx, msg-string		;calculate string length
mov al,1 			;write mode  
				;bit 0: update cursor after writing;
				;bit 1: string contains attributes.
mov bh, 0			;page num
mov bl, 07h			;color
mov dh, 23			;DX staring point ;row 5
mov dl, 0			;col 13
push cs
pop es
mov bp, string
mov ah, 13h			;To print string on the screen	
int 10h

ret


triangle:
	
	mov bl , 0
	mov cl , 1
	
	loop:
	
	mov dl, [array+bl]
	mov ah, 02
	int 21h
	
	add bl,1
	cmp al,cl
	
	loopne
	
	cmp bl,al
	jmp done
	
	add bl,1
	
	call goToNewLine

input:
	call printstr
	
	mov ah, 01
	int 21h
	
	sub al,30h
	
	call triangle
ret


	
start:

	call clearScreen
	call input
	

section.data

string: db 'Enter number of rows: '
msg:

array db "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 0x0d, 0x0a, '$'
newLine db 0x0a, '$'
