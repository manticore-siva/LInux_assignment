Msg=Compile done ........!
Mesg2=Clean ........!
CC=gcc
FLAG=-o
SOURCE=main.c
Out_file=out.elf

main:${SOURCE}
	${CC} ${SOURCE} ${FLAG} ${Out_file}
	@echo ${Msg}
clean:
	rm -rf ${Out_file}
	@echo ${Mesg2}
.PHONY:clean
