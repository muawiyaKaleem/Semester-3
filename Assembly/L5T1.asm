[org 0x100]

jmp start

num1: dw 1,2,3,4,5,1,2,3,4,5
result: dw 0

start:
	
	mov ax,0
	mov bx,0
	outerloop:
	
		add ax,[num1+bx]
		add bx,2
		cmp bx,20
		jne outerloop
		

mov [result],ax	
mov ax,0x4c00
int 0x21
	
