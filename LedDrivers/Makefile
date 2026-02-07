CC = gcc
CFLAGS = -Wall -g -I.
TARGET = led_app

SRCS = main.c led_driver.c
OBJS = $(SRCS:.c=.o)
DEPS = led_driver.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean