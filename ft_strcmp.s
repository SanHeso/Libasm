global _ft_strcmp

section .text

_ft_strcmp:
		xor	rcx, rcx
		not	rcx

main:
		inc	rcx
		mov	al, byte[rdi + rcx]
		mov	bl, byte[rsi + rcx]
		cmp	al, 0
		je	diff
		cmp	bl, 0
		je	diff
		cmp	al, bl
		jne	diff
		jmp	main

diff:
		sub	al, bl
		ret