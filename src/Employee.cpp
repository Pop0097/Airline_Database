//
// Created by Dhruv Rawat on 2020-06-17.
//

#import "Classes.h"

Employee::Employee() {
    username = "d_uname";
    encrypted_password = passwordEncrypt("pass", "A5HDUQ71JRBC0SK2HRU");
    name = "Default Name";
    employeeID = "Dafault ID";
}

string Employee::passwordEncrypt(string pass, string key) { //method encrypts the password
    //ensures the key is (at a minimum) as long as the message
    string tmp(key);
    while(key.size() < pass.size()){
        key += tmp;
    }

    for(int i = 0; i < pass.size(); ++i){
        pass[i] ^= key[i];
    }
    return pass;

}

Employee::~Employee() {}

string Employee::getUsername() {
    return username;
}

string Employee::getEncryptedPassword() {
    return encrypted_password;
}

void Employee::setName(string n) {
    name = n;
}

void Employee::setEmployeeId(string id) {
    if(this->idValid(id)) { //checks if employee ID is valid before setting it
        employeeID = id;
    } else {
        cout << "Employee ID is not valid" << endl;
    }
}

void Employee::setUsername(string uname) {
    username = uname;
}

void Employee::setPassword(string pass) {
    encrypted_password = passwordEncrypt(pass, "A5HDUQ71JRBC0SK2HRU");
}

bool Employee::idValid(string id) {
    int l = id.length();
    int valid = true;
    int i = 0;
    if(l == 10) { //if length of input is less than 10, it is automatically incorrect
       while(valid && i < 10) { //checks each character to see if it is correct
           int ASCII = (int) id.at(i);
           if(i == 0 && id.at(0) != 'E') { //first character is an "E"
               valid = false;
           } else if (i != 0 && (48 >= ASCII || 57 <= ASCII)) { //next nine characters are digits
                valid = false;
           }
           i++;
       }
    } else {
        valid = false;
    }
    return valid;
}

string Employee::toString() {
    cout << "Name: " << name << endl;
    cout << "Employee ID: " << employeeID << endl;
    cout << "Username: " << username << endl;
    return "";
}
