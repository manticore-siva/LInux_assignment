Mesg1=Compile Successfully ....!
Mesg2=Clean Successfully .....!
CC=gcc
FLAG=-o
Source_file=main.c
Out_file=out.elf

main:${Source_file}
	${CC} ${Source_file} ${FLAG} ${Out_file}
	@echo ${Mesg1}
clean:
	rm -rf ${Out_file}
	@echo ${Mesg2}
.PHONY:clean
