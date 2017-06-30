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

	;(1)复制安装程序代码
	mov ax, 0
	mov es, ax
	mov si, offset int9
	mov di, 204H
	mov cx, offset int9end - offset int9
	cld 
	rep movsb		

	;(2)保存系统的int9中断地址
	push es:[9 * 4]
	pop es:[200H]
	push es:[9 * 4 + 2]
	pop es:[202H]
	
	;(3)设置新的int9中断地址
	cli				;禁止CPU中断
	mov word ptr es:[9 * 4], 204H
	mov word ptr es:[9 * 4 + 2], 0
	sti

	mov ax, 4c00H
	int 21H

;自定义int9中断例程
int9:	push ax
	push bx
	push cx
	push es

	in al, 60H		;获取60H端口的键盘的内容

	;模仿int9的中断调用
	pushf
	call dword ptr cs:[200H]

	cmp al, 9eH
	jne int9ret		;等于A的断码( = 1EH + 80H = 9EH)就显示满屏幕的A

	mov ax, 0B800H
	mov es, ax
	mov bx, 0
	mov cx, 2000		;一页有2000个字单元 = 4000个字节
s:	mov byte ptr es:[bx], 41H	;偶地址存放字符, 这里全部存放A, 奇地址存放字符颜色属性
	add bx, 2			;指向下一个偶地址
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