DBG        = #-ggdb3
OPTFLAGS   = -Wall -Wextra -Wstrict-prototypes -Wmissing-prototypes $(DBG) -pedantic

SRC        = multithread.c
TARGET     = multithread
OBJ        = $(SRC:.c=.o)

default: $(TARGET)
LDFLAGS += -lpthread
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS) 

clean:
	rm $(TARGET) 
