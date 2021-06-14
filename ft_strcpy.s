global _ft_strcpy

section .text

_ft_strcpy:
		xor	rax, rax
		not	rax

main:
		inc	rax
		mov	bl, byte[rsi + rax]
		mov	byte[rdi + rax], bl
		cmp	bl, 0
		jne	main
		mov	rax, rdi
		ret