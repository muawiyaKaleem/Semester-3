[org 0x100]

mov ah,[tag]
mov ch,4
mov bx,0

outerloop:
	add ah,[tag+bx]
	add bx,1
	sub ch,1
jnz outerloop

mov ax,0x4c00
int 0x21

tag: db 1,2,3,1,2
