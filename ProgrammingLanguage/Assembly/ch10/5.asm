assume cs:code, ds:data


data segment
    db 'conversation'
data ends


code segment
start:	mov ax, data
	mov ds, ax

	mov si, 0
	mov cx, 12
	call capital

	mov ax, 4c00H
	int 21H

capital:and byte ptr [si], 11011111B	;将ds:si所指向字节单元的字母转换为大写
	inc si
	loop capital
	ret

code ends
end start







