.data
.align 2
var1:  .byte 15
var2:  .byte 45
TextA: .asciiz "the result is (GCD):\n"
.text
.align 2
.globl main
.ent main
main:

lbu $s0,var1 #load address of a
lbu $s1,var2 #load address of b
beq $s0,$zero,case1
beq $s1,$zero,case2
addi $t2,$zero,1
Loop:
beq $s0,$s1,Exit # while(a!=b)
slt $t1,$s0,$s1 # if (a<b)
bne $t2,$t1,Exit1 # else...
move $t3,$s0 # tmp=a;
move $s0,$s1 # a=b;
move $s1,$t3 # b=tmp;
j Loop
Exit1:
sub $s0,$s0,$s1 #else : a=a-b;
j Loop
case1: move $t0,$s0 # res=a;
case2: move $t0,$s1 # res =b;
Exit:
move $t0,$s0 #res=a;
la $a0, TextA #load address of TextA
li $v0,4 # print TextA
syscall
li $v0,1 #command: print integer
move $a0,$t0 #print res
syscall
.end main
