assume cs:code


code segment
start:	mov ax, cs
	mov ds, ax
	mov si, offset do0		;中断程序地址

	mov ax, 0
	mov es, ax
	mov di, 200H			;中断向量地址

	mov cx, offset do0end - offset do0	;中断程序长度
	cld				;正向传输
	rep movsb			;设置传输方向为正

	mov ax, 4c00H
	int 21H

 do0:	jmp short do0start
	db 'overflow!'

do0start:
	mov ax, cs
	mov ds, ax
	mov si, 202H			;ds:di指向字符串

	mov ax, 0b800H
	mov es, ax
	mov di, 12 * 160 + 36 * 2	;设置es:di指向显存中的中间位置

	mov cx, 9			;字符串长度
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
