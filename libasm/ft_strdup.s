segment			.text
				global _ft_strdup
				extern _malloc
				extern _ft_strlen
				extern _ft_strcpy

_ft_strdup:
				mov			rax, 0
				push		rdi
				call		_ft_strlen
				inc			rax
				mov			rdi, rax
				call		_malloc
				jz			error
				pop			rsi
				mov			rdi, rax
				call		_ft_strcpy
				mov			rdi, rsi
				ret

error:
				pop			rdi
				ret