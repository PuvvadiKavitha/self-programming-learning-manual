assume cs:code


code segment
	;��CMOS RAM��2�ŵ�Ԫд��0
start:	mov al, 2
	out 70H, al
	mov al, 0
	out 71H, al

	mov ax, 4c00H
	int 21H

code ends
end start