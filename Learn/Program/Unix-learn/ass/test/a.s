	.file	"a.c"
	.globl	s1
	.section	.rodata
.LC0:
	.string	"xinkge"
	.data
	.align 8
	.type	s1, @object
	.size	s1, 8
s1:
	.quad	.LC0
	.globl	s3
	.type	s3, @object
	.size	s3, 7
s3:
	.string	"xingke"
	.globl	t
	.align 4
	.type	t, @object
	.size	t, 4
t:
	.long	10
	.text
	.globl	fun
	.type	fun, @function
fun:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
.L4:
	movl	-20(%rbp), %eax
	addl	%eax, -4(%rbp)
	cmpl	$10, -4(%rbp)
	jle	.L2
	jmp	.L5
.L2:
	jmp	.L4
.L5:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	fun, .-fun
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	$1735289208, -32(%rbp)
	movw	$25963, -28(%rbp)
	movb	$0, -26(%rbp)
	leaq	-32(%rbp), %rax
	movq	%rax, -8(%rbp)
	movl	$5, -36(%rbp)
	leaq	-36(%rbp), %rax
	movq	%rax, -16(%rbp)
	movl	$2, -20(%rbp)
	movl	-20(%rbp), %eax
	movl	%eax, -36(%rbp)
	movzbl	s3+2(%rip), %eax
	movb	%al, -21(%rbp)
	movl	-36(%rbp), %eax
	movl	%eax, %edi
	call	fun
	movl	$12, t(%rip)
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Debian 4.9.2-10) 4.9.2"
	.section	.note.GNU-stack,"",@progbits
