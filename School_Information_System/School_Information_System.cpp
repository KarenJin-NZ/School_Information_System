// School_Information_System.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Group Assignment - CS103

#include <iostream>
#include<string>
#include<fstream>
using namespace std;

//declare functions
int line();
int main_menu();
void contact_detail();
void latest_event();
void term_dates();
void teacher_screen();
void parent_screen();
void admin_screen();
void register_t();//new teacher register
void login_t();//teacher login
void student_screen();//student record
void addStudent();//add student record
void editStudent();//edit student record
void deleteStudent();//delete student record
void updateStudent();//update student record
void displayStudent();//view student record

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
    char username_t [20];
    char password_t [20];
};

struct Parent //structure for parent record
{
    string full_name_p;
    char gender_p;
    string dob_p;
    string email_p;
    string contact_no_p;
    string child_name;
    int class_no_p;
    string caregiver_name;
    string emergency_no;
    string username_p;
    string password_p;
};

struct Student //structure for student record
{
    string full_name_s;
    string gender_s;
    string class_no_s;
    Subject mark;//nested structure
};

//nested structure
struct Subject//nested structure for student record
{
    int maths;
    int science;
    int writing;
    int reading;
    int sports;
};


struct LearningProgress //tbc
{
    
};

//delcare global varialbe
fstream teacherFile,studentFile;
struct Teacher newTeacher;
struct Student student;

int main()
{
    //title of the project
    cout << "\n\t\t\tSchool Information System";
    line();
    
    //display main menu
    main_menu();
    int option=0;//declare local variable
    cout << "\nEnter your option: \n";
    cin >> option;
    switch (option)
    {
    case 1: cout << "Glen Eden Intermediate School" << endl; break;
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
    default:cout << "Please enter a value between 1 and 7.\n";
        break;
    }

}

int line()
{
    cout << "\n";
    cout << "\t\t\t**********************************";
    cout << "\n";
}
int main_menu()
{
    //declare local variable
    int option = 0;
    cout << "\n\t\t\t1. Glen Eden Intermediate School";
    cout << "\n\t\t\t2. Contact Details";
    cout << "\n\t\t\t3. Latest events";
    cout << "\n\t\t\t4. Term dates";
    cout << "\n\t\t\t5. Teacher Login/Registration";
    cout << "\n\t\t\t6. Parent Login/Registration";
    cout << "\n\t\t\t7. Admin";
}

void contact_detail()
{
    cout << "\nAddress: 23 Kaurilands Road, Titirangi, Auckland 0604";
    cout << "\nEmail: office@geis.school.nz";
    cout << "\nPhone: +64 9 817 0032";
}

void latest_event()
{
    cout << "\n\t\t\tLatest Events";
    line();
    cout << "\t\t\tCross Country Event: 4 July 2021";
    cout << "\n\t\t\tMufty Day: 8 August 2021";
    cout << "\n\t\t\tSwimming Competition: 11 November 2021";
}

void term_dates()
{
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
}

void teacher_screen()//Karen
{
    //declare local varialbe
    int choice = 0;
    cout << "\n\t\t\tWelcome! Teacher!";
    line();
    cout << "\n\t\t\t1. New Teacher Registration";
    cout << "\n\t\t\t2. Teacher Login";
    line();
    cout << "\nEnter your choice: ";
    
    
    //call function

    switch (choice)
    {
    case 1: {
        register_t(); break;
    }
    case 2: {
        login_t(); break;
    }
    default:cout << "Please enter a value between 1 and 2.\n";
        break;
    }
}

void register_t()
{

    line();
    cout << "Hello! Welcome to the teacher registration process";
    line();
 
    //read teacher data
    cout << "Enter your full name: ";
    cin >> newTeacher.full_name_t;
    cout << "Gender(Male, Female, Non-Binary): ";
    cin >> newTeacher.gender_t;
    cout << "Date of Birth: ";
    cin >> newTeacher.dob_t;
    cout << "Email address: ";
    cin >> newTeacher.email_t;
    cout << "Contact Number: ";
    cin >> newTeacher.contact_no_t;
    cout << "Classroom number: ";
    cin >> newTeacher.class_no_t;
    cout << "Which year do you teach: ";
    cin >> newTeacher.year_t;
    cout << "Enter your username: ";
    cin >> newTeacher.username_t;
    cout << "Enter your password: ";
    cin >> newTeacher.password_t;

    //file handling to store data

    //open file for writing
    ofstream teacherFile;
    teacherFile.open("teacher.txt", ios::out | ios::app | ios::binary);

    teacherFile << newTeacher.full_name_t<<endl;
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
                if (isFound==false)
                {
                    cout << "Invalid username and password, please try again...\n";
                    i++;
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

}

void editStudent()
{

}

void deleteStudent()
{

}

void updateStudent()
{

}

void displayStudent()
{

}


void parent_screen()//Zack
{

}

void admin_screen()//Zack
{

}

