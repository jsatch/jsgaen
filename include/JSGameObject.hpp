//
//  JSGameObject.hpp
//  GameEngine
//
//  Created by Hernan Quintana on 10/21/18.
//  Copyright © 2018 Hernan Quintana. All rights reserved.
//

#ifndef JSGameObject_hpp
#define JSGameObject_hpp

#ifdef _WIN32
typedef __int32 int32_t;
typedef unsigned __int32 u_int32_t;
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

class JSGameObject
{
    
public:
    JSGameObject();
    virtual void handle_input(SDL_Event* event) = 0;
    virtual void update(u_int32_t ticks) = 0;
    virtual void render(SDL_Renderer* renderer) = 0;
};

#endif /* JSGameObject_hpp */
