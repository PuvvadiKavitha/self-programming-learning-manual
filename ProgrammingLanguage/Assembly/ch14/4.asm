assume cs:code

code segment
start:	mov al, 8
	out 70H, al
	in al, 71H		;读取71H中的一个字节

	mov ah, al
	mov cl, 4
	shr ah, cl		;取出71H中的高4位到ah中
	and al, 00001111B	;取出71H中的低4位到al中

	add ah, 30H		;ah转换为ASCII字符
	add al, 30H		;al转换为ASCII字符

	;显示71H中的一个字节的两个ASCII字符
	mov bx, 0b800H
	mov es, bx
	mov byte ptr es:[160 * 12 + 40 * 2], ah
	mov byte ptr es:[160 * 12 + 40 * 2 + 2], al

	mov ax, 4c00H
	int 21H


code ends
end start