assume cs:code

code segment
time db 'yy/mm/dd hh:mm:ss', '$'
CMOS db 9, 8, 7, 4, 2, 0

start:	mov ax, cs
	mov ds, ax
	mov si, 0
	mov cx, 6	;6������
	mov bx, 0
s:	push cx
	mov al, CMOS[bx]

	out 70H, al
	in al, 71H

	mov ah, al
	mov cl, 4

	;��Ϊ���͵�ds����С�˵ģ���������ĸ�λӦ����al�У�����ת�Ƶ�ʱ�򣬾ͻ��෴��Ϊ3136 = 16��
	shr al, cl	;al��ʾʮλ
	and ah, 0FH	;ah��ʾ��λ
	;ax = 0601 

	
	add ax, 3030H	;ax = 3631
	;С���ֽ������ڴ��е͵�ַ�洢����ʼ��ַ(�͵�ַ)
	mov cs:[si], ax	;ds:0 : 31 36 ... 16

	inc bx		;CMOS������λ��1
	add si, 3	;��ʾ��һ����ַ�������

	pop cx
	loop s

	
	mov ah, 2	;�ù��
	mov bh, 0	;ҳ��
	mov dh, 13	;�к�
	mov dl, 32	;�к�
	int 10H

	
	mov ah, 9	;��ʾ�ַ���
	mov dx, 0	;ds:dxָ����$��β���ַ���
	int 21H

	mov ax, 4c00H
	int 21H
 
code ends
end start
