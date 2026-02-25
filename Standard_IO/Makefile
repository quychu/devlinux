CC = gcc
CFLAGS = -Wall -Wextra
TARGET = logger_app

all: $(TARGET)

$(TARGET): main.o logger.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o logger.o

main.o: main.c logger.h
	$(CC) $(CFLAGS) -c main.c

logger.o: logger.c logger.h
	$(CC) $(CFLAGS) -c logger.c

clean:
	rm -f *.o $(TARGET) *.log