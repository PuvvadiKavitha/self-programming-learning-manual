assume cs:code, ss:stack

stack segment
    db 8 dup (0)
    db 8 dup (0)
stack ends


code segment
start:	mov ax, stack
	mov ss, ax
	mov sp, 16

	mov ax, 1000
	call s		;����һ��ָ���ipѹ��ջ��

	mov ax, 4c00H
	int 21H

    s:	add ax, ax
        ret		;��ip����

code ends
end start