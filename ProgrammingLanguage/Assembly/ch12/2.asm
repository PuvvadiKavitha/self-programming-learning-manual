assume cs:code

code segment
start:
	mov ax, 1000H
	mov bh, 1H
	div bh


	mov ax, 4c00H
	int 21H
code ends
end start