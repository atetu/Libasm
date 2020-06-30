extern __errno_location
global	ft_write
section .text

ft_write:

	xor	rax, rax
	jmp	.write
	
	.write:
		mov	rax, 1		; sys call for write
		syscall			;invoke operating system to do the call
		cmp	rax, 0
		jl	.error
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
