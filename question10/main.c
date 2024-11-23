/*
+------------------------------------------------------------------------------------------------------------------------------------+
|                                                                                                                                    |
|   Author name : Siva prakasam V                                                                                                    |
|   Date        : 20/11/24                                                                                                           |
|                                                                                                                                    |
|                                                                                                                                    |
|   Question                                                                                                                         |
|   ========                                                                                                                         |
|									                       					     |
|  Process Creation and File Descriptor Inheritance                                                                                  |
|   - Write a C program that:													     |
|     1. Creates a child process using `fork()`.								                     |	
|     2. In the child process, open a file `child.txt`, write some data, and close it.                                               |
|     3. In the parent process, after the `fork()`, open a file `parent.txt` and write some data.                                    |
|     4. Demonstrate that the file descriptors are inherited by the child process but can be closed independently by both processes. |
|																     |
+------------------------------------------------------------------------------------------------------------------------------------+

*/


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 50

char buf[BUF_SIZE] = {0};

int main (int argc, char *argv[])
{

    char buf[BUF_SIZE];
    int fd, pid;
    ssize_t write_ret, read_ret;

    if ((pid =  fork()) == -1)
    {
	perror("fork ");
	exit(-1);
    }

    if (pid == 0 ){


	if ((fd = open("child.txt", O_CREAT )) == -1){
	
	    perror("child open");
	    return -2;

	}
	else {

		if ((read_ret = read(fd, buf, BUF_SIZE)) == -1 )
		{
		    perror("child read ");
		    close(fd);
		    return -3;
		}
		else
		{

		    if ((write_ret = write(STDOUT_FILENO, buf, BUF_SIZE)) == -1)
		    {
			perror("write from child ");
			return -4;
		        close(fd);
		    }

		    close(fd);
		}
	}
    }

    if (pid > 0 ){

        if ((fd = open("parent.txt", O_RDWR)) == -1){

            perror("parent open");
            return -4;

        }
        else {

                if ((read_ret = read(fd, buf, BUF_SIZE)) == -1 )
                {
                    perror("child write ");
                    return -5;
                }
                else
                {
                    if ((write_ret = write(STDOUT_FILENO, buf, strlen(buf))) == -1 )
		    {
			perror("write from  parent");
			return -6;
		    }

                    close(fd);
                }
        }
    }
	
}

