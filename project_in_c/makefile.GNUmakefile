# code details

EXE_DIR	=	.
EXE	=	$(EXE_DIR)/exe

SRC=	main.c	functions.c

# generic build details

CC=	cc
COPT=	-O
CFLAGS=

# compile to  object code

OBJ=	$(SRC:.c=.o)

.c.o:
	$(CC)	$(COPT)	-c	-o	$@	$<

# build executable

$(EXE):	$(OBJ)
	$(CC)	$(OBJ)	$(CFLAGS)	-lm	-o	$(EXE)

# clean up compilation

clean:
	rm	-f	$(OBJ)	$(EXE)

# dependencies

main.o:	main.c	structqNode.h
functions.o:	functions.c	structqNode.h