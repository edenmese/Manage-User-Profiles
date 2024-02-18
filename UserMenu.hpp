//
//  Menu.hpp
//  Lab1 - Manage User Accounts
//
//  Created by Eden Meseret on 2/9/24.
//

#ifndef UserMenu_hpp
#define UserMenu_hpp
#include "User.hpp"
#include "Menu.hpp"
#include "DateTime.hpp"
#include <vector>
#include <ostream>
#include <fstream>
#include <string>
//#include <stdio.h>

using namespace std;


enum USER_MENU_OPTIONS {
  USER_MENU_SIGNIN = '1',
  USER_MENU_SIGNOUT = '2',
  USER_MENU_RESET = '3',
  USER_MENU_CREATE = '4',
  USER_MENU_MANAGEPROFILES = '5',
  USER_MENU_DOEXIT = 'x',
};


class UserMenu : public Menu{
public:
    UserMenu();
    ~UserMenu();
    
    void signIn();
    void signOut();
    void reset();
    void create();
    void manageProfiles();
    void doExit();
    void activate();
//    void setTempSignIn(DateTime& getCurrentTime());
    
    void loadCSV(const string filename);

    
    
    
    
private:
    //User user;
    vector<User>list;
    fstream myFile;
    bool signedIN;
    User tempUser;
//    DateTime tempSignIn, tempSignOut;



    
    
    
};


#endif /* UserMenu_hpp */
