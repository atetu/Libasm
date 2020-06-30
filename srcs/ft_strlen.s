global ft_strlen

section .text

ft_strlen:
	xor	rax, rax
	jmp	.loop

	.loop:
		cmp	byte [rdi + rax], 0
		jne	.increment
		jmp	.end

	.increment:
		inc	rax
		jmp	.loop

	.end:
		ret
