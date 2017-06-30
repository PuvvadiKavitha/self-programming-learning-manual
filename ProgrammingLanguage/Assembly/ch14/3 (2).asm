assume cs:code


code segment
start:	mov ax, cs
	mov ds, ax
	mov si, offset lp
	
	mov ax, 0
	mov es, ax
	mov di, 200H

	mov cx, offset lpend - offset lp
	cld 
	rep movsb

	mov ax, 0
	mov es, ax
	mov word ptr es:[7CH * 4], 200H
	mov word ptr es:[7CH * 4 + 2], 0

	mov ax, 4c00H
	int 21H

;模仿loop的功能
lp:	push bp
	mov bp, sp
	dec cx
	jcxz lpret
	add [bp + 2], bx	;ip + bx
lpret:	pop bp
	iret
	mov ax, 4c00H
	int 21H

lpend:	nop

code ends
end start