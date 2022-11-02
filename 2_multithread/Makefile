DBG        = #-ggdb3
OPTFLAGS   = -Wall -Wextra -Wstrict-prototypes -Wmissing-prototypes $(DBG) -pedantic

SRC        = produce_consume_link_list.c
TARGET     = produce_consume_link_list
OBJ        = $(SRC:.c=.o)

default: $(TARGET)
LDFLAGS += -lpthread
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS) 

clean:
	rm $(TARGET) 
