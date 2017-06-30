assume cs:code
code segment
start:
	mov ax, cs
	mov ds, ax
	mov si, offset show_str

	mov ax, 0
	mov es, ax
	mov di, 200H
	mov cx, offset show_strend - offset show_str

	;clear df flage bit
	cld
	
	;复制
	rep movsb

	mov ax, 0
	mov es, ax
	;设置中断向量表    0:200H
	mov word ptr es:[7cH * 4], 200H		;ip
	mov word ptr es:[7cH * 4 + 2], 0	;cs

	mov ax, 4c00H
	int 21H



;名称：show_str 

;功能：在指定的位置，用指定的颜色，显示一个用0结束的字符串。 

;参数：(dh)=行号(取值范围0~24)； 

;      (dl)=列号(取值范围0~79)； 

;      (cl)=颜色； 

;      ds:si指向字符串的首地址。 

;返回：无。 

show_str:
	push ax 

        push bx 

        push es 

        push si 

        mov ax,0b800h 

        mov es,ax 

        mov ax,160 

        mul dh 

        mov bx,ax        ;bx=160*dh 

        mov ax,2 

        mul dl           ;ax=dl*2 

        add bx,ax        ;mov bx,(160*dh+dl*2)设置es:bx指向显存首地址 

        mov al,cl        ;把颜色cl赋值al 

        mov cl,0 

show0:  mov ch,[si] 

        jcxz show1       ;(ds:si)=0时，转到show1执行         

        mov es:[bx],ch 

        mov es:[bx].1,al 

        inc si           ;ds:si指向下一个字符地址 

        add bx,2         ;es:bx指向下一个显存地址 

        jmp show0 

show1:  pop si 

        pop es 

        pop bx 

        pop ax 

        iret  
show_strend:nop 


code ends
end start