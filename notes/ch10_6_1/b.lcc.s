.globl add
.text
.align 16
.type add,@function
add:
pushl %ebp
pushl %ebx
pushl %esi
pushl %edi
movl %esp,%ebp
subl $8,%esp
movl $0,-8(%ebp)
movl $0,-4(%ebp)
jmp .LC5
.LC2:
movl -4(%ebp),%edi
movl 20(%ebp),%esi
movl (%esi,%edi,4),%edi
addl %edi,-8(%ebp)
.LC3:
incl -4(%ebp)
.LC5:
cmpl $10,-4(%ebp)
jl .LC2
movl -8(%ebp),%eax
.LC1:
movl %ebp,%esp
popl %edi
popl %esi
popl %ebx
popl %ebp
ret
.Lf6:
.size add,.Lf6-add
.ident "LCC: 4.1"
