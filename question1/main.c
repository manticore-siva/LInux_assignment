/*
+---------------------------------------------------------------------------------------------------------------+
|                                                                                                               |
|   Author name : Siba prakasam V                                                                               |
|   Date        : 20/11/24                                                                                      |
|                                                                                                               |
|                                                                                                               |
|   Question                                                                                                    |
|   ========                                                                                                    |
|														|
|    1. Open, Write, and Close a File Using File Descriptors							|
|   - Write a C program that:											|
|    1. Opens a file `example.txt` using the `open()` system call.						|
|     2. Writes a string `"Hello, World!"` to the file.								|
|     3. Closes the file descriptor after writing.								|
+---------------------------------------------------------------------------------------------------------------+

*/


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 50

char msg[]="Enter your message to write \n";
char buf[BUF_SIZE] = {0};

int main (int argc, char *argv[])
{

    int fd;
    ssize_t write_ret, read_ret;

    if ((fd = open(argv[1], O_RDWR)) == -1){

		perror("file open ");
		goto exit;
	    }
    else if(fd > 0)
    {
	perror("open file ");

	if ( (write_ret = write(fd, msg, strlen(msg))) == -1)
	{
	    perror("write ");
	    close(fd);
	    goto exit;
	}
	else if (write_ret > 0)
	{
	    perror("write ");

	    if( (read_ret = read(fd, buf, BUF_SIZE)) == -1)
	    {
		perror("read ");
		close(fd);
		goto exit;

	    }

	    else if (read_ret > 0 )
	    {
		perror("read ");
		close (fd);
		printf("%s",buf);
	    }
	    
	}

    }

exit:
    return -1;

return 0;
}

