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
    game_entities = new std::vector<JSEntity*>();
}

// ** //
void JSScreen::add_game_entity(JSEntity* entity)
{
    game_entities->push_back(entity);
}

void JSScreen::handle_input(SDL_Event* event)
{
    for (JSEntity* en : *game_entities)
    {
        en->handle_input(event);
    }
}
void JSScreen::update(uint32_t delta)
{
    for (JSEntity* en : *game_entities)
    {
        en->update(delta);
    }
}
void JSScreen::render()
{
    SDL_RenderClear(renderer);
    for (JSEntity* en : *game_entities)
    {
        en->render();
    }
    SDL_RenderPresent(renderer);
}
JSScreen::~JSScreen()
{
    for (JSEntity* en : *game_entities)
    {
        free(en);
    }
}
