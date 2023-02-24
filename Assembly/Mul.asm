[org 0x100]

mov ax,[Data]

mov bx,[Data+2]

mul bx

mov ax,0x4c00
int 0x21

Data: dw 3,4
