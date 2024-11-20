Mesg1=Complied Successfully ....!
Mesg2=Clean Successfully .....!
SOURCE=main.c
Out_file=out.elf
FLAG=-o

main:${SOURCE}
	${CC} ${SOURCE} ${FLAG} ${Out_file}
	@echo ${Mesg1}
clean:
	rm -rf ${Out_file}
	@echo ${Mesg2}

