//
//  Game.cpp
//  GameEngine
//
//  Created by Hernan Quintana on 10/21/18.
//  Copyright © 2018 Hernan Quintana. All rights reserved.
//

#include "JSGame.hpp"

JSCreationException::JSCreationException(std::string message)
{
    this->message = message;
}

JSCreationException::~JSCreationException() throw()
{}


void calculate_frame_rate(Uint32 starting_tick)
{
    if ((1000 / FPS) > SDL_GetTicks() - starting_tick)
    {
        SDL_Delay((1000 / FPS) - (SDL_GetTicks() - starting_tick));
    }
}

JSGame::JSGame()
{
    // Initializing SDL objects
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::cout << "Error SDL_Init: " << SDL_GetError() << std::endl;
    }
    
    window = SDL_CreateWindow("Game Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_FULLSCREEN);
    if (window == nullptr)
    {
        std::cout << "Error SDL_CreateWindow: " << SDL_GetError() << std::endl;
        SDL_Quit();
        std::stringstream ss;
        ss << "Error SDL_CreateWindow:" << SDL_GetError();
        throw JSCreationException(ss.str());
    }
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    
    if (renderer == nullptr)
    {
        std::cout << "Error SDL_CreateRenderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        std::stringstream ss;
        ss << "Error SDL_CreateRenderer:" << SDL_GetError();
        throw JSCreationException(ss.str());
    }
    
    // Initializing JSScreenManager
    manager = new JSScreenManager();
}
void JSGame::start()
{
    Uint32 starting_tick;
    bool running = true;
    SDL_Event event;
    while( running ) 
    {
        starting_tick = SDL_GetTicks();
        while ( SDL_PollEvent(&event) != 0)
        {
            if ( event.type == SDL_QUIT) 
            {
                running = false;
            }else if ( event.type == SDL_KEYDOWN)
            {
                if ( event.key.keysym.sym == SDLK_ESCAPE ){
                    running = false;
                }
            }
        }
        
        // TODO code for managing screen states
        manager->top()->update(starting_tick);
        manager->top()->render();
        
        calculate_frame_rate(starting_tick);
    }
}
void JSGame::set_start_controller(JSScreen* screen)
{
    manager->push_screen(screen);
}
SDL_Renderer* JSGame::get_renderer()
{
    return renderer;
}
JSGame::~JSGame()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
