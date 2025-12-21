.data
.text
.globl main
main:
    li t2, -50
    li t3, 3
    div t0, t2, t3 # t0 = t2 / t3
    rem t1, t2, t3 # t1 = t2 % t3