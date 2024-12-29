#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
int main()
{
    int fd = open("deneme.txt" , O_RDWR | O_CREAT);
    char *eben;
    int i = 0;
    while((eben = get_next_line(fd)))
    {
        printf("%s",eben);
        free(eben);
    }
    close(fd);
    return (0);
}
