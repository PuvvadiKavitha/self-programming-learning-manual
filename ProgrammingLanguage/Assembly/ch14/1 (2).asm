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
	
	;����
	rep movsb

	mov ax, 0
	mov es, ax
	;�����ж�������    0:200H
	mov word ptr es:[7cH * 4], 200H		;ip
	mov word ptr es:[7cH * 4 + 2], 0	;cs

	mov ax, 4c00H
	int 21H



;���ƣ�show_str 

;���ܣ���ָ����λ�ã���ָ������ɫ����ʾһ����0�������ַ����� 

;������(dh)=�к�(ȡֵ��Χ0~24)�� 

;      (dl)=�к�(ȡֵ��Χ0~79)�� 

;      (cl)=��ɫ�� 

;      ds:siָ���ַ������׵�ַ�� 

;���أ��ޡ� 

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

        add bx,ax        ;mov bx,(160*dh+dl*2)����es:bxָ���Դ��׵�ַ 

        mov al,cl        ;����ɫcl��ֵal 

        mov cl,0 

show0:  mov ch,[si] 

        jcxz show1       ;(ds:si)=0ʱ��ת��show1ִ��         

        mov es:[bx],ch 

        mov es:[bx].1,al 

        inc si           ;ds:siָ����һ���ַ���ַ 

        add bx,2         ;es:bxָ����һ���Դ��ַ 

        jmp show0 

show1:  pop si 

        pop es 

        pop bx 

        pop ax 

        iret  
show_strend:nop 


code ends
end start