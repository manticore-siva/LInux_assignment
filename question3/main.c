/*

+------------------------------------------------------------------------------------------------------------+
+                                                                                                            +
+   Author name : Siva prakasam V                                                                            +
+   Date        : 20/11/24                                                                                   +
+                                                                                                            +
+                                                                                                            +
+   Question                                                                                                 +
+   ========                                   								     +
+    Read from a File Using File Descriptors                                                                 +
+   - Write a C program that:                                                                                +
+     1. Opens an existing file `input.txt` for reading.                                                     +
+     2. Reads its contents into a buffer and prints it to the standard output.                              +
+     3. Closes the file descriptor after reading.							     +
+   Check and Handle File Descriptor Errors                                                                  +
+                                                                                                            +
+------------------------------------------------------------------------------------------------------------+

*/


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include<unistd.h>

#define BUF_SIZE 50

char buf[BUF_SIZE];

int main(int argc, char *argv[]){


    int fd;
    ssize_t read_ret;

    if ( ( fd = open(argv[1], O_RDONLY)) == -1){

	goto ERROR;
    }
    else if ( fd > 0 )
    {

	if ( ( read_ret = read(fd, buf, BUF_SIZE)) == -1){

	    close(fd);
	    goto ERROR;
	}
	else if ( read_ret > 0)
	{
	    close(fd);
	    printf("%s\n", buf);
	    return 1;
	}
    }

ERROR:
    perror("");
    return -1;

return 0;

}


