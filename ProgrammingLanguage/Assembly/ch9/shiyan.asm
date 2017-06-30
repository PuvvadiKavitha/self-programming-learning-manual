assume cs:code, ds:data 

data segment
    db 'Welcome to masm!'
data ends

code segment
start:	mov ax, data
	mov ds, ax

	mov ax, 0B800H
	mov es, ax

	mov bx, 0720H
	mov si, 0

	mov cx, 16
    s:	mov ax, [si]
	
	;黑底绿色
	mov ah, 2H		;高位字节在高地址，奇地址存放颜色属性
	mov es:[bx], ax
	
	;绿底蓝色
	mov ah, 24H
	mov es:[bx].0a0H, ax	;下一行 a0 = 160个字节 = 一行字符数 一个字符是一个字节

	;白底蓝色
	mov ah, 71H
	mov es:[bx].0a0H.0a0H, ax	;下一行

	inc si			;下一个字符
	add bx, 2		;下一个显存单元
	loop s

	mov ax, 4c00H
	int 21H



code ends
end start