org 100h

jmp start
clrscr:     
    push es
    push ax
    push di

    mov  ax, 0xb800
    mov  es, ax
    mov  di, 0

    nextloc:
        mov  word [es:di], 0x0720
        add  di, 2
        cmp  di, 4000
        jne  nextloc

    pop  di 
    pop  ax
    pop  es
    ret
 
Green:
   MOV AH, 06h    ; Scroll down function
    XOR AL, AL     ; number of lines by which to scroll up (00h = clear entire window)

    mov ch, 0      ; Upper left corner CH=row
    mov cl, 0 ; Upper left corner CL=column
    mov dh, 25 ; lower right corner DH=row
    MOV dl, 79  ; lower right corner DL=column 
    MOV BH, 22h    ; YellowOnBlue
    INT 10H
    mov  ah, 00h      ; BIOS.WaitKeyboardKey
    int  16h          ; -> AX
ret

Yellow:
   MOV AH, 06h    ; Scroll down function
    XOR AL, AL     ; number of lines by which to scroll up (00h = clear entire window)

    mov ch, 0      ; Upper left corner CH=row
    mov cl, 0 ; Upper left corner CL=column
    mov dh, 10 ; lower right corner DH=row
    MOV dl, 40  ; lower right corner DL=column 
    MOV BH, 66h    ; YellowOnBlue
    INT 10H
    mov  ah, 00h      ; BIOS.WaitKeyboardKey
    int  16h          ; -> AX
    
ret

w1:
   MOV AH, 06h    ; Scroll down function
    XOR AL, AL     ; number of lines by which to scroll up (00h = clear entire window)

    mov ch, 13      ; Upper left corner CH=row
    mov cl, 0 ; Upper left corner CL=column
    mov dh, 14 ; lower right corner DH=row
    MOV dl, 79  ; lower right corner DL=column 
    MOV BH, 77h    ; YellowOnBlue
    INT 10H
    mov  ah, 00h      ; BIOS.WaitKeyboardKey
    int  16h          ; -> AX
ret

w2:
   MOV AH, 06h    ; Scroll down function
    XOR AL, AL     ; number of lines by which to scroll up (00h = clear entire window)

    mov ch, 16      ; Upper left corner CH=row
    mov cl, 0 ; Upper left corner CL=column
    mov dh, 17 ; lower right corner DH=row
    MOV dl, 79  ; lower right corner DL=column 
    MOV BH, 77h    ; YellowOnBlue
    INT 10H
    mov  ah, 00h      ; BIOS.WaitKeyboardKey
    int  16h          ; -> AX
ret

w3:
   MOV AH, 06h    ; Scroll down function
    XOR AL, AL     ; number of lines by which to scroll up (00h = clear entire window)

    mov ch, 19      ; Upper left corner CH=row
    mov cl, 0 ; Upper left corner CL=column
    mov dh, 20 ; lower right corner DH=row
    MOV dl, 79  ; lower right corner DL=column 
    MOV BH, 77h    ; YellowOnBlue
    INT 10H
    mov  ah, 00h      ; BIOS.WaitKeyboardKey
    int  16h          ; -> AX
ret

w4:
   MOV AH, 06h    ; Scroll down function
    XOR AL, AL     ; number of lines by which to scroll up (00h = clear entire window)

    mov ch, 22      ; Upper left corner CH=row
    mov cl, 0 ; Upper left corner CL=column
    mov dh, 23 ; lower right corner DH=row
    MOV dl, 79  ; lower right corner DL=column 
    MOV BH, 77h    ; YellowOnBlue
    INT 10H
    mov  ah, 00h      ; BIOS.WaitKeyboardKey
    int  16h          ; -> AX
ret


start: 
call clrscr
call Green
call Yellow
call w1
call w2
call w3
call w4
mov ax, 0x4c00 ; terminate program
int 0x21
