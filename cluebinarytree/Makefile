DBG        = -g
OPTFLAGS   = -Wall -Wextra -Wstrict-prototypes -Wmissing-prototypes $(DBG) -pedantic

SRC        = cluebinarytree.c
TARGET     = cluebinarytree
OBJ        = $(SRC:.c=.o)

default: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) $(DBG) -c -o $@ $<

$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS)

clean:
	rm $(OBJ) $(TA
