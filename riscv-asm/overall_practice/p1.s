.data
    my_array: .word 0, 0, 0, 0, 0
.text
.globl main
main:
    li s0, 0         # i
    li s1, 5         # limit
    la s2, my_array
    
loop:
    bge s0, s1, exit # i >= 5
    
    slli t0, s0, 2   # i = i * 4
    addi t1, t0, -1  # data = i - 1
    add t2, s2, t0   # i + array_sum
    sw t1, 0(t2)     # mem[i]  = data
    
    addi s0, s0, 1   # i++
    j loop

exit:
    li a7, 10        # Standard exit
    ecall