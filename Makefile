CFLAGS += -W -Wall
ifdef debug
	CFLAGS += -DDEBUG -ggdb
else
	CFLAGS += -O3
endif

ifdef os
	OSMAK = -Dos=${os}
endif

incdir = lib
lib = ${incdir}/knini.o
list = ${incdir}/knsll/knsll.o ${incdir}/knsll/knsllnode.o
obj =  ${lib} ${list}

knini-test: knini-test.o knini.o
	${CC} ${CFLAGS} $< ${obj} ${OUTPUT_OPTION}

knini.o: ${obj} 
	cd lib; ${MAKE} knini.o "CFLAGS=${CFLAGS}" "os=${os}"

run: knini-test
	./$<

gdbrun: knini-test
	gdb ./$<

clean:
	${RM} *.o *.out knini-test; cd lib; ${MAKE} clean
