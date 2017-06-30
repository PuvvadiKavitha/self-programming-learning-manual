assume cs:code


code segment
start:
   mov dx, 1
   mov ax, 86A1H
   mov bx, 100
   div bx

   mov ax, 4c00H
   int 21H
code ends
end start