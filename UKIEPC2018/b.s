	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14
	.globl	_init                   ## -- Begin function init
	.p2align	4, 0x90
_init:                                  ## @init
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	_a_s@GOTPCREL(%rip), %rax
	xorl	%ecx, %ecx
	movl	$200, %edx
                                        ## kill: def %rdx killed %edx
	movq	_b_s@GOTPCREL(%rip), %rsi
	movl	$10000, %edi            ## imm = 0x2710
	movl	%edi, %r8d
	movq	%rsi, %rdi
	movl	%ecx, %esi
	movq	%rdx, -8(%rbp)          ## 8-byte Spill
	movq	%r8, %rdx
	movq	%rax, -16(%rbp)         ## 8-byte Spill
	movl	%ecx, -20(%rbp)         ## 4-byte Spill
	callq	_memset
	movq	-16(%rbp), %rdi         ## 8-byte Reload
	movl	-20(%rbp), %esi         ## 4-byte Reload
	movq	-8(%rbp), %rdx          ## 8-byte Reload
	callq	_memset
	addq	$32, %rsp
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
	subq	$48, %rsp
	movl	$0, -4(%rbp)
	callq	_init
	leaq	L_.str(%rip), %rdi
	movq	_m@GOTPCREL(%rip), %rsi
	movq	_b@GOTPCREL(%rip), %rdx
	movq	_s@GOTPCREL(%rip), %rcx
	movb	$0, %al
	callq	_scanf
	movq	_m@GOTPCREL(%rip), %rcx
	movl	(%rcx), %r8d
	addl	$-1, %r8d
	movl	%r8d, (%rcx)
	movl	$0, -8(%rbp)
	movl	%eax, -28(%rbp)         ## 4-byte Spill
LBB1_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB1_3 Depth 2
	movq	_b@GOTPCREL(%rip), %rax
	movl	-8(%rbp), %ecx
	cmpl	(%rax), %ecx
	jge	LBB1_8
## %bb.2:                               ##   in Loop: Header=BB1_1 Depth=1
	leaq	L_.str.1(%rip), %rdi
	movq	_tmp@GOTPCREL(%rip), %rsi
	movb	$0, %al
	callq	_scanf
	movl	$0, -12(%rbp)
	movl	%eax, -32(%rbp)         ## 4-byte Spill
LBB1_3:                                 ##   Parent Loop BB1_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movq	_s@GOTPCREL(%rip), %rax
	movl	-12(%rbp), %ecx
	cmpl	(%rax), %ecx
	jge	LBB1_6
## %bb.4:                               ##   in Loop: Header=BB1_3 Depth=2
	leaq	L_.str.1(%rip), %rdi
	movq	_tmp@GOTPCREL(%rip), %rsi
	movb	$0, %al
	callq	_scanf
	movq	_b_s@GOTPCREL(%rip), %rsi
	movq	_tmp@GOTPCREL(%rip), %rdi
	movsbl	(%rdi), %ecx
	subl	$48, %ecx
	movslq	-8(%rbp), %rdi
	imulq	$200, %rdi, %rdi
	addq	%rdi, %rsi
	movslq	-12(%rbp), %rdi
	movl	%ecx, (%rsi,%rdi,4)
	movl	%eax, -36(%rbp)         ## 4-byte Spill
## %bb.5:                               ##   in Loop: Header=BB1_3 Depth=2
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -12(%rbp)
	jmp	LBB1_3
LBB1_6:                                 ##   in Loop: Header=BB1_1 Depth=1
	jmp	LBB1_7
LBB1_7:                                 ##   in Loop: Header=BB1_1 Depth=1
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	LBB1_1
LBB1_8:
	movl	$0, -16(%rbp)
LBB1_9:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB1_12 Depth 2
	movq	_b@GOTPCREL(%rip), %rax
	movl	-16(%rbp), %ecx
	cmpl	(%rax), %ecx
	jge	LBB1_20
## %bb.10:                              ##   in Loop: Header=BB1_9 Depth=1
	movq	_m@GOTPCREL(%rip), %rax
	movq	_b_s@GOTPCREL(%rip), %rcx
	movslq	-16(%rbp), %rdx
	imulq	$200, %rdx, %rdx
	addq	%rdx, %rcx
	movslq	(%rax), %rax
	cmpl	$0, (%rcx,%rax,4)
	je	LBB1_18
## %bb.11:                              ##   in Loop: Header=BB1_9 Depth=1
	movl	$0, -20(%rbp)
LBB1_12:                                ##   Parent Loop BB1_9 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movq	_s@GOTPCREL(%rip), %rax
	movl	-20(%rbp), %ecx
	cmpl	(%rax), %ecx
	jge	LBB1_17
## %bb.13:                              ##   in Loop: Header=BB1_12 Depth=2
	movq	_b_s@GOTPCREL(%rip), %rax
	movslq	-16(%rbp), %rcx
	imulq	$200, %rcx, %rcx
	addq	%rcx, %rax
	movslq	-20(%rbp), %rcx
	cmpl	$0, (%rax,%rcx,4)
	je	LBB1_15
## %bb.14:                              ##   in Loop: Header=BB1_12 Depth=2
	movq	_a_s@GOTPCREL(%rip), %rax
	movslq	-20(%rbp), %rcx
	movl	$1, (%rax,%rcx,4)
LBB1_15:                                ##   in Loop: Header=BB1_12 Depth=2
	jmp	LBB1_16
LBB1_16:                                ##   in Loop: Header=BB1_12 Depth=2
	movl	-20(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -20(%rbp)
	jmp	LBB1_12
LBB1_17:                                ##   in Loop: Header=BB1_9 Depth=1
	jmp	LBB1_18
LBB1_18:                                ##   in Loop: Header=BB1_9 Depth=1
	jmp	LBB1_19
LBB1_19:                                ##   in Loop: Header=BB1_9 Depth=1
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -16(%rbp)
	jmp	LBB1_9
LBB1_20:
	movl	$0, -24(%rbp)
LBB1_21:                                ## =>This Inner Loop Header: Depth=1
	movq	_s@GOTPCREL(%rip), %rax
	movl	-24(%rbp), %ecx
	cmpl	(%rax), %ecx
	jge	LBB1_27
## %bb.22:                              ##   in Loop: Header=BB1_21 Depth=1
	movq	_a_s@GOTPCREL(%rip), %rax
	movslq	-24(%rbp), %rcx
	cmpl	$0, (%rax,%rcx,4)
	je	LBB1_25
## %bb.23:                              ##   in Loop: Header=BB1_21 Depth=1
	movq	_m@GOTPCREL(%rip), %rax
	movl	-24(%rbp), %ecx
	cmpl	(%rax), %ecx
	je	LBB1_25
## %bb.24:                              ##   in Loop: Header=BB1_21 Depth=1
	movl	_ans(%rip), %eax
	addl	$1, %eax
	movl	%eax, _ans(%rip)
LBB1_25:                                ##   in Loop: Header=BB1_21 Depth=1
	jmp	LBB1_26
LBB1_26:                                ##   in Loop: Header=BB1_21 Depth=1
	movl	-24(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	jmp	LBB1_21
LBB1_27:
	leaq	L_.str.2(%rip), %rdi
	movl	_ans(%rip), %esi
	movb	$0, %al
	callq	_printf
	xorl	%esi, %esi
	movl	%eax, -40(%rbp)         ## 4-byte Spill
	movl	%esi, %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_ans                    ## @ans
.zerofill __DATA,__common,_ans,4,2
	.comm	_b_s,10000,4            ## @b_s
	.comm	_a_s,200,4              ## @a_s
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d %d %d"

	.comm	_m,4,2                  ## @m
	.comm	_b,4,2                  ## @b
	.comm	_s,4,2                  ## @s
L_.str.1:                               ## @.str.1
	.asciz	"%c"

	.comm	_tmp,1,0                ## @tmp
L_.str.2:                               ## @.str.2
	.asciz	"%d\n"


.subsections_via_symbols
