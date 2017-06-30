assume cs:code

code segment
start:	mov al, 98H
	add al, al

	add al, al

	mov al, 97H
	sub al, 98H
	sub al, al

	mov ax, 4c00H
	int 21H
code ends
end start