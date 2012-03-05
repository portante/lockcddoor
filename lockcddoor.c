#include <sys/ioctl.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/cdrom.h>
#include <string.h>
#include <libgen.h>

int main(int argc, char *argv[])
{
    int fd;
    int lock;

    char *cmd1;

    cmd1 = basename(argv[0]);

    if (!strcmp(cmd1, "cd-lock"))
        lock = 1;
    else if (!strcmp(cmd1, "cd-unlock"))
        lock = 0;
    else {
        printf("program must be called cd-lock or cd-unlock\n");
        return 1;
    }

    if (argc != 2) {
        printf("not enough options\nUsage:\n\t%s device\n", cmd1);
        return 2;
    }
            

    if ((fd = open(argv[1], O_RDONLY)) <= 0) {
        perror("open failed");
        return 3;
    }

    if (ioctl(fd, CDROM_LOCKDOOR, lock)) {
        perror("ioctl failed");
        return 4;
    }

    return 0;
}
