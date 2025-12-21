.data
    a: .word 10
    b: .word 10
    sum: .word 0
    difference: .word 0
    multiply: .word 0
    division: .word 0
.text
.globl main
main:
    lw t0, a
    lw t1, b
    
    add t2, t0, t1
    la s1, sum
    sw t2, 0(s1)
    
    sub t2, t0, t1
    # sw t2, <label> -> Also works (pseudo-instruction) but IDE rooti hai
    la s1, difference
    sw t2, 0(s1)
    
    mul t2, t0, t1
    la s1, multiply
    sw t2, 0(s1)
    
    div t2, t0, t1
    la s1, division
    sw t2, 0(s1)
    
    
    