assume cs:code

code segment
start:	mov ax, 0B800H
	mov es, ax
	mov di, 160 * 12
	mov bx, offset s - offset se	;位移
	mov cx, 80	;循环次数
s:	mov byte ptr es:[di], '!'
	add di, 2
	int 7ch			;cx不等于0，转移到s标号
se:	nop

	mov ax, 4c00H
	int 21H

code ends
end start