#include "JSEcs.hpp"

JSComponent::JSComponent()
{
    id = getComponentID();
}
JSComponent::JSComponent(JSEntity *entity)
{
    this->entity = entity;
    this->entity->add_component(id, this);
}
ComponentID JSComponent::get_id()
{
    return id;
}
void JSComponent::update(u_int32_t delta)
{}
void JSComponent::render()
{}
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
}
void JSEntity::handle_input(SDL_Event* event)
{}
void JSEntity::update(u_int32_t delta)
{
    for (std::pair<ComponentID, JSComponent*> c : *components)
    {
        (c.second)->update(delta);
    }

}
void JSEntity::render()
{
    for (std::pair<ComponentID, JSComponent*> c : *components)
    {
        (c.second)->render();
    }
}
JSEntity::~JSEntity()
{
    free(components);
}