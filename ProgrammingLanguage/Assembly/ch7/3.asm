assume cs:code, ds:data


data segment
    db 'BaSiC'
    db 'MinIx'
data ends


code segment
start:
    mov ax, data
    mov ds, ax
    
    mov bx, 0
    
    mov cx, 5
  s:mov al, [bx]
    and al, 11011111B
    mov [bx], al
    
    mov al, 5[bx]	;[bx + 5]或者5[bx]或者[bx].5
    or al, 00100000B
    mov [bx].5, al 
    
    inc bx
    loop s

    
    mov ax, 4c00H
    int 21H
code ends
end start