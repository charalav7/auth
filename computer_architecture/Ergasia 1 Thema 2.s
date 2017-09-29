.data
.align 2
TextA: .asciiz "\nThe following character was typed:\n"

.text
.align 2
.globl main
.ent main
main: 
	subu $sp, $sp, 32 # Reserve a new 32 byte stack frame
	sw $ra, 20($sp) # Save old value of return address
	sw $fp, 16($sp) # Save old value of frame pointer
	sw $t0, 0($sp)
	sw $t1, 4($sp)
	sw $t2, 8($sp)
	sw $t3, 12($sp)
	addu $fp, $sp, 28 # Set up new frame pointer

	li $t3, 10 #Number of iterations
	lui $t0, 0xFFFF #$ t0 = 0xFFFF0000;

WaitLoop: 
	lw $t1, 0($t0) # $t1 = *($t0);
	andi $t1, $t1, 0x0001 # $t1 &= 0x00000001;
	beq $t1, $zero, WaitLoop # } while ($t1 == 0);
	lw $t2, 4($t0) # $t2 = *($t0 + 1); 

	la $a0, TextA # print text
	li $v0, 4     
      syscall

WaitLoop2: 
	lw $t1, 8($t0) #    $t1 = *($t0 + 2);
	andi $t1, $t1, 0x0001 #    $t1 &= 0x00000001;
	beq $t1, $zero, WaitLoop2 # } while ($t1 == 0);
	sw $t2, 12($t0) # *($t0 + 3) = $t2; 

	subu $t3,$t3,1
	bgtz $t3, WaitLoop

	lw $t0, 0($sp)
	lw $t1, 4($sp)
	lw $t2, 8($sp)
	lw $t3, 12($sp)
	lw $fp, 16($sp) # Restore old frame pointer
	lw $ra, 20($sp) # Restore old return address
	addu $sp, $sp, 32 # Pop stack frame
	jr $ra
.end main
