# SDL_image 1.2.12

![SDL_image Logo](https://www.libsdl.org/projects/SDL_image/docs/SDL_image.png)

SDL_image is a simple library to load images of various formats as SDL surfaces.

## Supported Formats

- BMP
- PNM (PPM/PGM/PBM)
- XPM
- LBM
- PCX
- GIF
- JPEG
- PNG
- TGA
- TIFF

## API

Include the following header in your code:

```c
#include "SDL_image.h"
```

### Loading Images

There are three main functions for loading images:

1. Load from file:
   ```c
   SDL_Surface *IMG_Load(const char *file);
   ```

2. Load from SDL_RWops:
   ```c
   SDL_Surface *IMG_Load_RW(SDL_RWops *src, int freesrc);
   ```

3. Load from SDL_RWops with specified image type:
   ```c
   SDL_Surface *IMG_LoadTyped_RW(SDL_RWops *src, int freesrc, char *type);
   ```
   where `type` is a string specifying the format (e.g., "PNG" or "pcx").

**Note:** `IMG_Load_RW` cannot load TGA images.

### Creating Surface from XPM

To create a surface from an XPM image included in C source:

```c
SDL_Surface *IMG_ReadXPMFromArray(char **xpm);
```

## Example Program

An example program 'showimage' is included, with source in `showimage.c`.

## Dependencies

- JPEG support requires the [JPEG library](http://www.ijg.org/)
- PNG support requires the [PNG library](http://www.libpng.org/pub/png/libpng.html) and the [Zlib library](http://www.gzip.org/zlib/)
- TIFF support requires the [TIFF library](ftp://ftp.sgi.com/graphics/tiff/)

### Installing Dependencies in Non-Standard Locations

If you have these libraries installed in non-standard places, you can try adding those paths to the configure script:

```sh
sh ./configure CPPFLAGS="-I/somewhere/include" LDFLAGS="-L/somewhere/lib"
```

If this works, you may need to add `/somewhere/lib` to your `LD_LIBRARY_PATH` for correct shared library loading.

## License

This library is under the zlib License. See the file "COPYING" for details.

## Contributing

We welcome contributions to SDL_image! Please check our [contribution guidelines](CONTRIBUTING.md) for more information on how to get started.

## Support

For support, please visit the [SDL forums](https://discourse.libsdl.org/) or the [SDL Discord server](https://discord.gg/SDL).

---

Happy coding with SDL_image!
