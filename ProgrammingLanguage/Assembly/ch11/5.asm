assume cs:code

code segment
start:	

;说明:计算两个128数的加法或者减法
;参数:ds:[si]存储第一个数据的内存首地址,ds:[di]存储第二个数据内存首地址
;返回值:将计算后的数据存储在第一个数据的地址处
add128:	push ax
	push cx
	push si
	push di

	sub ax, ax		;将CF设置为0

	mov cx, 8
     s: mov ax, [si]
	adc ax, [di]		;从低位开始依次进位计算,减法换成sbb指令即可
	mov [si], ax

	inc si			;inc指令不可以用add代替，因为add会影响CF标志位
	inc si			;inc和loop不影响CF标志位
	inc di
	inc di
	loop s

	pop di
	pop si
	pop cx
	pop ax
	ret
code ends
end start



