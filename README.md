# DREAMCAST SDL-DREAMHAL Version 1.0
- **Based on SDL 1.2.13**:
- **tested and working on KallistiOS v2.1.0 sh-elf-gcc (GCC) 13.2. Git revision: v2.0.0-1542-gcd4e5db0**
 
## Overview
SDL-DREAMHAL is a customized version of SDL (Simple DirectMedia Layer) tailored for the Dreamcast. It leverages GLDC for rendering, providing significant performance enhancements for 2D blitting and other operations. This version includes updates for fixed headers and multiple defines.

## Features
- **Dreamcast Hardware + OpenGL**: Optimized for SDL FAST BLIT SPEED.
- **2D Blit Speed Benchmark**: Significant improvements in both software and hardware modes.
- **Integration with GLDC**: Utilizes Kazade's GLDC library for enhanced OpenGL compatibility and performance.

![Screenshot of SDL-DREAMHAL](https://github.com/ianmicheal/SDL-dreamhal--GLDC/blob/main/benchmark.png)

## Performance Comparison direct rendering update no priming

| Resolution | Mode     | Slow Points<br>(frames/sec) | Fast Points<br>(frames/sec) | Rect Fill<br>(rects/sec) | 32x32 Blits<br>(blits/sec) |
|------------|----------|----------------------------:|----------------------------:|-------------------------:|---------------------------:|
| 320x240    | Software | 0.419749                    | 36.0411                     | 1314.51                  | 3075.08                    |
| 320x240    | Hardware | 1.03212                     | 62.699                      | 2684.14                  | 4133.2                     |
| 640x480    | Software | 0.220216                    | 20.444                      | 709.51                   | 3005.14                    |
| 640x480    | Hardware | 0.129902                    | 15.7296                     | 696.007                  | 4043.44                    |


This table compares performance across different resolutions and rendering methods.


## Dreamcast Integration
- **Correct OpenGL integration.**: 
- **Textured video driver for virtual resolutions.**: 
- **Direct framebuffer video driver using store queues.**:
- **Mouse emulation using analog pad**: 
- **Mapped keys as pad buttons.**:
- **Two texture internal color mode supported: RGB5551 and RGB4444.**:
- **Fast threaded audio driver.**:

  ## SDL
SDL is a cross-platform multimedia library designed to provide low-level access to audio, keyboard, mouse, joystick, 3D hardware via OpenGL, and 2D video framebuffer.

### New Features
- **Upgraded Blit Speed**: Utilizing moops dreamhal SH4 ASM memcpy and memset.
- **GLDC Integration**: Improved compatibility and performance with OpenGL 1.2.

### Video Drivers for Dreamcast
- **SDL_DC_DMA_VIDEO** (default): Fastest video driver using double buffer.
- **SDL_DC_TEXTURED_VIDEO**: Allows virtual resolutions and scaling using hardware texture.
- **SDL_DC_DIRECT_VIDEO**: Direct buffer video driver, potentially faster than DMA without double buffer.

### Configuration Options
- **SDL_DC_VerticalWait(SDL_bool value)**: Enable/disable wait for vertical retrace before blitting to PVR hardware.
- **SDL_DC_ShowAskHz(SDL_bool value)**: Enable/disable ask for 50/60Hz video (only for PAL Dreamcasts).
- **SDL_DC_Default60Hz(SDL_bool value)**: Set default display to 60Hz (only for PAL Dreamcasts).
- **SDL_DC_MapKey(int joy, SDL_DC_button button, SDLKey key)**: Map Dreamcast buttons to SDL keys.



## Additional Resources

- **PORTED TO SDL + OpenGL Dreamhal + GLDC Demos**:
- **SDL[DREAMHAL]+[GLDC]KOS2.0 TWINKLE STAR DEMO HARDWARE**:
  - [Demo 1](https://youtu.be/aTKOW4GrLsQ)
  -  ** SDL[DREAMHAL]+[GLDC]KOS2.0 BLENDING GLASS CUBE HARDWARE**:
  - [Demo 2](https://youtu.be/GM4JnKxp1ZQ)
  - ** SDL[DREAMHAL]+[GLDC]KOS2.0 SPINNING TEXTURES CUBE 60FPS
  - [Demo 3](https://youtu.be/G0KFthogrPg)
  - **SDLQUAKE DREAMHAL**:
  - [Demo port quake 1](https://youtu.be/QiEo3FNNEZc).
  - **OLD VERSION CANT BE COMPILED OR USED ON KOS2.0**
   - **Old Version**: [SDL by Chui](http://chui.dcemu.co.uk/sdl.html)

---

For a complete list of features and detailed documentation, please visit the [GLDC repository](https://gitlab.com/simulant/GLdc).

## Credits
- **BERO**: Original work  for SDL on Dreamcast.
- **Chui**: Original work and improvements for SDL on Dreamcast.
- **Kazade**: GLDC library and enhancements.
- **MRNEO240**:GLDC Optimizing and Support.
GNU Lesser General Public License, version 2.1
https://www.gnu.org/licenses/old-licenses/lgpl-2.1.en.html
# DEPRECATED

The 1.2 branch of SDL is deprecated. While we occasionally collect fixes
in revision control, there has not been a formal release since 2012, and
we have no intention to do future releases, either.

Current development is happening in SDL 2.0.x, which gets regular
releases and can be found at:

https://github.com/libsdl-org/SDL

Thanks!



# Simple DirectMedia Layer (SDL) Version 1.2

https://www.libsdl.org/

This is the Simple DirectMedia Layer, a general API that provides low
level access to audio, keyboard, mouse, joystick, 3D hardware via OpenGL,
and 2D framebuffer across multiple platforms.

The current version supports Linux, Windows CE/95/98/ME/XP/Vista, BeOS,
MacOS Classic, Mac OS X, FreeBSD, NetBSD, OpenBSD, BSD/OS, Solaris, IRIX,
and QNX.  The code contains support for Dreamcast, Atari, AIX, OSF/Tru64,
RISC OS, SymbianOS, Nintendo DS, and OS/2, but these are not officially
supported.

SDL is written in C, but works with C++ natively, and has bindings to
several other languages, including Ada, C#, Eiffel, Erlang, Euphoria,
Guile, Haskell, Java, Lisp, Lua, ML, Objective C, Pascal, Perl, PHP,
Pike, Pliant, Python, Ruby, and Smalltalk.

This library is distributed under GNU LGPL version 2, which can be
found in the file  "COPYING".  This license allows you to use SDL
freely in commercial programs as long as you link with the dynamic
library.

The best way to learn how to use SDL is to check out the header files in
the "include" subdirectory and the programs in the "test" subdirectory.
The header files and test programs are well commented and always up to date.
More documentation is available in HTML format in "docs/index.html".

The test programs in the "test" subdirectory are in the public domain.

Enjoy!

Sam Lantinga (slouken@libsdl.org)

