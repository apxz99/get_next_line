#include "get_next_line.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	char *str = calloc(1, 1);
	int fd1 = open("get_next_line.h", O_RDONLY);
	while (str != NULL) {
		free(str);
		str = get_next_line(fd1);
		if (str)
    		printf("%s", str);
	}
	free(str);
	close(fd1);
	return 0;
}
