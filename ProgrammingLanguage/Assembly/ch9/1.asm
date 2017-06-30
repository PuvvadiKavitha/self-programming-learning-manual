assume cs:code 

code segment
start:
    mov ax, bx
    mov si, offset start
    mov di, offset s
    mov ax, cs:[si]
    mov cs:[di], ax

  s:nop
    nop



code ends
end start