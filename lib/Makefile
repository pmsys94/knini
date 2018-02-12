CFLAGS += -W -Wall

ifdef debug
	CFLAGS += -DDEBUG -ggdb
else
	CFLAGS += -Werror -O3
endif

ifdef os
	OSMAK = -Dos=${os}
endif

incdir = libknsll
list = ${incdir}/knsll.o ${incdir}/knsllnode.o

knini: knini.o listobj
	${CC} ${CFLAGS} $< ${list} ${OUTPUT_OPTION}

knini.o: listobj iniparsefuncs.o
	${CC} -c ${CFLAGS} ${OSMAK} knini.c -o $@

iniparsefuncs.o: iniparsefuncs.c
	${CC} -c ${CFLAGS} ${OSMAK} $< -o $@

listobj: 
	cd ${incdir}; ${MAKE} knsll.o "debug=${debug}"

clean:
	${RM} *.o *.out; cd ${incdir}; ${MAKE} clean
