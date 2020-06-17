//
// Created by Dhruv Rawat on 2020-06-17.
//

#import "Classes.h"

Employee::Employee() {
    username = "Default Username";
    encrypted_password = passwordEncrypt("pass", "A5HDUQ71JRBC0SK2HRU");
    name = "Default Name";
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

string Employee::passwordDecrypt(string entry, string key){ //method decrpyts the password
    return passwordEncrypt(entry, key);
}
