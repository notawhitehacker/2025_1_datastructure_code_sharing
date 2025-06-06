
srcs = graph.c graph_search.c linkedlist.c queue.c
objs = $(srcs:.c=.o)

maincode.out : maincode.c $(objs)
	gcc -o maincode.out maincode.c $(objs)


%.o : %.c
	gcc -c $^


clean :
	rm -f *.o *.out



