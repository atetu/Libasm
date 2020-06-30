;int	ft_list_size(t_list *begin_list)

global ft_list_size

ft_list_size:

	cmp	rdi, 0
	je	.return
	xor	rcx, rcx	
	xor	rdx, rdx
	mov	rax, [rdi + 8]
	jmp	.loop
	
	.loop:
		inc	rcx
		cmp	rax, 0
		je	.end
		mov	rax, [rax + 8]
		jmp	.loop

	.return:
		mov	rax, 0
		ret
	.end:
		mov	rax, rcx
		ret
