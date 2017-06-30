assume cs:code, ss:stack

stack segment
    db 128 dup(0)
stack ends


code segment
start:	mov ax, stack
	mov ss, ax
	mov sp, 128

	push cs
	pop ds

	mov ax, 0
	mov es, ax
	;��װ�ж�����
	mov si, offset int9
	mov di, 204H
	mov cx, offset int9end - offset int9
	cld
	rep movsb

	;����ԭ����int9��ַ
	push es:[9 * 4]
	pop es:[200H]
	push es:[9 * 4 + 2]
	pop es:[202H]

	;�����µ�int9��ַ
	cli
	mov word ptr es:[9 * 4], 204H
	mov word ptr es:[9 * 4 + 2], 0
	sti

	mov ax, 4c00H
	int 21H


int9:	push ax
	push bx
	push cx
	push es

	in al, 60H

	;�൱��intָ��ִ�еĲ���
	pushf			;��־�Ĵ�����ջ
	call dword ptr cs:[200H];�����µ��ж����̵�cs:ip

	cmp al, 3bH		;����Ƿ�ΪF1��
	jne int9ret

	mov ax, 0b800H
	mov es, ax
	mov bx, 1
	mov cx, 2000
  s:	inc byte ptr es:[bx]
	add bx, 2
	loop s

int9ret:pop es
	pop cx
	pop bx
	pop ax
	iret

int9end:nop

code ends
end start