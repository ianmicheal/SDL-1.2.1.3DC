
DEFS =  -DPACKAGE=\"SDL_gfx" -DDC -DDREAMCAST
KOS_CFLAGS+=$(DEFS) $(INCS) $(OPTFLAGS)


TARGET = libSDL_gfx.a

all: $(TARGET)

include $(KOS_BASE)/Makefile.rules

SRCS =	\
	src/SDL_framerate.c \
	src/SDL_gfxPrimitives.c \
	src/SDL_imageFilter.c \
	src/SDL_rotozoom.c


OBJS = $(SRCS:.c=.o)

clean:
	rm -f $(OBJS)

$(TARGET) : $(OBJS)
	rm -f $(KOS_BASE)/addons/lib/dreamcast/$(TARGET)
	$(KOS_AR) rcs $(KOS_BASE)/addons/lib/dreamcast/$(TARGET) $(OBJS)
	$(KOS_RANLIB) $(KOS_BASE)/addons/lib/dreamcast/$(TARGET)
