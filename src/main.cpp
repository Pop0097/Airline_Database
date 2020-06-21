#include "Classes.h"

void customerSession(Airline&);
void employeeSession(Airline&, int);

int main() {

    Airline air; //Initializes the airline with 1 employee and 1 flight

    bool done = false, signedIn;
    int userType, userNumber = 0;
    string uname = "", pass = "";

    while(!done) { //Program loop starts
        cout << endl; cout << endl; cout << endl;
        cout << "Welcome to " << air.getAirlineName() << endl;
        cout << endl; cout << endl; cout << endl;
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
        if(!done && userType == 1) { //if user is a customer
            customerSession(air);
        } else if(!done && userType == 2) { //if user is an employee
            employeeSession(air, userNumber);
        }
    } //Program loop ends

    cout << "Thank you for using this database." << endl;
    return 0;
}

void customerSession(Airline& air) {
    bool done = false;
    int choice = 0;

    while(!done) { //Customer session loop starts
        //following output displays the employee actions the user can choose
        cout << endl;
        cout << "Select an Action:" << endl;
        cout << "1. Book a ticket (Type \"1\")" << endl;
        cout << "2. Cancel your ticket (Type \"2\")" << endl;
        cout << "3. View your ticket (Type \"3\")" << endl;
        cout << "4. Contact an employee (Type \"4\")" << endl;
        cout << endl;
        cout << "End session (Type \"100\")" << endl;
        cin >> choice;
        cout << endl;
        cout << endl;

        if(choice == 1) { //book ticket

        } else if(choice == 2) { //cancel ticket

        } else if(choice == 3) { //view ticket

        } else if(choice == 4) { //contact employee

        } else { //logout
            done = true;
        }
    } //Customer session loop ends
}

void employeeSession(Airline& air, int userNumber) {
    bool done = false;
    int choice = 0;

    while(!done) { //Employee session loop starts
        //following output displays the employee actions the user can choose
        cout << endl;
        cout << "Select an Action:" << endl;
        cout << "Customer Actions:" << endl;
        cout << "1. Book a ticket for a customer (Type \"1\")" << endl;
        cout << "2. Cancel a ticket for a customer (Type \"2\")" << endl;
        cout << "3. Edit a ticket for a customer (Type \"3\")" << endl;
        cout << "4. View a customer's ticket (Type \"4\")" << endl;
        cout << "Flight Actions:" << endl;
        cout << "5. Schedule a flight (Type \"5\")" << endl;
        cout << "6. Cancel a flight (Type \"6\")" << endl;
        cout << "7. Edit a flight (Type \"7\")" << endl;
        cout << "8. View a flight (Type \"8\")" << endl;
        cout << "Account Actions:" << endl;
        cout << "9. View your account information (Type \"9\")" << endl;
        cout << "10. Edit your account information (Type \"10\")" << endl;
        cout << "Employee Actions:" << endl;
        cout << "11. Create an employee account (Type \"11\")" << endl;
        cout << "12. Delete an employee account (Type \"12\")" << endl;
        cout << "Extras:" << endl;
        cout << "13. View all scheduled flights (Type \"13\")" << endl;
        cout << endl;
        cout << "Logout (Type \"100\")" << endl;
        cin >> choice;
        cout << endl;
        cout << endl;

        if(choice == 1) { //book ticket

        } else if(choice == 2) { //cancel ticket

        } else if(choice == 3) { //edit ticket information

        } else if(choice == 4) { //view ticket

        } else if(choice == 5) { //schedule flight
            air.createFlight();
        } else if(choice == 6) { //cancel flight
            air.deleteFlight();
        } else if(choice == 7) { //edit flight
            air.editFlight();
        } else if(choice == 8) {//view flight
            air.viewFlight();
        } else if(choice == 9) { //view account information
            air.viewEmployeeAccount(userNumber);
        } else if(choice == 10) { //edit account information
            air.editEmployeeAccount(userNumber);
        } else if(choice == 11) { //create employee account
            air.createEmployeeAccount();
        } else if(choice == 12) { //delete employee acccount
            userNumber = air.deleteEmployeeAccount(userNumber);
        } else if(choice == 13) {
            air.toString();
        } else { //logout
            done = true;
        }
    } //Employee session loop starts
}
