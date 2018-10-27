//
//  JSSimpleGameObject.hpp
//  GameEngine
//
//  Created by Hernan Quintana on 10/21/18.
//  Copyright © 2018 Hernan Quintana. All rights reserved.
//

#ifndef JSSimpleGameObject_hpp
#define JSSimpleGameObject_hpp

#include <string>
#include <sstream>
#include <SDL2_image/SDL_image.h>
#include "JSGame.hpp"
#include "JSGameObject.hpp"

class JSSimpleGameObject : public JSGameObject
{
private:
    SDL_Rect* rect;
    SDL_Texture* texture;
public:
    JSSimpleGameObject(std::string path, SDL_Renderer* renderer);
    void update(u_int32_t ticks);
    void render(SDL_Renderer* renderer);
    SDL_Rect* get_rect();
    ~JSSimpleGameObject();
};

#endif /* JSSimpleGameObject_hpp */
