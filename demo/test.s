.globl bubble_sort
.text
.align 16
.type bubble_sort,@function
bubble_sort:
pushl %ebp
pushl %ebx
pushl %esi
pushl %edi
movl %esp,%ebp
subl $12,%esp
movl $0,-12(%ebp)
jmp .LC5
.LC2:
movl -12(%ebp),%edi
movl %edi,-8(%ebp)
leal 1(%edi),%edi
movl %edi,-4(%ebp)
jmp .LC9
.LC6:
movl 20(%ebp),%edi
movl -4(%ebp),%esi
movl -8(%ebp),%ebx
movl (%edi,%ebx,4),%ebx
cmpl %ebx,(%edi,%esi,4)
jge .LC10
movl -4(%ebp),%edi
movl %edi,-8(%ebp)
.LC10:
.LC7:
incl -4(%ebp)
.LC9:
movl 24(%ebp),%edi
cmpl %edi,-4(%ebp)
jl .LC6
movl -8(%ebp),%edi
cmpl %edi,-12(%ebp)
je .LC12
movl 20(%ebp),%edi
movl -12(%ebp),%esi
leal (%edi,%esi,4),%esi
movl -8(%ebp),%ebx
movl (%edi,%ebx,4),%edi
addl %edi,(,%esi)
movl 20(%ebp),%edi
movl -8(%ebp),%esi
leal (%edi,%esi,4),%esi
movl -12(%ebp),%ebx
movl (%edi,%ebx,4),%edi
subl (,%esi),%edi
movl %edi,(,%esi)
movl 20(%ebp),%edi
movl -12(%ebp),%esi
leal (%edi,%esi,4),%esi
movl -8(%ebp),%ebx
movl (%edi,%ebx,4),%edi
sub %edi,(,%esi)
.LC12:
.LC3:
incl -12(%ebp)
.LC5:
movl 24(%ebp),%edi
subl $1,%edi
cmpl %edi,-12(%ebp)
jl .LC2
.LC1:
movl %ebp,%esp
popl %edi
popl %esi
popl %ebx
popl %ebp
ret
.Lf14:
.size bubble_sort,.Lf14-bubble_sort
.ident "LCC: 4.1"
