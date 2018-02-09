CFLAGS += -W -Wall

ifdef debug
	CFLAGS += -DDEBUG -ggdb
else
	CFLAGS += -Werror -O3
endif

ifdef os
	OSMAK = -Dos=${os}
endif

incdir = lib
lib = ${incdir}/knini.o ${incdir}/iniparsefuncs.o
list = ${incdir}/knsll/knsll.o ${incdir}/knsll/knsllnode.o
obj =  ${lib} ${list}

knini-test: knini.o testfuncs.o knini-test.o
	${CC} ${CFLAGS} ${OSMAK} ${obj} knini-test.o testfuncs.o ${OUTPUT_OPTION}

knini.o:  
	cd lib; ${MAKE} $@ "os=${os}" "debug=${debug}"

%.o: %.c
	${CC} ${CFLAGS} -c ${OSMAK} $< ${OUTPUT_OPTION}

run: knini-test
	./$<

gdbrun: knini-test
	gdb ./$<

clean:
	${RM} *.o *.out knini-test; cd lib; ${MAKE} clean
