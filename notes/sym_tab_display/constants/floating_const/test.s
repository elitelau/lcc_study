.globl f1
.text
.align 16
.type f1,@function
f1:
pushl %ebp
pushl %ebx
pushl %esi
pushl %edi
movl %esp,%ebp
.LC1:
movl %ebp,%esp
popl %edi
popl %esi
popl %ebx
popl %ebp
ret
.Lf2:
.size f1,.Lf2-f1
.globl f2
.align 16
.type f2,@function
f2:
pushl %ebp
pushl %ebx
pushl %esi
pushl %edi
movl %esp,%ebp
.LC3:
movl %ebp,%esp
popl %edi
popl %esi
popl %ebx
popl %ebp
ret
.Lf4:
.size f2,.Lf4-f2
.globl main
.align 16
.type main,@function
main:
pushl %ebp
pushl %ebx
pushl %esi
pushl %edi
movl %esp,%ebp
flds .LC6
subl $4,%esp
fstps (%esp)
call f1
addl $4,%esp
fldl .LC7
subl $8,%esp
fstpl (%esp)
call f2
addl $8,%esp
movl $1371,%eax
.LC5:
movl %ebp,%esp
popl %edi
popl %esi
popl %ebx
popl %ebp
ret
.Lf8:
.size main,.Lf8-main
.data
.align 4
.LC7:
.long 1374389535
.long 1074339512
.align 4
.LC6:
.long 1078523331
.text
.ident "LCC: 4.1"
