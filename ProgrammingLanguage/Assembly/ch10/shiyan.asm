assume cs:code,ds:data,es:table

table segment

    db '1975','1976','1977','1978','1979','1980','1981','1982','1983'

    db '1984','1985','1986','1987','1988','1989','1990','1991','1992'

    db '1993','1994','1995'

    dd 16,22,382,1356,2390,8000,16000,24486,50065,97479,140417,197514

    dd 345980,590827,803530,1183000,1843000,2795000,3753000,4649000,5937000

    dw 3,7,9,13,28,38,130,220,476,778,1001,1442,2258,2793,4037,5635,8226

    dw 11542,14430,15257,17800

    dw 5,3,42,104,85,210,123,111,105,125,140,136,153,211,199,209,224,239

    dw 260,304,333

table ends

data segment

    db 32 dup (0)

data ends

code segment

start:   
     mov ax,data

     mov ds,ax

     mov ax,table

     mov es,ax

     mov bx,0

     mov si,0

     mov di,0

     mov cx,21	;共21年

     mov dh,2	;行

     mov dl,30	;列

g:   push cx

     push dx

     mov ax,es:[bx]

     mov [si],ax	;19

     mov ax,es:[bx].2	;75

     mov [si].2,ax ;年份入ds:si

     add si,6 

     mov ax,es:[bx].84

     mov dx,es:[bx].86

     call dtoc2    ;收入转成十进制字符入ds:si

     add si,10

     mov ax,es:[di].168

     mov dx,0

     call dtoc2    ;人员数转成十进制字符入ds:si

     add si,6

     mov ax,es:[di].210

     mov dx,0

     call dtoc2    ;人均收入转成十进制字符入ds:si

     mov si,0      ;设置ds:si指向需显示字符首地址

b:   mov cx,29		;一行共30个字节

c:   push cx

     mov cl,[si]

     jcxz f        ;(ds:si)=0转到f执行

d:   inc si

     pop cx

     loop c

     inc si

     mov al,0

     mov [si],al   ;设置结尾符0

     mov si,0      ;设置ds:si指向需显示字符首地址

     pop dx

     mov cl,2

     call show_str

     add bx,4      ;dword数据指向下一数据单元

     add di,2      ;word数据指向下一数据单元

     add dh,1      ;指向显存下一行

     pop cx

     loop g

     mov ax,4c00h

     int 21h

f:   mov al,20h

     mov [si],al   ;(ds:si)=0的数据改成空格

     jmp d

 

;名称：dtoc2

;功能：将dword型数据转变为表示十进制的字符串，字符串以0为结尾符。

;参数：(ax)=dword型数据的低16位；

;      (dx)=dword型数据的高16位；

;      ds:si指向字符串首地址。

;返回：无

dtoc2:

     push ax

     push bx

     push cx

     push dx

     push si

     push di

     mov di,0

d20: mov cx,10     ;除数为10

     call divdw

     add cx,30h    ;余数+30h，转为字符

     push cx       ;字符入栈

     inc di        ;记录字符个数

     mov cx,ax 

     jcxz d21      ;低位商=0时，转到d21检测高位商

     jmp d20

d21: mov cx,dx

     jcxz d22      ;高低位商全=0时，转到d22执行

     jmp d20

d22: mov cx,di

d23: pop ax        ;字符出栈

     mov [si],al

     inc si        ;ds:si指向下一单元

     loop d23

     mov al,0

     mov [si], al   ;设置结尾符0

     pop di

     pop si

     pop dx

     pop cx

     pop bx

     pop ax

     ret

 

;名称：divdw

;功能：进行不会产生溢出的除法运算，被除数为dword型，除数为word型，结果为dword型。

;参数：(ax)=dword型数据的低16位；

;      (dx)=dword型数据的高16位；

;      (cx)=除数。

;返回：(dx)=结果的高16位；

;      (ax)=结果的低16位；

;      (cx)=余数。

divdw:

     push si

     push bx

     push ax

     mov ax,dx

     mov dx,0

     div cx        ;被除数的高位/cx

     mov si,ax

     pop ax 

     div cx        ;(被除数高位的商+低位)/cx

     mov cx,dx     ;余数入cx

     mov dx,si     ;高位的商入dx

     pop bx

     pop si

     ret

 

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

     mov bx,ax     ;bx=160*dh

     mov ax,2

     mul dl        ;ax=dl*2

     add bx,ax     ;mov bx,(160*dh+dl*2)设置es:bx指向显存首地址

     mov al,cl     ;把颜色cl赋值al

     mov cl,0

show0:

     mov ch,[si]

     jcxz show1    ;(ds:si)=0时，转到show1执行    

     mov es:[bx],ch

     mov es:[bx].1,al

     inc si        ;ds:si指向下一个字符地址

     add bx,2      ;es:bx指向下一个显存地址

     jmp show0

show1:

     pop si

     pop es

     pop bx

     pop ax

     ret

 

code ends

end start
