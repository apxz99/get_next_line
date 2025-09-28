#include "get_next_line.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd = open("hello",O_RDONLY);
	printf("%s",get_next_line(fd));
	return(0);
}
