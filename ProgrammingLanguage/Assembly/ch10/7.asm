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

;˵��:��һ��ȫ����ĸ��0��β���ַ���ת��Ϊ��д
;����:ds:siָ���ַ����׵�ַ
;���:û�з���ֵ
  fun:	mov cl, [si]		
	mov ch, 0
	jcxz ok			;���cx = 0�� ���������򣬴���Ϊ��д
	and cl, 11011111B	;����Ϊ��д
	mov [si], cl		;ds:siָ����һ����Ԫ
	inc si
	jmp short fun
   ok:	ret
code ends
end start