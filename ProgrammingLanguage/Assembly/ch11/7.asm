assume cs:code, ds:data

data segment
    db 8, 11, 8, 1, 8, 5, 63, 38
data ends


code segment
start:	mov ax, data
	mov ds, ax
	mov bx, 0
	mov ax, 0

	mov cx, 8
    s:	cmp byte ptr [bx], 8
        jna next		;统计大于8的数
	inc ax

 next:	inc bx
	loop s
	
	mov ax, 4c00H
	int 21H
code ends
end start