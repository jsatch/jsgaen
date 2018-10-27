//
//  JSScreenManager.hpp
//  GameEngine
//
//  Created by Hernan Quintana on 10/21/18.
//  Copyright © 2018 Hernan Quintana. All rights reserved.
//

#ifndef JSScreenManager_hpp
#define JSScreenManager_hpp

#include <stack>
#include "JSScreen.hpp"

class JSScreenManager 
{
private:
    std::stack<JSScreen> *screen_stack;
public:
    JSScreenManager();
    void push_screen(JSScreen* screen);
    void pop_screen();
    JSScreen* top();
    ~JSScreenManager();
};

#endif /* JSScreenManager_hpp */
