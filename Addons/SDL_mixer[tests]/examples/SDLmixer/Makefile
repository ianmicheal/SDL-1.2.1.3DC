#ATEST  port IAN MICHEAL KOS2.0 SDL_MIXER1.2.6 upport
#DC SDL MIXER EXAMPLE with midi playback
#
# SDLDC Image display example using SDL + SDL IMAGE 
# (c)2003/2024 Ian micheal 
#   

  

TARGET = SDL_mixer.elf
OBJS =  main.o SFont.o





all: rm-elf $(TARGET)

include $(KOS_BASE)/Makefile.rules

KOS_CFLAGS+= -O3 -Wno-switch -ffast-math -fno-common -fno-builtin -fno-exceptions -fstrict-aliasing 

clean:
	-rm -f $(TARGET) $(OBJS) romdisk.*

rm-elf:
	-rm -f $(TARGET) romdisk.*

$(TARGET): $(OBJS) romdisk.o
	$(KOS_CC) $(KOS_CFLAGS) $(KOS_LDFLAGS) -o $(TARGET) $(KOS_START) \
		$(OBJS) romdisk.o $(OBJEXTRA) -L$(KOS_BASE)/lib -lgcc  -lSDL -lSDL_image -lpng -lz -ljpeg  -lSDL  -lSDL_mixer_126  -loggvorbisplay -ltremor -lm   $(KOS_LIBS)

romdisk.img:
	$(KOS_GENROMFS) -f romdisk.img -d romdisk -v

romdisk.o: romdisk.img
	$(KOS_BASE)/utils/bin2o/bin2o romdisk.img romdisk romdisk.o

run: $(TARGET)
	$(KOS_LOADER) $(TARGET)


          
