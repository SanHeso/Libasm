section .text

global _ft_strdup

extern _malloc
extern _ft_strlen
extern _ft_strcpy

_ft_strdup:
		mov		rbx, rdi
		call	_ft_strlen
		mov		rdi, rax
		inc		rdi
		call	_malloc
		cmp		rax, 0
		je		error
		mov		rsi, rbx
		mov		rdi, rax
		call	_ft_strcpy
		ret

error:
		xor		rax, rax
		ret