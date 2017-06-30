assume cs:code

code segment
;º∆À„(ax) = (ax) * 10
;(ax) * 10 = (ax) * 2 + (ax) * 8

start:	mov ax, 2

	mov bx, ax
	shl ax, 1	;2 * 2

	mov cl, 3
	shl bx, cl	;2 * 2 * 2
	
	add ax, bx

	mov ax, 4c00H
	int 21H
code ends
end start