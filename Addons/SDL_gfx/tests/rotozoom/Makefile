TARGET = rotozoom

OPTFLAGS=-O3 -fomit-frame-pointer -DDREAMCAST

#KOS_CFLAGS+= -I$(KOS_BASE)/addons/include -I$(KOS_BASE)/addons/include/SDL $(OPTFLAGS) 

all: $(TARGET).bin

include $(KOS_BASE)/Makefile.rules

.SRCS	=	rotozoom.c \

OBJS = $(.SRCS:.c=.o)

clean:
	rm -f $(OBJS) $(TARGET).elf $(TARGET).bin

$(TARGET).elf: $(OBJS)
	$(KOS_CC) $(KOS_CFLAGS) $(KOS_LDFLAGS) -o $(TARGET).elf $(KOS_START) \
	$(OBJS) -lSDL_gfx -lSDL -lm $(OBJEXTRA) $(KOS_LIBS)

$(TARGET).bin: $(TARGET).elf
	$(KOS_OBJCOPY) -R .stack -O binary $(TARGET).elf $(TARGET).bin

run: $(TARGET).bin
	$(KOS_LOADER) $(TARGET).bin

