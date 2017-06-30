assume cs:code

code segment
	mov ax, 4c00H
	int 21H

start:	mov ax, 0

    s:	nop		;将s2段的位移复制到这里之后，jmp的位移仍然为-10，刚好定位到上面的结束代码
        nop

	mov di, offset s
	mov si, offset s2
	mov ax, cs:[si]
	mov cs:[di], ax

   s0:  jmp short s

   s1:  mov ax, 0
	int 21H
	mov ax, 0

   s2:  jmp short s1		;与s1标号的位移：s1地址减去jmp后面一条指令的地址 = -10
        nop

code ends
end start