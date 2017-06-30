assume cs:code

code segment
start:	mov ax, 1
        sub ax, 1

	mov ax, 2
	sub ax, 1

	mov ax, 1
	and ax, 0

	mov ax, 1
	or ax, 0

	mov ax, 4c00H
	int 21H
code ends
end start