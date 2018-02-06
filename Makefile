CFLAGS += -W -Wall
ifdef debug
	CFLAGS += -DDEBUG -ggdb
else
	CFLAGS += -O3
endif

knini-test: knini-test.o knini.o
	${CC} ${CFLAGS} $+ ${OUTPUT_OPTION}

run: knini-test
	./$<

gdbrun: knini-test
	gdb ./$<

clean:
	${RM} *.o *.out knini-test
