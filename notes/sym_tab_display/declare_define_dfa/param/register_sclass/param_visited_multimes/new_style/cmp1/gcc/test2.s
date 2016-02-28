	.file	"test2.c"
	.text
.globl f
	.type	f, @function
f:
	pushl	%ebp
	movl	%esp, %ebp
	shrl	$16, 8(%ebp)
	movl	8(%ebp), %eax
	andl	$15, %eax
	leave
	ret
	.size	f, .-f
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.4.6 20060404 (Red Hat 3.4.6-3)"
