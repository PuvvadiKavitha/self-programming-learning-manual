assume cs:code, ds:data

data segment
    db 'ibm             '
    db 'dec             '
    db 'dos             '
    db 'vax             '
data ends


code segment
start:
    mov ax, data
    mov ds, ax

    mov bx, 0
    mov cx, 4
 s1:mov si, 0
    
    mov cx, 3		;每次都将cx设置为3，造成死循环
 s2:mov al, [bx + si]
    and al, 11011111B
    mov [bx + si], al
    inc si
    loop s2

    add bx, 16
    loop s1


    mov ax, 4c00H
    int 21H

code ends
end start















