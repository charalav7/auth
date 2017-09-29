	.text
	.globl main

main:
	subu	$sp, $sp, 12		# Make room on the stack.
	sw	$ra, 0($sp)		# Save the return address.
	sw	$s0, 4($sp)		# Save $s0
	sw	$s1, 8($sp)		# Save $s1

	# Place a zero in the sum
	li	$s0, 0

	#Read a, b, c
read:
	li $v0, 4
	la $a0, prompt
	syscall
	
	li $v0, 5
	syscall
	move $s1, $v0
	
	li $v0, 4
	la $a0, prompt
	syscall
	
	li $v0, 5
	syscall
	move $s2, $v0
	
	li $v0, 4
	la $a0, prompt
	syscall
	
	li $v0, 5
	syscall
	move $s3, $v0
	
check_a: #if(a<b)
	bge $s1, $s2, check_b
	move $t0, $s2
	move $s2, $s1
	move $s1, $t0

check_b: #if(b<c)		
	bge $s2, $s3, ComputeSum 
	move $t0, $s3
	move $s3, $s2
	move $s2, $t0	
	
ComputeSum:
	add $s0, $s1, $s2

print_res:
	li	$v0, 4
	la	$a0, tmsg
	syscall
	li	$v0, 1
	move	$a0, $s0
	syscall

	# Return
	lw	$s1, 8($sp)		# Restore $s1
	lw	$s0, 4($sp)		# Restore $s0
	lw	$ra, 0($sp)		# Restore the return address.
	addu	$sp, $sp, 12		# Pop the stack
	jr	$ra

	.data
prompt:	.asciiz	">"			# Input prompt
tmsg:	.asciiz	"The sum is = "	# message.
nl:	.asciiz	"\n"			# Newline


