//
//  Menu.hpp
//  Lab1 - Manage User Accounts
//
//  Created by Eden Meseret on 2/10/24.
//

#ifndef Menu_hpp
#define Menu_hpp
//#include "UserMenu.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
class UserMenu;

class Menu {
    
public:
    
    Menu();
    ~Menu();
    void displayMenu(UserMenu& menuChoice);
//    void getCurrentTime();
    
    
    
private:
    
    bool quit = false;
    char choice;
};




#endif /* Menu_hpp */
