assume cs:code, ds:data 

data segment
    db 'Welcome to masm!'
data ends

code segment
start:	mov ax, data
	mov ds, ax

	mov ax, 0B800H
	mov es, ax

	mov bx, 0720H
	mov si, 0

	mov cx, 16
    s:	mov ax, [si]
	
	;�ڵ���ɫ
	mov ah, 2H		;��λ�ֽ��ڸߵ�ַ�����ַ�����ɫ����
	mov es:[bx], ax
	
	;�̵���ɫ
	mov ah, 24H
	mov es:[bx].0a0H, ax	;��һ�� a0 = 160���ֽ� = һ���ַ��� һ���ַ���һ���ֽ�

	;�׵���ɫ
	mov ah, 71H
	mov es:[bx].0a0H.0a0H, ax	;��һ��

	inc si			;��һ���ַ�
	add bx, 2		;��һ���Դ浥Ԫ
	loop s

	mov ax, 4c00H
	int 21H



code ends
end start