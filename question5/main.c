/*

+---------------------------------------------------------------------------------------------------------------+
+                                                                                                               +
+   Author name : Siva prakasam V                                                                               +
+   Date        : 20/11/24                                                                                      +
+                                                                                                               +
+                                                                                                               +
+   Question                                                                                                    +
+   ========                                                                                                    +
+   Check and Handle File Descriptor Errors                                                                     +
+   ---------------------------------------                                                                     +
+   Use `open()` with `O_CREAT`											+
+   - Write a program that attempts to open a file called `newfile.txt` using `open()` with the `O_CREAT` flag. +
+   If the file doesn’t exist, create it and write some data to it.                                             +                                                               +
+---------------------------------------------------------------------------------------------------------------+

*/


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc, char *argv[]){

    int fd;

    if((fd = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)) == -1)
    {
	goto ERROR;
    }
    else if (fd > 0)
    {
	perror("Open ");
	close(fd);
    }
ERROR:
    perror("");
}
