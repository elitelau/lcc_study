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
movl %edi,%ebx
movb %bl,20(%ebp)
movl 24(%ebp),%edi
movl %edi,%ebx
movb %bl,24(%ebp)
movsbl 20(%ebp),%edi
movsbl 24(%ebp),%esi
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
