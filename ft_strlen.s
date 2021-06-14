global _ft_strlen

section .text

_ft_strlen:
		xor	rax, rax
		not	rax

amin:
		inc	rax
		cmp	byte [rdi + rax], 0
		jne	amin
		ret