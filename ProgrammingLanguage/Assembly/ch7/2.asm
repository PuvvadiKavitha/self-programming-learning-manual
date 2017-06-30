assume cs:code, ds:data

data segment
    db 'BaSiC'		;单引号表示数据以字符的形式给出，自动转换为ASCII码
    db 'INFOrMaTion'
data ends

code segment
start:
    mov ax, data
    mov ds, ax		;设置ds指向data段

    mov bx, 0
    
    mov cx, 5
  s:mov al, [bx]
    and al, 11011111B	;将字符的ASCII中的第五位置为0，变为大写字母
    mov [bx], al
    inc bx
    loop s
    
     
    mov cx, 11
 s1:mov al, [bx]
    or al, 00100000B	;将字符的ASCII中的第五位置为1，变为小写字母
    mov [bx], al
    inc bx
    loop s1


    mov ax, 4c00H
    int 21H
code ends
end start
