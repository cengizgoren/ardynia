#ifndef renderer_h
#define renderer_h

#include <Arduino.h>
#include <Arduboy2.h>
#include "tinyfont.h"
#include "drawBitmap.h"

class Renderer {
    private:
        Arduboy2* arduboy;
        SpritesB sprite;
        Tinyfont tinyFont;

    public:
        Renderer(Arduboy2* arduboy):
            arduboy(arduboy),
            tinyFont(arduboy->sBuffer, WIDTH, HEIGHT),
            translateX(0),
            translateY(0)
        {}

        int16_t translateX;
        int16_t translateY;

        void fillRect(int16_t x, int16_t y, uint8_t w, uint8_t h, uint8_t color = WHITE);
        void drawRect(int16_t x, int16_t y, uint8_t w, uint8_t h, uint8_t color = WHITE);
        void fillCircle(int16_t x, int16_t y, uint8_t r, uint8_t color = WHITE);
        void drawOverwrite(int16_t x, int16_t y, const uint8_t* bitmap, uint8_t frame, MirrorMode mirror = 0, bool invert = false);
        void drawPlusMask(int16_t x, int16_t y, const uint8_t* bitmap, uint8_t frame, MirrorMode mirror = 0, bool invert = false);
        void print(int16_t x, int16_t y, const __FlashStringHelper* message);
        void print(int16_t x, int16_t y, int16_t num);
};

#endif

