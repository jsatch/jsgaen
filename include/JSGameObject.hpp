//
//  JSGameObject.hpp
//  GameEngine
//
//  Created by Hernan Quintana on 10/21/18.
//  Copyright © 2018 Hernan Quintana. All rights reserved.
//

#ifndef JSGameObject_hpp
#define JSGameObject_hpp

#include <SDL2/SDL.h>

class JSGameObject
{
    
public:
    JSGameObject();
    virtual void update(u_int32_t ticks) = 0;
    virtual void render(SDL_Renderer* renderer) = 0;
};

#endif /* JSGameObject_hpp */
