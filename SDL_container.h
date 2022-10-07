#pragma once
#include "SDL.h"
#include "pixel_buffer.h"

class SDL_container {
public:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_container();

    void render_pixel_buffer(glm::vec3* image);
};


