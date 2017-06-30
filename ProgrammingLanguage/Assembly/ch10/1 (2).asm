assume cs:code, ds:data

data segment
    db 'Welcome to masm!', 0
data ends


code segment
start:	mov dh, 8		;8行
	mov dl, 3		;3列
	mov cl, 2		;黑底绿色

	mov ax, data
	mov ds, ax
	mov si, 0
	call show_str

	mov ax, 4c00H
	int 21H 


show_str:
	;寄存器入栈
	push ax
	push es
	push si
	push bx

	mov ax, 0B800H
	mov es, ax
	mov ax, 160

	mul dh		;确定行
	mov bx, ax	;将行数放在bx中

	mov ax, 2	;显存字单元每次加2
	mul dl		;确定列
	add bx, ax	;将最后的显存地址加起来放在bx中

	mov al, cl	;颜色属性放在al中
	mov cl, 0

show0:	mov ch, [si]
	jcxz show1		;0直接结束
	mov es:[bx], ch		;显存地址在bx中
	mov es:[bx + 1], al	;颜色属性在al中
	inc si
	add bx, 2		;字单元步长为2
	jmp show0

	;寄存器出栈
show1:	pop bx
	pop si
	pop es
	pop ax
	ret 
code ends
end start