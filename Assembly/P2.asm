org 100h

jmp start

clearScreen:
	mov ah, 07h		;scroll down ftn
	xor al, al		;no of lines by which to scroll down(00h=entire window)
	xor cx, cx		;upper left corner
	mov dx,174fh		;lower right corner ==> 23 rows & 79 col

	mov bh, 00h		;Black on Black
	int 10h

	ret


;goToNewLine:
;	mov dx, newLine
;	mov  ah, 9          ; DOS print-string function
;	int  0x21
 ;   ret

printStr1:
mov cx, msg1end-data1		;calculate string length
mov al,1 			;write mode  
				;bit 0: update cursor after writing;
             			;bit 1: string contains attributes.
mov bh, 0			;page num
mov bl, 70h			;color
mov dh, 20			;DX staring point ;row 5
mov dl, 13			;col 13
push cs
pop es
mov bp, data1
mov ah, 13h			;To print string on the screen	
int 10h

ret

printStr2:
mov cx, msg2end-data2		;calculate string length
mov al,1 			;write mode  
				;bit 0: update cursor after writing;
             			;bit 1: string contains attributes.
mov bh, 0			;page num
mov bl, 70h			;color
mov dh, 13			;DX staring point ;row 5
mov dl, 37			;col 13
push cs
pop es
mov bp, data2
mov ah, 13h			;To print string on the screen	
int 10h

ret

printStr3:
mov cx, msg3end-data3		;calculate string length
mov al,1 			;write mode  
				;bit 0: update cursor after writing;
             			;bit 1: string contains attributes.
mov bh, 0			;page num
mov bl, 70h			;color
mov dh, 7			;DX staring point ;row 5
mov dl, 65			;col 13
push cs
pop es
mov bp, data3
mov ah, 13h			;To print string on the screen	
int 10h

ret
	

box1:
    mov ah, 06h    ; Scroll down function
    xor al, al     ; number of lines by which to scroll up (00h = clear entire window)

    mov ch, 2      ; Upper left corner CH=row
    mov cl, 2     ; Upper left corner CL=column
    mov dh, 11     ; lower right corner DH=row
    mov dl, 25     ; lower right corner DL=column 
    mov bh, 70h    ; YellowOnBlue
    int 10h
    ret

box2:
    mov ah, 06h    ; Scroll down function
    xor al, al     ; number of lines by which to scroll up (00h = clear entire window)

    mov ch, 15      ; Upper left corner CH=row
    mov cl, 2     ; Upper left corner CL=column
    mov dh, 24     ; lower right corner DH=row
    mov dl, 25     ; lower right corner DL=column 
    mov bh, 70h    ; YellowOnBlue
    int 10h
    
    ret

box3:
    mov ah, 06h    ; Scroll down function
    xor al, al     ; number of lines by which to scroll up (00h = clear entire window)

    mov ch, 2      ; Upper left corner CH=row
    mov cl, 55     ; Upper left corner CL=column
    mov dh, 11     ; lower right corner DH=row
    mov dl, 77     ; lower right corner DL=column 
    mov bh, 70h    ; YellowOnBlue
    int 10h
ret

box4:
    mov ah, 06h    ; Scroll down function
    xor al, al     ; number of lines by which to scroll up (00h = clear entire window)

    mov ch, 15      ; Upper left corner CH=row
    mov cl, 55     ; Upper left corner CL=column
    mov dh, 24     ; lower right corner DH=row
    mov dl, 77     ; lower right corner DL=column 
    mov bh, 70h    ; YellowOnBlue
    int 10h
ret

box5:
    mov ah, 06h    ; Scroll down function
    xor al, al     ; number of lines by which to scroll up (00h = clear entire window)

    mov ch, 9      ; Upper left corner CH=row
    mov cl, 25     ; Upper left corner CL=column
    mov dh, 17     ; lower right corner DH=row
    mov dl, 55     ; lower right corner DL=column 
    mov bh, 70h    ; YellowOnBlue
    int 10h
ret


start: 

call clearScreen
call box1
call box2
call box3
call printStr3
call box4
call printStr1
call box5
call printStr2


mov ax, 0x4c00 ; terminate program
int 0x21


data1: db 'I'
msg1end:

data2: db 'LOVE'
msg2end:

data3: db 'PAKISTAN'
msg3end:


;newLine db 0x0a, '$'
