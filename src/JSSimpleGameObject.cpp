//
//  JSSimpleGameObject.cpp
//  GameEngine
//
//  Created by Hernan Quintana on 10/21/18.
//  Copyright © 2018 Hernan Quintana. All rights reserved.
//

#include "JSSimpleGameObject.hpp"


JSSimpleGameObject::JSSimpleGameObject(const char* path, SDL_Renderer* renderer) :JSGameObject()
{
    
    SDL_Surface* surface = IMG_Load(path);
    if (surface == nullptr){
        std::stringstream ss;
        ss << "IMG_Load Background Error" << SDL_GetError();
        throw JSCreationException(ss.str());
    }
    
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    
    if (texture == nullptr){
        std::stringstream ss;
        ss << "SDL_CreateTextureFromSurface Background Error"<< SDL_GetError();
        throw JSCreationException(ss.str());
    }
    
    rect = new SDL_Rect();
}
void JSSimpleGameObject::update(u_int32_t ticks)
{
    rect->x++;
}
void JSSimpleGameObject::render(SDL_Renderer* renderer)
{
    SDL_RenderCopy(renderer, texture, nullptr, rect);
}

SDL_Rect* JSSimpleGameObject::get_rect()
{
    return rect;
}
JSSimpleGameObject::~JSSimpleGameObject()
{
    SDL_DestroyTexture(texture);
    free(rect);
}
