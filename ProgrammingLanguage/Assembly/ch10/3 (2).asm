assume cs:code, ds:data

data segment
    db 10 dup (0)
data ends
 

code segment
start:	mov ax, 12666
	mov bx, data
	mov ds, bx

	mov si, 0
	call dtoc

	mov dh, 8
	mov dl, 3
	mov cl, 2
	call show_str

	mov ax, 4c00H
	int 21H
dtoc:	push ax
	push bx
	push cx
	push dx
	push si
	push di 

	mov di, 0	;��¼�ַ���Ŀ
d10:	mov dx, 0
	mov bx, 10	;����Ϊ10
	div bx
	add dx, 30H	;ת��Ϊ�ַ�
	push dx		;������ջ
	inc di		;��¼�ַ���
	mov cx, ax	;��ת�Ƶ�cx��
	jcxz d11	;�ж����Ƿ�Ϊ0��Ϊ0��ת��d11��
	jmp d10

d11:	mov cx, di	;�ַ�������cx�У�ȷ��ѭ������ 
d12:	pop dx
	mov [si], dl	;���ַ�����ת�Ƶ�ds:si��
	inc si
	loop d12

	;��0��β�ַ���
	mov dl, 0
	mov [di], dl

	pop di
	pop si
	pop dx
	pop cx
	pop bx
	pop ax
	ret

show_str:
	;�Ĵ�����ջ
	push ax
	push es
	push si
	push bx

	mov ax, 0B800H
	mov es, ax
	mov ax, 160

	mul dh		;ȷ����
	mov bx, ax	;����������bx��

	mov ax, 2	;�Դ��ֵ�Ԫÿ�μ�2
	mul dl		;ȷ����
	add bx, ax	;�������Դ��ַ����������bx��

	mov al, cl	;��ɫ���Է���al��
	mov cl, 0

show0:	mov ch, [si]
	jcxz show1		;0ֱ�ӽ���
	mov es:[bx], ch		;�Դ��ַ��bx��
	mov es:[bx + 1], al	;��ɫ������al��
	inc si
	add bx, 2		;�ֵ�Ԫ����Ϊ2
	jmp show0

	;�Ĵ�����ջ
show1:	pop bx
	pop si
	pop es
	pop ax
	ret 

code ends
end start







