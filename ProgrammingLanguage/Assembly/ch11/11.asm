assume cs:code

code segment
start:	mov ax, 0
	push ax
	popf			;��������־�Ĵ�����
	mov ax, 0fff0H
	add ax, 0010H
	pushf			;��־�Ĵ�����ջ
	pop ax
	and al, 11000101B	;and���Ա���ĳЩλ����ͽ�ĳЩλ��0
	and ah, 00001000B

	mov ax, 4c00H
	int 21H
code ends
end start