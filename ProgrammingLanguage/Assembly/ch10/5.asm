assume cs:code, ds:data


data segment
    db 'conversation'
data ends


code segment
start:	mov ax, data
	mov ds, ax

	mov si, 0
	mov cx, 12
	call capital

	mov ax, 4c00H
	int 21H

capital:and byte ptr [si], 11011111B	;��ds:si��ָ���ֽڵ�Ԫ����ĸת��Ϊ��д
	inc si
	loop capital
	ret

code ends
end start







