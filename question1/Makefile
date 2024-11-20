MESG1=Compiled Success ... !
MESG2=Clean Success ...!

CC=gcc 
FLAG= -o 
OUT_FILE=out.elf
SOURCE=main.c
OUT:${SOURCE}
	${CC} ${SOURCE} ${FLAG} ${OUT_FILE}
	@echo ${MESG1}
clean:
	rm -rf ${OUT_FILE}
	@echo  ${MESG2}
.PHONY:clean

