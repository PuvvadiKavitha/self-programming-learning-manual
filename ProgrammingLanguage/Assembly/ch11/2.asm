assume cs:code

code segment
start:	mov al, 1
        add al, 10


	mov al, 1
	or al, 2

	sub al, al

	 

	mov ax, 4c00H
	int 21H
code ends
end start