//
//  JSScreen.cpp
//  GameEngine
//
//  Created by Hernan Quintana on 10/21/18.
//  Copyright © 2018 Hernan Quintana. All rights reserved.
//

#include "JSScreen.hpp"

JSScreen::JSScreen( SDL_Renderer* renderer)
{
    this->renderer = renderer;
    game_objects = new std::vector<JSGameObject*>();
}
void JSScreen::add_game_object(JSGameObject* object)
{
    game_objects->push_back(object);
}

JSScreen::~JSScreen()
{
    for (std::vector<JSGameObject*>::iterator it = game_objects->begin(); it != game_objects->end(); ++it)
    {
        JSGameObject* object = *it;
        free(object);
    }
}
