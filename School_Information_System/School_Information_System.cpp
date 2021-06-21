// School_Information_System.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Group Assignment - CS103

#include <iostream>
#include <string>
#include <fstream>
#include "Goto.h"
#include <conio.h>
using namespace std;

//declare function prototype
void line();
int main_menu();
void contact_detail();
void latest_event();
void term_dates();
void teacher_screen();
void parent_screen();
void register_p();
void login_p();
void admin_screen();
void register_t();//new teacher register
void login_t();//teacher login
void student_screen();//student record
void addStudent();//add student record
void editStudent();//edit student record
void deleteStudent();//delete student record
void updateStudent();//update student record
void displayStudent();//view student record
string LearningProgress(float);//convert average subject score to learning progress, >=80:Achieved; >=50 and <80: Progressing; <50: Help

//declare structure
struct Teacher //structure for teacher record
{
    string full_name_t;
    string gender_t;
    string dob_t;
    string email_t;
    string contact_no_t;
    int class_no_t;
    int year_t;
    char username_t[20];
    char password_t[20];
};

struct Parent //structure for parent record
{
    string full_name_p;
    string gender_p;
    string dob_p;
    string email_p;
    string contact_no_p;
    string child_name_p;
    string caregiver_name_p;
    string emergency_no_p;
    char username_p[20];
    char password_p[20];
};

//nested structure
struct Subject//nested structure for student record
{
    int maths;
    int science;
    int writing;
    int reading;
    int sports;
    float average;
    string progress;
};

struct Student //structure for student record
{
    string full_name_s;
    string gender_s;
    string class_no_s;
    Subject mark;
};

//delcare global varialbe
fstream teacherFile, studentFile, ParentFile;
struct Teacher newTeacher;
struct Student student;
struct Parent newParent;


int main()
{
    int option = 0;//declare local variable

    //display main menu
    do
    {
        option = main_menu();

        switch (option)
        {
        case 1: { system("CLS");
            line();
            cout << "\t\t\tGlen Eden Intermediate School" << endl;
            line();
            _getch();
            break;
        }
        case 2: {
            contact_detail(); break;
        }
        case 3: {
            latest_event(); break;
        }
        case 4: {
            term_dates(); break;
        }
        case 5: {
            teacher_screen(); break;
        }
        case 6: {
            parent_screen(); break;
        }
        case 7: {
            admin_screen(); break;
        }
        case 8: {
            cout << "\nExiting the program...";
        }
        default:cout << "Please enter a value between 1 and 7.\n";
            break;
        }
    } while (option != 8);
}

void line()
{
    cout << "\n";
    cout << "\t\t\t**********************************";
    cout << "\n";
}

int main_menu()
{
    //declare local variable
    int option = 0;
    system("CLS");
    cout << "\n\t\t\tSchool Information System";
    cout << "\n\n\t\t\t1) Glen Eden Intermediate School";
    cout << "\n\t\t\t2) Contact Details";
    cout << "\n\t\t\t3) Latest events";
    cout << "\n\t\t\t4) Term dates";
    cout << "\n\t\t\t5) Teacher Login/Registration";
    cout << "\n\t\t\t6) Parent Login/Registration";
    cout << "\n\t\t\t7) Admin";
    cout << "\n\t\t\t8) Exit";
    cout << "\nPlease select an option from the menu: ";
    cin >> option;
    return option;
}

void contact_detail()
{
    system("CLS");
    line();
    cout << "\t\t\tContact Details";
    line();
    cout << "\n\t\t\tAddress: 23 Kaurilands Road, Titirangi, Auckland 0604";
    cout << "\n\t\t\tEmail: office@geis.school.nz";
    cout << "\n\t\t\tPhone: +64 9 817 0032";
    line();
    _getch();
}

void latest_event()
{
    system("CLS");
    line();
    cout << "\n\t\t\tLatest Events";
    line();
    cout << "\t\t\tCross Country Event: 4 July 2021";
    cout << "\n\t\t\tMufty Day: 8 August 2021";
    cout << "\n\t\t\tSwimming Competition: 11 November 2021";
    line();
    _getch();
    system("CLS");
}

void term_dates()
{
    system("CLS");
    line();
    cout << "\n\t\t\tSchool Terms";
    line();
    cout << "\t\t\tTerm 1: 1 February to 16 April\n";
    cout << "\t\t\tSchool Holidays: 17 April to 2 May\n";
    cout << "\t\t\tTerm 2: 3 May to 9 July\n";
    cout << "\t\t\tSchool Holidays: 10 July to 25 July\n";
    cout << "\t\t\tTerm 3: 26 July to 1 October\n";
    cout << "\t\t\tSchool Holidays: 2 October to 17 October\n";
    cout << "\t\t\tTerm 4: 18 October to 20 December\n";
    cout << "\t\t\tSchool Holidays: From school's closing date until opening date of school the following year\n";
    line();
    _getch();
    system("CLS");
}

void teacher_screen()//Karen
{
    //declare local varialbe
    int choice = 0;

    do
    {
        cout << "\n\t\t\tWelcome! Teacher!";
        line();
        cout << "\n\t\t\t1. New Teacher Registration";
        cout << "\n\t\t\t2. Teacher Login";
        line();
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1: {
            register_t(); break;//call function
        }
        case 2: {
            login_t(); break;//call function
        }
        default:cout << "Please enter a value between 1 and 2.\n";
            break;
        }
    } while (choice == 1 || choice == 2);
}

void register_t()
{
    system("CLS");
    line();
    cout << "\t\tHello! Welcome to the teacher registration process";
    line();

    //read teacher data
    cout << "\n\tEnter your full name: ";
    //cin >> newTeacher.full_name_t;
    cout << "\n\tGender(Male, Female, Non-Binary): ";
    //cin >> newTeacher.gender_t;
    cout << "\n\tDate of Birth: ";
    //cin >> newTeacher.dob_t;
    cout << "\n\tEmail address: ";
    //cin >> newTeacher.email_t;
    cout << "\n\tContact Number: ";
    //cin >> newTeacher.contact_no_t;
    cout << "\n\tClassroom number (number): ";
    //cin >> newTeacher.class_no_t;
    cout << "\n\tWhich year do you teach (number): ";
    //cin >> newTeacher.year_t;
    cout << "\n\tEnter your username: ";
    //cin >> newTeacher.username_t;
    cout << "\n\tEnter your password: ";
    //cin >> newTeacher.password_t;

    Gotoxy(30, 5);
    cin >> newTeacher.full_name_t;

    Gotoxy(42, 6);
    cin >> newTeacher.gender_t;

    Gotoxy(23, 7);
    cin >> newTeacher.dob_t;

    Gotoxy(23, 8);
    cin >> newTeacher.email_t;

    Gotoxy(24, 9);
    cin >> newTeacher.contact_no_t;

    Gotoxy(35, 10);
    cin >> newTeacher.class_no_t;

    Gotoxy(42, 11);
    cin >> newTeacher.year_t;

    Gotoxy(29, 12);
    cin >> newTeacher.username_t;

    Gotoxy(29, 13);
    cin >> newTeacher.password_t;



    //file handling to store data

    //open file for writing
    ofstream teacherFile;
    teacherFile.open("teacher.txt", ios::out | ios::app | ios::binary);

    teacherFile << newTeacher.full_name_t << endl;
    teacherFile << newTeacher.gender_t << endl;
    teacherFile << newTeacher.dob_t << endl;
    teacherFile << newTeacher.email_t << endl;
    teacherFile << newTeacher.contact_no_t << endl;
    teacherFile << newTeacher.class_no_t << endl;
    teacherFile << newTeacher.year_t << endl;
    teacherFile << newTeacher.username_t << endl;
    teacherFile << newTeacher.password_t << endl;

    teacherFile.close();//save and close file
}


void login_t()
{
    char usernameSearch_t[20];
    char passwordSearch_t[20];
    int i = 0;
    bool isFound = false;
    do
    {
        //search for teacher record
        cout << "\nEnter your username: ";
        cin >> usernameSearch_t;
        cout << "Enter your password: ";
        cin >> passwordSearch_t;

        ifstream teacherFile;
        //open in read mode
        teacherFile.open("teacher.txt", ios::in | ios::binary);

        //search for record
        if (teacherFile.is_open())
        {

            while (!teacherFile.eof())
            {
                teacherFile.getline(newTeacher.username_t, 20);
                teacherFile.getline(newTeacher.password_t, 20);

                //validate record
                if (strcmp(newTeacher.username_t, usernameSearch_t) == 0 && strcmp(newTeacher.password_t, passwordSearch_t) == 0)
                {
                    //if validated, lead to another screen - student screenis
                    isFound = true;
                    student_screen();//nested scenario, after login, show nested student record menu
                    break;
                }
                else
                {
                    isFound = false;
                }
                if (isFound == false)
                {
                    cout << "Invalid username and password, please try again...\n";
                    i++;
                    /*if (i >= 3)
                    {
                        system("CLS");
                        cout << "Too many wrong attemps";
                        exit;
                    }
                    else
                    {
                        cout << "test";
                        _getch();
                    }*/
                }
            }
        }

        teacherFile.close();
    } while (i < 3);

}

void student_screen()
{
    //student menu after teacher logined
    line();
    cout << "Welcome to Student Record Menu!" << endl;
    cout << "\n\t\t\t1. Add Student";
    cout << "\n\t\t\t2. Edit Student Record";
    cout << "\n\t\t\t3. Delete Student Record";
    cout << "\n\t\t\t4. Update Record";
    cout << "\n\t\t\t5. View the Records";
    line();

    //declare variable
    int choice;
    cout << "\nEnter your option: ";
    cin >> choice;

    //switch case to call for related function

    switch (choice)
    {
    case 1: {
        addStudent();
        break;
    }
    case 2: {
        editStudent();
        break;
    }
    case 3: {
        deleteStudent();
        break;
    }
    case 4: {
        updateStudent();
        break;
    }
    case 5: {
        displayStudent();
        break;
    }
    default:cout << "\nInvalid option, please choose between 1 and 5" << endl;
        break;
    }
}

void addStudent()
{
    //ask which class for file access
    string fileName;
    line();
    cout << "\n\t\t\tWhich class would you like to add the student record(101/102/103): ";
    cin >> fileName;

    //access file






    


}

void editStudent()
{
    //seekp

}

void deleteStudent()
{
    //temp file to swap
}

void updateStudent()
{
    //update another term observation observation
}

void displayStudent()
{
    //display the way it is

}

string LearningProgress(float average)
{
    if (average >= 80)
    {
        return "Achieved";
    }
    else if (average >= 50 && average < 80)
    {
        return "Progressing";
    }
    else
    {
        return "Help";
    }
}


void parent_screen()//Zack
{
    int choice = 0;

    do
    {
        cout << "\n\t\t\tWelcome! Parent!";
        line();
        cout << "\n\t\t\t1. New Parent/Student Registration";
        cout << "\n\t\t\t2. Parent Login";
        line();
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1: {
            register_p(); break;
        }
        case 2: {
            login_p(); break;
        }
        default:cout << "Please enter a value between 1 and 2.\n";
            break;
        }
    } while (choice == 1 || choice == 2);
}

void register_p()
{
    system("CLS");
    line();
    cout << "Hello! Welcome to the Parent/Student registration process";
    line();

    cout << "\n\tEnter your full name: ";
    cout << "\n\tGender(Male, Female, Non-Binary): ";
    cout << "\n\tDate of Birth: ";
    cout << "\n\tEmail address: ";
    cout << "\n\tContact Number: ";
    cout << "\n\tChild Name: ";
    cout << "\n\tAdditional Caregiver Name: ";
    cout << "\n\tEmergency Contact Number: ";
    cout << "\n\tEnter your username: ";
    cout << "\n\tEnter your password: ";

    Gotoxy(30, 5);
    cin >> newParent.full_name_p;

    Gotoxy(42, 6);
    cin >> newParent.gender_p;

    Gotoxy(23, 7);
    cin >> newParent.dob_p;

    Gotoxy(23, 8);
    cin >> newParent.email_p;

    Gotoxy(24, 9);
    cin >> newParent.contact_no_p;

    Gotoxy(20, 10);
    cin >> newParent.child_name_p;

    Gotoxy(35, 11);
    cin >> newParent.caregiver_name_p;

    Gotoxy(34, 12);
    cin >> newParent.emergency_no_p;

    Gotoxy(29, 13);
    cin >> newParent.username_p;

    Gotoxy(29, 14);
    cin >> newParent.password_p;

    //file handling to store data

    //open file for writing
    ofstream ParentFile;
    ParentFile.open("Parent.txt", ios::out | ios::app | ios::binary);

    ParentFile << newParent.full_name_p << endl;
    ParentFile << newParent.gender_p << endl;
    ParentFile << newParent.dob_p << endl;
    ParentFile << newParent.email_p << endl;
    ParentFile << newParent.contact_no_p << endl;
    ParentFile << newParent.child_name_p << endl;
    ParentFile << newParent.caregiver_name_p << endl;
    ParentFile << newParent.emergency_no_p << endl;
    ParentFile << newParent.username_p << endl;
    ParentFile << newParent.password_p << endl;

    ParentFile.close();
}

void login_p()
{

    char usernameSearch_p[20];
    char passwordSearch_p[20];
    int i = 0;
    bool isFound = false;
    do
    {

        cout << "\nEnter your username: ";
        cin >> usernameSearch_p;
        cout << "Enter your password: ";
        cin >> passwordSearch_p;

        ifstream ParentFile;
        ParentFile.open("Parent.txt", ios::in | ios::binary);

        //search for record
        if (ParentFile.is_open())
        {

            while (!ParentFile.eof())
            {
                ParentFile.getline(newParent.username_p, 20);
                ParentFile.getline(newParent.password_p, 20);

                //validate record
                if (strcmp(newParent.username_p, usernameSearch_p) == 0 && strcmp(newParent.password_p, passwordSearch_p) == 0)
                {
                    //if validated, lead to another screen - student screenis
                    isFound = true;
                    student_screen();//nested scenario, after login, show nested student record menu
                    break;
                }
                else
                {
                    isFound = false;
                }
                if (isFound == false)
                {
                    cout << "Invalid username and password, please try again...\n";
                    i++;
                }
            }
        }

        ParentFile.close();
    } while (i < 3);


    if (i > 3)
    {
        system("CLS");
        cout << "Too many wrong attemps";
        exit;
    }

}

void admin_screen()//Zack
{

}

