assume cs:code, ds:data, ss:stack


data segment
    db '1. display      '
    db '2. brows        '
    db '3. replace      '
    db '4. modify       '
data ends


stack segment
    dw 0, 0, 0, 0, 0, 0, 0, 0
stack ends


code segment
start:
    mov ax, data
    mov ds, ax
    
    mov ax, stack
    mov ss, ax
    mov sp, 16

    mov bx, 0
    mov cx, 4
 s1:push cx		;保存cx
    
    mov si, 0
    mov cx, 4
 s2:mov al, [bx + si + 3]
    and al, 11011111B
    mov [bx + si + 3], al
    inc si
    loop s2

    pop cx		;恢复cx
    add bx, 16		;换到下一行
    loop s1

 
    mov ax, 4c00H
    int 21H
code ends
end start