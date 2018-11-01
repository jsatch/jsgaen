//
//  JSSimpleGameObject.hpp
//  GameEngine
//
//  Created by Hernan Quintana on 10/21/18.
//  Copyright © 2018 Hernan Quintana. All rights reserved.
//

#ifndef JSSimpleGameObject_hpp
#define JSSimpleGameObject_hpp

#include <sstream>

#ifdef _WIN32
	#include <SDL_image.h>
#else
	#include <SDL2_image/SDL_image.h>
#endif

#include "JSGame.hpp"
#include "JSGameObject.hpp"

class JSSimpleGameObject : public JSGameObject
{
private:
    SDL_Rect* rect;
    SDL_Texture* texture;
public:
    JSSimpleGameObject(const char* path, SDL_Renderer* renderer);
    void handle_input(SDL_Event* event);
    void update(u_int32_t ticks);
    void render(SDL_Renderer* renderer);
    SDL_Rect* get_rect();
    ~JSSimpleGameObject();
};

#endif /* JSSimpleGameObject_hpp */
