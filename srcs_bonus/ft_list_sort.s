;void	ft_list_sort(t_list **begin_list, int(*cmp));
;(*cmp)(list_ptr->data, other_list_ptr->data);

global ft_list_sort

ft_list_sort:

	cmp	rdi, 0
	je	.end
	mov	rdx, 0
	cmp	[rdi], rdx
	je	.end
	cmp	rsi, 0
	je	.end
	mov 	r10, [rdi]			; r10 -> first element of the list
	mov	rdx, rsi			; rsi -> cmp function
	mov	r9, [r10 + 8]			; check if next of the first element is not null
	cmp	r9, 0
	je	.end
	mov	r11, [r10 + 8]			; r11 -> second element of the list
	
	.compare:
		push	rdx			
		mov	rax, rdx		; stock in rax function cmp
		mov	rdi, [r11]		; arguments for cmp function (date of the first element and second element)
		mov	rsi, [r10]
		push	r11
		push	r10
		call	rax			; call of cmp function
		pop r10
		pop	r11
		pop 	rdx			; we take back rdx
		jl	.swap
		jmp	.inc_next_elements	; if not we passe to the next element
	
	.swap:
		mov	rcx, [r10]		; we swap the values of the datas
		mov	r13, [r11]
		mov	[r10], r13
		mov	[r11], rcx
	
	.inc_next_elements:
		mov	r11, [r11 + 8]		; r11 becomes the third element
		cmp	r11, 0			; we check that we are not the end of the list
		je	.inc_cursor		; if so we increase the cursor of the first element so that we can compare the second element with all the next elements
		jmp	.compare		; if not we ckeep on comparing the first element with the next elements of the list

	.inc_cursor:
		mov	r10, [r10 + 8]		; r10 becomes the second element
		mov	r9, [r10 + 8]		; we check that there is an element after it
		cmp	r9, 0
		je	.end
		mov	r11, [r10 +8]		; if there is, r11 becomes the element after bthe new r10
		jmp	.compare
	
	.end:
		ret
