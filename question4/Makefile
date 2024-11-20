Msg1=Compile Success fully ...!
Mes2=Clean Success fully ...!
CC=gcc
FLAG=-o
Out_file=out.elf
SOURCE=main.c

main:${SOURCE}
	${CC} ${SOURCE} ${FLAG} ${Out_file}
	@echo ${Msg1}
clean:
	rm -rf ${Out_file}
	@echo ${Mes2}
.PHONY:clean
