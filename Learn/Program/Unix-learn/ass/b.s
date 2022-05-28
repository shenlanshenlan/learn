# 这里是一个模板
.section .data  #数据段 这里定义变量

value:
 .int 105,235,61,315,134,221,53,145,117,5
.section .text  #本文段 这里是命令代码

.globl _start
_start:

movl $value,%esi  
movl $9,%ecx
movl $9,%ebx
loop:
 movl (%esi),%eax
cmp %eax,4(%esi)
jpe skip
xchg %eax,4(%esi)
movl %eax,(%esi)
skip:
add $4,%esi
dec %ebx
jnz loop
dec %ecx
jz end
movl $value,%esi
movl %ecx,%ebx
jmp loop
end:
movl $1,%eax
movl $0,%ebx
int $0x80


  
int $0x80



