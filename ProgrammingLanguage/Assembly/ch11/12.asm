assume cs:code, ds:data

data segment
    db 'aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ', 0
data ends



code segment
start:	mov ax, data
	mov ds, ax
	mov si, 0
	call letterc

	mov ax, 4c00H
	int 21H

;说明:将字符串中的小写字符变为大写
;参数:ds:si存储字符串首地址
;返回值：无
letterc:push si
	cmp byte ptr [si], 0	;为0直接返回
	je s0
	cmp byte ptr [si], 97
	jb s			;小于字母a的不处理
	cmp byte ptr [si], 122
	ja s			;大于字母z的不处理
	and byte ptr [si], 11011111B

    s:	inc si
	loop letterc

   s0:	pop si
	ret 
 
code ends
end start