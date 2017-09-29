#
# This program reads integers until -1 and reports their sum.
# 
	.text
	.globl	main
main:
	subu	$sp, $sp, 12		# Make room on the stack.
	sw	$ra, 0($sp)		# Save the return address.
	sw	$s0, 4($sp)		# Save $s0
	sw	$s1, 8($sp)		# Save $s1

	# Place a zero in the sum
	li	$s1, 0

	# Issume a prompt and read a string.
read:	
	li	$v0, 4			# String
	la	$a0, prompt
	syscall
	li	$v0, 5			# Read int, into $s0
	syscall
	move	$s0, $v0

	# See if it's a -1, and proceed to print if so
	li	$t0, -1
	beq	$s0, $t0, printtot

	# Add to total
	add	$s1, $s1, $s0

	# Round again
	j	read

printtot:
	# Print the total
	li	$v0, 4
	la	$a0, tmsg
	syscall
	li	$v0, 1
	move	$a0, $s1
	syscall
	li	$v0, 4
	la	$a0, nl
	syscall

	# Return
	lw	$s1, 8($sp)		# Restore $s1
	lw	$s0, 4($sp)		# Restore $s0
	lw	$ra, 0($sp)		# Restore the return address.
	addu	$sp, $sp, 12		# Pop the stack
	jr	$ra
# Note:	 The order in which the registers are restored is not important.
# What matters is that each value is restored to the correct offset of
# from $sp.  That is, since we put $s0 at 4($sp) on the way in, we must
# restore it from 4($sp) on the way out.  Also be sure to adjust the the
# stack by the same amount and in the opposite direction when you return.

	.data
prompt:	.asciiz	">"			# Input prompt
tmsg:	.asciiz	"The total is: "	# Total message.
nl:	.asciiz	"\n"			# Newline
