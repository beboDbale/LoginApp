#include "LoginApp.h"

//-------------------------------------Functions------------------------------------------
//encrypting password
string encryption(string &Decrypt_Pass) {
    //simple substitution cipher
    //putting the ciphered characters in a vector
    int ind;
    vector<char> cipherChar;
    string Char;
    cipherChar.push_back('c');
    cipherChar.push_back('a');
    cipherChar.push_back('i');
    cipherChar.push_back('r');
    cipherChar.push_back('o');

    for (int i = 97; i <= 122; i++)
        // to add the whole lower case character in the string
        Char.push_back(char(i));

    for (int i = 65; i <= 90; i++)
        // to add the whole upper case character in the string
        Char.push_back(char(i));

    for (int i = 97; i <= 122; i++) {
        //if the character in lower case isn't repeated add it to cipherChar
        if (!count(cipherChar.begin(), cipherChar.end(), char(i)))

            cipherChar.push_back(char(i));

    }

    cipherChar.push_back('C');

    cipherChar.push_back('A');

    cipherChar.push_back('I');

    cipherChar.push_back('R');

    cipherChar.push_back('O');

    for (int i = 65; i <= 90; i++) {
        //if the character in upper case isn't repeated add it to cipherChar
        if (!count(cipherChar.begin(), cipherChar.end(), char(i)))

            cipherChar.push_back(char(i));

    }

    for (char &Pas: Decrypt_Pass) {
        // if pas was = space ---> add to its ascii 1 ---> !
        if (Pas == ' ')

            Pas = char(int(Pas) + 1);

        else if (ispunct(Pas) || isdigit(Pas)) {
            // if pas was = digit/punctuation sign  ---> substract 1  from its ascii
            Pas = char(int(Pas) - 1);

        } else {
            // put the index of pas in ind variable
            ind = (int) Char.find(Pas);
            //pas = the charcter which found in the index of pas in cipherchar vector
            Pas = (char) cipherChar.at(ind);

        }
    }

    return Decrypt_Pass;
}

// to decrypt password when riching it
string Decrypt(string &Decrypt_Pass) {
//to save ciphered characters in vector
    int ind;

    vector<char> cipherChar;

    string Char;

    cipherChar.push_back('c');

    cipherChar.push_back('a');

    cipherChar.push_back('i');

    cipherChar.push_back('r');

    cipherChar.push_back('o');

    for (int i = 97; i <= 122; i++)

        Char.push_back(char(i));

    for (int i = 65; i <= 90; i++)

        Char.push_back(char(i));

    for (int i = 97; i <= 122; i++) {

        if (!count(cipherChar.begin(), cipherChar.end(), char(i)))

            cipherChar.push_back(char(i));

    }

    cipherChar.push_back('C');

    cipherChar.push_back('A');

    cipherChar.push_back('I');

    cipherChar.push_back('R');

    cipherChar.push_back('O');

    for (int i = 65; i <= 90; i++) {

        if (!count(cipherChar.begin(), cipherChar.end(), char(i)))

            cipherChar.push_back(char(i));

    }

    for (char &Pas: Decrypt_Pass) {
        // if pas was = ! ---> substract from its ascii 1 ---> space
        if (Pas == '!')

            Pas = char(int(Pas) - 1);

        else if (ispunct(Pas) || isdigit(Pas)) {
            // if pas was = digit/puctuation sign  ---> add to its ascii 1
            Pas = char(int(Pas) + 1);

        } else {
            // to find the index of pas in the vector
            auto it = find(cipherChar.begin(), cipherChar.end(), Pas);
            //if the index of pas not equal its end
            if (it != cipherChar.end())
                // substract vector beginning  from the the index of its index
                ind = int(it - cipherChar.begin());
            //pas = the charcter which found in the index of pas in char string
            Pas = Char.at(ind);

        }
    }

    return Decrypt_Pass;
}

//----------------------
string password() {
    string pass1, pass2;
    bool check = false;
//condition for a strong password
    cout << "the password should be strong \n1-You should enter at least one character capital\n";
    cout
            << "2- the password should contain nums and special character \n3- Password should contain at least one space\n\n";
    regex chk("((?=.*[a-z])(?=.*[0-9])(?=.*[A-Z])(?=.*[!?_.,/><*&^%$#@ ]*)[a-zA-Z0-9!?_.,/><*&^%$#@ ]*){8,15}");
//check if the password is strong
    repeat:
    //to print **** when entering the password
    do {
        pass1 = "";
        pass2 = "";

        cout << "enter your password here :";
        int Check = 0;
        char character;
        //to enter password as *******
        // while the character the user enter not equal " Enter "
        while ((character = getch()) != '\r') {
            // to check that the size of password from 8 to 15 characters
            if (character < 0 || Check % 2 != 0) {

                Check++;

            }

                // if the character of password = Backspace
            else if (character == 8) {
                // if password wasn't empty

                if (!pass1.empty()) {
                    //delete the last element of the  password
                    pass1.pop_back();

                    cout << character << " " << character;

                }
            } else {
                //add charcters to the password
                pass1 += character;

                cout << "*";

            }
        }

        if (regex_match(pass1, chk)) {
            cout << "\nenter your password again here :";
            int Check = 0;
            char character;
            //to enter password as *******
            // while the character the user enter not equal " Enter "
            while ((character = getch()) != '\r') {
                // to check that the size of password from 8 to 15 characters
                if (character < 0 || Check % 2 != 0) {
                    Check++;
                }
                    // if the character of password = Backspace
                else if (character == 8) {
                    // if password wasn't empty
                    if (!pass2.empty()) {
                        //delete the last element of the  password
                        pass2.pop_back();
                        cout << character << " " << character;
                    }
                } else {
                    //add charcters to the password
                    pass2 += character;

                    cout << "*";

                }
            }
        } else {
            cout << "\nyour password is not strong\n";
            goto repeat;

        }

        if (pass1 == pass2) {
            check = true;
        } else {
            cout << "\nyour password is not strong or matching \n";
            goto repeat;
        }
    } while (!regex_match(pass1, chk));
    if (check) {
        cout << "\nyour password is strong and matching :)\n ";
    }
    return pass1;
}
//-------------------------------------------------------------------------------------------------------

void loadUsers() {
    userfile.close();

    userfile.open(filename);

    string Id, User_Name, Email, phoneNum, Password;

    while (userfile.peek() != EOF) {  // to check that the size of password from 8 to 15 characters
//read the information of user
        getline(userfile, Id);

        getline(userfile, User_Name);

        getline(userfile, Email);

        getline(userfile, phoneNum);

        getline(userfile, Password);
        // to access the elements of the map by key " ID"
        UserProfile[Id] = {Id, User_Name, Email, phoneNum, Password};

    }

    userfile.close();
}

//-------------------------------------------------------------------------------------------------------
void fillfile() {
    //to store the information of user in the  file
    userfile.close();
    userfile.open(filename, ios::app);

    userfile << user.ID << endl;
    userfile << user.username << endl;
    userfile << user.email << endl;
    userfile << user.phoneNum << endl;
    userfile << user.password << endl;

    userfile.close();
}

void replace_password(string &pass, string pass2) {
    //to update the new password in the file
    string line, data;
    userfile.close();
    userfile.open("user information.txt");
    //to read each line in the file
    while (userfile.peek() != EOF) {
        //to read each line in the file
        getline(userfile, line);
        //if the password the user entered is found in the file
        if (pass == line) {
            // add the new password to data string
            data += pass2;
            cout << "\nthe password has been changed :)\n";
        } else {
            //else copy the line in the data
            data += line;
        }
        data += "\n";
    }
// we now have the data of user updated with the new password
    userfile.close();
    userfile.open("user information.txt", ios::out);
    //write the data in the file
    userfile << data;
    userfile.close();
}

//--------------------------------------------------------------------------------------------------------
void registeration() {
    // to allow user to register and entering his information
    bool ret = false;
    // to take the id from the user
    cout << "please enter your id :";
    cin >> user.ID;
    // condition of ID that it contains only numbers
    regex int_format("[0-9]+");
    // if the ID matches our format ---> true
    if (regex_match(user.ID, int_format))
        ret = true;
    // if the ID didn't match take it from user again and check
    while (!ret) {
        cout << "invalid id please enter again: ";
        cin >> user.ID;
        if (regex_match(user.ID, int_format))
            ret = true;
    }
    // to take the id from the user
    cout << "please enter your phoneNum :";
    cin >> user.phoneNum;
    // coindition of phone number that it start with 011/012/010/015 and after it only 8 digits
    regex phoneNumformat("(011|012|010|015)+[0-9]{8}");
    // if the phone number matches our format
    ret = regex_match(user.phoneNum, phoneNumformat);
    // if the phone number didn't match take it from user again and check
    while (!ret) {

        cout << "invalid phoneNum please enter again: ";
        cin >> user.phoneNum;
        ret = regex_match(user.phoneNum, phoneNumformat);
    }
    // to take the username from the user
    cout << "please enter your user name :";
    cin >> user.username;
    string username1 = user.username;
    // condition of username that it contains alpha lower/upper case + _ + alpha lower/upper case
    regex usernameformat("([a-zA-Z])+[\\_]?([a-zA-Z])+");
    ret = regex_match(user.username, usernameformat);
    // if the username didn't match take it from user again and check
    while (!ret) {

        cout << "invalid username please enter again: ";
        cin >> user.username;
        ret = regex_match(user.username, usernameformat);
    }
    if (UserProfile.count(username1)>1) {
        cout << "invalid username please enter again: ";
        cin >> user.username;
        ret = regex_match(user.username, usernameformat);
    }
    // to take the email from the user
    cout << "please enter your email :";
    cin >> user.email;
    // condition of email that it it has alpha lower/upper case + @ + alpha lower/upper case
    regex emailformat("^[a-zA-Z0-9+_.-]+@[a-zA-Z.-]+$");
    ret = regex_match(user.email, emailformat);
    // if the email didn't match take it from user again and check
    while (!ret) {

        cout << "invalid email please enter again: ";
        cin >> user.email;
        ret = regex_match(user.email, emailformat);

    }
    cout << "";
    user.password = password();

    encryption(user.password);

    fillfile();
    loadUsers();

    cout << "the registration completed successfully" << endl;
}

//to confirm that the ID is correct
bool Check_ID(string ID) {
// if the ID is not repeated
    if (UserProfile.count(ID) == 1) {
        return true;
    } else {
        return false;
    }
}

//---------------------------------------------------------------------------------------------------------
// to allow the user to login when he is registred before
void login() {
    string ID;
    int n = 2;
    string password;
    id:
// take from user the id
    cout << "please enter your id :";
    cin >> ID;
// if ID is not found in the file enter the ID again
    if (!Check_ID(ID)) {
        cout << "The ID is not Exist...";

        goto id;
    }

    string name = UserProfile[ID].username;

    string getpassword;
    getpassword = Decrypt(UserProfile[ID].password);

    label:

    cout << "please enter your password :";

    char character;
    int Check = 0;
    string pass1;
    //to enter password as *******
    // while the character the user enter not equal " Enter "
    while ((character = getch()) != '\r') {
        // to check that the size of password from 8 to 15 characters
        if (character < 0 || Check % 2 != 0) {

            Check++;

        }
            // if the character of password = Backspace
        else if (character == 8) {
            // if password wasn't empty
            if (!pass1.empty()) {
                //delete the last element of the  password
                pass1.pop_back();

                cout << character << " " << character;

            }
        } else {

            pass1 += character;

            cout << "*";

        }
    }
// if the password the user enter matches the password in the file --> success
    if (getpassword == pass1) {
        cout << "\nSuccessful login, welcome " << name << endl;

    } else {
        // else ---> failed ---> remove the password and enter the password again
        cout << "\nFailed login.. pass again.\n";
        pass1 = "";
        //decrese the number of trials to deny the user
        while (n--) {
            cout << "you have " << n + 1 << " chance to login before ban!!\n";
            goto label;
        }
        //if the user tried 3 times to login and failed
        cout << "\nyou are denied of access to the system \n";
    }
//encrypt password again
    encryption(UserProfile[ID].password);

}

//---------------------------------------------------------------------------------------------------------
//to change the password if the user choose this option
void ChangePass() {
    string ID;
    string password;
    id:
// ask user to enter his id
    cout << "please enter your id :";
    cin >> ID;
// check if the ID is found in the file
    if (!Check_ID(ID)) {
        cout << "The ID is not Exist...";

        goto id;
    }
//acessing the user name of user using the key of map
    string name = UserProfile[ID].username;


    label:
    string getpassword;
//acessing the password of user using the key of map
    getpassword = UserProfile[ID].password;
    getpassword = Decrypt(getpassword);

    cout << "please enter your password :";

    char character;
    int Check = 0;
    string old_password, new_password, repeatedPass;
//to enter password as *******
// while the character the user enter not equal " Enter "
    while ((character = getch()) != '\r') {
        //check password size  from 8 to 15 characters
        if (character < 0 || Check % 2 != 0) {

            Check++;

        }
            // if the character of password = Backspace
        else if (character == 8) {
            // if  the old password wasn't empty
            if (!old_password.empty()) {
                //delete the last element of the old  password
                old_password.pop_back();

                cout << character << " " << character;

            }
        } else {

            old_password += character;

            cout << "*";

        }
    }
// if the password is not correct enter the password again
    if (old_password != getpassword) {
        old_password = "";
        getpassword = "";
        cout << "\nthe password is not correct....\n";
        goto label;
    }
    label2:
    cout << "\nenter the new password :";
    //to enter password as *******
    // while the character the user enter not equal " Enter "
    while ((character = getch()) != '\r') {
        // to check that the size of password from 8 to 15 characters

        if (character < 0 || Check % 2 != 0) {
            Check++;
        }
            // if the character of password = Backspace
        else if (character == 8) {
            // if  the new password wasn't empty
            if (!new_password.empty()) {
                //delete the last element of the  new password
                new_password.pop_back();

                cout << character << " " << character;

            }
        } else {
            new_password += character;
            cout << "*";
        }
    }
    // the condition of strong password
    regex chk("((?=.*[a-z])(?=.*[0-9])(?=.*[A-Z])(?=.*[!?_.,/><*&^%$#@ ]*)[a-zA-Z0-9!?_.,/><*&^%$#@ ]*){8,15}");
    if (!(regex_match(new_password, chk))) {
        new_password = "";

        cout << "\nyour password is not strong :)\n ";
        goto label2;
    }

    cout << "\nenter the new password again :";
    //to enter password as *******
    // while the character the user enter not equal " Enter "
    while ((character = getch()) != '\r') {
        // to check that the size of password from 8 to 15 characters
        if (character < 0 || Check % 2 != 0) {
            Check++;
        }
            // if the character of password = Backspace
        else if (character == 8) {
            //repeated pass is not empty
            if (!repeatedPass.empty()) {
                // remove the last character of the password
                repeatedPass.pop_back();

                cout << character << " " << character;

            }
        } else {
            // add  the character to the repeated pass string and print *
            repeatedPass += character;

            cout << "*";

        }
    }
    // if the new password didn't match the reapeated one  start from label again
    if (!(repeatedPass == new_password)) {
        cout << "\nyour password is not matching\n :)\n ";
        new_password = "";
        repeatedPass = "";

        goto label2;
    }
// to store the new password encrypted in the file
    new_password = encryption(new_password);
    old_password = encryption(old_password);
    replace_password(old_password, new_password);
    //-----------------------
    // to replace the old password by the new one in the struct
    user.password = new_password;
    loadUsers();
}