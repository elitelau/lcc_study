	.file	"b.c"
	.text
.globl add
	.type	add, @function
add:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	$0, -4(%ebp)
	movl	$0, -8(%ebp)
.L2:
	cmpl	$9, -8(%ebp)
	jg	.L3
	movl	-8(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	8(%ebp), %eax
	movl	(%edx,%eax), %edx
	leal	-4(%ebp), %eax
	addl	%edx, (%eax)
	leal	-8(%ebp), %eax
	incl	(%eax)
	jmp	.L2
.L3:
	movl	-4(%ebp), %eax
	leave
	ret
	.size	add, .-add
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.4.6 20060404 (Red Hat 3.4.6-3)"
