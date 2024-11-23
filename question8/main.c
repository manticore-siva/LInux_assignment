/*
+---------------------------------------------------------------------------------------------------------------+
|                                                                                                               |
|   Author name : Siva prakasam V                                                                               |
|   Date        : 20/11/24                                                                                      |
|                                                                                                               |
|                                                                                                               |
|   Question                                                                                                    |
|   ========                                                                                                    |
| 														| 
|     Using `fcntl()` to Get and Set File Descriptor Flags							|
|   - Write a program that:											|
|     1. Opens a file  data.txt.										|
|     2. Uses `fcntl()` to get the current flags set on the file descriptor.					|
|     3. Changes the file descriptor flags to non-blocking (`O_NONBLOCK`), 					|
|         then tries to read the file to demonstrate non-blocking behavior.					|
|                                                                                                               |
+---------------------------------------------------------------------------------------------------------------+

*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int func_read(int );
int func_write(char *);
int func_error_handle(int );

char buf[1024];
#define BUF_SIZE 1024


int func_read(int fd)
{
	ssize_t read_byte;

	if ((read_byte = read(fd, buf, BUF_SIZE)) == -1){
	    func_error_handle(fd);

	}

	else {

		func_write(&buf[0]);
	}
}

int func_write(char *buf)
{
	if ((write(STDOUT_FILENO, buf, BUF_SIZE)) == -1) {
		
	      perror("");
	}
}

int func_error_handle(int fd){

		perror("");
		close(fd);
	        exit(-1);

}

int main(int argc, char *argv[]){


    int fd, pid, flags, std_error;

    if ((fd = open(argv[1], O_RDWR)) == -1){

	if((std_error = dup2(fd, STDERR_FILENO) == -1))
	{
	    perror("");
	    exit(1);
	}
	perror("");
    }
    else if (fd > 0){

    if ((flags = fcntl(fd, F_GETFL)) == -1)
    {
	func_error_handle(fd);
    }

    printf("%d\n",flags);

    printf("%d\n",F_GETFL);


    flags |= O_NONBLOCK;

    flags = fcntl(fd, F_SETFL, flags);

    printf("%d\n",flags);

    printf("%d\n",O_NONBLOCK);

    func_read(fd);

    }
    
    close(fd);
}
