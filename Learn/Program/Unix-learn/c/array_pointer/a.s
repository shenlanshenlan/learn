	.file	"a.c"
	.comm	str,128,64
	.text
	.globl	k_ntop
	.type	k_ntop, @function
k_ntop:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	addq	$4, %rax
	movl	$128, %ecx
	movl	$str, %edx
	movq	%rax, %rsi
	movl	$2, %edi
	movl	$0, %eax
	call	inet_ntop
	movl	$str, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	k_ntop, .-k_ntop
	.section	.rodata
.LC0:
	.string	"\345\234\260\345\235\200\346\234\252\346\211\276\345\210\260"
	.text
	.globl	host_serv
	.type	host_serv, @function
host_serv:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$96, %rsp
	movq	%rdi, -72(%rbp)
	movq	%rsi, -80(%rbp)
	movl	%edx, -84(%rbp)
	movl	%ecx, -88(%rbp)
	movl	$2, -48(%rbp)
	movl	-84(%rbp), %eax
	movl	%eax, -44(%rbp)
	movl	-88(%rbp), %eax
	movl	%eax, -40(%rbp)
	leaq	-56(%rbp), %rcx
	leaq	-48(%rbp), %rdx
	movq	-80(%rbp), %rsi
	movq	-72(%rbp), %rax
	movq	%rax, %rdi
	call	getaddrinfo
	testl	%eax, %eax
	je	.L4
	movl	$.LC0, %edi
	call	puts
	movl	$0, %eax
	jmp	.L6
.L4:
	movq	-56(%rbp), %rax
.L6:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	host_serv, .-host_serv
	.globl	cout
	.type	cout, @function
cout:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	puts
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	cout, .-cout
	.globl	sock_set_port
	.type	sock_set_port, @function
sock_set_port:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, %eax
	movw	%ax, -28(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	movzwl	-28(%rbp), %eax
	movl	%eax, %edi
	call	htons
	movl	%eax, %edx
	movq	-8(%rbp), %rax
	movw	%dx, 2(%rax)
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	sock_set_port, .-sock_set_port
	.globl	sock_cmp_addr
	.type	sock_cmp_addr, @function
sock_cmp_addr:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	%edx, -20(%rbp)
	movq	-8(%rbp), %rax
	movzwl	(%rax), %edx
	movq	-16(%rbp), %rax
	movzwl	(%rax), %eax
	cmpw	%ax, %dx
	je	.L10
	movl	$-1, %eax
	jmp	.L11
.L10:
	movl	-20(%rbp), %eax
	movq	-16(%rbp), %rdx
	leaq	4(%rdx), %rsi
	movq	-8(%rbp), %rdx
	leaq	4(%rdx), %rcx
	movq	%rax, %rdx
	movq	%rcx, %rdi
	call	memcmp
.L11:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	sock_cmp_addr, .-sock_cmp_addr
	.globl	tv_sub
	.type	tv_sub, @function
tv_sub:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rdx
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	subq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 8(%rax)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	jns	.L13
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	leaq	-1(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	leaq	1000000(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 8(%rax)
.L13:
	movq	-8(%rbp), %rax
	movq	(%rax), %rdx
	movq	-16(%rbp), %rax
	movq	(%rax), %rax
	subq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	tv_sub, .-tv_sub
	.globl	sock_get_port
	.type	sock_get_port, @function
sock_get_port:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movzwl	2(%rax), %eax
	movzwl	%ax, %eax
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	sock_get_port, .-sock_get_port
	.globl	create_IP4
	.type	create_IP4, @function
create_IP4:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	$4, %edi
	call	malloc
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movw	$2, (%rax)
	movl	-28(%rbp), %eax
	movzwl	%ax, %eax
	movl	%eax, %edi
	call	htons
	movl	%eax, %edx
	movq	-8(%rbp), %rax
	movw	%dx, 2(%rax)
	movq	-8(%rbp), %rax
	leaq	4(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	movl	$2, %edi
	movl	$0, %eax
	call	inet_pton
	movq	-8(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	k_ntop
	movq	%rax, %rdi
	call	cout
	movq	-16(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	create_IP4, .-create_IP4
	.globl	create_IP4_2
	.type	create_IP4_2, @function
create_IP4_2:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movw	$2, (%rax)
	movl	-28(%rbp), %eax
	movzwl	%ax, %eax
	movl	%eax, %edi
	call	htons
	movl	%eax, %edx
	movq	-8(%rbp), %rax
	movw	%dx, 2(%rax)
	movq	-8(%rbp), %rax
	leaq	4(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	movl	$2, %edi
	movl	$0, %eax
	call	inet_pton
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	create_IP4_2, .-create_IP4_2
	.section	.rodata
.LC1:
	.string	"src:"
.LC2:
	.string	"des:"
.LC3:
	.string	"\346\217\217\350\277\260\347\254\246\351\224\231\350\257\257:%d\n"
	.text
	.globl	echo_1
	.type	echo_1, @function
echo_1:
.LFB11:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$2352, %rsp
	movl	%edi, -2340(%rbp)
	movq	$.LC1, -8(%rbp)
	movq	$.LC2, -16(%rbp)
	cmpl	$1, -2340(%rbp)
	jg	.L20
	movl	-2340(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %edi
	call	exit
.L20:
	movl	$0, %eax
	movl	$16, %ecx
	leaq	-160(%rbp), %rdx
	movq	%rdx, %rdi
#APP
# 121 "/home/k/include/include.c" 1
	cld; rep; stosq
# 0 "" 2
#NO_APP
	movl	%edi, %eax
	movl	%ecx, %edx
	movl	%edx, -20(%rbp)
	movl	%eax, -24(%rbp)
.L26:
	movq	-160(%rbp), %rax
	orq	$2, %rax
	movq	%rax, -160(%rbp)
	movl	-2340(%rbp), %eax
	leal	63(%rax), %edx
	testl	%eax, %eax
	cmovs	%edx, %eax
	sarl	$6, %eax
	movl	%eax, %esi
	movslq	%esi, %rax
	movq	-160(%rbp,%rax,8), %rdi
	movl	-2340(%rbp), %eax
	cltd
	shrl	$26, %edx
	addl	%edx, %eax
	andl	$63, %eax
	subl	%edx, %eax
	movl	$1, %edx
	movl	%eax, %ecx
	salq	%cl, %rdx
	movq	%rdx, %rax
	orq	%rax, %rdi
	movq	%rdi, %rdx
	movslq	%esi, %rax
	movq	%rdx, -160(%rbp,%rax,8)
	leaq	-160(%rbp), %rax
	movl	$0, %r8d
	movl	$0, %ecx
	movl	$0, %edx
	movq	%rax, %rsi
	movl	$10, %edi
	call	select
	movq	-160(%rbp), %rax
	andl	$2, %eax
	testq	%rax, %rax
	je	.L21
	leaq	-1312(%rbp), %rax
	movl	$1024, %edx
	movq	%rax, %rsi
	movl	$1, %edi
	call	read
	movl	%eax, -28(%rbp)
	movl	-28(%rbp), %eax
	movslq	%eax, %rdx
	leaq	-1312(%rbp), %rcx
	movl	-2340(%rbp), %eax
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	write
.L21:
	movl	-2340(%rbp), %eax
	leal	63(%rax), %edx
	testl	%eax, %eax
	cmovs	%edx, %eax
	sarl	$6, %eax
	cltq
	movq	-160(%rbp,%rax,8), %rsi
	movl	-2340(%rbp), %eax
	cltd
	shrl	$26, %edx
	addl	%edx, %eax
	andl	$63, %eax
	subl	%edx, %eax
	movl	%eax, %ecx
	sarq	%cl, %rsi
	movq	%rsi, %rax
	andl	$1, %eax
	testq	%rax, %rax
	je	.L22
	leaq	-2336(%rbp), %rcx
	movl	-2340(%rbp), %eax
	movl	$1024, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read
	movl	%eax, -28(%rbp)
	cmpl	$0, -28(%rbp)
	je	.L23
	cmpl	$0, -28(%rbp)
	js	.L23
	cmpl	$10, -28(%rbp)
	jne	.L24
.L23:
	jmp	.L28
.L24:
	movq	-16(%rbp), %rax
	movl	$4, %edx
	movq	%rax, %rsi
	movl	$2, %edi
	call	write
	movl	-28(%rbp), %eax
	movslq	%eax, %rdx
	leaq	-2336(%rbp), %rax
	movq	%rax, %rsi
	movl	$2, %edi
	call	write
.L22:
	jmp	.L26
.L28:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	echo_1, .-echo_1
	.globl	echo_2
	.type	echo_2, @function
echo_2:
.LFB12:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$2112, %rsp
	movl	%edi, -2100(%rbp)
	movq	$.LC1, -8(%rbp)
	movq	$.LC2, -16(%rbp)
	movl	-2100(%rbp), %eax
	movl	%eax, -2096(%rbp)
	movw	$64, -2092(%rbp)
	movl	$1, -2088(%rbp)
	movw	$64, -2084(%rbp)
.L35:
	leaq	-2096(%rbp), %rax
	movl	$10000, %edx
	movl	$2, %esi
	movq	%rax, %rdi
	call	poll
	movl	%eax, -20(%rbp)
	movzwl	-2090(%rbp), %eax
	cwtl
	andl	$64, %eax
	testl	%eax, %eax
	je	.L30
	leaq	-2080(%rbp), %rcx
	movl	-2100(%rbp), %eax
	movl	$1024, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read
	movl	%eax, -20(%rbp)
	cmpl	$0, -20(%rbp)
	je	.L31
	cmpl	$0, -20(%rbp)
	js	.L31
	cmpl	$10, -20(%rbp)
	jne	.L32
.L31:
	jmp	.L37
.L32:
	movq	-16(%rbp), %rax
	movl	$4, %edx
	movq	%rax, %rsi
	movl	$2, %edi
	call	write
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	leaq	-2080(%rbp), %rax
	movq	%rax, %rsi
	movl	$2, %edi
	call	write
.L30:
	movzwl	-2082(%rbp), %eax
	cwtl
	andl	$64, %eax
	testl	%eax, %eax
	je	.L34
	leaq	-1056(%rbp), %rax
	movl	$1024, %edx
	movq	%rax, %rsi
	movl	$1, %edi
	call	read
	movl	%eax, -20(%rbp)
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	leaq	-1056(%rbp), %rcx
	movl	-2100(%rbp), %eax
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	write
.L34:
	jmp	.L35
.L37:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	echo_2, .-echo_2
	.section	.rodata
.LC4:
	.string	"\351\223\276\346\216\245\345\244\261\350\264\245"
	.text
	.globl	tcp_connect
	.type	tcp_connect, @function
tcp_connect:
.LFB13:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	$6, %edx
	movl	$1, %esi
	movl	$2, %edi
	call	socket
	movl	%eax, -4(%rbp)
	movq	-24(%rbp), %rcx
	movl	-4(%rbp), %eax
	movl	$32, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	connect
	movl	%eax, -8(%rbp)
	cmpl	$0, -8(%rbp)
	jns	.L39
	movl	$.LC4, %edi
	call	puts
.L39:
	movl	-4(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	tcp_connect, .-tcp_connect
	.globl	move_space
	.type	move_space, @function
move_space:
.LFB14:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L42
.L46:
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$32, %al
	jne	.L43
	movl	-20(%rbp), %eax
	movl	%eax, -24(%rbp)
	jmp	.L44
.L45:
	movl	-24(%rbp), %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	addq	%rax, %rdx
	movl	-24(%rbp), %eax
	cltq
	leaq	1(%rax), %rcx
	movq	-40(%rbp), %rax
	addq	%rcx, %rax
	movzbl	(%rax), %eax
	movb	%al, (%rdx)
	addl	$1, -24(%rbp)
.L44:
	movl	-24(%rbp), %eax
	movslq	%eax, %rbx
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen
	cmpq	%rax, %rbx
	jb	.L45
	subl	$1, -20(%rbp)
.L43:
	addl	$1, -20(%rbp)
.L42:
	movl	-20(%rbp), %eax
	movslq	%eax, %rbx
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen
	cmpq	%rax, %rbx
	jb	.L46
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE14:
	.size	move_space, .-move_space
	.globl	getkeyandvalue
	.type	getkeyandvalue, @function
getkeyandvalue:
.LFB15:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	movq	%rsi, -48(%rbp)
	movq	%rdx, -56(%rbp)
	movl	$0, -20(%rbp)
	jmp	.L48
.L55:
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$61, %al
	jne	.L49
	movl	$0, -28(%rbp)
	movl	$0, -24(%rbp)
	jmp	.L50
.L51:
	movl	-24(%rbp), %eax
	movslq	%eax, %rdx
	movq	-48(%rbp), %rax
	addq	%rax, %rdx
	movl	-24(%rbp), %eax
	movslq	%eax, %rcx
	movq	-40(%rbp), %rax
	addq	%rcx, %rax
	movzbl	(%rax), %eax
	movb	%al, (%rdx)
	addl	$1, -24(%rbp)
.L50:
	movl	-24(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jl	.L51
	movl	-20(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	jmp	.L52
.L53:
	movl	-28(%rbp), %eax
	movslq	%eax, %rdx
	movq	-56(%rbp), %rax
	addq	%rax, %rdx
	movl	-24(%rbp), %eax
	movslq	%eax, %rcx
	movq	-40(%rbp), %rax
	addq	%rcx, %rax
	movzbl	(%rax), %eax
	movb	%al, (%rdx)
	addl	$1, -28(%rbp)
	addl	$1, -24(%rbp)
.L52:
	movl	-24(%rbp), %eax
	movslq	%eax, %rbx
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen
	cmpq	%rax, %rbx
	jb	.L53
	jmp	.L47
.L49:
	addl	$1, -20(%rbp)
.L48:
	movl	-20(%rbp), %eax
	movslq	%eax, %rbx
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	strlen
	cmpq	%rax, %rbx
	jb	.L55
.L47:
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE15:
	.size	getkeyandvalue, .-getkeyandvalue
	.globl	read_line
	.type	read_line, @function
read_line:
.LFB16:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L57
.L60:
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	-32(%rbp), %rax
	leaq	(%rdx,%rax), %rcx
	movl	-20(%rbp), %eax
	movl	$1, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	cmpb	$10, %al
	jne	.L58
	jmp	.L56
.L58:
	addl	$1, -4(%rbp)
.L57:
	cmpl	$99, -4(%rbp)
	jle	.L60
.L56:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE16:
	.size	read_line, .-read_line
	.section	.rodata
.LC5:
	.string	"\350\257\273\345\217\226\350\267\257\345\276\204\345\244\261\350\264\245"
	.text
	.globl	getcfg
	.type	getcfg, @function
getcfg:
.LFB17:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$304, %rsp
	movq	%rdi, -296(%rbp)
	movq	%rsi, -304(%rbp)
	movl	$0, -4(%rbp)
	movl	$1, -8(%rbp)
	movq	-296(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	open
	movl	%eax, -12(%rbp)
	cmpl	$0, -12(%rbp)
	jns	.L62
	movl	$.LC5, %edi
	call	cout
.L62:
	leaq	-112(%rbp), %rax
	movl	$100, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset
	leaq	-112(%rbp), %rdx
	movl	-12(%rbp), %eax
	movq	%rdx, %rsi
	movl	%eax, %edi
	call	read_line
	movzbl	-112(%rbp), %eax
	testb	%al, %al
	jne	.L63
	movl	-12(%rbp), %eax
	movl	%eax, %edi
	call	close
	jmp	.L64
.L63:
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	move_space
	leaq	-288(%rbp), %rax
	movl	$50, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset
	leaq	-224(%rbp), %rax
	movl	$100, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset
	leaq	-224(%rbp), %rdx
	leaq	-288(%rbp), %rcx
	leaq	-112(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	getkeyandvalue
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,4), %rdx
	addq	%rdx, %rax
	salq	$2, %rax
	movq	%rax, %rdx
	movq	-304(%rbp), %rax
	addq	%rdx, %rax
	movl	$100, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset
	movl	-4(%rbp), %eax
	cltq
	leaq	1(%rax), %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,4), %rdx
	addq	%rdx, %rax
	salq	$2, %rax
	movq	%rax, %rdx
	movq	-304(%rbp), %rax
	addq	%rdx, %rax
	movl	$100, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	memset
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,4), %rdx
	addq	%rdx, %rax
	salq	$2, %rax
	movq	%rax, %rdx
	movq	-304(%rbp), %rax
	addq	%rax, %rdx
	leaq	-288(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	strcpy
	movl	-4(%rbp), %eax
	cltq
	leaq	1(%rax), %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,4), %rdx
	addq	%rdx, %rax
	salq	$2, %rax
	movq	%rax, %rdx
	movq	-304(%rbp), %rax
	addq	%rax, %rdx
	leaq	-224(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	strcpy
	addl	$2, -4(%rbp)
	jmp	.L62
.L64:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE17:
	.size	getcfg, .-getcfg
	.comm	p,8,8
	.globl	ss
	.section	.rodata
.LC6:
	.string	"xingke"
	.data
	.align 8
	.type	ss, @object
	.size	ss, 8
ss:
	.quad	.LC6
	.globl	s2
	.type	s2, @object
	.size	s2, 7
s2:
	.string	"xingke"
	.section	.rodata
.LC7:
	.string	"\345\255\227\347\254\246\344\270\262%c\n"
.LC8:
	.string	"\345\255\227\347\254\246\344\270\262%s\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB18:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movb	$101, -1(%rbp)
	movq	$ss, p(%rip)
	movq	p(%rip), %rax
	movq	(%rax), %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %esi
	movl	$.LC7, %edi
	movl	$0, %eax
	call	printf
	movq	p(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, %rsi
	movl	$.LC8, %edi
	movl	$0, %eax
	call	printf
	movq	ss(%rip), %rax
	addq	$5, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %esi
	movl	$.LC7, %edi
	movl	$0, %eax
	call	printf
	movq	ss(%rip), %rax
	addq	$5, %rax
	movb	$112, (%rax)
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE18:
	.size	main, .-main
	.ident	"GCC: (Debian 4.9.2-10) 4.9.2"
	.section	.note.GNU-stack,"",@progbits
