#ifndef JSTextureManager_hpp
#define JSTextureManager_hpp

#ifdef _WIN32
    #include <SDL.h>
	#include <SDL_image.h>
#else
    #include <SDL2/SDL.h>
	#include <SDL2_image/SDL_image.h>
#endif

#include <sstream>
#include "JSGame.hpp"

class JSTextureManager
{
public:
    static SDL_Texture* load_texture(const char* filename, SDL_Renderer* renderer);
};

#endif // JSTextureManager_hpp