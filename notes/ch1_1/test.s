.globl round
.text
.align 16
.type round,@function
round:
pushl %ebp
pushl %ebx
pushl %esi
pushl %edi
movl %esp,%ebp
fldl 20(%ebp)
fstps 20(%ebp)
flds 20(%ebp)
faddl .LC2
subl $4,%esp
fistpl 0(%esp)
popl %eax
.LC1:
movl %ebp,%esp
popl %edi
popl %esi
popl %ebx
popl %ebp
ret
.Lf3:
.size round,.Lf3-round
.data
.align 4
.LC2:
.long 0
.long 1071644672
.text
.ident "LCC: 4.1"
