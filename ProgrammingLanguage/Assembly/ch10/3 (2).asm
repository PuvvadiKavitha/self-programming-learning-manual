assume cs:code, ds:data

data segment
    db 10 dup (0)
data ends
 

code segment
start:	mov ax, 12666
	mov bx, data
	mov ds, bx

	mov si, 0
	call dtoc

	mov dh, 8
	mov dl, 3
	mov cl, 2
	call show_str

	mov ax, 4c00H
	int 21H
dtoc:	push ax
	push bx
	push cx
	push dx
	push si
	push di 

	mov di, 0	;记录字符数目
d10:	mov dx, 0
	mov bx, 10	;除数为10
	div bx
	add dx, 30H	;转换为字符
	push dx		;余数入栈
	inc di		;记录字符数
	mov cx, ax	;商转移到cx中
	jcxz d11	;判断商是否为0，为0跳转到d11段
	jmp d10

d11:	mov cx, di	;字符数放在cx中，确定循环次数 
d12:	pop dx
	mov [si], dl	;将字符依次转移到ds:si中
	inc si
	loop d12

	;以0结尾字符串
	mov dl, 0
	mov [di], dl

	pop di
	pop si
	pop dx
	pop cx
	pop bx
	pop ax
	ret

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







