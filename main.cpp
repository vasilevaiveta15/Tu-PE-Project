#include <iostream>
#include <string>
#include <fstream>
#include "Employee.cpp"
#include "String.cpp"
#include <cstdio>


void createEmployees();

void printAllEmployees(Employee pEmployee[100], int i);

void printEmployeesWithCode(Employee pEmployee[100]);

int main() {
      createEmployees();

    /*          Check class String

                String s1;
                try{
                    s1.setStr("Hello.!");
                }catch (const invalid_argument &ex) {
                    cout << ex.what() << endl;
                }
                s1.setStr("Hello.");
                String s2 = s1+s1;
                String s3 = s2;
                cout<<s1.getStr()+"\n";
                printf("%c",s1.getStart());
                printf("\n");
                printf("%d",s1.getLenght());
                printf("\n");
                cout<<s2.getStr();
                printf("\n");
                cout<<s3.getStr();

    */


    return 0;
}

void createEmployees() {
    int numOfEmployee;

    cout << "\033[3;42;30mEnter how many employees you want to create: \033[0m\t";
    cin >> numOfEmployee;
/*          Check for overflow of array         */
    while (numOfEmployee > 100 || numOfEmployee <= 0) {
        cout << "\x1B[34mInvalid input of employees! Enter again: \033[0m\t";
        cin >> numOfEmployee;
    }

    string firstName;
    string middleName;
    string lastName;
    string egn;
    string code;
    char hasAPosition;
    Employee employees[100];

/*          Create and open a text file         */
    ofstream MyFile("employees.txt");


/*          All employees, which we want to enter           */

    for (int i = 0; i < numOfEmployee; i++) {
        cout << "\033[3;43;30mEmployee:  \033[0m\t";
        cout << (i + 1);
        cout << "\x1B[36m\nEnter first name: \033[0m\t";
        cin >> firstName;

        cout << "\x1B[36mEnter middle name: \033[0m\t";
        cin >> middleName;

        cout << "\x1B[36mEnter last name: \033[0m\t";
        cin >> lastName;

        cout << "\x1B[36mEnter egn: \033[0m\t";
        cin >> egn;

/*          Check does he want to enter a position          */
        cout << "\x1B[36mEnter does he has a position (y/n): \033[0m\t";
        cin >> hasAPosition;

        if (hasAPosition == 'y') {
            cout << "\x1B[36mEnter code: \033[0m\t";
            cin >> code;
            try {
                employees[i] = Employee(firstName, middleName, lastName, egn, code);

/*          Write to the file           */
                MyFile << employees[i].toString();

            } catch (const invalid_argument &ex) {
                cerr << ex.what() << endl;
                i--;
                continue;
            }
        } else if (hasAPosition == 'n') {
            try {
                employees[i] = Employee(firstName, middleName, lastName, egn);

/*          Write to the file           */
                MyFile << employees[i].toString();

            } catch (const invalid_argument &ex) {
                cerr << ex.what() << endl;
                i--;
                continue;
            }
        } else {
            cout << "Invalid input!\n";
            i--;
            continue;
        }
    }

/*          Close the file           */
    MyFile.close();

/*          Menu for user           */
    int input;

    while (true) {
        cout
                << "\x1B[33mYou can choose: \n (1) Show all employees\n (2) Show all employees with code\n (3) Exit\n\033[0m\t";
        cout << "\x1B[35mEnter your choose: \033[0m\n";
        cin >> input;
        if (input == 1) {
            printAllEmployees(employees, numOfEmployee);
        } else if (input == 2) {
            printEmployeesWithCode(employees);

        } else if (input == 3) {
            return;
        }
    }
}

/*          Print employees with code           */
void printEmployeesWithCode(Employee employees[100]) {
    cout << "\033[1;47;35mEmployees with code\n\033[0m\t";
    for (int i = 0; i < sizeof(employees); i++) {
        if (employees[i].getCode().empty()) {
            continue;
        }
        cout << (i + 1);
        cout << "\033[1;47;35m: Employee details: \033[0m";
        cout << "\x1B[36m"
             << employees[i].getFirstName() + " " + employees[i].getMiddleName() + " " + employees[i].getLastName() +
                " EGN: " + employees[i].getEgn() + " CODE: " + employees[i].getCode() + "\n\033[0m";
    }
}

/*          Print all employees           */
void printAllEmployees(Employee employees[100], int numOfEmployee) {
    for (int i = 0; i < numOfEmployee; i++) {
        if (employees[i].getCode().empty()) {
            cout << (i + 1);
            cout << "\033[1;47;35m: Employee details: \033[0m";
            cout << "\x1B[36m" << employees[i].getFirstName() + " " + employees[i].getMiddleName() + " " +
                                  employees[i].getLastName() +
                                  " EGN: " + employees[i].getEgn() + "\n\033[0m";
            continue;
        }
        cout << (i + 1);
        cout << "\033[1;47;35m: Employee details: \033[0m";
        cout << "\x1B[36m"
             << employees[i].getFirstName() + " " + employees[i].getMiddleName() + " " + employees[i].getLastName() +
                " EGN: " + employees[i].getEgn() + " CODE: " + employees[i].getCode() + "\n\033[0m";
    }
}


