DBG        = #-ggdb3
OPTFLAGS   = -Wall -Wextra -Wstrict-prototypes -Wmissing-prototypes $(DBG) -pedantic

SRC        = convery_and_load.c
TARGET     = convery_and_load
OBJ        = $(SRC:.c=.o)

default: $(TARGET)
LDFLAGS += -lpthread
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS) 

clean:
	rm $(TARGET) 
