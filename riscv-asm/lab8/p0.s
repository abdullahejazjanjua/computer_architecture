.data
.text
.globl main
main:
    lui t0, 0x12345 # Load 0x12345 into t0 and move to upper 20 bits 0x12345000
    addi t0, t0, 0x678 