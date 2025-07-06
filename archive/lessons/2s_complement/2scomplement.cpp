#include <stdint.h>
#include <stdio.h>

int main()
{
    int64_t s64;

    int16_t upper = 0x0000a5a5;
    uint32_t lower = 0xa5a5a5a5;

    bool is_neg = !!((1<<15) & upper);
    bool is_neg = !!(0x00008000 & upper);
    if (is_neg) {
        upper |= 0xffff0000;
        upper = upper | 0xffff0000;
    }


    s64 = ((int64_t)upper<<32) | lower;
    //s64 = (upper<<32) | lower;

    printf("0x%016llx\n", (long long)s64);
}
