#include "JSEcs.hpp"

JSComponent::JSComponent()
{}
ComponentID JSComponent::get_id()
{
    return id;
}
void JSComponent::handle_input(SDL_Event* event)
{}
void JSComponent::update(uint32_t delta)
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
{
    components = new std::map<ComponentID, JSComponent*>();
}
JSComponent *JSEntity::get_component(ComponentID id)
{
    return components->at(id);
}
void JSEntity::add_component(ComponentID id, JSComponent *component)
{
    (*components)[id] = component;
    component->set_entity(this);
}
void JSEntity::handle_input(SDL_Event* event)
{
    for (std::pair<ComponentID, JSComponent*> c : *components)
    {
        if (c.second->get_active()) c.second->handle_input(event);
    }
}
void JSEntity::update(uint32_t delta)
{
    for (std::pair<ComponentID, JSComponent*> c : *components)
    {
        if (c.second->get_active()) c.second->update(delta);
    }

}
void JSEntity::render()
{
    for (std::pair<ComponentID, JSComponent*> c : *components)
    {
        if (c.second->get_active()) c.second->render();
    }
}
JSEntity::~JSEntity()
{
    free(components);
}