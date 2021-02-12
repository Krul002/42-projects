segment			.text
				global _ft_write
				extern ___error

_ft_write:
				mov			rax, 0x2000004
				syscall
				jc			error
				ret

error:
				push		r10
				mov			r10, rax
				call		___error
				mov			qword [rax], r10
				pop			r10
				mov			rax, -1
				ret