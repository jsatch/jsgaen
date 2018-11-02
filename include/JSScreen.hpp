//
//  JSScreen.hpp
//  GameEngine
//
//  Created by Hernan Quintana on 10/21/18.
//  Copyright © 2018 Hernan Quintana. All rights reserved.
//

#ifndef JSScreen_hpp
#define JSScreen_hpp

#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif
#include <vector>
#include "JSEcs.hpp"

class JSScreen
{
private:
    uint32_t width, height;
    SDL_Renderer* renderer;
    std::vector<JSEntity*>* game_entities;
public:
    JSScreen(SDL_Renderer* renderer);

    void add_game_entity(JSEntity* entity);
    virtual void handle_input(SDL_Event* event);
    virtual void update(uint32_t delta);
    virtual void render();
    ~JSScreen();
};


#endif /* JSScreen_hpp */

