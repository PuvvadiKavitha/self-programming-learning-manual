assume cs:code, ds:data

data segment
    db 'conversation', 0
data ends

code segment
start:	mov ax, data
	mov ds, ax
	mov si, 0

	call fun

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