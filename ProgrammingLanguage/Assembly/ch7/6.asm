assume cs:code, ds:data

data segment
    db 'welcome to masm!'
    db '................'
data ends


code segment
start:
    mov ax, data
    mov ds, ax

    mov bx, 0

    mov cx, 8
  s:mov ax, [bx]
    mov [bx + 16], ax
    add bx, 2
    loop s

    mov ax, 4c00H
    int 21H

code ends
end start











