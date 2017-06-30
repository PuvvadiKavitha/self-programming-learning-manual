assume cs:code, ds:data, ss:stack


stack segment
    db 128 dup (0)
stack ends


data segment
    dw 0, 0
data ends


code segment
start:	mov ax, stack
	mov ss, ax
	mov sp, 128

	mov ax, data
	mov ds, ax

	mov ax, 0
	mov es, ax

	;����ԭ����int9�жϵ�ַ
	push es:[9 * 4]
	pop ds:[0]
	push es:[9 * 4 + 2]
	pop ds:[2]

	;�����µ�int9�жϵ�ַ
	cli
	mov word ptr es:[9 * 4], offset int9
	mov es:[9 * 4 + 2], cs
	sti

	;��ʾ�ַ�����Ļ��
	mov ax, 0b800H
	mov es, ax
	mov ah, 'a'
s:      mov es:[160 * 12 + 40 * 2], ah
        call delay		;sleep
	inc ah
	cmp ah, 'z'
	jna s

	mov ax, 0
	mov es, ax

	;�ָ�int9�жϵĵ�ַ
	push ds:[0]
	pop es:[9 * 4]
	push ds:[2]
	pop es:[9 * 4 + 2]

	mov ax, 4c00H
	int 21H

	;sleep����
delay:  push ax
        push dx

	mov dx, 10h
	mov ax, 0
s1:     sub ax, 1
        sbb dx, 0
	cmp ax, 0
	jne s1
	cmp dx, 0
	jne s1

	pop dx
	pop ax
	ret
    
	;�µ�int9�ж�����
 int9:	push ax
	push bx
	push es

	in al, 60H

	pushf
	call dword ptr ds:[0]		;ģ��int9�ж�����

	cmp al, 1			;����Ƿ���Esc��
	jne int9ret

	mov ax, 0b800H
	mov es, ax
	inc byte ptr es:[160 * 12 + 40 * 2 + 1]	;���Լ�1���ı���ɫ

int9ret:pop es
	pop bx
	pop ax
	iret


code ends
end start