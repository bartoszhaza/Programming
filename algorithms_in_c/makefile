EXE_DIR=	.
EXE=	$(EXE_DIR)/Executable
SRC=	main.c	quickSort.c	bubbleSort.c selectionSort.c	gnu.c	insertionSort.c

CC=	cc
COPT=	-O
CFLAGS=

OBJ=	$(SRC:.c=.o)

.c.o:
	$(CC)	$(COPT)	-c	-o	$@	$<

$(EXE):	$(OBJ)
	$(CC)	$(OBJ)	$(CFLAGS)	-lm	-o	$(EXE)

clean:
	rm	-f	$(OBJ)	$(EXE)

main.o:	main.c	header.h
quickSort.o:	quickSort.c	header.h
bubbleSort.o:	bubbleSort.c	header.h
selectionSort.o: selectionSort.c header.h
gnu.o:	gnu.c	header.h
insertionSort.o:	insertionSort.c	header.h
