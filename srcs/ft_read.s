global	ft_read
extern	__errno_location

section .text

ft_read:
	xor	rax, rax
	
	jmp	.read
	
	.read:
		mov	rax, 0		; sys call for read
		syscall			;invoke operating system to do the call
		cmp	rax, 0
		jl	.error
		mov	rdx, 0
		mov	[rsi + rax], rdx
		jmp	.end

	.error:
		neg	rax
		mov	rcx, rax
		push	rcx
		call	__errno_location
		pop	rcx
		mov	[rax], rcx
		mov	rax, -1
		jmp	.end

	.end:
		ret
