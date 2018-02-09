ifndef CFLAGS
	CFLAGS += -W -Wall
endif

ifdef debug
	CFLAGS += -DDEBUG -ggdb
else
	CFLAGS += -O3
endif

knsll.o: knsllnode.o knsll.c
	${CC} -c ${CFLAGS} knsll.c -o $@

knsllnode.o: knsllnode.c 
	${CC} -c ${CFLAGS} $< -o $@

clean:
	${RM} *.o *.out
