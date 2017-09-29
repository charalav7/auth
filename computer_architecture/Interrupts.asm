.data
.align 2
TextA: .asciiz "\nFinishing.....\n"


.text
.globl main
.ent main
main: 
	subu $sp, $sp, 32 
	sw $ra, 20($sp) 
	sw $fp, 16($sp) 
	sw $t0, 0($sp)
	sw $t1, 4($sp)
	sw $t2, 8($sp)
	sw $t3, 12($sp)
	addu $fp, $sp, 28 

	#li $t3, 10 
	lui $t0, 0xFFFF  
	li $t1, 2 
	sw $t1, 0($t0) 
	li $t1, 0x0000fffd 
	mtc0 $t1, $12 
	
	
waitloop:	
	b waitloop
	
	la $a0, TextA 
	li $v0, 4     
      syscall


	lw $t0, 0($sp)
	lw $t1, 4($sp)
	lw $t2, 8($sp)
	lw $t3, 12($sp)
	lw $fp, 16($sp) 
	lw $ra, 20($sp) 
	addu $sp, $sp, 32 
	jr $ra
.end main
