.data
.text
.globl main
main:
    lui t0, 0x12345
    addi t0, t0, 0x678
    
    li t1, 2
    
    bne t1, zero, target  # if t1 != 0
    xori t0, t0, 0xFF
    srli t0, t0, 2
    
    j exit
    
target:
    or s2, t0, t1
    
exit:
    li a7, 10
    ecall