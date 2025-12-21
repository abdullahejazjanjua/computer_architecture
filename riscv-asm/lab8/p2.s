.data
    op1: .word 10
    op2: .word 20
.text
.globl main
main:
    la s0, op1 # Load address of op1 into s0
    
    
    lw t0, 0(s0) # Load value at address op1
    lw t1, 4(s0) # Load value at address op1 + 4 or op2
    
    add t2, t1, t0
    sub t3, t1, t0
    
    