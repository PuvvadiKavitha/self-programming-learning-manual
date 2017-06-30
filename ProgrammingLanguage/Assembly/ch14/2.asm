assume cs:code


code segment
	;向CMOS RAM的2号单元写入0
start:	mov al, 2
	out 70H, al
	mov al, 0
	out 71H, al

	mov ax, 4c00H
	int 21H

code ends
end start