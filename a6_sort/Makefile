
srcs = array.c heap.c quicksort.c mergesort.c
objs = $(srcs:.c=.o)

maincode.out : maincode.c $(objs)
	gcc -o maincode.out maincode.c $(objs)


%.o : %.c
	gcc -c $^


clean :
	rm -f *.o *.out



