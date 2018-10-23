	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14
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
	leaq	L_.str(%rip), %rdi
	movq	_m@GOTPCREL(%rip), %rsi
	movq	_b@GOTPCREL(%rip), %rdx
	movq	_s@GOTPCREL(%rip), %rcx
	movl	$0, -4(%rbp)
	movb	$0, %al
	callq	_scanf
	movq	_m@GOTPCREL(%rip), %rcx
	movq	_b_s@GOTPCREL(%rip), %rdx
	xorl	%esi, %esi
	movl	$400, %r8d              ## imm = 0x190
	movl	%r8d, %edi
	movq	%rdi, -24(%rbp)         ## 8-byte Spill
	movq	%rdx, %rdi
	movq	-24(%rbp), %rdx         ## 8-byte Reload
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	movq	%rcx, -40(%rbp)         ## 8-byte Spill
	callq	_memset
	movq	-40(%rbp), %rcx         ## 8-byte Reload
	movl	(%rcx), %eax
	addl	$-1, %eax
	movl	%eax, (%rcx)
	movl	$0, -8(%rbp)
LBB0_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_3 Depth 2
	movq	_b@GOTPCREL(%rip), %rax
	movl	-8(%rbp), %ecx
	cmpl	(%rax), %ecx
	jge	LBB0_8
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	leaq	L_.str.1(%rip), %rdi
	movq	_tmp@GOTPCREL(%rip), %rsi
	movb	$0, %al
	callq	_scanf
	movl	$0, -12(%rbp)
	movl	%eax, -44(%rbp)         ## 4-byte Spill
LBB0_3:                                 ##   Parent Loop BB0_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movq	_s@GOTPCREL(%rip), %rax
	movl	-12(%rbp), %ecx
	cmpl	(%rax), %ecx
	jge	LBB0_6
## %bb.4:                               ##   in Loop: Header=BB0_3 Depth=2
	leaq	L_.str.1(%rip), %rdi
	movq	_tmp@GOTPCREL(%rip), %rsi
	movb	$0, %al
	callq	_scanf
	movq	_b_s@GOTPCREL(%rip), %rsi
	movq	_tmp@GOTPCREL(%rip), %rdi
	movsbl	(%rdi), %ecx
	subl	$48, %ecx
	movl	-12(%rbp), %edx
	movl	%ecx, -48(%rbp)         ## 4-byte Spill
	movl	%edx, %ecx
                                        ## kill: def %cl killed %ecx
	movl	-48(%rbp), %edx         ## 4-byte Reload
	shll	%cl, %edx
	movslq	%edx, %rdi
	movslq	-8(%rbp), %r8
	orq	(%rsi,%r8,8), %rdi
	movq	%rdi, (%rsi,%r8,8)
	movl	%eax, -52(%rbp)         ## 4-byte Spill
## %bb.5:                               ##   in Loop: Header=BB0_3 Depth=2
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -12(%rbp)
	jmp	LBB0_3
LBB0_6:                                 ##   in Loop: Header=BB0_1 Depth=1
	jmp	LBB0_7
LBB0_7:                                 ##   in Loop: Header=BB0_1 Depth=1
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	LBB0_1
LBB0_8:
	movl	$0, -16(%rbp)
LBB0_9:                                 ## =>This Inner Loop Header: Depth=1
	movq	_b@GOTPCREL(%rip), %rax
	movl	-16(%rbp), %ecx
	cmpl	(%rax), %ecx
	jge	LBB0_14
## %bb.10:                              ##   in Loop: Header=BB0_9 Depth=1
	movl	$1, %eax
	movq	_m@GOTPCREL(%rip), %rcx
	movq	_b_s@GOTPCREL(%rip), %rdx
	movslq	-16(%rbp), %rsi
	movq	(%rdx,%rsi,8), %rdx
	movl	(%rcx), %ecx
                                        ## kill: def %cl killed %ecx
	shll	%cl, %eax
	movslq	%eax, %rsi
	andq	%rsi, %rdx
	cmpq	$0, %rdx
	je	LBB0_12
## %bb.11:                              ##   in Loop: Header=BB0_9 Depth=1
	movq	_b_s@GOTPCREL(%rip), %rax
	movslq	-16(%rbp), %rcx
	movq	(%rax,%rcx,8), %rax
	orq	_ans(%rip), %rax
	movq	%rax, _ans(%rip)
LBB0_12:                                ##   in Loop: Header=BB0_9 Depth=1
	jmp	LBB0_13
LBB0_13:                                ##   in Loop: Header=BB0_9 Depth=1
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -16(%rbp)
	jmp	LBB0_9
LBB0_14:
	leaq	L_.str.2(%rip), %rdi
	movl	$1, %eax
	movq	_m@GOTPCREL(%rip), %rcx
	movl	(%rcx), %ecx
                                        ## kill: def %cl killed %ecx
	shll	%cl, %eax
	xorl	$-1, %eax
	movslq	%eax, %rdx
	andq	_ans(%rip), %rdx
	movq	%rdx, _ans(%rip)
	movq	_ans(%rip), %rdx
	movl	%edx, %eax
	movl	%eax, %esi
	shrl	%esi
	andl	$1431655765, %esi       ## imm = 0x55555555
	subl	%esi, %eax
	movl	%eax, %esi
	andl	$858993459, %esi        ## imm = 0x33333333
	shrl	$2, %eax
	andl	$858993459, %eax        ## imm = 0x33333333
	addl	%eax, %esi
	movl	%esi, %eax
	shrl	$4, %eax
	addl	%eax, %esi
	andl	$252645135, %esi        ## imm = 0xF0F0F0F
	imull	$16843009, %esi, %eax   ## imm = 0x1010101
	shrl	$24, %eax
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	xorl	%esi, %esi
	movl	%eax, -56(%rbp)         ## 4-byte Spill
	movl	%esi, %eax
	addq	$64, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_ans                    ## @ans
.zerofill __DATA,__common,_ans,8,3
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d %d %d"

	.comm	_m,4,2                  ## @m
	.comm	_b,4,2                  ## @b
	.comm	_s,4,2                  ## @s
	.comm	_b_s,400,4              ## @b_s
L_.str.1:                               ## @.str.1
	.asciz	"%c"

	.comm	_tmp,1,0                ## @tmp
L_.str.2:                               ## @.str.2
	.asciz	"%d\n"


.subsections_via_symbols
