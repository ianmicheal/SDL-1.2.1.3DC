
# 🎮 Dreamcast SDL Warp Example

![Dreamcast](https://img.shields.io/badge/Dreamcast-20B2AA?style=for-the-badge&logo=sega&logoColor=white)
![SDL](https://img.shields.io/badge/SDL-1.2.13DC-blue?style=for-the-badge&logo=sdl&logoColor=white)
![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

A mesmerizing image warping demo showcasing the power of SDL on the Dreamcast! 🌀✨

## 🚀 Features

- 🖼️ Multi-image support with smooth transitions
- 🕹️ Interactive warp control using D-pad
- 🔄 Fullscreen display with automatic image scaling
- ⚡ Optimized for Dreamcast hardware

## 🛠️ Technology Stack

- **SDL Version**: Custom SDL1.2.13DC for Dreamcast
- **Platform**: Sega Dreamcast
- **Language**: C

## 🧠 How It Works

1. 🎨 **Image Loading**: Loads multiple images from the Dreamcast's romdisk.
2. 🖥️ **Screen Setup**: Utilizes Dreamcast-specific video modes for optimal performance.
3. 🔄 **Image Conversion**: Scales and converts images to match the screen format.
4. 🌀 **Warp Effect**: Applies a real-time warping effect to the displayed image.
5. 🎮 **User Interaction**: 
   - 🅰️ A Button: Cycle through loaded images
   - 🕹️ D-Pad: Adjust warp intensity
   - 🏁 Start Button: Exit the program

## 💡 Dreamcast-Specific Optimizations

- Uses `SDL_DC_SetVideoDriver(SDL_DC_DMA_VIDEO)` for fast rendering.
- Implements `SDL_DC_ShowAskHz` and `SDL_DC_Default60Hz` for display tuning.
- Utilizes `SDL_DC_MapKey` to map Dreamcast controller buttons to keyboard inputs.

## 🚀 Getting Started

1. Set up your Dreamcast development environment.
2. Clone this repository.
3. Compile using your Dreamcast toolchain:
   ```
   kos-cc main.c warp.c -o warp.elf -lSDL -lSDL_image
   ```
4. Run on Dreamcast hardware or an emulator.

## 📚 Code Highlights

```c
SDL_DC_SetVideoDriver(SDL_DC_DMA_VIDEO);
screen = SDL_SetVideoMode(screen_width, screen_height, 16, SDL_FULLSCREEN | SDL_HWSURFACE | SDL_DOUBLEBUF);
```
Setting up Dreamcast-optimized video mode.

```c
SDL_DC_MapKey(0, SDL_DC_START, SDLK_ESCAPE);
```
Mapping Dreamcast START button to ESC key for easy porting.

## 🤝 Contributing

Contributions are welcome! Feel free to submit pull requests or open issues.

## 📄 License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- Original Warp-SDL by Emmanuel Marty
- SDL port by Sam Lantinga
- Dreamcast port and enhancements by Ian Micheal

---

⭐ Star this repo if you find it interesting!
