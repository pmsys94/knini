ifndef CFLAGS
	CFLAGS += -W -Wall
endif

ifdef debug
	CFLAGS += -DDEBUG -ggdb
else
	CFLAGS += -O3
endif

ifdef os
	OSMAK = -Dos=${os}
endif

incdir = knsll
list = ${incdir}/knsll.o ${incdir}/knsllnode.o

knini: knini.o ${list}
	${CC} ${CFLAGS} $+ ${OUTPUT_OPTION}

knini.o: ${list} 
	${CC} -c ${CFLAGS} $< -o $@

clean:
	${RM} *.o *.out; cd knsll; ${MAKE} clean
