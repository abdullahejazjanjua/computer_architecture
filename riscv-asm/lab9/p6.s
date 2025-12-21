.data
.text
.globl main
main:
    li s0, 0 # sum
    li s1, 0 # i
    li s2, 10 # limit
    
loop:
    add s0, s0, s1 # sum = sum + i
    addi s1, s1, 1 # i = i + 1
    bge s1, s2, exit # jump to exit if i >= 10 
    j loop
    
exit:
    nop
    