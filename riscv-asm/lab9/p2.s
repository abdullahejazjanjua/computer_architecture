.data
.text
.globl main
main:
    li s0, 8
    li s1, 2
    
    slli s1, s1, 2
    
    bne s0, s1, target
    addi s1, s1, 2
    addi s1, s1, 2
    j exit
    
target:
    add s1, s0, s1
        
exit:
    nop