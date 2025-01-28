
/*
  Name: SDL-DC Video Benchmark
  Copyright: 2024
  Author: Original SDL example modified for DC, enhanced by Ian Michael
         Further optimized for Dreamcast video driver testing
  
  Description: 
  A comprehensive Dreamcast SDL video benchmark testing all available video modes:
  
  1. DIRECT VIDEO (320x240):
     - Direct framebuffer access
     - Basic hardware surface mode
     - No double buffering
  
  2. DMA VIDEO (320x240):
     - Hardware accelerated DMA transfers
     - Double buffered for smooth updates
     - Full hardware surface support
  
  3. PVR TEXTURED (512x256 -> 320x240):
     - PowerVR2 texture-based rendering
     - Hardware scaled to display size
     - Single buffered texture mode
  
  4. PVR TEXTURED + DB (512x256 -> 320x240):
     - PowerVR2 texture-based rendering
     - Hardware scaled with double buffering
     - Optimal for sprite/texture heavy content
  
  5. DMA VIDEO HI-RES (640x480):
     - High resolution DMA mode
     - Double buffered hardware surfaces
     - Tests scaling performance impact
*/

#include <kos.h>
#include <stdio.h>
#include "SDLDH/SDL.h"
#include "SDLDH/SDL_dreamcast.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Real coords (texture width and height) for hardware scaled */
#define TXR_X 512
#define TXR_Y 256

/* Screen coords */
#define SCR_X 320
#define SCR_Y 240

int VIDEOX;
int VIDEOY;

static unsigned char spriteData[] = {
0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,0,0,0,0,0,0,0,
0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,
0,0,0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,
0,0,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,0,0,0,
0,0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,0,0,0,
0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
0,0,0,1,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,1,0,0,0,0,
0,0,0,1,0,0,0,0,0,2,0,0,2,0,0,0,0,0,2,0,0,2,0,0,0,0,0,1,0,0,0,0,
0,0,0,1,0,0,0,0,0,2,0,0,2,0,0,0,0,0,2,0,0,2,0,0,0,0,0,1,0,0,0,0,
0,0,0,1,0,0,0,0,0,2,0,0,2,0,0,0,0,0,2,0,0,2,0,0,0,0,0,1,0,0,0,0,
0,0,0,1,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,1,0,0,0,0,
0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,
0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,
0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,
0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,
0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,
0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,
0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,
0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,
0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,
0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,
0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

static int getInfo(SDL_Surface *surface) {
   printf("Pitch = %d\n", surface->pitch);
   printf("Hardware surfaces avail  = %d\n", SDL_GetVideoInfo()->hw_available);
   printf("Window manager avail     = %d\n", SDL_GetVideoInfo()->wm_available);
   printf("Blitter hardware         = %d\n", SDL_GetVideoInfo()->blit_hw);
   printf("Colorkey blit hardware   = %d\n", SDL_GetVideoInfo()->blit_hw_CC);
   printf("Alpha blit hardware      = %d\n", SDL_GetVideoInfo()->blit_hw_A);
   printf("Software->Hardware accel = %d\n", SDL_GetVideoInfo()->blit_sw);
   if (SDL_GetVideoInfo()->hw_available == 1)
       printf("Video memory             = %d\n", SDL_GetVideoInfo()->video_mem);
   else
       printf("Video memory             = N/A\n");

   return SDL_GetVideoInfo()->hw_available;
}

static int doSlowPoints(SDL_Surface *surface) {
   int numFrames = 8;
   int k, i, j, ofs, yofs;
    int is_doublebuf = (surface->flags & SDL_DOUBLEBUF);

   if (SDL_LockSurface(surface) < 0) return k;
   for (k = 0; k < numFrames; k++) {
       yofs = 0;
       for (i = 0; i < VIDEOY; i++) {
           for (j = 0, ofs = yofs; j < VIDEOX; j++, ofs++) {
               ((unsigned char *)surface->pixels)[ofs] = (unsigned char)255 - k*16 - k;
           }
           yofs += surface->pitch;
          if(is_doublebuf) {
               SDL_Flip(surface);
           } else {
               SDL_UpdateRect(surface, 0, 0, VIDEOX, VIDEOY);
           }
       }
   }
   SDL_UnlockSurface(surface);
   return k;
}

static int doFastPoints(SDL_Surface *surface) {
   int numFrames = 256;
   int k, i, j, ofs, yofs;
     int is_doublebuf = (surface->flags & SDL_DOUBLEBUF);

   if (SDL_LockSurface(surface) < 0) return k;
   for (k = 0; k < numFrames; k++) {
       yofs = 0;
       for (i = 0; i < VIDEOY; i++) {
           for (j = 0, ofs = yofs; j < VIDEOX; j++, ofs++) {
               ((unsigned char *)surface->pixels)[ofs] = (unsigned char)255 - k;
           }
           yofs += surface->pitch;
       }
       if(is_doublebuf) {
           SDL_Flip(surface);
       } else {
           SDL_UpdateRect(surface, 0, 0, VIDEOX, VIDEOY);
       }
   }
   SDL_UnlockSurface(surface);
   return k;
}

static int doRects(SDL_Surface *surface) {
   int numRects = 4096;
   int k;
   SDL_Rect rect;
   int is_doublebuf = (surface->flags & SDL_DOUBLEBUF);

   if (SDL_LockSurface(surface) < 0) return k;
   rect.x = 0;
   rect.y = 0;
   for (k = 0; k < numRects; k++) {
       rect.x++;
       if (rect.x == VIDEOX - 6) rect.x = 0;
       rect.y++;
       if (rect.y == VIDEOY - 6) rect.y = 0;
       rect.w = (VIDEOX - rect.x)/2;
       rect.h = (VIDEOY - rect.y)/2;
       
       SDL_FillRect(surface, &rect, k % 256);
      if(is_doublebuf) {
           SDL_Flip(surface);
       } else {
           SDL_UpdateRect(surface, rect.x, rect.y, rect.w, rect.h);
       }
   }
   SDL_UnlockSurface(surface);
   return k;
}

static int doBlitter(SDL_Surface *surface) {
   int numBlits = 4096;
   int i, j;
   int ofs;
   int minx, miny;
   SDL_Rect rect, orect;
   SDL_Color colors[3];
   int is_doublebuf = (surface->flags & SDL_DOUBLEBUF);

   colors[0].r = 0;
   colors[0].g = 0;
   colors[0].b = 0;
   colors[1].r = 255;
   colors[1].g = 255;
   colors[1].b = 0;
   colors[2].r = 255;
   colors[2].g = 0;
   colors[2].b = 0;
   SDL_SetColors(surface, colors, 0, 3);

   if (SDL_LockSurface(surface) < 0) return 0;
   rect.x = 0;
   rect.y = 0;
   rect.w = VIDEOX;
   rect.h = VIDEOY;
   SDL_FillRect(surface, &rect, 0);
   for (i = 0; i < 32; i++)
       for (j = 0; j < 32; j++) {
           ofs = j*surface->pitch + i;
           ((unsigned char *)surface->pixels)[ofs] = spriteData[j*32 + i];
       }
   if(is_doublebuf) {
       SDL_Flip(surface);
   } else {
       SDL_UpdateRect(surface, 0, 0, 32, 32);
   }
   SDL_UnlockSurface(surface);

   rect.x = 32;
   rect.y = 32;
   rect.w = 32;
   rect.h = 32;
   orect.x = 0;
   orect.y = 0;
   orect.w = 32;
   orect.h = 32;

   rect.x = 0;
   rect.y = 0;
   for (i = 0; i < numBlits; i++) {
       orect.x = rect.x;
       orect.y = rect.y;
       rect.x++;
       if (rect.x >= VIDEOX - 32) rect.x = 0;
       rect.y++;
       if (rect.y >= VIDEOY - 32) rect.y = 0;
       minx = (orect.x < rect.x) ? orect.x : rect.x;
       miny = (orect.y < rect.y) ? orect.y : rect.y;
       SDL_BlitSurface(surface, &orect, surface, &rect);
       if(is_doublebuf) {
           SDL_Flip(surface);
       } else {
       	    SDL_UpdateRect(surface, minx, miny, 32, 32);
        }
    }
    return i;
}

int main(int argc, char **argv) {
    Uint32 video_flags;
    SDL_Surface *screen;
    time_t starttime;
    int i, iter, state = 0;
    int hw_avail = 1;
    double results[4][4];

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_TIMER);
    SDL_DC_ShowAskHz(SDL_FALSE);
    SDL_DC_Default60Hz(SDL_FALSE);
    SDL_DC_VerticalWait(SDL_FALSE);
    
 for (iter = 0; iter < 4; iter++) {
        for (i = 0; i < 4; i++)
            results[iter][i] = -1.0;

        switch (iter) {
            case 0:  
                puts("\n-----------------\n| DIRECT DRIVER |\n-----------------");
                SDL_DC_SetVideoDriver(SDL_DC_DIRECT_VIDEO);
                VIDEOX = 320;  
                VIDEOY = 240;
                video_flags = SDL_FULLSCREEN | SDL_HWSURFACE;
                fprintf(stderr, "Mode = 320x240, software SDL_HWSURFACE|SDL_FULLSCREEN normal\n");
                break;

            case 1:  
                puts("\n--------------\n| DMA DRIVER |\n--------------");
                SDL_DC_SetVideoDriver(SDL_DC_DMA_VIDEO);
                VIDEOX = 320;  
                VIDEOY = 240;
                video_flags = SDL_FULLSCREEN | SDL_DOUBLEBUF | SDL_HWSURFACE;
                fprintf(stderr, "Mode = 320x240, hardware SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN\n");
                break;

            case 2:  
           // Textured mode test
                puts("\n-------------------\n| TEXTURED DRIVER |\n-------------------");
                SDL_DC_SetVideoDriver(SDL_DC_TEXTURED_VIDEO);
                VIDEOX = TXR_X;
                VIDEOY = TXR_Y;
                video_flags = SDL_HWSURFACE;
                screen = SDL_SetVideoMode(VIDEOX, VIDEOY, 16, video_flags);
                SDL_DC_SetWindow(SCR_X, SCR_Y);
                fprintf(stderr, "Mode = 320x240 (texture: 512x256), hardware scaled\n");
                break;
                
            case 3:  // Textured mode with double buffer test
                puts("\n------------------------\n| TEXTURED DRIVER + DB |\n------------------------");
                SDL_DC_SetVideoDriver(SDL_DC_TEXTURED_VIDEO);
                VIDEOX = TXR_X;
                VIDEOY = TXR_Y;
                video_flags = SDL_HWSURFACE | SDL_DOUBLEBUF;
                screen = SDL_SetVideoMode(VIDEOX, VIDEOY, 16, video_flags);
                SDL_DC_SetWindow(SCR_X, SCR_Y);
                fprintf(stderr, "Mode = 320x240 (texture: 512x256), hardware scaled + double buffer\n");
                break;
        


            case 4:  
                puts("\n--------------\n| DMA DRIVER |\n--------------");
                SDL_DC_SetVideoDriver(SDL_DC_DMA_VIDEO);
                VIDEOX = 640;  
                VIDEOY = 480;
                video_flags = SDL_FULLSCREEN | SDL_DOUBLEBUF | SDL_HWSURFACE;
                fprintf(stderr, "Mode = 640x480, hardware SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_FULLSCREEN\n");
                break;
        }

        screen = SDL_SetVideoMode(VIDEOX, VIDEOY, 8, video_flags);
        if (screen == NULL) {
            fprintf(stderr, "Unable to set video mode.\n");
            continue;
        }

        if (iter == 0) {
            SDL_EventState(SDL_ACTIVEEVENT, SDL_IGNORE);
            SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);
            starttime = 1;
            state = 0;
            hw_avail = getInfo(screen);
            printf("\n");
        }

        // Slow points test
        starttime = SDL_GetTicks(); 
        fprintf(stderr, "Slow points test\n");
        state = doSlowPoints(screen);
        results[iter][0] = ((double)state * 1000) / (SDL_GetTicks() - starttime);
       
        // Fast points test
        starttime = SDL_GetTicks(); 
        fprintf(stderr, "Fast points test\n");
        for (i = 0; i < 2; i++)
            state = doFastPoints(screen);
        results[iter][1] = ((double)state * 1000) / (SDL_GetTicks() - starttime);

        // Rect fill test
        starttime = SDL_GetTicks(); 
        fprintf(stderr, "Rect fill test\n");
        state = doRects(screen);
        results[iter][2] = ((double)state * 1000) / (SDL_GetTicks() - starttime);
        
        // Blitter test
        starttime = SDL_GetTicks(); 
        fprintf(stderr, "32x32 Blitter test\n");
        state = doBlitter(screen);
        results[iter][3] = ((double)state * 1000) / (SDL_GetTicks() - starttime);

        SDL_Delay(500); // Small delay between tests
    }

    // Print results
    printf("\nResults for each driver mode:\n");
    printf("                          DIRECT   DMA     PVRTEXTURED    PVRTEXTURE+DB\n");
    printf("                          320x240 320x240 scaled  scaled\n");
    printf("Slow points (frames/sec): ");
    for (iter = 0; iter < 4; iter++)
        printf("%8g ", results[iter][0]);
    printf("\nFast points (frames/sec): ");
    for (iter = 0; iter < 4; iter++)
        printf("%8g ", results[iter][1]);
    printf("\n   Rect fill (rects/sec): ");
    for (iter = 0; iter < 4; iter++)
        printf("%8g ", results[iter][2]);
    printf("\n 32x32 blits (blits/sec): ");
    for (iter = 0; iter < 4; iter++)
        printf("%8g ", results[iter][3]);
    printf("\n");

    return 0;
}
