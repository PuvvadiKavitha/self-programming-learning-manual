assume cs:code

code segment
start:	mov al, 8
	out 70H, al
	in al, 71H		;��ȡ71H�е�һ���ֽ�

	mov ah, al
	mov cl, 4
	shr ah, cl		;ȡ��71H�еĸ�4λ��ah��
	and al, 00001111B	;ȡ��71H�еĵ�4λ��al��

	add ah, 30H		;ahת��ΪASCII�ַ�
	add al, 30H		;alת��ΪASCII�ַ�

	;��ʾ71H�е�һ���ֽڵ�����ASCII�ַ�
	mov bx, 0b800H
	mov es, bx
	mov byte ptr es:[160 * 12 + 40 * 2], ah
	mov byte ptr es:[160 * 12 + 40 * 2 + 2], al

	mov ax, 4c00H
	int 21H


code ends
end start