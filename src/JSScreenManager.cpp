//
//  JSScreenManager.cpp
//  GameEngine
//
//  Created by Hernan Quintana on 10/21/18.
//  Copyright © 2018 Hernan Quintana. All rights reserved.
//

#include "JSScreenManager.hpp"

JSScreenManager::JSScreenManager()
{
    screen_stack = new std::stack<JSScreen>();
}
void JSScreenManager::push_screen(JSScreen* screen)
{
    screen_stack->push(*screen);
}
void JSScreenManager::pop_screen()
{
    screen_stack->pop();
}
JSScreen* JSScreenManager::top()
{
    return &screen_stack->top();
}
JSScreenManager::~JSScreenManager()
{
    while (!screen_stack->empty())
    {
        free(&screen_stack->top());
        screen_stack->pop();
    }
}
