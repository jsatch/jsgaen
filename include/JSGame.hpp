//
//  Game.hpp
//  GameEngine
//
//  Created by Hernan Quintana on 10/21/18.
//  Copyright © 2018 Hernan Quintana. All rights reserved.
//

#ifndef JSGame_hpp
#define JSGame_hpp

#include <iostream>
#include <exception>

#ifdef _WIN32
	#include <SDL.h>
#else
	#include <SDL2/SDL.h>
#endif

#include <sstream>
#include "JSScreen.hpp"
#include "JSScreenManager.hpp"
#define FPS 60


class JSCreationException : public std::exception
{
private:
    std::string message;
public:
    explicit JSCreationException(std::string message);
    const char * what () const throw ()
    {
        return message.c_str();
    }
    virtual ~JSCreationException() throw();
};

class JSGame
{
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    JSScreenManager* manager;
    uint32_t window_mode; // SDL_WINDOW_SHOWN o SDL_WINDOW_FULLSCREEN
    uint32_t width, height;
public:
    JSGame(uint32_t, uint32_t, uint32_t);
    void start();
    void set_start_controller(JSScreen* screen);
    SDL_Renderer* get_renderer();
    ~JSGame();
};

#endif /* JSGame_hpp */
