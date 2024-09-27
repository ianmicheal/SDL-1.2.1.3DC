
# SDL_gfx Library

## SDL graphics drawing primitives and other support functions

The SDL_gfx library evolved out of the **SDL_gfxPrimitives** code which provided basic drawing routines such as lines, circles or polygons and **SDL_rotozoom** which implemented an interpolating rotozoomer for SDL surfaces.

### Current Components

The current components of the SDL_gfx library are:

1. **Graphic Primitives** (SDL_gfxPrimitves.h)
2. **Rotozoomer** (SDL_rotozoom.h)
3. **Framerate control** (SDL_framerate.h)
4. **MMX image filters** (SDL_imageFilter.h)

### Features

- The library is backwards compatible with the above-mentioned code.
- It is written in plain C and can be used in C++ code.

### Usage

To use the SDL_gfx library in your project, include the necessary headers:

```c
#include <SDL_gfxPrimitives.h>
#include <SDL_rotozoom.h>
#include <SDL_framerate.h>
#include <SDL_imageFilter.h>
```

## Contributors
* Fix for filledbox by Ingo van Lil, inguin at gmx.de - thanks Ingo.

* Non-alpha line drawing code adapted from routine by Pete Shinners, pete at shinners.org - thanks Pete.

* More fixes by Karl Bartel, karlb at gmx.net - thanks Karl.

* Much testing and suggestions for fixes from Danny van Bruggen, danny at froukepc.dhs.org - thanks Danny.

* AA-circle/-ellipse code idea from Stephane Magnenat, nct at wg0.ysagoon.com - thanks Stephane.

* Faster blending routines contributed by Anders Lindström, cal at swipnet.se - thanks Anders.

* VisualC makefile contributed by Danny van Bruggen, danny at froukepc.dhs.org - thanks Danny.

* VisualC7 project file contributed by James Turk, jturk at conceptofzero.com - thanks James.

* Project Builder package contributed by Thomas Tongue, TTongue at imagiware.com - Thanks Thomas.

* Fix for filledPolygon contributed by Kentaro Fukuchi fukuchi at is.titech.ac.jp - Thanks Kentaro.

* QNX6 patch contributed by Mike Gorchak, mike at malva.ua - Thanks Mike.

* Pie idea contributed by Eike Lange, eike.lange at uni-essen.de - Thanks Eike.

* Dynamic font setup by Todor Prokopov, koprok at dir.bg - Thanks Todor.

* Horizontal/Vertical flipping code by Victor (Haypo) Stinner, victor.stinner at haypocalc.com - Thanks Victor.

* OSX build fixes by Michael Wybrow, mjwybrow at cs.mu.oz.au - Thanks Michael.

* gcc3.4 build fixes by Dries Verachtert, dries at ulyssis.org - Thanks Dries.


