.data
    arr: .word 4 
         .word 2
         .word 10
 arr_size: .word 3
.text
.globl main
main:
    la s1, arr
    lw s2, arr_size
    
    li s0, 0 # sum
    li t0, 0 # i
    
loop:
    bge t0, s2, exit # if i >= 3, exit
    
    lw t1, 0(s1) # load value from arr[0]
    
    andi t3, t1, 1 
    bne t3, zero, skip # if arr[0] & 1 != 0 jump to skip
    add s0, s0, t1  # else add arr[0] to sum 
    
    skip:
    addi s1, s1, 4
    addi, t0, t0, 1
    
    j loop
    
exit:
    nop