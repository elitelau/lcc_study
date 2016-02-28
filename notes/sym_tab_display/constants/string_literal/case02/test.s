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
leal .LC2,%edi
movl %edi,-4(%ebp)
movl -4(%ebp),%eax
.LC1:
movl %ebp,%esp
popl %edi
popl %esi
popl %ebx
popl %ebp
ret
.Lf3:
.size f,.Lf3-f
.globl main
.align 16
.type main,@function
main:
pushl %ebp
pushl %ebx
pushl %esi
pushl %edi
movl %esp,%ebp
movl $13,%eax
.LC4:
movl %ebp,%esp
popl %edi
popl %esi
popl %ebx
popl %ebp
ret
.Lf5:
.size main,.Lf5-main
.data
.align 1
.LC2:
.byte 104
.byte 101
.byte 108
.byte 108
.byte 111
.byte 32
.byte 119
.byte 111
.byte 114
.byte 108
.byte 100
.byte 33
.byte 0
.text
.ident "LCC: 4.1"
