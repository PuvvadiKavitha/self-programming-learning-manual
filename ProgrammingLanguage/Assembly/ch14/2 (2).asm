assume cs:code, ds:data
data segment
    db 'Welcome to masm!', 0
data ends



code segment
start:
	mov dh, 10	;�к�
	mov dl, 10	;�к�
	mov cl, 2	;��ɫ

	;Դ��ַds:si
	mov ax, data
	mov ds, ax
	mov si, 0
	
	;7ch-show_str
	int 7cH

	mov ax, 4c00H
	int 21H

code ends
end start