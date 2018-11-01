#include "JSAnimatedGameObject.hpp"

JSAnimatedGameObject::JSAnimatedGameObject(const char* path, SDL_Renderer* renderer) :JSGameObject()
{
    SDL_Surface *surface = IMG_Load(path);
    if (surface == nullptr)
    {
        std::stringstream ss;
        ss << "IMG_Load Background Error" << SDL_GetError();
        throw JSCreationException(ss.str());
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (texture == nullptr)
    {
        std::stringstream ss;
        ss << "SDL_CreateTextureFromSurface Background Error" << SDL_GetError();
        throw JSCreationException(ss.str());
    }

    rect = new SDL_Rect();
    inner_rect = new SDL_Rect();
    frame_index = 0;

    animation_speed = 5; // Default
}
void JSAnimatedGameObject::handle_input(SDL_Event* event)
{
    // TO change for ECS
    switch(event->key.keysym.sym)
    {
        case SDLK_UP:
            y -= 10;
        break;
        case SDLK_DOWN:
            y += 10;
        break;
        case SDLK_LEFT:
            x -= 10;
        break;
        case SDLK_RIGHT:
            x += 10;
        break;
    }
}
void JSAnimatedGameObject::update(u_int32_t ticks)
{
    if (current_frame_loop >  (animation_speed / 8.0))
    {
        frame_index++;
        current_frame_loop = 0;

        if (frame_index == 8)
        {
            frame_index = 0;
        }
    }else{
        current_frame_loop++;
    }
}
void JSAnimatedGameObject::render(SDL_Renderer* renderer)
{
    inner_rect->x = frame_index * (width  + offset);
    inner_rect->y = 0;
    inner_rect->w = width;
    inner_rect->h = height;

    rect->x = x;
    rect->y = y;
    rect->w = width;
    rect->h = height;
    SDL_RenderCopy(renderer, texture, inner_rect, rect);
}
void JSAnimatedGameObject::set_width(u_int32_t w)
{
    width = w;
}
void JSAnimatedGameObject::set_height(u_int32_t h)
{
    height = h;
}
void JSAnimatedGameObject::set_x(u_int32_t posx)
{
    x = posx;
}
void JSAnimatedGameObject::set_y(u_int32_t posy)
{
    y = posy;
}
void JSAnimatedGameObject::set_offset(u_int32_t off)
{
    offset = off;
}
void JSAnimatedGameObject::set_animation_speed(double speed)
{
    animation_speed = speed;
}
u_int32_t JSAnimatedGameObject::get_width()
{
    return width;
}
u_int32_t JSAnimatedGameObject::get_height()
{
    return height;
}
u_int32_t JSAnimatedGameObject::get_x()
{
    return x;
}
u_int32_t JSAnimatedGameObject::get_y()
{
    return y;
}
double JSAnimatedGameObject::get_animation_speed()
{
    return animation_speed;
}
SDL_Rect *JSAnimatedGameObject::get_rect()
{
    return rect;
}
JSAnimatedGameObject::~JSAnimatedGameObject()
{
    SDL_DestroyTexture(texture);
    free(inner_rect);
    free(rect);
}