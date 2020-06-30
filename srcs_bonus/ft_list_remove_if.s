;void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
;(*cmp)(list_ptr->data, data_ref)
;(*free_fct)(list_ptr->data)


global ft_list_remove_if

ft_list_remove_if:

	cmp	rdi, 0
	je	.end
	mov	r9, 0
	cmp	[rdi], r9
	je 	.end
	cmp	rdx, 0
	je	.end
	cmp	rcx, 0
	je	.end	
	mov	r9, rdi			; r9 ->**begin list
	cmp	r9, 0
	je	.end	
	mov	r10, [rdi]		; r10 ->*begin_list, first element
	cmp	r10, 0
	je	.end
	mov	r11, rsi		; r11 -> data_ref
	mov	r12, rdx		; r12 -> cmp
	mov	r13, rcx		; r13 -> free
	
	.first_element:
		mov	rdi, [r10]	; rdi -> data of the first element
		mov	rsi, r11	; rsi -> data_ref
		cmp	rdi, 0
		je 	.comp_null_el
		cmp	rsi, 0
		je 	.comp_null_ref
		mov	rax, r12;	; rax -> cmp	
		push	r9
		push	r10
		push	r11
		push	r12
		push	r13
		call	rax
		pop	r13
		pop	r12
		pop	r11
		pop	r10
		pop	r9
		cmp	rax, 0
		je	.free_first_element
		jmp	.other_elements

	.comp_null_el:
		cmp	rsi, 0
		je	.free_first_element
		jmp	.other_elements

	.comp_null_ref:
		cmp	rdi, 0
		je	.free_first_element
		jmp	.other_elements
		
	.free_first_element:
		mov 	rdi, [r10]
		mov	rax, r13
		push	r9
		push	r10
		push	r11
		push	r12
		push	r13
		call	rax
		pop	r13
		pop	r12
		pop	r11
		pop	r10
		pop	r9
		mov 	QWORD [r10], 0	
		
	.suppress_first_element:
		mov	r10, [r10 + 8]	; r10 ->second element
		mov	[r9], r10	; *begin_list points towards the second element
		cmp	r10, 0		; check if the second element exists
		je	.end	
		jmp	.first_element

	.other_elements:
		mov	r9, r10		; r9 -> save the first element address 
		mov	r10, [r10 + 8]	; r10 -> second element
		cmp	r10, 0		; check if the second element exists
		je	.end
		mov	rdi, [r10]	; rdi -> data of the second element
		mov	rsi, r11	; rsi -> data_ref
		cmp	rdi, 0
		je	.comp_null_el_two
		cmp	rsi, 0
		je	.comp_null_ref_two
		mov	rax, r12;	; rax -> cmp	
		push	r9		; save  everything
		push	r10		
		push	r11
		push 	r12
		push 	r13
		call	rax
		pop	r13
		pop	r12
		pop	r11
		pop	r10
		pop	r9
		cmp	rax, 0
		je	.free_other_elements
		jmp	.other_elements

	.comp_null_el_two:
		cmp	rsi, 0
		je	.free_other_elements
		jmp	.other_elements

	.comp_null_ref_two:
		cmp	rdi, 0
		je	.free_other_elements
		jmp	.other_elements

	.free_other_elements:
		mov	rax, r13
		push	r9
		push	r10		
		push	r11
		push 	r12
		push 	r13
		mov	rdi, [r10]
		call	rax
		pop	r13
		pop	r12
		pop	r11
		pop	r10
		pop	r9
		mov 	QWORD [r10], 0
		
	.suppress_other_elements:
		mov	r10, [r10 + 8]	; r10 -> third element
		cmp	r10, 0
		je	.end_of_list
		mov	[r9 + 8], r10	; r9->next : third element address
		mov	rcx, r10
		mov	r10, r9
		jmp	.other_elements
	
	.end_of_list:
		mov	[r9 + 8], r10	; the previous element points towards NULL
		
	.end:
		ret
