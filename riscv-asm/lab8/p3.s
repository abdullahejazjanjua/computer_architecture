.data
    op1: .word 10
    op2: .word 20
.text
.globl main
main:
    # No need for label as we are loading from offset    
    lw t0, op1 # Load value at address op1 
    lw t1, op2 # Load value at address op2
    
    add t2, t1, t0
    sub t3, t1, t0
    
    