TARGET = videobench

OPTFLAGS=-Os



all: $(TARGET).bin

include $(KOS_BASE)/Makefile.rules

.SRCS	=	videobench.c \

OBJS = $(.SRCS:.c=.o)

clean:
	rm -f $(OBJS) $(TARGET).elf $(TARGET).bin

$(TARGET).elf: $(OBJS)
	$(KOS_CC) $(KOS_CFLAGS) $(KOS_LDFLAGS) -o $(TARGET).elf $(KOS_START) \
		$(OBJS) -lSDLDH -lm $(OBJEXTRA) $(KOS_LIBS)

$(TARGET).bin: $(TARGET).elf
	$(KOS_OBJCOPY) -R .stack -O binary $(TARGET).elf $(TARGET).bin

run: $(TARGET).bin
	$(KOS_LOADER) $(TARGET).bin

