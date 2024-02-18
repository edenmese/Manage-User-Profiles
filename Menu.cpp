//
//  Menu.cpp
//  Lab1 - Manage User Accounts
//
//  Created by Eden Meseret on 2/10/24.
//

#include "Menu.hpp"
#include "UserMenu.hpp"

Menu::Menu(){}


Menu::~Menu(){}


void Menu::displayMenu(UserMenu& menuChoice){
    quit = false;
    do{
        cout << "***** Manage User Accounts ******" << endl;
        cout << "1) Sign-In" << endl;
        cout << "2) Sign-Out" << endl;
        cout << "3) Reset Password" << endl;
        cout << "4) Create Account" << endl;
        cout << "5) Manage Profiles" << endl;
        cout << "x) Quit" << endl;
        
        cout << "Enter Choice: ";
        cin >> choice;
        
        switch(choice){
                
            case USER_MENU_SIGNIN:
                cout << "sign-in" << endl;
                menuChoice.signIn();
                break;
                
            case USER_MENU_SIGNOUT:
                cout << "sign-out" << endl;
                menuChoice.signOut();
                break;
                
            case USER_MENU_RESET:
                cout << "reset password" << endl;
                menuChoice.reset();
                break;
                
            case USER_MENU_CREATE:
                cout << "create account" << endl;
                menuChoice.create();
                break;
                
            case USER_MENU_MANAGEPROFILES:
                cout << "manage profiles" << endl;
                menuChoice.manageProfiles();

                break;
                
            case USER_MENU_DOEXIT:
                cout << "Menu Exited" << endl;
                menuChoice.doExit();
                quit = true;
                break;
        }
    }while(!quit);
}



