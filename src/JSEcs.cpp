#include "JSEcs.hpp"

JSComponent::JSComponent()
{}
ComponentTypeID JSComponent::get_id()
{
    return id;
}
void JSComponent::handle_input(SDL_Event* event)
{}
void JSComponent::update(u_int32_t delta)
{}
void JSComponent::render()
{}
void JSComponent::set_entity(JSEntity* entity)
{
    this->entity = entity;
}
void JSComponent::set_active(bool active)
{
    this->active = active;
}
bool JSComponent::get_active() 
{
    return active;
}
JSComponent::~JSComponent()
{}

// -------------------------------------------------------------

JSEntity::JSEntity()
{}
template<typename T> bool JSEntity::has_component()
{
    return cBitSet[getComponentTypeID<T>];
}
template<typename T> T& JSEntity::get_component()
{
    auto ptr(cArray[getComponentTypeID<T>()]);
    return *static_cast<T*>(ptr);
}
template <typename T, typename... TArgs> T& JSEntity::add_component(TArgs&&... mArgs)
{
    T* c(new T(std::forward<TArgs>(mArgs)...));
    c->entity = this;
    std::unique_ptr<JSComponent> uPtr {c};
    components.emplace_back(std::move(uPtr));

    cArray[getComponentTypeID<T>()] = c;
    cBitSet[getComponentTypeID<T>()] = true;

    return *c;
}
void JSEntity::handle_input(SDL_Event* event)
{
    for (JSComponent* c : cArray)
    {
        if (c->get_active()) c->handle_input(event);
    }
}
void JSEntity::update(u_int32_t delta)
{
    for (JSComponent* c : cArray)
    {
        if (c->get_active()) c->update(delta);
    }

}
void JSEntity::render()
{
    for (JSComponent* c : cArray)
    {
        if (c->get_active()) c->render();
    }
}
JSEntity::~JSEntity()
{}