#include "Classes.h"

int main() {

    //Creates the airline
    Airline air;

    bool done = false, signedIn;
    int userType, userNumber = 0;
    string uname = "", pass = "";

    while(!done) { //Program loop starts
        cout << "Welcome to " << air.getAirlineName() << endl;
        signedIn = false;
        userType = 0;

        while(!signedIn) { //Sign in loop starts
            cout << "Are you a customer (Type \"1\") or an employee (Type \"2\")? (To exit the program, type \"0\")" << endl;
            cin  >> userType;
            if(userType == 1) { //If customer
                signedIn = true;
            } else if(userType == 2) { //If emloyee, they must sign in first
                cin.ignore();
                while(!signedIn) { //Credential loop starts
                    cout << "Enter Username: ";
                    getline(cin, uname);
                    cout << "Enter Password: ";
                    getline(cin, pass);
                    userNumber = air.employeeLogin(uname, pass); //checks if credentials are correct
                    if(userNumber >= 0) { //if credentials are correct, user is signed in
                        signedIn = true;
                    }
                } //Credential loop ends
            } else if(userType == 0) { //User cancels
                signedIn = true;
                done = true;
            }
        } //Sign in loop ends

        //calls session functions based on user type
        if(!done && userType == 1) {
            cout << "We are here " << endl;
        }
    } //Program loop ends


    cout << "Thank you for using this database." << endl;
    return 0;
}
