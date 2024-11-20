/*
+---------------------------------------------------------------------------------------------------------------+
|                                                                                                               |
|   Author name : Siva prakasam V                                                                               |
|   Date        : 20/11/24                                                                                      |
|                                                                                                               |
|                                                                                                               |
|   Question                                                                                                    |
|   ========                                                                                                    |
|														|
|   Duplicate File Descriptors Using `dup()`									|
|   - Write a program that:											|
|     1. Opens a file `file.txt` for reading.									|
|     2. Duplicates the file descriptor using `dup()` (creates a copy of the original descriptor).		|
|     3. Reads from the new file descriptor and prints the content to standard output.                          |
|														|
+---------------------------------------------------------------------------------------------------------------+

*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#define BUF_SIZE 50

int main(int argc, char *argv[]){

	int fd, new_fd;
	ssize_t read_ret;
	char buf[BUF_SIZE] = {0};

	if ((fd = open(argv[1], O_RDWR)) == -1){
	
	    goto ERROR_HANDLE;

	}
	else if (fd > 0 ){

	    perror("Open");

	    if ((new_fd = dup(fd)) == -1){
		goto ERROR_HANDLE;
	    }
	    else{
		close(fd);
		perror("Old file discriptor close");
		
		if((read_ret = read(new_fd, buf, BUF_SIZE)) == -1)
		{
		    close(new_fd);
		    goto ERROR_HANDLE;
		}
		else if(read_ret > 0)
		{
		    	printf(" Old file Discriptor : %d\n New file Discriptor : %d\n",fd, new_fd);
			close(new_fd);
			perror("close ");
			printf("Read Data\n %s\n",buf);
			return 0;
		}
	    }

	}

	return 0;
ERROR_HANDLE:
	perror("");
	return -1;
}

