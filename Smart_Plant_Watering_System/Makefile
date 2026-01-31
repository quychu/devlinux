CC = gcc
CFLAGS = -Iconfig \
         -Ihal_actuators \
         -Ihal_sensors \
         -Ihal_buttons \
         -Ispws_controller \
         -Wall -g

SRCS = src/main.c \
       hal_actuators/hal_actuators.c \
       hal_sensors/hal_sensors.c \
       hal_buttons/hal_buttons.c \
       spws_controller/spws_controller.c

TARGET = smart_watering_system

all:
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)