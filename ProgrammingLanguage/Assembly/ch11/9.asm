assume cs:code, ds:data

data segment
    db 'Welcome to masm!'
    db 16 dup (0)
data ends


code segment
start:	mov ax, data
	mov ds, ax
	mov si, 0
	
	mov es, ax
	mov di, 16

	mov cx, 16
        cld		;设置df = 0，正向传送
	rep movsb

	mov ax, 4c00H
	int 21H

code ends
end start