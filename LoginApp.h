#ifndef MAIN_CPP_LOGINAPP_H
#define MAIN_CPP_LOGINAPP_H


#include <bits/stdc++.h>
#include <fstream>
#include <conio.h>

using namespace std;
//-------------------------------------Variables------------------------------------------
fstream userfile, storingfile;
string filename = "user information.txt";
//structure with the information of the user
struct userInfo {
    string ID, username, email, phoneNum, password;
};
//using map of strings & structure
map<string, userInfo> UserProfile;

userInfo user;

//-------------------------------------Functions------------------------------------------
string encryption(string &Decrypt_Pass);
string Decrypt(string &Decrypt_Pass);
string password();
void loadUsers();
void fillfile();
void replace_password(string &pass, string pass2);
void registeration();
bool Check_ID(string ID);
void login();
void ChangePass();

#endif //MAIN_CPP_LOGINAPP_H
