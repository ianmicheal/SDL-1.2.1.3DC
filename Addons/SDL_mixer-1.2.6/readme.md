
# 🎵 SDL_mixer - Multi-Channel Audio Mixer Library

![SDL_mixer Logo](https://path/to/sdl_mixer_logo.png)

### Description:
**SDL_mixer** is a powerful sample-based multi-channel audio mixer library. It supports any number of simultaneous channels for 16-bit stereo audio playback, as well as a single dedicated channel for music. It integrates popular libraries to mix various audio formats, including:
- 🎛️ **MOD**: via MikMod
- 🎹 **MIDI**: through Timidity
- 🎶 **Ogg Vorbis**
- 🎵 **MP3**: using SMPEG

---

### 🎼 Timidity: MIDI Playback Support

SDL_mixer can play **MIDI** format files using software wavetable synthesis, enabled by an older version of **Timidity**. To use this feature, you need to have a set of **GUS-compatible sound patches** installed on your system. The library looks for these patches in the following default locations:
- **Windows**: `C:\timidity`
- **UNIX**: `/usr/local/lib/timidity/`

#### 🔗 Resources:
- [**Freely Redistributable GUS-Compatible Patches (14 MB)**](https://link.to/timidity_patches)  
  `timidity.tar.gz`
  
- [**Sample MIDI Songs (1.3 MB)**](https://link.to/sample_midi_songs)  
  `bestmid3.tar.gz`

---

### 📦 Supported Formats
- 🎵 **MOD** files (via MikMod)
- 🎧 **Ogg Vorbis** files
- 🎶 **MP3** files (via SMPEG)
- 🎼 **MIDI** files (via Timidity)

---

### 🛠️ Installation

Follow the instructions in the official [SDL_mixer documentation](https://www.libsdl.org/projects/SDL_mixer/) to install the library and set up Timidity on your system.
