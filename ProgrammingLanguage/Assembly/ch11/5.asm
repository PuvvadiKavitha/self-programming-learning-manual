assume cs:code

code segment
start:	

;˵��:��������128���ļӷ����߼���
;����:ds:[si]�洢��һ�����ݵ��ڴ��׵�ַ,ds:[di]�洢�ڶ��������ڴ��׵�ַ
;����ֵ:�����������ݴ洢�ڵ�һ�����ݵĵ�ַ��
add128:	push ax
	push cx
	push si
	push di

	sub ax, ax		;��CF����Ϊ0

	mov cx, 8
     s: mov ax, [si]
	adc ax, [di]		;�ӵ�λ��ʼ���ν�λ����,��������sbbָ���
	mov [si], ax

	inc si			;incָ�������add���棬��Ϊadd��Ӱ��CF��־λ
	inc si			;inc��loop��Ӱ��CF��־λ
	inc di
	inc di
	loop s

	pop di
	pop si
	pop cx
	pop ax
	ret
code ends
end start



