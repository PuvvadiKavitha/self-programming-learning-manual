assume cs:code

code segment
start:

    mov ax, 0
    mov bx, 0
    jmp ax 

    mov ax, 4c00H
    int 21H
code ends
end start