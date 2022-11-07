DBG        = -g
OPTFLAGS   = -Wall -Wextra -Wstrict-prototypes -Wmissing-prototypes $(DBG) -pedantic

SRC        = trietree.c
TARGET     = trietree
OBJ        = $(SRC:.c=.o)

default: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) $(DBG) -c -o $@ $<

$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS)

clean:
	rm $(OBJ) $(TA
