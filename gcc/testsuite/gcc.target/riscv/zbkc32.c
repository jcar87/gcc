/* { dg-do compile } */
/* { dg-options "-O2 -march=rv32gc_zbkc -mabi=ilp32" } */
/* { dg-skip-if "" { *-*-* } { "-g" "-flto"} } */
#include <stdint-gcc.h>

uint32_t foo1(uint32_t rs1, uint32_t rs2)
{
    return __builtin_riscv_clmul(rs1, rs2);
}

uint32_t foo2(uint32_t rs1, uint32_t rs2)
{
    return __builtin_riscv_clmulh(rs1, rs2);
}

/* { dg-final { scan-assembler-times "clmul\t" 1 } } */
/* { dg-final { scan-assembler-times "clmulh" 1 } } */
