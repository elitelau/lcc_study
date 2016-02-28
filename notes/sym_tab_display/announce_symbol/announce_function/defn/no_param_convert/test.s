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
.size f,.Lf2-f
.ident "LCC: 4.1"
