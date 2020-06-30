;void ft_list_push_front(t_list **begin_list, void *data)

extern malloc
extern __errno_location
global ft_list_push_front

ft_list_push_front:

;	push	rbp			; either push rbp, either sub 8 to rsp
;	mov	rbp, rsp
	cmp	rdi, 0
	je	.null
	push	rdi			; we save rdi and rsi
	push	rsi
	sub	rsp, 8
	mov	rdi, 16			; we malloc of 16
	call	malloc
	add	rsp, 8
	pop	rsi
	pop	rdi
	cmp	rax, 0
	je	.error
	mov	rcx, [rdi]		; we dereference rdi 
	mov	[rax + 8], rcx		; we put it in next of the structure
	mov	[rax], rsi		; we put data given in argument in the data element of the structure
	mov	[rdi], rax		; we put structure's address in begin_list pointer
;	pop	rbp
	jmp	.end

	.null:
;		pop rbp
		ret
	.error:
		call	__errno_location
		mov 	rcx, 12
		mov	[rax], rcx
		mov	rax, 0
;		pop	rbp
		jmp	.end
	
	.end:
		ret
