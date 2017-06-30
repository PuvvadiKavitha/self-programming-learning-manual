assume cs:code

code segment
start:
    mov al, 100
    mov bl, 10
    mul bl

    mov ax, 4c00H
    int 21H

code ends
end start