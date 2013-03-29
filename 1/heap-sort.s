	.file	"heap-sort.c"
	.comm	len,4,4
	.comm	heap_size,4,4
	.section	.rodata
.LC0:
	.string	"%d,"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$80, %esp
	movl	$3, 20(%esp)
	movl	$412, 24(%esp)
	movl	$5, 28(%esp)
	movl	$1, 32(%esp)
	movl	$2, 36(%esp)
	movl	$13, 40(%esp)
	movl	$12, 44(%esp)
	movl	$351, 48(%esp)
	movl	$23, 52(%esp)
	movl	$41, 56(%esp)
	movl	$31, 60(%esp)
	movl	$432, 64(%esp)
	movl	$321, 68(%esp)
	movl	$45, 72(%esp)
	movl	$14, len
	movl	len, %eax
	movl	%eax, heap_size
	leal	20(%esp), %eax
	movl	%eax, (%esp)
	call	create_heap
	leal	20(%esp), %eax
	movl	%eax, (%esp)
	call	heap_sort
	movl	$0, 76(%esp)
	jmp	.L2
.L3:
	movl	76(%esp), %eax
	movl	20(%esp,%eax,4), %edx
	movl	$.LC0, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	addl	$1, 76(%esp)
.L2:
	movl	len, %eax
	cmpl	%eax, 76(%esp)
	jl	.L3
	movl	$10, (%esp)
	call	putchar
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	heap_sort
	.type	heap_sort, @function
heap_sort:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	len, %eax
	subl	$1, %eax
	movl	%eax, -12(%ebp)
	jmp	.L5
.L6:
	movl	-12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$0, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	exchange_heap
	movl	heap_size, %eax
	subl	$1, %eax
	movl	%eax, heap_size
	movl	$0, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	max_heapify
	subl	$1, -12(%ebp)
.L5:
	cmpl	$0, -12(%ebp)
	jg	.L6
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	heap_sort, .-heap_sort
	.globl	max_heapify
	.type	max_heapify, @function
max_heapify:
.LFB2:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	12(%ebp), %eax
	addl	%eax, %eax
	movl	%eax, -16(%ebp)
	movl	12(%ebp), %eax
	addl	%eax, %eax
	addl	$1, %eax
	movl	%eax, -12(%ebp)
	movl	heap_size, %eax
	cmpl	%eax, -16(%ebp)
	jge	.L13
.L8:
	movl	12(%ebp), %eax
	sall	$2, %eax
	addl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-16(%ebp), %eax
	sall	$2, %eax
	addl	8(%ebp), %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jge	.L10
	movl	-16(%ebp), %eax
	movl	%eax, -20(%ebp)
	jmp	.L11
.L10:
	movl	12(%ebp), %eax
	movl	%eax, -20(%ebp)
.L11:
	movl	heap_size, %eax
	cmpl	%eax, -12(%ebp)
	jge	.L12
	movl	-20(%ebp), %eax
	sall	$2, %eax
	addl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	sall	$2, %eax
	addl	8(%ebp), %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jge	.L12
	movl	-12(%ebp), %eax
	movl	%eax, -20(%ebp)
.L12:
	movl	-20(%ebp), %eax
	cmpl	12(%ebp), %eax
	je	.L7
	movl	-20(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	exchange_heap
	movl	-20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	max_heapify
	jmp	.L7
.L13:
	nop
.L7:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	max_heapify, .-max_heapify
	.globl	exchange_heap
	.type	exchange_heap, @function
exchange_heap:
.LFB3:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	12(%ebp), %eax
	sall	$2, %eax
	addl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
	movl	12(%ebp), %eax
	sall	$2, %eax
	addl	8(%ebp), %eax
	movl	16(%ebp), %edx
	sall	$2, %edx
	addl	8(%ebp), %edx
	movl	(%edx), %edx
	movl	%edx, (%eax)
	movl	16(%ebp), %eax
	sall	$2, %eax
	addl	8(%ebp), %eax
	movl	-4(%ebp), %edx
	movl	%edx, (%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE3:
	.size	exchange_heap, .-exchange_heap
	.globl	create_heap
	.type	create_heap, @function
create_heap:
.LFB4:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	len, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -12(%ebp)
	jmp	.L16
.L17:
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	max_heapify
	subl	$1, -12(%ebp)
.L16:
	cmpl	$0, -12(%ebp)
	jns	.L17
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE4:
	.size	create_heap, .-create_heap
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
