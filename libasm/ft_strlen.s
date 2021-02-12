segment			.text
				global _ft_strlen

_ft_strlen:
				mov			rax, 0
				jmp			while

while:
				cmp			byte [rdi + rax], 0
					je		return
				inc			rax
				jmp			while

return:
				ret