[org 0x100]

mov ah,byte[num1]
mov al,byte[num1+1]

mov bh,byte[num1]
mov al,byte[num1+1+1]

mov ch,[num2]
mov cl,[num2+1]

add ax,bx
add ax,cx

mov ax,0x4c00
int0x21

num1: dw 2,3
num2: db 1,2
