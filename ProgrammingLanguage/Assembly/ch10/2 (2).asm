assume cs:code

code segment
start:	mov ax, 4240H
	mov dx, 000FH
	mov cx, 0AH
	call divdw


	mov ax, 4c00H
	int 21H

;公式x/n=int(h/n)*65536+[rem(h/n)*65536+l]/n解析： 
;把一个会溢出的除法 变成几个除法来做！ 
;如果高位除法有商，那么商就是结果的高位值，如果会有余数，那么余数自然不能丢弃
;余数就作为低位除法的dx(也就是高位的被除数，因为他是从高位除法中余下的）  
;做低位除法的时候，就拿余下的dx+低位数的ax除以除数，会得到一个低位的商和余数  
;高位的商+低位数的商+余数就是结果


divdw:	push si
	push bx
	push ax

	mov ax, dx	;先计算高位
	mov dx, 0
	div cx		;高位/cx的余数在dx中

	mov si, ax	;高位/cx的商在si中
	
	pop ax		;弹出低16位的ax
	div cx		;低16位/cx, 被除数：dx中是高位除法的余数, ax是低16位

	mov cx, dx	;余数在dx中
	mov dx, si	;高位的商转移到dx中

	pop ax
	pop bx
	pop si
	ret

code ends
end start