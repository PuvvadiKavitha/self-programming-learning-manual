assume cs:code, ds:data

data segment
    db 'BaSiC'		;�����ű�ʾ�������ַ�����ʽ�������Զ�ת��ΪASCII��
    db 'INFOrMaTion'
data ends

code segment
start:
    mov ax, data
    mov ds, ax		;����dsָ��data��

    mov bx, 0
    
    mov cx, 5
  s:mov al, [bx]
    and al, 11011111B	;���ַ���ASCII�еĵ���λ��Ϊ0����Ϊ��д��ĸ
    mov [bx], al
    inc bx
    loop s
    
     
    mov cx, 11
 s1:mov al, [bx]
    or al, 00100000B	;���ַ���ASCII�еĵ���λ��Ϊ1����ΪСд��ĸ
    mov [bx], al
    inc bx
    loop s1


    mov ax, 4c00H
    int 21H
code ends
end start
