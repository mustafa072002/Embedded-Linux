#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    if (argv[1][0] != '0' && argv[1][0] != '1')
    {
        printf("Invalid Argument\n");
    }
    else
    {
        int fd = open("/sys/class/leds/input3::capslock/brightness", O_RDWR);
        write(fd, argv[1], 1);
        close(fd);
    }
}