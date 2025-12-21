.data
.text
.globl main
main:
    li t1, 20 # b
    li t2, 10 # c
    
    sub t0, t1, t2 # a = b - c
     
     li t1, 10 # g
     li t2, 20 # h
     li t3, 10 # i
     li t4, 20 # j
     
     add t1, t1, t2 # g + h
     add t3, t3, t4 # i + j
     
     sub t4, t1, t3 # (g+h) - (i+j)
     
    