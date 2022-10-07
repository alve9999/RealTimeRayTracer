#include "SDL_container.h"
#include "pixel_buffer.h"
#include "common.h"

SDL_container::SDL_container() {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(
        "RTRY",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        screen_width,
        screen_height,
        0
    );
    renderer = SDL_CreateRenderer(window, -1, 0);
}

void SDL_container::render_pixel_buffer(glm::vec3* image) {
    for (int i=0; screen_height > i; i++) {
        for (int j = 0; screen_width > j; j++) {
            glm::vec3 colour = image[i / screen_height * screen_width + i % screen_width];
            SDL_SetRenderDrawColor(renderer, int(colour.x*255), int(colour.y * 255), int(colour.z*255), 255);
            SDL_RenderDrawPoint(renderer, i, j);
        }
    }
    SDL_RenderPresent(renderer);
}
