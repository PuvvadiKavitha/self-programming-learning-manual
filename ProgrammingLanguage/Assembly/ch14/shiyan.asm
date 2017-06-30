assume cs:code

code segment
time db 'yy/mm/dd hh:mm:ss', '$'
CMOS db 9, 8, 7, 4, 2, 0

start:	mov ax, cs
	mov ds, ax
	mov si, 0
	mov cx, 6	;6个数据
	mov bx, 0
s:	push cx
	mov al, CMOS[bx]

	out 70H, al
	in al, 71H

	mov ah, al
	mov cl, 4

	;因为传送到ds段是小端的，所以这里的高位应该在al中，后面转移的时候，就会相反变为3136 = 16年
	shr al, cl	;al表示十位
	and ah, 0FH	;ah表示个位
	;ax = 0601 

	
	add ax, 3030H	;ax = 3631
	;小端字节序，在内存中低地址存储在起始地址(低地址)
	mov cs:[si], ax	;ds:0 : 31 36 ... 16

	inc bx		;CMOS的数据位加1
	add si, 3	;显示下一个定址表的数据

	pop cx
	loop s

	
	mov ah, 2	;置光标
	mov bh, 0	;页数
	mov dh, 13	;行号
	mov dl, 32	;列号
	int 10H

	
	mov ah, 9	;显示字符串
	mov dx, 0	;ds:dx指向以$结尾的字符串
	int 21H

	mov ax, 4c00H
	int 21H
 
code ends
end start
