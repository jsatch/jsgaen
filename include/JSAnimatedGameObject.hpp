#ifndef JSAnimatedGameObject_hpp
#define JSAnimatedGameObject_hpp

#include <sstream>

#ifdef _WIN32
    #include <SDL.h>
	#include <SDL_image.h>
#else
    #include <SDL2/SDL.h>
	#include <SDL2_image/SDL_image.h>
#endif

#include "JSGame.hpp"
#include "JSGameObject.hpp"

class JSAnimatedGameObject : public JSGameObject
{
private:
    SDL_Rect* rect;
    SDL_Rect* inner_rect;
    SDL_Texture* texture;
    u_int32_t frame_index;
    u_int32_t width;
    u_int32_t height;
    u_int32_t x;
    u_int32_t y;
    u_int32_t offset; // space between frames
    double animation_speed; // Total number of frames of the animation
    u_int32_t current_frame_loop;
public:
    JSAnimatedGameObject(const char* path, SDL_Renderer* renderer);
    void update(u_int32_t ticks);
    void render(SDL_Renderer* renderer);
    void set_width(u_int32_t w);
    void set_height(u_int32_t h);
    void set_x(u_int32_t posx);
    void set_y(u_int32_t posy);
    void set_offset(u_int32_t off);
    void set_animation_speed(double speed);
    u_int32_t get_width();
    u_int32_t get_height();
    u_int32_t get_x();
    u_int32_t get_y();
    double get_animation_speed();
    SDL_Rect* get_rect();
    ~JSAnimatedGameObject();
};

#endif /* JSAnimatedGameObject_hpp */