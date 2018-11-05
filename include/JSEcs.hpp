#ifndef JSEcs_hpp
#define JSEcs_hpp

#include <vector>
#include <bitset>
#include <array>
#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

class JSComponent;
class JSEntity;

using ComponentTypeID = std::size_t;

inline ComponentTypeID getComponentTypeID()
{
    static ComponentTypeID last_id = 0;
    return last_id++;
}

template <typename T> inline ComponentTypeID getComponentTypeID() noexcept
{
    static ComponentTypeID type_id = getComponentTypeID();
    return type_id;
}

constexpr std::size_t max_components = 32;

using ComponentBitSet = std::bitset<max_components>;
using ComponentArray = std::array<JSComponent*, max_components>;


class JSComponent
{
protected:
    JSEntity* entity;
    ComponentTypeID id;
    bool active = true;
public:
    JSComponent();
    ComponentTypeID get_id();
    virtual void handle_input(SDL_Event* event);
    virtual void update(u_int32_t delta);
    virtual void render();
    void set_entity(JSEntity*);
    void set_active(bool);
    bool get_active();
    ComponentTypeID getComponentID()
    {
        static ComponentTypeID last_id = 0;
        return last_id++;
    }
    ~JSComponent();
};

class JSEntity
{
private:
    //std::map<ComponentID, JSComponent*>* components;
    std::vector<std::unique_ptr<JSComponent>> components;
    ComponentArray cArray;
    ComponentBitSet cBitSet;
public:
    JSEntity();
    template<typename T> bool has_component();
    template<typename T> T& get_component();
    template <typename T, typename... TArgs> T& add_component(TArgs&&... mArgs);
    virtual void handle_input(SDL_Event* event);
    virtual void update(u_int32_t delta);
    virtual void render();
    ~JSEntity();
};

#endif // JSEcs_hpp