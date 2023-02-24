[org 0x100]

jmp start
data: dw 3,1,2,4

start:
	mov cx,4
	outerloop:
		mov bx,0
		innerloop:
			mov ax,[data+bx]
			cmp ax,[data+bx+2]
			jbe noswap
			
	mov dx,[data+bx+2]
	mov [data+bx+2],ax
	mov [data+bx],dx
		
	noswap:
		add bx,2
		cmp bx,6
		jne innerloop
		
	sub cx,1
	jnz outerloop

mov ax,0x4c00
int 0x21
