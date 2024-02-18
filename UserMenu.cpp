//
//  Menu.cpp
//  Lab1 - Manage User Accounts
//
//  Created by Eden Meseret on 2/9/24.
//

#include "UserMenu.hpp"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>



UserMenu::UserMenu() : Menu(){}
UserMenu::~UserMenu(){}



void UserMenu::signIn(){
    string input;
    string password;
    cout << "Enter email or phone number: ";
    cin >> input;


    if (input.find('@') != string::npos){
//        cout << "found @" << endl;
        tempUser.setEmail(input);
//        cout << "tempUser email: " << tempUser.getEmail() << endl;
    }else {
        tempUser.setPhone(input); // LATER ADD MORE VALIDATION IF NOT EMAIL OR PHONE
    }
    cout << "Enter password: ";
    cin >> password;
    tempUser.setPassword(password);

    signedIN = false;

    for(int i = 0; i<list.size(); i++){
        
        User u = list[i];
        
        if (tempUser == u){
            signedIN = true;
            cout << "\nYAY! You are signed in\n" << endl;
            string dt = DateTime::now();
            tempUser.setSignIn_dt(DateTime(dt));
            
            tempUser.setSignedIn();
            break;
        }
    }
    if (!signedIN){
        cout << "No username or password found.\n" << endl;

    }
}


void UserMenu::signOut(){
    if (signedIN){
        signedIN = false;
        cout << "You have been signed out.\n" << endl;
        string dt = DateTime::now();
        tempUser.setSignOut_dt(DateTime(dt));
        tempUser.setSignedOut();
       
        
    }else {
        cout << "You are not signed in.\n" << endl;
    }
}

void UserMenu::reset(){
    int attempt = 0;
    if (signedIN){
        string oldPassword;
        string newPassword;
        
        
        int attempt = 0;
        while(attempt < 3){
            cout << "Enter old password: ";
            cin >> oldPassword;
            
            if (tempUser.comparePassword(oldPassword)){
                cout << "Enter new password: ";
                cin >> newPassword;
                tempUser.setPassword(newPassword);
                cout << "\nPassword reset Successfully\n"<< endl;
                cout << "temp Pass: " << tempUser.getPassword() << endl;
                
                break ;
            }
            else{
                cout << "Incorrect password. Try again.\n" << endl;
            }
            attempt++;
        }
        
    }
    else{
        cout << "\nYou must sign to reset password.\n" << endl;
    }
    if (attempt == 3){
        cout << "You have exceeded amount of attempts.";
    }
}


void UserMenu::create(){
    if (!signedIN){
        bool verified = false;
        cout << "verified = false : " << endl << endl;
        while (!verified){
            cout << "entered while loop " << endl << endl;
            string firstName;
            string lastName;
            string phoneNumber;
            string email;
            string password;
            
            cout << "Enter first name: ";
            cin >> firstName;
            cout << "Enter last name: ";
            cin >> lastName;
            cout << "Enter phone number: ";
            cin >> phoneNumber;
            cout << "Enter email: ";
            cin >> email;
            cout << "Enter password: ";
            cin >> password;
            
            tempUser.setFirstname(firstName);
            tempUser.setLastname(lastName);
            tempUser.setPhone(phoneNumber);
            tempUser.setEmail(email);
            tempUser.setPassword(password);
            //
            //        cout << "tempUser first: |" << tempUser.getFirstName() << "|\ntempUser pass: |" << tempUser.getPassword() << "|\n tempUser phone: |" << tempUser.getPhone() << "|\n tempUser email: |" << tempUser.getEmail() << "|\tempUser pass: |" << tempUser.getPassword() << "|" << endl;
            
            char confirmed;
            cout << "\nIs the following information all correct ?(Y/N)" << endl;
            cout << "First Name: |" << tempUser.getFirstName() << "|\nLast Name: |" << tempUser.getLastName() << "|\nPassword: |" << tempUser.getPassword() << "|\nPhone: |" << tempUser.getPhone() << "|\nEmail: |" << tempUser.getEmail() << "|\nPassword: |" << tempUser.getPassword() << "|" << endl;
            cin >> confirmed;
            if (toupper(confirmed) == 'Y'){
                //verified = true;
               tempUser.setId(list[list.size()-1].getiId()+1);
            
                
                cout << "\nAccount Created Succesfully!" << endl;
                //PUSH USER
                
                
                break;
            }
            else if (toupper(confirmed) == 'N') {
                cout << "re-enter information: " << endl << endl;
            }
        }
        
    }else {
        cout << "please sign out first" << endl << endl;
    }
}

void UserMenu::manageProfiles(){
    if (!signedIN){
        cout << "You must sign in to manage profiles.\n";
        return;
    }
    char action;
    cout << "\n(U)-Update info or (D)-Delete profile? ";
    cin >> action;
    if (toupper(action) == 'U'){
        int option;
        cout << "\nWhat would you like to update: " << endl;
        cout << "1)Name   2)Role   3)Address\n4)Phone   5)Email" <<endl;
        cout  << "Enter option: ";
        cin >> option;
        tempUser.updateProfile(option, tempUser);
    }else{
        tempUser.deleteAccount(tempUser);
    }
}


void UserMenu::doExit(){
    list.push_back(tempUser);
    
    ofstream outputFile("/Users/edenmese/Desktop/Ohlone/2024/CS-124/Lab1 - Manage User Accounts/Lab1 - Manage User Accounts/users_data__2.csv");
    if (!outputFile.is_open()){
        cout << "Error opening file for writing\n";
        return;
    }
    
    outputFile << "ID,Role,Username,Password,SignInDateTime,SignOutDateTime,FirstName,LastName,Address,City,State,Zip,Phone,Email\n";
    for (const auto&user : list){
        string signedInTime = "";
        string signedOutTime = "";
        if (user.getSignedIn()){
            signedInTime = user.getSignInDt().format();
        }
        if (user.getSignedOut()){
            signedOutTime = user.getSignOutDt().format();
        }
        outputFile << user.getiId() << "," << user.getRole() << "," << user.getUsername() << "," << user.getPassword() << "," << signedInTime << "," << signedOutTime << "," << user.getFirstName() << "," << user.getLastName() << "," << user.getAddress() << "," << user.getCity() << "," << user.getState()  << "," << user.getZip() << "," << user.getPhone() << "," << user.getEmail() << "\n";
    }
    outputFile.close();
    
}
                      
void UserMenu::activate(){
    loadCSV("/Users/edenmese/Desktop/Ohlone/2024/CS-124/Lab1 - Manage User Accounts/Lab1 - Manage User Accounts/users_data.csv");
    displayMenu(*this);
    
//    Menu application;
//    loadCSV("/Users/edenmese/Desktop/Ohlone/2024/CS-124/Lab1 - Manage User Accounts/Lab1 - Manage User Accounts/users_data.csv");
//    
//    application.displayMenu(*this);

}

void UserMenu::loadCSV(const string filename){
    myFile.open(filename,ios::in);   // Read

    if (!myFile.is_open()){       // Returns error is file does not open
        cout << "Error opening file\n";
        return;
    }
    
    string firstLine;
    getline(myFile, firstLine); // discard first line in users_data.csv, this function read \n too
        
    while (!myFile.eof()){
        string line;
        getline(myFile, line); //read \n too
        
        line.erase(line.find_last_not_of("\n\r") + 1);
        if (line.empty()){
            continue;
        } 
        
        istringstream ss(line);

        int id;
        string role, username, password, inDt, outDt, firstName, lastName, address, city, state, zip, phone, email;
        
        string idStr;
        getline(ss, idStr, ',');
        id = stoi(idStr);
        
        getline(ss,role,',');
        getline(ss,username,',');
        getline(ss,password,',');
        getline(ss,inDt,',');
        getline(ss,outDt,',');
        getline(ss,firstName,',');
        getline(ss,lastName,',');
        getline(ss,address,',');
        getline(ss,city,',');
        getline(ss,state,',');
        getline(ss,zip,',');
        getline(ss,phone,',');
        getline(ss,email,',');
        
        DateTime signInDt(inDt); // reads, sepeartes and initializes sign in time
        DateTime signOutDt(outDt); // reads, sepeartes and initializes sign out time
        
        User user(id, role, username, password,signInDt, signOutDt, firstName, lastName, address, city, state, zip, phone, email);
        list.push_back(user);
        
        cout << "Loaded phone: " << user.getPhone() << " Pass:" << user.getPassword() << endl;
    }
    myFile.close();

}
