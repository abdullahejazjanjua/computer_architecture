.data
.text
.globl main
main:
    li s0, 10
    add s1, s1, zero
    
    
loop:
    addi s1, s1, 1
    addi s0, s0, -1
    bne s0, zero, loop