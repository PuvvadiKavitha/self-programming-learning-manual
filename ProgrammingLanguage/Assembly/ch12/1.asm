assume cs:code


code segment
start:	mov ax, cs
	mov ds, ax
	mov si, offset do0		;�жϳ����ַ

	mov ax, 0
	mov es, ax
	mov di, 200H			;�ж�������ַ

	mov cx, offset do0end - offset do0	;�жϳ��򳤶�
	cld				;������
	rep movsb			;���ô��䷽��Ϊ��

	mov ax, 4c00H
	int 21H

 do0:	jmp short do0start
	db 'overflow!'

do0start:
	mov ax, cs
	mov ds, ax
	mov si, 202H			;ds:diָ���ַ���

	mov ax, 0b800H
	mov es, ax
	mov di, 12 * 160 + 36 * 2	;����es:diָ���Դ��е��м�λ��

	mov cx, 9			;�ַ�������
   s:	mov al, [si]
	mov es:[di], al
	inc si
	add di, 2
	loop s

	mov ax, 4c00H
	int 21H
do0end:	nop
code ends
end start
