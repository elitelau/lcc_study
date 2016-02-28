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
movl $1,-4(%ebp)
incl 20(%ebp)
movl 24(%ebp),%edi
addl %edi,20(%ebp)
movl -4(%ebp),%edi
addl %edi,20(%ebp)
.LC1:
movl %ebp,%esp
popl %edi
popl %esi
popl %ebx
popl %ebp
ret
.Lf2:
.size f,.Lf2-f
.ident "LCC: 4.1"
