section .text
global	ft_strdup
extern	malloc
extern	ft_strlen
extern	ft_strcpy
extern	__errno_location

ft_strdup:
	push	rbp
	mov	rbp, rsp	
	push	rdi
	call	ft_strlen
	push	rax	
	mov	rdi, rax
	call	malloc
	test	rax, rax
	jz	.fail
	pop	rsi
	pop	rdi
	mov	rsi, rdi
	mov	rdi, rax
	push	rdi
	push	rsi
	call	ft_strcpy
	leave
	ret

	.fail:
		call	__errno_location
		mov	rcx, 12
		mov	[rax], rcx 
		mov	rax, 0
		pop	rbp
		ret

