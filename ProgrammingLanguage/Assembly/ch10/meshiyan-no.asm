assume cs:code, ds:data, es:table

data segment
    ;���
    db '1975','1976','1977','1978','1979','1980','1981','1982','1983'
    db '1984','1985','1986','1987','1988','1989','1990','1991','1992'
    db '1993','1994','1995' 
    
    ;����
    dd 16,22,382,1356,2390,8000,16000,24486,50065,97479,140417,197514
    dd 345980,590827,803530,1183000,1843000,2759000,3753000,4649000,5937000 
   
    ;����
    dw 3,7,9,13,28,38,130,220,476,778,1001,1442,2258,2793,4037,5635,8226
    dw 11542,14430,45257,17800 

    ;�˾�����
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
	;���
	mov ax, es:[bx]
	mov [si], ax
	mov ax, es:[bx + 2]
	mov [si + 2], ax

	;����
	add si, 6
	mov ax, es:[bx + 84]
	mov dx, es:[bx + 86]
	;ת�����ַ���
	call dtoc2

	;��Ա��
	add si, 10
	mov ax, es:[di + 168]
	mov dx, 0
	call dtoc2

	;�˾�����
	add si, 6
	mov ax, es:[di + 210]
	mov dx, 0
	call dtoc2

	mov si, 0	;ds:siָ���Դ��׵�ַ
b:	mov cx, 29

c:	push cx
	mov cl, [si]
	jcxz f

d:	inc si
	pop cx
	loop c

	inc si
	mov al, 0
	mov [si], al	;��β0
	mov si, 0	;ds:siָ���Դ��׵�ַ��show_str
	pop dx
	mov cl, 2	;��ɫΪ��ɫ
	call show_str

	add bx, 4	;dwordָ����һ����Ԫ	
	add di, 2	;wordָ����һ����Ԫ
	add dh, 1	;�Դ���һ��
	pop cx
	loop g

	mov ax, 4c00H
	int 21H



f:	mov al, 20H
	mov [si], al	;����0��Ϊ�ո�
	jmp d


;���ƣ�dtoc2
;���ܣ���dword������ת��Ϊ��ʾʮ���Ƶ��ַ������ַ�����0Ϊ��β����
;������(ax)=dword�����ݵĵ�16λ��
;      (dx)=dword�����ݵĸ�16λ��
;      ds:siָ���ַ����׵�ַ��
;���أ���
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

;���ƣ�show_str
;���ܣ���ָ����λ�ã���ָ������ɫ����ʾһ����0�������ַ�����
;������(dh)=�к�(ȡֵ��Χ0~24)��
;      (dl)=�к�(ȡֵ��Χ0~79)��
;      (cl)=��ɫ��
;      ds:siָ���ַ������׵�ַ��
;���أ���
show_str:
	;�Ĵ�����ջ
	push ax
	push es
	push si
	push bx

	mov ax, 0B800H
	mov es, ax
	mov ax, 160

	mul dh		;ȷ����
	mov bx, ax	;����������bx��

	mov ax, 2	;�Դ��ֵ�Ԫÿ�μ�2
	mul dl		;ȷ����
	add bx, ax	;�������Դ��ַ����������bx��

	mov al, cl	;��ɫ���Է���al��
	mov cl, 0

show0:	mov ch, [si]
	jcxz show1		;0ֱ�ӽ���
	mov es:[bx], ch		;�Դ��ַ��bx��
	mov es:[bx + 1], al	;��ɫ������al��
	inc si
	add bx, 2		;�ֵ�Ԫ����Ϊ2
	jmp show0

	;�Ĵ�����ջ
show1:	pop bx
	pop si
	pop es
	pop ax
	ret 
 
divdw:	push si
	push bx
	push ax

	mov ax, dx	;�ȼ����λ
	mov dx, 0
	div cx		;��λ/cx��������dx��

	mov si, ax	;��λ/cx������si��
	
	pop ax		;������16λ��ax
	div cx		;��16λ/cx, ��������dx���Ǹ�λ����������, ax�ǵ�16λ

	mov cx, dx	;������dx��
	mov dx, si	;��λ����ת�Ƶ�dx��

	pop ax
	pop bx
	pop si
	ret	 
code ends
end start