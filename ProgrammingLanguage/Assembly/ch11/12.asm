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

;˵��:���ַ����е�Сд�ַ���Ϊ��д
;����:ds:si�洢�ַ����׵�ַ
;����ֵ����
letterc:push si
	cmp byte ptr [si], 0	;Ϊ0ֱ�ӷ���
	je s0
	cmp byte ptr [si], 97
	jb s			;С����ĸa�Ĳ�����
	cmp byte ptr [si], 122
	ja s			;������ĸz�Ĳ�����
	and byte ptr [si], 11011111B

    s:	inc si
	loop letterc

   s0:	pop si
	ret 
 
code ends
end start