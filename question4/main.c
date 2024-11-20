/*
 
+--------------------------------------------------------------------------+
+									   +
+   Author name : Siva prakasam V				           +
+   Date        : 20/11/24						   +
+									   +
+   Question:								   +
+    Write to a File Using File Descriptors				   +
+   - Write a C program that:						   +
+    1. Opens a file `output.txt` with write-only mode (`O_WRONLY`).       +
+    2. Writes a simple message to the file.				   +
+    3. Closes the file descriptor.					   +
+									   +
+--------------------------------------------------------------------------+

*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

char write_data[]=" this is sample text\n";

int main(int argc, char *argv[]){

    	int fd;
	ssize_t write_ret;

	if ( (fd = open(argv[1], O_WRONLY)) == -1){

	    goto ERROR;
	}
	else if( fd > 0 ){

	    if((write_ret = write(fd, write_data, strlen(write_data))) == -1){
		
		close(fd);
		goto ERROR;
	    }
	    else 
	    {
		perror(" ");
		close(fd);
		return 0;
	    }
	}

ERROR:
	perror("");
	return -1;
}
