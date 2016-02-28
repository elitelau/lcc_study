.globl f
.text
.align 16
.type f,@function
f:
pushl %ebp
pushl %ebx
pushl %esi
pushl %edi
movl %esp,%ebp
subl $4,%esp
movl $0,-4(%ebp)
incl -4(%ebp)
.LC2:
.LC3:
incl -4(%ebp)
.LC1:
movl %ebp,%esp
popl %edi
popl %esi
popl %ebx
popl %ebp
ret
.Lf4:
.size f,.Lf4-f
.ident "LCC: 4.1"
