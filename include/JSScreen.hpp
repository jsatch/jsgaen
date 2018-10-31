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
#include "JSGameObject.hpp"


class JSScreen
{
private:
    uint32_t width, height;
    SDL_Renderer* renderer;
    std::vector<JSGameObject*>* game_objects;
public:
    JSScreen(SDL_Renderer* renderer);
    void add_game_object(JSGameObject* object);
    virtual void update(uint32_t ticks) const
    {
        for (std::vector<JSGameObject*>::iterator it = game_objects->begin(); it != game_objects->end(); ++it)
        {
            JSGameObject* object = *it;
            object->update(ticks);
        }
    };
    virtual void render() const
    {
        SDL_RenderClear(renderer);
        for (std::vector<JSGameObject*>::iterator it = game_objects->begin(); it != game_objects->end(); ++it)
        {
            JSGameObject* object = *it;
            object->render(renderer);
        }
        SDL_RenderPresent(renderer);
    };
    ~JSScreen();
};


#endif /* JSScreen_hpp */

