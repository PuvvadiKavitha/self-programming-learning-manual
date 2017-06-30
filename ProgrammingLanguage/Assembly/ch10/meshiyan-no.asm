assume cs:code, ds:data, es:table

data segment
    ;年份
    db '1975','1976','1977','1978','1979','1980','1981','1982','1983'
    db '1984','1985','1986','1987','1988','1989','1990','1991','1992'
    db '1993','1994','1995' 
    
    ;收入
    dd 16,22,382,1356,2390,8000,16000,24486,50065,97479,140417,197514
    dd 345980,590827,803530,1183000,1843000,2759000,3753000,4649000,5937000 
   
    ;人数
    dw 3,7,9,13,28,38,130,220,476,778,1001,1442,2258,2793,4037,5635,8226
    dw 11542,14430,45257,17800 

    ;人均收入
    dw 5,3,42,104,85,210,123,111,105,125,140,136,153,211,199,209,224,239
    dw 260,304,333

data ends

table segment
    db 32 dup ('year summ ne ?? ')
table ends


code segment
start:	mov ax, table
	mov ds, ax

	mov ax, data
	mov es, ax

	mov bx, 0
	mov si, 0
	mov di, 0

	mov cx, 21
	mov dh, 2
	mov dl, 30

g:	push cx
	push dx
	;年份
	mov ax, es:[bx]
	mov [si], ax
	mov ax, es:[bx + 2]
	mov [si + 2], ax

	;收入
	add si, 6
	mov ax, es:[bx + 84]
	mov dx, es:[bx + 86]
	;转换成字符串
	call dtoc2

	;人员数
	add si, 10
	mov ax, es:[di + 168]
	mov dx, 0
	call dtoc2

	;人均收入
	add si, 6
	mov ax, es:[di + 210]
	mov dx, 0
	call dtoc2

	mov si, 0	;ds:si指向显存首地址
b:	mov cx, 29

c:	push cx
	mov cl, [si]
	jcxz f

d:	inc si
	pop cx
	loop c

	inc si
	mov al, 0
	mov [si], al	;结尾0
	mov si, 0	;ds:si指向显存首地址来show_str
	pop dx
	mov cl, 2	;颜色为绿色
	call show_str

	add bx, 4	;dword指向下一个单元	
	add di, 2	;word指向下一个单元
	add dh, 1	;显存下一行
	pop cx
	loop g

	mov ax, 4c00H
	int 21H



f:	mov al, 20H
	mov [si], al	;数据0改为空格
	jmp d


;名称：dtoc2
;功能：将dword型数据转变为表示十进制的字符串，字符串以0为结尾符。
;参数：(ax)=dword型数据的低16位；
;      (dx)=dword型数据的高16位；
;      ds:si指向字符串首地址。
;返回：无
dtoc2:	push ax
	push bx 
	push cx
	push dx
	push si
	push di

	mov di, 0
d20:	mov cx, 10
	call divdw
	add cx, 30H
	push cx
	inc di
	mov cx, ax
	jcxz d21
	jmp d20
d21:	mov cx, dx
	jcxz d22
	jmp d20
d22:	mov cx, di
d23:	pop ax
	mov [si], al
	inc si
	loop d23
	mov al, 0
	mov [si], al

	pop di
	pop si
	pop dx
	pop cx
	pop bx
	pop ax
	ret

;名称：show_str
;功能：在指定的位置，用指定的颜色，显示一个用0结束的字符串。
;参数：(dh)=行号(取值范围0~24)；
;      (dl)=列号(取值范围0~79)；
;      (cl)=颜色；
;      ds:si指向字符串的首地址。
;返回：无
show_str:
	;寄存器入栈
	push ax
	push es
	push si
	push bx

	mov ax, 0B800H
	mov es, ax
	mov ax, 160

	mul dh		;确定行
	mov bx, ax	;将行数放在bx中

	mov ax, 2	;显存字单元每次加2
	mul dl		;确定列
	add bx, ax	;将最后的显存地址加起来放在bx中

	mov al, cl	;颜色属性放在al中
	mov cl, 0

show0:	mov ch, [si]
	jcxz show1		;0直接结束
	mov es:[bx], ch		;显存地址在bx中
	mov es:[bx + 1], al	;颜色属性在al中
	inc si
	add bx, 2		;字单元步长为2
	jmp show0

	;寄存器出栈
show1:	pop bx
	pop si
	pop es
	pop ax
	ret 
 
divdw:	push si
	push bx
	push ax

	mov ax, dx	;先计算高位
	mov dx, 0
	div cx		;高位/cx的余数在dx中

	mov si, ax	;高位/cx的商在si中
	
	pop ax		;弹出低16位的ax
	div cx		;低16位/cx, 被除数：dx中是高位除法的余数, ax是低16位

	mov cx, dx	;余数在dx中
	mov dx, si	;高位的商转移到dx中

	pop ax
	pop bx
	pop si
	ret	 
code ends
end start