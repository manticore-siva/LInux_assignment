Mesg1=Compiled Successfull ....!
Mesg2=Clean Successfull ....!
CC=gcc
FLAG= -o
SOURCE=main.c
OUT_FILE=out.elf

main:${SOURCE}
	${CC} ${SOURCE} ${FLAG} ${OUT_FILE}
	@echo ${Mesg1}
clean:
	rm -rf ${OUT_FILE}
	@echo ${Mesg2}
.PHONY:clean
