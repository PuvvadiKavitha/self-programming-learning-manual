assume cs:code, ss:stack

stack segment
   db 128 dup (0)
stack ends

code segment
start:	mov ax, stack
	mov ss, ax
	mov sp, 128

	push cs
	pop ds

	;(1)���ư�װ�������
	mov ax, 0
	mov es, ax
	mov si, offset int9
	mov di, 204H
	mov cx, offset int9end - offset int9
	cld 
	rep movsb		

	;(2)����ϵͳ��int9�жϵ�ַ
	push es:[9 * 4]
	pop es:[200H]
	push es:[9 * 4 + 2]
	pop es:[202H]
	
	;(3)�����µ�int9�жϵ�ַ
	cli				;��ֹCPU�ж�
	mov word ptr es:[9 * 4], 204H
	mov word ptr es:[9 * 4 + 2], 0
	sti

	mov ax, 4c00H
	int 21H

;�Զ���int9�ж�����
int9:	push ax
	push bx
	push cx
	push es

	in al, 60H		;��ȡ60H�˿ڵļ��̵�����

	;ģ��int9���жϵ���
	pushf
	call dword ptr cs:[200H]

	cmp al, 9eH
	jne int9ret		;����A�Ķ���( = 1EH + 80H = 9EH)����ʾ����Ļ��A

	mov ax, 0B800H
	mov es, ax
	mov bx, 0
	mov cx, 2000		;һҳ��2000���ֵ�Ԫ = 4000���ֽ�
s:	mov byte ptr es:[bx], 41H	;ż��ַ����ַ�, ����ȫ�����A, ���ַ����ַ���ɫ����
	add bx, 2			;ָ����һ��ż��ַ
	loop s

int9ret:
	pop es
	pop cx
	pop bx
	pop ax
	iret

int9end:nop

code ends
end start