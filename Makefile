CFLAGS += -W -Wall -Werror -O3
ifdef debug
	CFLAGS += -DDEBUG
endif

knini-test: 
	${CC} ${CFLAGS} $< ${OUTPUTFILE_OPTION}

run: knini-test
	./$<

clean:
	${RM} *.o *.out knini-test
