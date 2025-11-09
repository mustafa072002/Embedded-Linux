
#include "myprintf.h"

void mywrite(uint32_t fd, const char *buff, size_t count)
{
    asm volatile(
        "mov $1, %%rax\n" // put 1 syscall id for write
        "mov %0, %%rdi\n" // put fd in rdi
        "mov %1, %%rsi\n" // put buff in rsi
        "mov %2, %%rdx\n" // put count in rdx
        "syscall\n"
        :
        : "r"((uint64_t)fd), "r"(buff), "r"(count)
        : "%rax", "%rdi", "%rsi", "%rdx");
}

void myprintf(const char *buff, size_t count)
{
    mywrite(1, buff, count);
}