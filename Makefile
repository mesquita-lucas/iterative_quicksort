CC = gcc
CFLAGS = -Wall -Wextra -Isrc -Iinc
OBJDIR = objs

OBJS = $(OBJDIR)/main.o \
	   $(OBJDIR)/quicksort.o \
	   $(OBJDIR)/stack.o
	
all: sort

sort: $(OBJS)
	$(CC) $(CFLAGS) -o sort $(OBJS)

$(OBJDIR)/main.o: src/main.c inc/quicksort.h
	$(CC) $(CFLAGS) -c src/main.c -o $@

$(OBJDIR)/quicksort.o: src/quicksort.c inc/quicksort.h inc/stack.h
	$(CC) $(CFLAGS) -c src/quicksort.c -o $@

$(OBJDIR)/stack.o: src/stack.c inc/stack.h
	$(CC) $(CFLAGS) -c src/stack.c -o $@

$(OBJDIR):
	mkdir -p $@

$(OBJS): | $(OBJDIR)

clean:
	rm -rf sort $(OBJDIR)