# 这里是一个模板
.section .data  #数据段 这里定义变量

value:
 .int 105,235,61,315,134,221,53,145,117,5
.section .text  #本文段 这里是命令代码

.globl _start
_start:
movq $55,%r14
jmp k
movq $44,%r13

#调用
k:
call fun
movq $88,%r15

fun:
movq $66, %r10
ret

int $0x80
#要另存为
