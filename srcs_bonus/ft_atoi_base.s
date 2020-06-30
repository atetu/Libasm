global	ft_atoi_base
extern	ft_strlen

section	.text

ft_atoi_base:

	cmp	rsi, 0
	je	.error
	xor	rcx, rcx
	mov	r9, 1				; r9 -> neg sign
	xor	r10, r10
	xor	r11, r11
	xor	r12, r12
	jmp	.first_arg

	.first_arg:
		cmp	byte[rdi + rcx], 9	; check of spaces
		je	.index_inc
		cmp	byte[rdi + rcx], 10
		je	.index_inc
		cmp	byte[rdi + rcx], 11 
		je	.index_inc
		cmp	byte[rdi + rcx], 12 
		je	.index_inc
		cmp	byte[rdi + rcx], 13 
		je	.index_inc
		cmp	byte[rdi + rcx], 32 
		je	.index_inc
		jmp	.sign
		
	.sign:
		cmp	byte[rdi + rcx], 43	; check of + and - signs
		je	.pos_inc
		cmp	byte[rdi + rcx], 45
		je	.neg_inc
		jmp	.character

	.index_inc:
		inc	rcx			;rcx index of first string
		jmp	.first_arg

	.pos_inc:
		inc	rcx
		jmp	.sign

	.neg_inc:
		inc	rcx
		imul	r9, -1			; r9 number of neg signs
		jmp	.sign

	.character:
		mov	r10, rcx		; r10 start of the string
		jmp	.check_second_arg

	.check_second_arg:
		push	rdi
		push	rsi
		push	r9
		mov	rdi, rsi
		call	ft_strlen
		mov	r12, rax		; r12 -> base size
		pop	r9
		pop	rsi
		pop	rdi
		cmp	r12, 1
		jle	.error
		xor	rcx, rcx
		xor	r13, r13		; r13 second index second string
		jmp	.double_char_check

	.double_char_check:
		cmp	rcx, r12		; is rcx < r12
		jl	.first_char_check
		xor	r13, r13
		xor	rax, rax
		xor	r11, r11
		jmp	.check_wrong_char
		jmp	.convert

	.first_char_check:
		cmp	r13, rcx		; is r13 < rcx
		jl	.is_same_char
		inc	rcx
		xor	r13, r13
		jmp	.double_char_check

	.is_same_char:
		mov	dl, byte[rsi + rcx]
		cmp	byte[rsi + r13], dl
		je	.error
		inc	r13
		jmp	.double_char_check
	
	.check_wrong_char:
		cmp	byte[rsi + r13], 9	; check of spaces
		je	.error
		cmp	byte[rsi + r13], 10
		je	.error
		cmp	byte[rsi + r13], 11 
		je	.error
		cmp	byte[rsi + r13], 12 
		je	.error
		cmp	byte[rsi + r13], 13 
		je	.error
		cmp	byte[rsi + r13], 32 
		je	.error
		cmp	byte[rsi + r13], 43	; check of + and - signs
		je	.error
		cmp	byte[rsi + r13], 45
		je	.error
		inc	r13
		cmp	byte[rsi + r13], 0
		jne	.check_wrong_char
		xor	r13, r13
		jmp	.convert

	.convert:
		mov	dl, byte[rsi + r13]
		cmp	byte[rdi + r10], dl
		jne	.convert_inc
		jmp	.base_convert

	.convert_inc:
		inc	r13
		cmp	byte[rsi + r13], 0
		je	.sign_neg_check		; stop if character in first arg is not present in the base
		jmp	.convert
		
	.base_convert:
		imul	r11, r12		; mul by base size
		add	r11, r13
		inc 	r10
		xor	r13, r13
		cmp	byte[rdi + r10], 0
		jne	.convert
		jmp	.sign_neg_check
		
	.sign_neg_check:
		imul	r11, r9
		mov	rax, r11
		jmp	.end	

	.error:
		mov	rax, 0
		jmp	.end
	.end:
		ret
