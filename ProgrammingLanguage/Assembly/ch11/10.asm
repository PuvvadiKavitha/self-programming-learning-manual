assume cs:code, es:data

data segment 
    db 16 dup (0)
data ends


code segment
start:	mov ax, 0f000H
	mov ds, ax
	mov si, 0ffffH
	
	mov ax, data
	mov es, ax
	mov di, 15

	mov cx, 16
        std		;设置df = 1，反向传送
	rep movsb

	mov ax, 4c00H
	int 21H

code ends
end start