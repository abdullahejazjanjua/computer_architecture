.data
.text
.global main
main:
    li s0, 1 
    li s1, 2
    li s3, 3
    li s4, 4
    
    bne s0, s1, L1
    add s2, s3, s4
    
L1:
    sub s0, s1, s4
