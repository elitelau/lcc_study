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
add $11,20(%ebp)
.LC1:
movl %ebp,%esp
popl %edi
popl %esi
popl %ebx
popl %ebp
ret
.Lf2:
.size f,.Lf2-f
.globl main
.align 16
.type main,@function
main:
pushl %ebp
pushl %ebx
pushl %esi
pushl %edi
movl %esp,%ebp
pushl $13
call f
addl $4,%esp
movl $7,%eax
.LC3:
movl %ebp,%esp
popl %edi
popl %esi
popl %ebx
popl %ebp
ret
.Lf4:
.size main,.Lf4-main
.ident "LCC: 4.1"
