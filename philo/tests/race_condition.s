	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15, 6
	.globl	_routine                ## -- Begin function routine
	.p2align	4, 0x90
_routine:                               ## @routine
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$0, -4(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$1000000, -4(%rbp)      ## imm = 0xF4240
	jge	LBB0_4
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movq	_mutex@GOTPCREL(%rip), %rdi
	callq	_pthread_mutex_lock
## %bb.3:                               ##   in Loop: Header=BB0_1 Depth=1
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -4(%rbp)
	jmp	LBB0_1
LBB0_4:
	movq	_mutex@GOTPCREL(%rip), %rdi
	movl	_mails(%rip), %eax
	addl	$1, %eax
	movl	%eax, _mails(%rip)
	callq	_pthread_mutex_unlock
	xorl	%ecx, %ecx
	movl	%ecx, %edx
	movl	%eax, -8(%rbp)          ## 4-byte Spill
	movq	%rdx, %rax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	movq	_mutex@GOTPCREL(%rip), %rax
	xorl	%ecx, %ecx
	movl	%ecx, %edx
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rax, %rdi
	movq	%rdx, %rsi
	callq	_pthread_mutex_init
	xorl	%ecx, %ecx
	movl	%ecx, %edx
	leaq	_routine(%rip), %rsi
	leaq	-24(%rbp), %rdi
	movq	%rsi, -40(%rbp)         ## 8-byte Spill
	movq	%rdx, %rsi
	movq	-40(%rbp), %r8          ## 8-byte Reload
	movq	%rdx, -48(%rbp)         ## 8-byte Spill
	movq	%r8, %rdx
	movq	-48(%rbp), %rcx         ## 8-byte Reload
	movl	%eax, -52(%rbp)         ## 4-byte Spill
	callq	_pthread_create
	cmpl	$0, %eax
	je	LBB1_2
## %bb.1:
	movl	$1, -4(%rbp)
	jmp	LBB1_9
LBB1_2:
	xorl	%eax, %eax
	movl	%eax, %ecx
	leaq	_routine(%rip), %rdx
	leaq	-32(%rbp), %rdi
	movq	%rcx, %rsi
	callq	_pthread_create
	cmpl	$0, %eax
	je	LBB1_4
## %bb.3:
	movl	$2, -4(%rbp)
	jmp	LBB1_9
LBB1_4:
	xorl	%eax, %eax
	movl	%eax, %esi
	movq	-24(%rbp), %rdi
	callq	_pthread_join
	cmpl	$0, %eax
	je	LBB1_6
## %bb.5:
	movl	$3, -4(%rbp)
	jmp	LBB1_9
LBB1_6:
	xorl	%eax, %eax
	movl	%eax, %esi
	movq	-32(%rbp), %rdi
	callq	_pthread_join
	cmpl	$0, %eax
	je	LBB1_8
## %bb.7:
	movl	$4, -4(%rbp)
	jmp	LBB1_9
LBB1_8:
	movq	_mutex@GOTPCREL(%rip), %rdi
	callq	_pthread_mutex_destroy
	movl	_mails(%rip), %esi
	leaq	L_.str(%rip), %rdi
	movl	%eax, -56(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	movl	$0, -4(%rbp)
LBB1_9:
	movl	-4(%rbp), %eax
	addq	$64, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_mails                  ## @mails
.zerofill __DATA,__common,_mails,4,2
	.comm	_mutex,64,3             ## @mutex
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Number of mails: %d\n"

.subsections_via_symbols
