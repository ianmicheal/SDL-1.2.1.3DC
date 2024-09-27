TARGET = video_test

#OPTFLAGS=-O3 -fomit-frame-pointer
CXXFLAGS   +=  -flto -fuse-linker-plugin -fno-exceptions -fno-rtti -ffunction-sections
CFLAGS       += -O3 -flto -fuse-linker-plugin -ffast-math -mfused-madd -fno-delayed-branch -fno-optimize-sibling-calls -funroll-all-loops -fschedule-insns2 -fexpensive-optimizations -fomit-frame-pointer  -finline-functions
KOS_CFLAGS+= -I$(KOS_BASE)/addons/include/SDL $(OPTFLAGS) 

all: $(TARGET).bin

include $(KOS_BASE)/Makefile.rules

.SRCS	=	video_test.c \

OBJS = $(.SRCS:.c=.o)

clean:
	rm -f $(OBJS) $(TARGET).elf $(TARGET).bin

$(TARGET).elf: $(OBJS)
	$(KOS_CC) $(KOS_CFLAGS) $(KOS_LDFLAGS) -flto -fuse-linker-plugin -o $(TARGET).elf -flto -fuse-linker-plugin $(KOS_START) \
		$(OBJS) -lSDL -lm $(OBJEXTRA)  $(KOS_LIBS)
		
	

$(TARGET).bin: $(TARGET).elf
	$(KOS_OBJCOPY) -R .stack -O binary $(TARGET).elf $(TARGET).bin

run: $(TARGET).bin
	$(KOS_LOADER) $(TARGET).bin

