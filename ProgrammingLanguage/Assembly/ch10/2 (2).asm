assume cs:code

code segment
start:	mov ax, 4240H
	mov dx, 000FH
	mov cx, 0AH
	call divdw


	mov ax, 4c00H
	int 21H

;��ʽx/n=int(h/n)*65536+[rem(h/n)*65536+l]/n������ 
;��һ��������ĳ��� ��ɼ������������� 
;�����λ�������̣���ô�̾��ǽ���ĸ�λֵ�����������������ô������Ȼ���ܶ���
;��������Ϊ��λ������dx(Ҳ���Ǹ�λ�ı���������Ϊ���ǴӸ�λ���������µģ�  
;����λ������ʱ�򣬾������µ�dx+��λ����ax���Գ�������õ�һ����λ���̺�����  
;��λ����+��λ������+�������ǽ��


divdw:	push si
	push bx
	push ax

	mov ax, dx	;�ȼ����λ
	mov dx, 0
	div cx		;��λ/cx��������dx��

	mov si, ax	;��λ/cx������si��
	
	pop ax		;������16λ��ax
	div cx		;��16λ/cx, ��������dx���Ǹ�λ����������, ax�ǵ�16λ

	mov cx, dx	;������dx��
	mov dx, si	;��λ����ת�Ƶ�dx��

	pop ax
	pop bx
	pop si
	ret

code ends
end start