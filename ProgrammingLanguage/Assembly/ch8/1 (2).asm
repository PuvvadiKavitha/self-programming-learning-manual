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
data ends

table segment
    db 21 dup ('year summ ne ?? ')
table ends


code segment
start:	mov ax, data
	mov ds, ax

	mov ax, table
	mov es, ax

	mov bx, 0
	mov si, 0
	mov di, 0

	mov cx, 21
   s:	mov ax, [bx]			;年份的第一个字节
	mov es:[si], ax
	mov ax, [bx].2			;年份的第二个字节
	mov es:[si].2, ax

	mov ax, [bx].84			;收入 = 4B  在DX和AX中存放，用来div
	mov es:[si].5, ax
	mov dx, [bx].86
	mov es:[si].7, dx

	div word ptr ds:[di].168	;计算人均收入
	mov es:[si].13, ax		

	mov ax, [di].168		;人数
	mov es:[si].10, ax

	add di, 2	;人数加2B
	add bx, 4	;年份加4B
	add si, 16	;下一行结构数据
	
	loop s

	mov ax, 4c00H
	int 21H
code ends
end start