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
    mov si, 0
    mov di, 16

    mov cx, 8
  s:mov ax, [si]	;si存放源数据地址
    mov [di], ax	;di存放目的地址
    add si, 2
    add di, 2
    loop s


    mov ax, 4c00H
    int 21H 
code ends

end start