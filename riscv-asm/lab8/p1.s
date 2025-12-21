.data
    op1: .word 10
    op2: .word 20
.text
.globl main
main:
    lw t0, op1
    lw t1, op2
    
    add t2, t1, t0
    sub t3, t1, t0
    
    