
# 🎮 Dreamcast Development with KallistiOS and SDL

![KallistiOS Version](https://img.shields.io/badge/KallistiOS-v2.1.0-blue)
![SDL Version](https://img.shields.io/badge/SDL-1.2.1.3DC-green)
![GLdc Version](https://img.shields.io/badge/GLdc-Latest-orange)

### 📦 Precompiled Libraries and Headers
These libraries and headers are **precompiled** and fully working with the following setup:

```
OUTPUT:> KallistiOS v2.1.0
OUTPUT:> Git revision: v2.0.0-1542-gcd4e5db0  
         sh-elf-gcc (GCC) 13.2.0
```

⚠️ **Note:** These headers differ from those in `kos-ports`. To ensure correct compilation, **keep the headers local** and avoid looking in the main path, or you'll get incorrect headers and compile failures.

---

### 🖼️ SDL Framebuffer (Non-OpenGL)

For **2D framebuffer rendering** using SDL (without OpenGL), include the following headers:

```c
#include "include/SDL.h"
#include "include/SDL_dreamcast.h"
```

Your link line should look like this to include all current libraries:

```bash
-L$(KOS_BASE)/lib -lgcc -lSDL -lSDL_image -lpng -lz -ljpeg -lSDL -lSDL_mixer_126 -loggvorbisplay -ltremor -lm $(KOS_LIBS)
```

✅ **Important:** The order of libraries matters! If not linked in this order, you may encounter undefined references and compilation errors.

**📁 Place the `.lib` or `.a` files** in:
```
opt/toolchains/dc/kos/addons/lib/dreamcast
```

---

### 🎨 Hardware 3D Rendering (OpenGL)

For **3D hardware rendering** using SDL with OpenGL on Dreamcast, your link line should include:

```bash
$(OBJS) $(OBJEXTRA) -lSDL_gl -lGLdc -lm $(KOS_LIBS)
```

- **SDL framebuffer** is used for fast 2D blitting.
- **SDL-GLdc** is for hardware-accelerated OpenGL rendering with PVR.

---

### 📚 Setup Overview

- **KallistiOS:** v2.1.0
- **SDL Version:** 1.2.1.3DC (Framebuffer & OpenGL)
- **GCC Version:** 13.2.0

