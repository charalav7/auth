.data
.align 2
.globl Test
Test: .word 1
	.word 3
	.word 5
	.word 7
	.word 90
	.word 8
	.word 6
	.word 4
	.word 2
	.word 100
TextA: .asciiz "Lab 3, Home Assignment 1\n"
TextB: .asciiz "The max is \n"
TextC: .asciiz "\nDone\n"

.text
.align 2

.globl FindMax
.ent FindMax
FindMax:
	subu $sp, $sp, 24 # Reserve a new 24 byte stack frame
	sw $s0, 0($sp) # Save value of s0 on the stack
	sw $s1, 4($sp) # Save value of s1 on the stack
sw $a0, 8($sp) # Save the address of the vector
	sw $a1, 12($sp) # Save the number n
	sw $s2, 16($sp)
	sw $s3, 20($sp)
	
	
	
	lw $t0, 0($a0)  # load A[0]
	add $v0,$zero,$t0  # $v0=max, max=A[0]
	addi $t1,$t1,1  # $t1=i, i=1
	addi $t3,$t3,1  # $t3=1
	addi $a1,$a1,1  # n=10 gia na parw kai ta deka stoixeia tou pinaka
	Loop: slt $t2,$t1,$a1 # $t2=1 if i<n
	bne $t2,$t3, Exit  # while (i<n)
	sll $t4,$t1,2  # $t4= 4*i
	add $t4,$t4,$a0  # $t4=address of A[i]
	lw $t0, 0($t4)  # $t0=A[i]
	slt $t2,$v0,$t0  # $t2=1 if max<A[i]
	bne $t2,$t3, Exit1  # if (max<A[i])
	add $v0,$zero,$t0 # epistrofi tou max
	j Exit1
	Exit1: addi $t1,$t1,1
	       j Loop
	Exit: jr $ra

	 

	lw $s1, 4($sp) # Restore old value of s1
	lw $s0, 0($sp) # Restore old value of s0
	lw $s2, 16($sp) # Restore s2
	lw $s3, 20($sp) # Restore s3
	addu $sp, $sp, 24 # Pop the stack frame
	jr $ra # Jump back to calling routine
.end FindMax

.text
.align 2
.globl main
.ent main
main: 	subu $sp, $sp, 32 # Reserve a new 32 byte stack frame
	sw $ra, 20($sp) # Save old value of return address
	sw $fp, 16($sp) # Save old value of frame pointer
	addu $fp, $sp, 28 # Set up new frame pointer
	
	la $a0, TextA # Load address to welcome text
	li $v0, 4     
      syscall
      
	la $a0, Test # Load address to vector
	li $a1, 9 #Number n
	jal FindMax # Call FindMax subroutine
	move $t0, $v0	

	la $a0, TextB # Load address to result text
	li $v0, 4
	syscall 
	
	li $v0, 1
      	move    $a0, $t0
      syscall

	la $a0, TextC # Load address to goodbye text
	li $v0, 4
	syscall

	lw $fp, 16($sp) # Restore old frame pointer
	lw $ra, 20($sp) # Restore old return address
	addu $sp, $sp, 32 # Pop stack frame
	jr $ra
.end main
