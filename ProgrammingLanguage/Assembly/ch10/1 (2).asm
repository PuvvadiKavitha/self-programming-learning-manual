assume cs:code, ds:data

data segment
    db 'Welcome to masm!', 0
data ends


code segment
start:	mov dh, 8		;8��
	mov dl, 3		;3��
	mov cl, 2		;�ڵ���ɫ

	mov ax, data
	mov ds, ax
	mov si, 0
	call show_str

	mov ax, 4c00H
	int 21H 


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