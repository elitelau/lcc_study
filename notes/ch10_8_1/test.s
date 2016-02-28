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
movl 20(%ebp),%edi
movl 24(%ebp),%esi
leal (%esi,%edi),%eax
.LC1:
movl %ebp,%esp
popl %edi
popl %esi
popl %ebx
popl %ebp
ret
.Lf2:
.size add,.Lf2-add
.globl f
.align 16
.type f,@function
f:
pushl %ebp
pushl %ebx
pushl %esi
pushl %edi
movl %esp,%ebp
subl $12,%esp
movl $1,-4(%ebp)
movl $2,-8(%ebp)
pushl -8(%ebp)
pushl -4(%ebp)
call add
addl $8,%esp
movl %eax,-12(%ebp)
.LC3:
movl %ebp,%esp
popl %edi
popl %esi
popl %ebx
popl %ebp
ret
.Lf4:
.size f,.Lf4-f
.ident "LCC: 4.1"
