assume cs:code

code segment
start:	sub al, al
	mov al, 1
	push ax
	pop ax
	add al, bl
	add al, 10
	mul al

	mov ax, 4c00H
	int 21H
code ends
end start