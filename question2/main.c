/*

+------------------------------------------------------------------------------------------------------------+
+													     +
+   Author name : Siba prakasam V									     +
+   Date        : 20/11/24									   	     +
+													     +
+													     +
+   Question 												     +
+   ========												     +
+   Check and Handle File Descriptor Errors								     +
+   ---------------------------------------								     +
+   - Write a C program that:										     +
+     1. Attempts to open a non-existent file.								     +
+     2. Checks whether the file descriptor returned by `open()` is valid or not (i.e., checks for `-1`).    +
+     3. Prints an appropriate error message if the file cannot be opened.				     +
+													     +
+------------------------------------------------------------------------------------------------------------+

*/



#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define SIZE_BUF 50

int main(int argc, char *argv[])
{

    int fd;
    ssize_t read_ret, write_ret;

    if((fd = open(argv[1], O_RDWR)) == -1)
    {
	printf("open return file discriptor value : %d\n",fd);
	goto ERROR;
    }
    else if(fd > 0)
    {
	if ((write_ret = write(fd, argv[2], strlen(argv[2])) == -1))
	{
	    perror("write ");
	    close (fd);
	    goto ERROR;
	}
	else 
	{
	    perror("Write \n");
	    close(fd);
	}
    }

ERROR:
    perror("");
    return -1;
}
