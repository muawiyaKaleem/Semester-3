[org 0x100]

jmp start

tag: dw 47,72,31
tag2: dw 10
result: dw 0

outerloop:
	mov ax,[tag+bx]
	
	inner:
		div cx
		add ax,dx
		cmp [result],ax
		jae final
		
		jmp outerloop
		
		final:
			mov [result],ax
			jmp outerloop
	
	
start:
	mov bx,0	
	mov cx,[tag2]
	call func
	mov ax,0x4c00
	int 0x21
