assume cs:code

code segment
start:	mov ax, 0B800H
	mov es, ax
	mov di, 160 * 12
	mov bx, offset s - offset se	;λ��
	mov cx, 80	;ѭ������
s:	mov byte ptr es:[di], '!'
	add di, 2
	int 7ch			;cx������0��ת�Ƶ�s���
se:	nop

	mov ax, 4c00H
	int 21H

code ends
end start