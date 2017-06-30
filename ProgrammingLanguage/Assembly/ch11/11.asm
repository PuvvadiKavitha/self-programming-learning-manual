assume cs:code

code segment
start:	mov ax, 0
	push ax
	popf			;弹出到标志寄存器中
	mov ax, 0fff0H
	add ax, 0010H
	pushf			;标志寄存器入栈
	pop ax
	and al, 11000101B	;and可以保持某些位不变和将某些位清0
	and ah, 00001000B

	mov ax, 4c00H
	int 21H
code ends
end start