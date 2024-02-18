//
//  User.hpp
//  Lab1 - Manage User Accounts
//
//  Created by Eden Meseret on 2/9/24.
//

#ifndef User_hpp
#define User_hpp
#include <string>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include "DateTime.hpp"
using namespace std;

enum UPDATE_OPTIONS{
    UPDATE_NAME = 1,
    UPDATE_ROLE,
    UPDATE_ADDRESS,
    UPDATE_PHONE,
    UPDATE_EMAIL,
};
enum DELETE_OPTIONS{
    DELETE_NAME = 1,
    DELETE_ROLE,
    DELETE_ADDRESS,
    DELETE_PHONE,
    DELETE_EMAIL,
};

class User{

public:
    User();
    
    User(int id, const string&role, const string& username, const string& password,const DateTime& signIn_dt, const DateTime& signOut_dt, const string& firstName, const string& lastName, const string& address, const string& city, const string& state, const string& zip, const string& phone, const string& email);
    
//    User(string password, string username);
    
    User (const string& firstName,const string& lastName,const string& phone,const string& email,const string&password); //THIS IS FOR CREATE ACCOUNT CONSTRUCTOR
    ~User();
    
    void setId(int id);
    void setRole(string role);
    void setUsername(string user);
    void setPassword(string pass);
    void setFirstname(string firstName);
    void setLastname(string lastName);
    void setAddress(string addy);
    void setCity(string city);
    void setState(string state);
    void setZip(string zip);
    void setPhone(string phone);
    void setEmail(string email);
    void setSignIn_dt(const DateTime& signIn_dt);
    void setSignOut_dt(const DateTime& signOut_dt);
    

    int getiId() const;
    string getRole() const;
    string getUsername() const;
    string getPassword() const;
    string getFirstName() const;
    string getLastName() const;
    string getAddress() const;
    string getCity() const;
    string getState() const;
    string getZip() const;
    string getPhone() const;
    string getEmail() const;
    DateTime getSignInDt()const;
    DateTime getSignOutDt()const;
    
    bool operator==(const User& other) const;
    bool comparePassword(const string& oldPassword)const;
    void updateProfile(int option,User& user);
    void deleteAccount(User&user);
    
    bool getSignedIn() const;
    bool getSignedOut() const;
    void setSignedIn();
    void setSignedOut();
    
private:
    int id;
    string role, username, password, firstName,lastName, address, city, state, zip, phone, email;
    DateTime signIn_dt, signOut_dt;
    
//    string signInDt, signOutDt;
    bool signedIn;
    bool signedOut;
        
};

#endif /* User_hpp */
