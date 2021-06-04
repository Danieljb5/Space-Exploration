#include "renderer.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

int i = 0;

void Renderer::clear(void)
{
    SDL_SetRenderDrawColor(app->renderer, bgCol.r, bgCol.g, bgCol.b, bgCol.a);
    SDL_RenderClear(app->renderer);
}

void Renderer::display(void)
{
    SDL_RenderPresent(app->renderer);
}

SDL_Texture* Renderer::loadTexture(char* filename)
{
    std::string msg = "Loading " + (std::string)filename;
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, msg.c_str());
    
    int w;
    int h;
    int of;
    int rf = STBI_rgb_alpha;
    unsigned char* data = stbi_load(filename, &w, &h, &of, rf);
    if(data == NULL) std::cout << "Failed to load image" << std::endl;
    int depth, pitch;
    Uint32 pixelFormat;
    depth = 32;
    pitch = 4 * w;
    pixelFormat = SDL_PIXELFORMAT_RGBA32;
    SDL_Surface* surf = SDL_CreateRGBSurfaceWithFormatFrom((void*)data, w, h, depth, pitch, pixelFormat);
    if(surf == NULL) std::cout << "Failed creating surface" << std::endl;
    SDL_Texture* texture = SDL_CreateTextureFromSurface(app->renderer, surf);
    SDL_FreeSurface(surf);
    stbi_image_free(data);
    if(texture == NULL) std::cout << "Failed creating texture" << std::endl;
    return texture;
}

void Renderer::blit(Sprite sprite)
{
    SDL_Rect dest;
    dest.x = sprite.x;
    dest.y = sprite.y;
    SDL_QueryTexture(sprite.texture, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(app->renderer, sprite.texture, NULL, &dest);
}