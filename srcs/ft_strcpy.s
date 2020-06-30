global ft_strcpy

section .text

ft_strcpy:
	xor	rcx, rcx
	cmp	rsi, 0
	je	.end
	jmp	.loop

	.loop:
		cmp	byte [rsi + rcx], 0
		jne	.copy
		jmp	.end
	
	.copy:
		mov	dl, byte[rsi + rcx]
		mov	byte[rdi + rcx], dl
		inc	rcx
		jmp	.loop

	.end:
		mov	dl, byte[rsi + rcx]
		mov	byte[rdi + rcx], dl
		mov	rax, rdi
		ret
