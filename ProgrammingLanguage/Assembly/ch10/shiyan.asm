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

     mov cx,21	;��21��

     mov dh,2	;��

     mov dl,30	;��

g:   push cx

     push dx

     mov ax,es:[bx]

     mov [si],ax	;19

     mov ax,es:[bx].2	;75

     mov [si].2,ax ;�����ds:si

     add si,6 

     mov ax,es:[bx].84

     mov dx,es:[bx].86

     call dtoc2    ;����ת��ʮ�����ַ���ds:si

     add si,10

     mov ax,es:[di].168

     mov dx,0

     call dtoc2    ;��Ա��ת��ʮ�����ַ���ds:si

     add si,6

     mov ax,es:[di].210

     mov dx,0

     call dtoc2    ;�˾�����ת��ʮ�����ַ���ds:si

     mov si,0      ;����ds:siָ������ʾ�ַ��׵�ַ

b:   mov cx,29		;һ�й�30���ֽ�

c:   push cx

     mov cl,[si]

     jcxz f        ;(ds:si)=0ת��fִ��

d:   inc si

     pop cx

     loop c

     inc si

     mov al,0

     mov [si],al   ;���ý�β��0

     mov si,0      ;����ds:siָ������ʾ�ַ��׵�ַ

     pop dx

     mov cl,2

     call show_str

     add bx,4      ;dword����ָ����һ���ݵ�Ԫ

     add di,2      ;word����ָ����һ���ݵ�Ԫ

     add dh,1      ;ָ���Դ���һ��

     pop cx

     loop g

     mov ax,4c00h

     int 21h

f:   mov al,20h

     mov [si],al   ;(ds:si)=0�����ݸĳɿո�

     jmp d

 

;���ƣ�dtoc2

;���ܣ���dword������ת��Ϊ��ʾʮ���Ƶ��ַ������ַ�����0Ϊ��β����

;������(ax)=dword�����ݵĵ�16λ��

;      (dx)=dword�����ݵĸ�16λ��

;      ds:siָ���ַ����׵�ַ��

;���أ���

dtoc2:

     push ax

     push bx

     push cx

     push dx

     push si

     push di

     mov di,0

d20: mov cx,10     ;����Ϊ10

     call divdw

     add cx,30h    ;����+30h��תΪ�ַ�

     push cx       ;�ַ���ջ

     inc di        ;��¼�ַ�����

     mov cx,ax 

     jcxz d21      ;��λ��=0ʱ��ת��d21����λ��

     jmp d20

d21: mov cx,dx

     jcxz d22      ;�ߵ�λ��ȫ=0ʱ��ת��d22ִ��

     jmp d20

d22: mov cx,di

d23: pop ax        ;�ַ���ջ

     mov [si],al

     inc si        ;ds:siָ����һ��Ԫ

     loop d23

     mov al,0

     mov [si], al   ;���ý�β��0

     pop di

     pop si

     pop dx

     pop cx

     pop bx

     pop ax

     ret

 

;���ƣ�divdw

;���ܣ����в����������ĳ������㣬������Ϊdword�ͣ�����Ϊword�ͣ����Ϊdword�͡�

;������(ax)=dword�����ݵĵ�16λ��

;      (dx)=dword�����ݵĸ�16λ��

;      (cx)=������

;���أ�(dx)=����ĸ�16λ��

;      (ax)=����ĵ�16λ��

;      (cx)=������

divdw:

     push si

     push bx

     push ax

     mov ax,dx

     mov dx,0

     div cx        ;�������ĸ�λ/cx

     mov si,ax

     pop ax 

     div cx        ;(��������λ����+��λ)/cx

     mov cx,dx     ;������cx

     mov dx,si     ;��λ������dx

     pop bx

     pop si

     ret

 

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

     mov bx,ax     ;bx=160*dh

     mov ax,2

     mul dl        ;ax=dl*2

     add bx,ax     ;mov bx,(160*dh+dl*2)����es:bxָ���Դ��׵�ַ

     mov al,cl     ;����ɫcl��ֵal

     mov cl,0

show0:

     mov ch,[si]

     jcxz show1    ;(ds:si)=0ʱ��ת��show1ִ��    

     mov es:[bx],ch

     mov es:[bx].1,al

     inc si        ;ds:siָ����һ���ַ���ַ

     add bx,2      ;es:bxָ����һ���Դ��ַ

     jmp show0

show1:

     pop si

     pop es

     pop bx

     pop ax

     ret

 

code ends

end start
