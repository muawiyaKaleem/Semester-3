[org 0x100]

jmp start

tag: dw 2,2,1,2,4,3,1,3,3,4
size: dw 10
mode: dw 0,0



outerloop:
	mov bx,0
	mov ax,[tag+dx]    ; tag
	
	inerloop:
		add cx,1
		cmp ax,[tag+bx]  ;tag comp with it self
		je mod
		
		add bx,2   ; iner loop increment
				
		jmp inerloop    ; jump if not equal
		
		cmp cx,[size]
		
		add dx,2  ; outer loop increment
		
		je outerloop
		mod:
			add [mode],1
			add bx,2
			jmp inerloop ; jmp if equal
start:
	
	mov cx,0
	xor dx,dx
	call func	
