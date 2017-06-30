assume cs:code


code segment
start:
    mov ax, 1001
    mov bl, 100
    div bl


    mov ax, 4c00H
    int 21H
code ends
end start