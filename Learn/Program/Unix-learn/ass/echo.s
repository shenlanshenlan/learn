# 这里是一个模板

.section .data  #数据段 这里定义变量

value:
 .int 6,8
msg:
   .ascii "hello\n"
.section .text  #本文段 这里是命令代码

.globl _start
_start:


movq $5581,%rbx
int $0x80



