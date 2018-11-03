#ifndef JSEcs_hpp
#define JSEcs_hpp

#include <map>
#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

using ComponentID = std::size_t;


class JSComponent;
class JSEntity;

class JSComponent
{
protected:
    JSEntity* entity;
    ComponentID id;
    bool active = true;
public:
    JSComponent();
    ComponentID get_id();
    virtual void handle_input(SDL_Event* event);
    virtual void update(u_int32_t delta);
    virtual void render();
    void set_entity(JSEntity*);
    void set_active(bool);
    bool get_active();
    ComponentID getComponentID()
    {
        static ComponentID last_id = 0;
        return last_id++;
    }
    ~JSComponent();
};

class JSEntity
{
private:
    std::map<ComponentID, JSComponent*>* components;
public:
    JSEntity();
    JSComponent* get_component(ComponentID id);
    void add_component(ComponentID id, JSComponent* component);
    virtual void handle_input(SDL_Event* event);
    virtual void update(u_int32_t delta);
    virtual void render();
    ~JSEntity();
};

#endif // JSEcs_hpp