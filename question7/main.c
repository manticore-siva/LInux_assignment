/*
+---------------------------------------------------------------------------------------------------------------+
|                                                                                                               |
|   Author name : Siva prakasam V                                                                               |
|   Date        : 20/11/24                                                                                      |
|                                                                                                               |
|                                                                                                               |
|   Question                                                                                                    |
|   ========                                                                                                    |
|    Redirecting Output to a File Using `dup2()`								|
|   - Write a C program that:											|
|    1. Redirects `stdout` to a file `output.txt` using `dup2()`.						|
|    2. Any `printf()` or other standard output operations should write to `output.txt` instead of the terminal.|
|    3. Ensure that you restore `stdout` to its original value at the end.					|
|														|
+---------------------------------------------------------------------------------------------------------------+

*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#define BUF_SIZE 50

int main(int argc, char *argv[]){

    int fd, new_fd;
    ssize_t read_ret, write_ret;
    char buf[BUF_SIZE] = {0};

    if ((fd = open(argv[1], O_RDWR)) == -1)
    {
	perror("Open");
	return -1;
    }

    int pid = fork();

    // child process
    if (pid == 0) {
		
//		read_ret = read(fd, buf, BUF_SIZE);

		if ( 1 != (new_fd = dup2(fd, 1)))
			{
				perror("dup2");
				goto ERROR;
			}
		printf("hiii\n");
    }

   // Parent process
    else if (pid > 0){

		write(new_fd, buf, BUF_SIZE);
		close (fd);
		close (new_fd);
		return 0;
    }
ERROR:
    perror("");
    close(fd);
    close(new_fd);
}
