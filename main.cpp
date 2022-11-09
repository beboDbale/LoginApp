// FCI – Programming 1 – 2022 - Assignment 4
// Program Name: LoginApp.cpp
// Last Modification Date: 15/5/2022
// Author: Belal Ahmed Eid
// Purpose:This program is for login system

#include "LoginAppFunctinos.cpp"

int main() {

    loadUsers();
    int Choice;
    bool Case = true;
    while (Case) {
        cout << "what do you want to do from this menu\n"
                "1- Register\n"
                "2- Login\n"
                "3- Change Password\n"
                "4- Exit\n"
                ">>>> ";
        cin >> Choice;
        if (Choice == 1) {
            registeration();
        } else if (Choice == 2) {
            login();
        } else if (Choice == 3) {
            ChangePass();
        } else if (Choice == 4) {
            Case = false;
        } else cout << "the Choice you entered is not correct\n ";
    }
}

