assume cs:code, ds:data


data segment
    db 'unix'
    db 'linux'
    db 'windows'
    db 'mac'
data ends

code segment
start:
    mov al, 'a'
    mov bl, 'b'

    mov ax, 4c00H
    int 21H		;int21HÓÃpÃüÁîÖ´ĞĞ
code ends
end start