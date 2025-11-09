#include <stdint.h>
#include <stddef.h>
#include <unistd.h>

void mywrite(uint32_t fd, const char *buff, size_t count);
void myprintf(const char *buff, size_t count);