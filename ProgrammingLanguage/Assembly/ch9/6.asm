assume cs:code, ds:data

data segment
    db 0, offset start		;����db 0, 0, 0
data ends
 

code segment
start:
    mov ax, data
    mov ds, ax
    mov bx, 0
    jmp word ptr [bx + 1]

    mov ax, 4c00H
    int 21H
code ends
end start