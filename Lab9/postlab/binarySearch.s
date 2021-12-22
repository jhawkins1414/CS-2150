	;; Jared Hawkins jmh7ax 4/11/2021

	global binarySearch

	section .text

binarySearch:
	mov rax, -1 		;if not found
	xor r10, r10		;zero temp middle
	xor eax, eax		;zero temp

	cmp rsi,rdx		;compare beginning and end
	je done			;finish if beginning == end
	jg done			;finish if beginning > end
	lea r10, [rdx, rsi]	;temp = beginning + end
	shr r10, 1		;temp = middle (divide by 2)
	mov eax, [rdi+4*r10]	;store midle of array in eax
	cmp ecx, eax		;compare search and middle
	je found		;if equal - found
	jg greater		;if greater - greater
	jl less			;if less - less
	
greater:
	mov rsi, r10		;beginning = middle
	call binarySearch	;recurse
	jmp done
	
less:
	mov rdx, r10		;end = middle
	call binarySearch	;recurse
	jmp done
	
found:
	mov rax, r10		;put in return address
	jmp done		;done

done:
	ret
