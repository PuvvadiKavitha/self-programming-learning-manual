assume cs:code

code segment

;安装程序
start:	mov ax, cs
	mov ds, ax
	mov si, offset do0	;设置ds:si指向源地址

	mov ax, 0
	mov es, ax
	mov di, 200H

	;设置传输的字节
	mov cx, offset do0E - offset do0S
	
	;设置正向传输
	cld
	;传输字节
	rep movsb

	;设置中断向量表
	mov ax, 0
	mov es, ax
	mov word ptr es:[0 * 4], 200H
	mov word ptr es:[0 * 4 + 2], 0

	mov ax, 4c00H
	int 21H


  do0:	jmp short do0S
	db 'divide error!'		;显示的字符串

;显示字符串的程序
 do0S:	mov ax, cs
	mov ds, ax
	mov si, 202H

	mov ax, 0B800H
	mov es, ax
	mov di, 12 * 160 + 36 * 2

	mov cx, 13
    s:	mov al, [si]
	mov es:[di], al
	inc si
	add di, 2
	loop s

	mov ax, 4c00H
	int 21H
do0E:	nop


code ends
end start






