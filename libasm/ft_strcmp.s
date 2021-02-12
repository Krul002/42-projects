segment			.text
				global _ft_strcmp

_ft_strcmp:
				mov			rax, 0
				mov			rdx, 0
				mov			rcx, 0
				jmp			while

while:
				mov			dl, byte [rdi + rax]
				cmp			byte [rsi + rax], dl
					jne		return
				cmp			byte [rsi + rax], 0
					je		return
				inc			rax
				jmp			while

return:
				mov			cl, byte [rsi + rax]
				sub			rdx, rcx
				mov			rax, rdx
				ret