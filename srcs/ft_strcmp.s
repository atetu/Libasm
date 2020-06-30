global ft_strcmp

section	.text

ft_strcmp:
	xor	rcx, rcx
	xor	rax, rax
	xor	rdx, rdx
	xor	r9, r9
	xor	r10, r10
	jmp	.loop

	.loop:
		xor	rax, rax
		xor	rdx, rdx
		mov	dl, byte[rsi + rcx]
		mov	al, byte[rdi + rcx]
		sub	rax, rdx
		cmp	rax, 0
		jne	.end
		cmp	rdx, 0
		je	.end
		inc	rcx
		jmp	.loop
	
	.end:
		ret
