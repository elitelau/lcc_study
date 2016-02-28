.data
.globl p
.align 4
.type p,@object
.size p,4
p:
.long .LC1
.globl main
.text
.align 16
.type main,@function
main:
pushl %ebp
pushl %ebx
pushl %esi
pushl %edi
movl %esp,%ebp
movl $7,%eax
.LC2:
movl %ebp,%esp
popl %edi
popl %esi
popl %ebx
popl %ebp
ret
.Lf3:
.size main,.Lf3-main
.data
.align 1
.LC1:
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
