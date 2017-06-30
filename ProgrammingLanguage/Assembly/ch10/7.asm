assume cs:code, ds:data


data segment
    db 'word', 0
    db 'unix', 0
    db 'wind', 0
    db 'good', 0
data ends

code segment
start:	mov ax, data
	mov ds, ax
	mov bx, 0

	mov cx, 4
    s:  mov si, bx
	call fun
	add bx, 5
	loop s

	mov ax, 4c00H
	int 21H

;说明:将一个全是字母以0结尾的字符串转换为大写
;参数:ds:si指向字符串首地址
;结果:没有返回值
  fun:	mov cl, [si]		
	mov ch, 0
	jcxz ok			;如果cx = 0， 结束，否则，处理为大写
	and cl, 11011111B	;处理为大写
	mov [si], cl		;ds:si指向下一个单元
	inc si
	jmp short fun
   ok:	ret
code ends
end start