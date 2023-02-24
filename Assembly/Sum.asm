[org 0x100]

jmp main

Data: dw 1,2,1,1,1,1,1
result: dw 0



	Sum:
		mov ax,[Data+bx]
		add [result],ax
		add bx,2
		sub cx,1
		jnz Sum
		ret

main:
	mov ax,[Data]
	mov cx,7
	mov bx,0
	
	call Sum
	
	mov ax,0x4c00
	int 0x21


