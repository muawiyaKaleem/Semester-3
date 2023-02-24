[org 0x100]

mov ax,0
mov cx,9
mov bx,0
outerloop:

	check:
	mov dx,[tag+bx]
	cmp dx,2
	je if

	s
	add ax,[tag+bx]
	jnp end
	
	if:
	add bx,1
	jmp check

end:	
	sub cx,1
	
jnz outerloop

mov ax,0x4c00
int 0x21

tag: dw 1,2,3,2,1,2,3,0,1,2
