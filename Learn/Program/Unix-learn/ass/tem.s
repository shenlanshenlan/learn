# 这里是一个模板
.section .data  #数据段 这里定义变量

value:
 .int 6
.section .text  #本文段 这里是命令代码

.globl _start
_start:

nop
movl $1000,%eax
movl $eax,value
movl $1,   %eax
movl $0,   %ebx
int $0x80



