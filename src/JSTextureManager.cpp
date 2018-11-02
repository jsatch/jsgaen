#include "JSTextureManager.hpp"

SDL_Texture* JSTextureManager::load_texture(const char* filename, SDL_Renderer* renderer)
{
    SDL_Surface *surface = IMG_Load(filename); 
    if (surface == nullptr)
    {
        std::stringstream ss;
        ss << "IMG_Load Background Error" << SDL_GetError();
        throw JSCreationException(ss.str());  
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (texture == nullptr)
    {
        std::stringstream ss;
        ss << "SDL_CreateTextureFromSurface Background Error" << SDL_GetError();
        throw JSCreationException(ss.str());
    }
    return texture;
}