	;; Jared Hawkins jmh7ax 4/11/2021

	global linearSearch

	section .text


	;; Parameter 1 is a pointer to the int array - rdi
	;; Parameter 2 is size of array - rsi
	;; Parameter 3 is element to find - rdx
	
linearSearch:
	xor rax, rax 		; zero out return register
	xor r10, r10 		; zero out  i
	xor r11, r11 		; zero out rax
	xor rax, -1


start:
	cmp r10, rsi 		; compare i to size
	je  done		; if i == size then done
	cmp edx, [rdi+4*r10]	; compare edx to a[i]
	jne after		; if != inc i
	mov rax, r10		;rax = i
	jmp done		;done

after:
	;; i++
	;; jump to start
	inc r10
	jmp start
	
	
done:
	ret
