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
void Admin_Dash();
void Class_Records();
void Parent_Page();
void parent_dash();
void report();
void register_t();//new teacher register
void login_t();//teacher login
void student_screen();//student record
void addStudent();//add student record
void editStudent(char []);//edit student record
void deleteStudent(char[]);
void displayStudent();//view student record
string LearningProgress(int);//convert each subject score to learning progress, >=80:Achieved; >=50 and <80: Progressing; <50: Help

//declare structure
struct Teacher //structure for teacher record
{
    char full_name_t[50];
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
    char full_name_p[50];
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

struct Student //structure for student record
{
    char full_name_s[50];
    string gender_s;
    string class_no_s;
    int maths;
    int science;
    int writing;
    int reading;
    int sports;
    string progress_maths;
    string progress_science;
    string progress_writing;
    string progress_reading;
    string progress_sports;
};

//delcare global varialbe
fstream teacherFile, studentFile, ParentFile;
fstream class101, class102, class103;
struct Teacher newTeacher;
struct Student student;
struct Parent newParent;
char name[50];
char search_name[50];
int position = 0;


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
            cout << "\t\t\tGlen Eden Intermediate School Information System" << endl;
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
        default:cout << "Please enter a value between 1 and 8.\n";
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
    //system("CLS");
    cout << "\n\t\t\tSchool Information System";
    line();
    cout << "\n\t\t\t1) Glen Eden Intermediate School";
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
}

void teacher_screen()//Karen
{
    //declare local varialbe
    int choice = 0;

    do
    {
        //system("CLS");
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
    line();
    cout << "\t\tHello! Welcome to the teacher registration process";
    line();

    ofstream teacherFile;
    teacherFile.open("teacher.txt", ios::out | ios::app | ios::binary);

    if (teacherFile.is_open())
    {
        //read teacher data
        cout << "\n\tEnter your full name: ";
        cout << "\n\tGender(Male, Female, Non-Binary): ";
        cout << "\n\tDate of Birth: ";
        cout << "\n\tEmail address: ";
        cout << "\n\tContact Number: ";
        cout << "\n\tClassroom number (101/102/103): ";
        cout << "\n\tWhich year do you teach (number): ";
        cout << "\n\tEnter your username: ";
        cout << "\n\tEnter your password: ";


        cin.ignore();
        Gotoxy(30, 5);
        cin.getline(newTeacher.full_name_t, 50);
        Gotoxy(42, 6);
        cin >> newTeacher.gender_t;
        Gotoxy(23, 7);
        cin >> newTeacher.dob_t;
        Gotoxy(23, 8);
        cin >> newTeacher.email_t;
        Gotoxy(24, 9);
        cin >> newTeacher.contact_no_t;
        Gotoxy(40, 10);
        cin >> newTeacher.class_no_t;
        Gotoxy(42, 11);
        cin >> newTeacher.year_t;
        Gotoxy(29, 12);
        cin >> newTeacher.username_t;
        Gotoxy(29, 13);
        cin >> newTeacher.password_t;
        cin.ignore();

        teacherFile << newTeacher.full_name_t << endl;
        teacherFile << newTeacher.gender_t << endl;
        teacherFile << newTeacher.dob_t << endl;
        teacherFile << newTeacher.email_t << endl;
        teacherFile << newTeacher.contact_no_t << endl;
        teacherFile << newTeacher.class_no_t << endl;
        teacherFile << newTeacher.year_t << endl;
        teacherFile << newTeacher.username_t << endl;
        teacherFile << newTeacher.password_t << endl;
    }

    teacherFile.close();//save and close file
    line();
    cout << "\t\t\t\tRegistration Successful!!!";
    line();
    student_screen();//after completing registration, direct to student screen (login)
    _getch();
    system("CLS");
}

void login_t()
{

    char usernameSearch_t[20];
    char passwordSearch_t[20];
    int i = 0;
    bool isFound = false;
    do
    {
        cout << "\nEnter your username: ";
        cin >> usernameSearch_t;
        cout << "Enter your password: ";
        cin >> passwordSearch_t;

        ifstream teacherFile;
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
            }
        }
        if (isFound == false && i<2)
        {
            cout << "Invalid username and password, please try again...\n";
            _getch();
        }
        i++;
        teacherFile.close();
        //if (i == 3 && isFound==false)
        //{
        //    cout << "\nToo Many Attempts!!!Please try later...\n";
        //    line();
        //    break;
        //    //main();
        //    //exit;
        //}

    } while (i < 3);

    if (i == 3 && isFound == false)
    {
        cout << "\nToo Many Attempts!!!Send you Back to Main Screen!!!Please try again later...\n";
        line();
        main();
    }

}

void student_screen()
{
    //student menu after teacher logined
    line();
    cout << "\t\t\tWelcome to Student Record Menu!" << endl;
    line();
    cout << "\n\t\t\t1. Add Student";
    cout << "\n\t\t\t2. Edit Student Record";
    cout << "\n\t\t\t3. Delete Student Record";
    cout << "\n\t\t\t4. Update Student Record";
    cout << "\n\t\t\t5. View the Records";
    cout << "\n\t\t\t6. Back to Main Menu";
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
        editStudent(search_name);
        break;
    }
    case 3: {
        deleteStudent(name);
        break;
    }
    case 4: {
        editStudent(search_name);
        break;
    }
    case 5: {
        displayStudent();
        break;
    }
    case 6: {
        main();
    }
    default:cout << "\nInvalid option, please choose between 1 and 5" << endl;
        break;
    }
}

void addStudent()
{
    int ClassSelection;
    bool StudentDone = false;

    do
    {
        //system("CLS");
        line();
        cout << "\n\t\t\tWelcome to Add Student Record Page";
        line();
        cout << "\t\t\t1. Class 101\n";
        cout << "\t\t\t2. Class 102\n";
        cout << "\t\t\t3. Class 103\n";
        cout << "\t\t\t4. Return to previous page\n";
        cout << "Please enter your choice: ";
        cin >> ClassSelection;
        system("CLS");
        //switch case for access separte class files, class
        switch (ClassSelection)
        {
        case 1: {

            class101.open("class_101.txt", ios::out | ios::app | ios::binary);//open class101 file

            if (class101.is_open())
            {
                //read student data
                cin.ignore();
                cout << "\n\n\tEnter your full name: ";
                cout << "\n\tGender(Male, Female, Non-Binary): ";
                cout << "\n\tMaths Score (0-100): ";
                cout << "\n\tScience Score (0-100): ";
                cout << "\n\tWriting Score (0-100): ";
                cout << "\n\tReading Score (0-100): ";
                cout << "\n\tSports Score (0-100): ";
                Gotoxy(29, 2);
                cin.getline(student.full_name_s, 50);
                Gotoxy(41, 3);
                cin >> student.gender_s;
                Gotoxy(29, 4);
                cin >> student.maths;
                Gotoxy(30, 5);
                cin >> student.science;
                Gotoxy(30, 6);
                cin >> student.writing;
                Gotoxy(30, 7);
                cin >> student.reading;
                Gotoxy(30, 8);
                cin >> student.sports;

                student.progress_maths = LearningProgress(student.maths);
                student.progress_science = LearningProgress(student.science);
                student.progress_writing = LearningProgress(student.writing);
                student.progress_reading = LearningProgress(student.reading);
                student.progress_sports = LearningProgress(student.sports);

                //open file for writing
                ofstream class101;
                class101.open("class_101.txt", ios::out | ios::app | ios::binary);

                class101 << "Full name: " << student.full_name_s;
                class101 << "    Gender: " << student.gender_s;
                class101 << "    Maths: " << student.progress_maths;
                class101 << "    Science: " << student.progress_science;
                class101 << "    Writing: " << student.progress_writing;
                class101 << "    Reading: " << student.progress_reading;
                class101 << "    Sports: " << student.progress_sports << endl;
            }
            else
            {
                cout << "\nUnable to access file....\n";
                _getch();
                system("CLS");
            }
            class101.close();//save and close file
            cout << "\nNew Student Record Added Successfully\n";
            break;
        }
        case 2: {

            class102.open("class_102.txt", ios::out | ios::app | ios::binary);//open class101 file

            if (class102.is_open())
            {
                //read student data
                cin.ignore();
                cout << "\n\n\tEnter your full name: ";
                cout << "\n\tGender(Male, Female, Non-Binary): ";
                cout << "\n\tMaths Score (0-100): ";
                cout << "\n\tScience Score (0-100): ";
                cout << "\n\tWriting Score (0-100): ";
                cout << "\n\tReading Score (0-100): ";
                cout << "\n\tSports Score (0-100): ";
                Gotoxy(29, 2);
                cin.getline(student.full_name_s, 50);
                Gotoxy(41, 3);
                cin >> student.gender_s;
                Gotoxy(29, 4);
                cin >> student.maths;
                Gotoxy(30, 5);
                cin >> student.science;
                Gotoxy(30, 6);
                cin >> student.writing;
                Gotoxy(30, 7);
                cin >> student.reading;
                Gotoxy(30, 8);
                cin >> student.sports;

                student.progress_maths = LearningProgress(student.maths);
                student.progress_science = LearningProgress(student.science);
                student.progress_writing = LearningProgress(student.writing);
                student.progress_reading = LearningProgress(student.reading);
                student.progress_sports = LearningProgress(student.sports);

                //open file for writing
                ofstream class102;
                class102.open("class_102.txt", ios::out | ios::app | ios::binary);

                class102 << "Full name: " << student.full_name_s;
                class102 << "    Gender: " << student.gender_s;
                class102 << "    Maths: " << student.progress_maths;
                class102 << "    Science: " << student.progress_science;
                class102 << "    Writing: " << student.progress_writing;
                class102 << "    Reading: " << student.progress_reading;
                class102 << "    Sports: " << student.progress_sports << endl;
                _getch();
            }
            else
            {
                cout << "\nUnable to access file....\n";
                _getch();
                system("CLS");
            }

            class102.close();//save and close file
            cout << "\nNew Student Record Added Successfully\n";
            break;
        }
        case 3: {

            class103.open("class_103.txt", ios::out | ios::app | ios::binary);//open class101 file

            if (class103.is_open())
            {
                //read student data
                cin.ignore();
                cout << "\n\n\tEnter your full name: ";
                cout << "\n\tGender(Male, Female, Non-Binary): ";
                cout << "\n\tMaths Score (0-100): ";
                cout << "\n\tScience Score (0-100): ";
                cout << "\n\tWriting Score (0-100): ";
                cout << "\n\tReading Score (0-100): ";
                cout << "\n\tSports Score (0-100): ";
                Gotoxy(29, 2);
                cin.getline(student.full_name_s, 50);
                Gotoxy(41, 3);
                cin >> student.gender_s;
                Gotoxy(29, 4);
                cin >> student.maths;
                Gotoxy(30, 5);
                cin >> student.science;
                Gotoxy(30, 6);
                cin >> student.writing;
                Gotoxy(30, 7);
                cin >> student.reading;
                Gotoxy(30, 8);
                cin >> student.sports;

                student.progress_maths = LearningProgress(student.maths);
                student.progress_science = LearningProgress(student.science);
                student.progress_writing = LearningProgress(student.writing);
                student.progress_reading = LearningProgress(student.reading);
                student.progress_sports = LearningProgress(student.sports);

                //open file for writing
                ofstream class103;
                class103.open("class_103.txt", ios::out | ios::app | ios::binary);

                class103 << "Full name: " << student.full_name_s;
                class103 << "    Gender: " << student.gender_s;
                class103 << "    Maths: " << student.progress_maths;
                class103 << "    Science: " << student.progress_science;
                class103 << "    Writing: " << student.progress_writing;
                class103 << "    Reading: " << student.progress_reading;
                class103 << "    Sports: " << student.progress_sports << endl;
                _getch();
                system("CLS");
            }
            else
            {
                cout << "\nUnable to access file....\n";
                _getch();
                system("CLS");
            }

            class103.close();//save and close file
            cout << "\nNew Student Record Added Successfully\n";
            break;
        }
        case 4: {
            StudentDone = true;
            student_screen();
        }
        default:cout << "\nPlease enter correct option.\n";
            _getch();
            system("CLS");
            break;
        }

    } while (!StudentDone);

}


void editStudent(char search_name[50])
{
    int edit_choice;
    bool edit_done = false;


    do
    {
        line();
        cout << "\n\t\t\tWelcome to Edit Student Record Page\n";
        line();
        cout << "\t\t\t1. Class 101\n";
        cout << "\t\t\t2. Class 102\n";
        cout << "\t\t\t3. Class 103\n";
        cout << "\t\t\t4. Return to previous page\n";
        cout << "Please enter your choice: ";
        cin >> edit_choice;

        switch (edit_choice)
        {
        case 1: {
            class101.open("class_101.txt", ios::in | ios::out | ios::binary);
            cout << "\n\tSearch Student in Class 101\n";
            cin.ignore();
            cout << "\n\tEnter Student Full Name: ";
            cin.getline(student.full_name_s, 50);

            if (class101.is_open())
            {
                while (!class101.eof())
                {
                    class101.read(reinterpret_cast<char*>(&student), sizeof(student));
                    position = class101.tellg();

                    if (strcmp(search_name, student.full_name_s) == 0)
                    {
                        cout << "\n\tRecord Found:\n";
                        line();
                        cout << "Full name: " << student.full_name_s;
                        cout << "    Gender: " << student.gender_s;
                        cout << "    Maths: " << student.progress_maths;
                        cout << "    Science: " << student.progress_science;
                        cout << "    Writing: " << student.progress_writing;
                        cout << "    Reading: " << student.progress_reading;
                        cout << "    Sports: " << student.progress_sports << endl;

                        class101.seekp(position = (sizeof(student)));
                        cout << "\n\n\tEdit Student Record";
                        cout << "\n\tPlease enter student Information";
                        cout << "\n\tMaths Score (0-100): ";
                        cin >> student.maths;
                        cout << "\n\tScience Score (0-100): ";
                        cin >> student.science;
                        cout << "\n\tWriting Score (0-100): ";
                        cin >> student.writing;
                        cout << "\n\tReading Score (0-100): ";
                        cin >> student.reading;
                        cout << "\n\tSports Score (0-100): ";
                        cin >> student.sports;

                        cout << "\n\n\tStudent Record Edit Successful\n";
                        class101.write(reinterpret_cast<char*>(&student), sizeof(student));//store record in binary
                        break;
                    }
                }
            }
            else
            {
                cout << "\nUnable to access file...";
            }
            class101.close();
            break;
        }
        case 2: {

            class102.open("class_102.txt", ios::in | ios::out | ios::binary);
            cout << "\n\tSearch Student in Class 102\n";
            cin.ignore();
            cout << "\n\tEnter Student Full Name: ";
            cin.getline(student.full_name_s, 50);

            if (class102.is_open())
            {
                while (!class102.eof())
                {
                    class102.read(reinterpret_cast<char*>(&student), sizeof(student));
                    position = class102.tellg();

                    if (strcmp(search_name, student.full_name_s) == 0)
                    {
                        cout << "\n\tRecord Found:\n";
                        line();
                        cout << "Full name: " << student.full_name_s;
                        cout << "    Gender: " << student.gender_s;
                        cout << "    Maths: " << student.progress_maths;
                        cout << "    Science: " << student.progress_science;
                        cout << "    Writing: " << student.progress_writing;
                        cout << "    Reading: " << student.progress_reading;
                        cout << "    Sports: " << student.progress_sports << endl;

                        class102.seekp(position = (sizeof(student)));
                        cout << "\n\n\tEdit Student Record";
                        cout << "\n\tPlease enter student Information";
                        cout << "\n\tMaths Score (0-100): ";
                        cin >> student.maths;
                        cout << "\n\tScience Score (0-100): ";
                        cin >> student.science;
                        cout << "\n\tWriting Score (0-100): ";
                        cin >> student.writing;
                        cout << "\n\tReading Score (0-100): ";
                        cin >> student.reading;
                        cout << "\n\tSports Score (0-100): ";
                        cin >> student.sports;

                        cout << "\n\n\tStudent Record Edit Successful\n";
                        class102.write(reinterpret_cast<char*>(&student), sizeof(student));//store record in binary
                        break;
                    }
                }
            }
            else
            {
                cout << "\nUnable to access file...";
            }
            class102.close();
            break;

        }
        case 3: {

            class103.open("class_103.txt", ios::in | ios::out | ios::binary);
            cout << "\n\tSearch Student in Class 103\n";
            cin.ignore();
            cout << "\n\tEnter Student Full Name: ";
            cin.getline(student.full_name_s, 50);

            if (class103.is_open())
            {
                while (!class103.eof())
                {
                    class103.read(reinterpret_cast<char*>(&student), sizeof(student));
                    position = class103.tellg();

                    if (strcmp(search_name, student.full_name_s) == 0)
                    {
                        cout << "\n\tRecord Found:\n";
                        line();
                        cout << "Full name: " << student.full_name_s;
                        cout << "    Gender: " << student.gender_s;
                        cout << "    Maths: " << student.progress_maths;
                        cout << "    Science: " << student.progress_science;
                        cout << "    Writing: " << student.progress_writing;
                        cout << "    Reading: " << student.progress_reading;
                        cout << "    Sports: " << student.progress_sports << endl;

                        class103.seekp(position = (sizeof(student)));
                        cout << "\n\n\tEdit Student Record";
                        cout << "\n\tPlease enter student Information";
                        cout << "\n\tMaths Score (0-100): ";
                        cin >> student.maths;
                        cout << "\n\tScience Score (0-100): ";
                        cin >> student.science;
                        cout << "\n\tWriting Score (0-100): ";
                        cin >> student.writing;
                        cout << "\n\tReading Score (0-100): ";
                        cin >> student.reading;
                        cout << "\n\tSports Score (0-100): ";
                        cin >> student.sports;

                        cout << "\n\n\tStudent Record Edit Successful\n";
                        class103.write(reinterpret_cast<char*>(&student), sizeof(student));//store record in binary
                        break;
                    }
                }
            }
            else
            {
                cout << "\nUnable to access file...";
            }
            class103.close();
            break;
        }
        case 4:edit_done = true;
        default:
            break;
        }

    } while (!edit_done);

}



void deleteStudent(char name[50])
{
    int choice;
    fstream tempfile;
    string line;
    bool delete_done = false;

    do
    {
        cout << "\n\n\t\t\tWelcome to Delete Student Record Page";
        cout << "\n\t\t\t1. Class 101";
        cout << "\n\t\t\t2. Class 102";
        cout << "\n\t\t\t3. Class 103";
        cout << "\n\t\t\t4. Return to previous page";
        cout << "\nPlease enter your choice: ";
        cin >> choice;
        //switch case to ask which file to edit

        switch (choice)
        {
        case 1: {
            cout << "\nPlease enter the name of student you want to delete: ";
            cin.ignore();
            cin.getline(name, 50);

            class101.open("class_101.txt", ios::in | ios::out | ios::binary);//open class 102 file
            if (class101.is_open())
            {
                while (!class101.eof())
                {
                    while (class101.read(reinterpret_cast<char*>(&student), sizeof(student)))
                    {
                        if (strcmp(student.full_name_s, name) == 0)
                        {
                            cout << "\nRecord Found";
                            cout << "\nStudent Name: " << student.full_name_s;
                        }
                        else
                        {
                            tempfile.open("temp.txt", ios::out | ios::app | ios::binary);
                            tempfile.write(reinterpret_cast<char*>(&student), sizeof(student));
                            tempfile.close();
                        }
                    }
                }
            }
            class101.close();
            remove("class_101.txt");
            rename("temp.txt", "class_101.txt");
            break;

        }
        case 2: {

            cout << "\nPlease enter the name of student you want to delete: ";
            cin.ignore();
            cin.getline(name, 50);

            class102.open("class_102.txt", ios::in | ios::out | ios::binary);//open class 102 file
            if (class102.is_open())
            {
                while (!class102.eof())
                {
                    while (class102.read(reinterpret_cast<char*>(&student), sizeof(student)))
                    {
                        if (strcmp(student.full_name_s, name) == 0)
                        {
                            cout << "\nRecord Found";
                            cout << "\nStudent Name: " << student.full_name_s;
                        }
                        else
                        {
                            tempfile.open("temp.txt", ios::out | ios::app | ios::binary);
                            tempfile.write(reinterpret_cast<char*>(&student), sizeof(student));
                            tempfile.close();
                        }
                    }
                }
            }
            class102.close();
            remove("class_102.txt");
            rename("temp.txt", "class_102.txt");
            break;

        }
        case 3: {

            cout << "\nPlease enter the name of student you want to delete: ";
            cin.ignore();
            cin.getline(name, 50);

            class103.open("class_103.txt", ios::in | ios::out | ios::binary);//open class 101 file
            if (class103.is_open())
            {
                while (!class103.eof())
                {
                    while (class103.read(reinterpret_cast<char*>(&student), sizeof(student)))
                    {
                        if (strcmp(student.full_name_s, name) == 0)
                        {
                            cout << "\nRecord Found";
                            cout << "\nStudent Name: " << student.full_name_s;
                        }
                        else
                        {
                            tempfile.open("temp.txt", ios::out | ios::app | ios::binary);
                            tempfile.write(reinterpret_cast<char*>(&student), sizeof(student));
                            tempfile.close();
                        }
                    }
                }
            }
            class103.close();
            remove("class_103.txt");
            rename("temp.txt", "class_103.txt");
            break;

        }
        case 4: {
            delete_done = true;
            student_screen();
            break;
        }

        default:cout << "\nInvalid choice, please enter correct number...";
            break;
        }

    } while (!delete_done);
    
}


void displayStudent()
{
    //display the way it is
    int choice;
    bool display_done = false;

    do
    {
        system("CLS");
        line();
        cout << "\n\t\t\tWelcome to Display Student Record Page";
        line();
        cout << "\n\t\t\t1. Class 101";
        cout << "\n\t\t\t2. Class 102";
        cout << "\n\t\t\t3. Class 103";
        cout << "\n\t\t\t4. Return to previous page\n";
        cout << "Please enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: {

            class101.open("class_101.txt", ios::in | ios::binary);
            cout << "\n\t\t\tAll Student Record in Class 101\n";

            if (class101.is_open())
            {
                string line;
                while (getline(class101, line))
                {
                    cout << line << endl;

                }
                _getch();
                class101.close();
            }

            break;
        }
        case 2: {

            class102.open("class_102.txt", ios::in | ios::binary);
            cout << "\n\t\t\tAll Student Record in Class 101\n";

            if (class102.is_open())
            {
                string line;
                while (getline(class102, line))
                {
                    cout << line << endl;
                }
                _getch();
                class102.close();
            }
            break;
        }
        case 3: {
            class103.open("class_103.txt", ios::in | ios::binary);
            cout << "\n\t\t\tAll Student Record in Class 101\n";

            if (class103.is_open())
            {
                string line;
                while (getline(class103, line))
                {
                    cout << line << endl;
                }
                _getch();
                class103.close();
            }

            break;
        }
        case 4: {
            display_done = true;
            student_screen();
            break;
        }
        default:cout << "\nPlease enter correct choice\n";
            break;
        }

    } while (!display_done);
}

string LearningProgress(int score)
{
    if (score >= 80)
    {
        return "Achieved";
    }
    else if (score < 50)
    {
        return "Help Needed";
    }
    else
    {
        return "Progressing";
    }
}


void parent_screen()//Zack
{
    int choice = 0;

    do
    {
        system("CLS");
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
            _getch();
            system("CLS");
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

    ofstream ParentFile;
    //open file to write
    ParentFile.open("Parent.txt", ios::out | ios::app | ios::binary);

    if (ParentFile.is_open())
    {
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

        cin.ignore();
        Gotoxy(30, 5);
        cin.getline(newParent.full_name_p, 50);
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
        cin.ignore();

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

    }

    ParentFile.close();//close file, save and store data
    line();
    cout << "\t\t\tRegistration Successful!";
    line();
    _getch();
    system("CLS");
    login_p();
}

void login_p()
{

    char usernameSearch_p[20];
    char passwordSearch_p[20];
    int i = 0;
    bool isFound = false;
    do
    {
        system("CLS");
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
                    parent_dash();//nested scenario, after login, show nested student record menu
                    break;
                }
                else
                {
                    isFound = false;
                }
            }
        }
        if (isFound == false)
        {
            cout << "Invalid username and password, please try again...\n";
            _getch();
        }
        i++;
        ParentFile.close();
        if (i == 3)
        {
            cout << "\nToo Many Attempts!!!Please try later...\n";
            line();
            main();
            //exit;
        }
    } while (i < 3);

}

void parent_dash()
{
    int option;

    system("CLS");
    line();
    cout << "\t\tParent DashBoard";
    line();
    cout << "\n\t\t1) Edit Profile";
    cout << "\n\t\t2) View Student Details";
    cout << "\n\n\t\tEnter your choice: ";
    cin >> option;

    switch (option)
    {
    case 1: {

        break;
    }
    case 2: {
        student_screen();
        break;
    }
    default:cout << "\nInvalid option, please choose between 1 and 2" << endl;
        _getch();
        system("CLS");
        break;
    }

}

void school_notice()
{


}

void admin_screen()//Zack
{
    string Admin_Password;
    string Admin_Attempt;
    Admin_Password = "Password01";

    line();
    cout << "\t\tAdmin Login Page";
    line();

    cout << "Password: ";
    cin >> Admin_Attempt;

    if (Admin_Attempt == Admin_Password)
    {
        Admin_Dash();
    }
    else
    {
        cout << "Incorrect Password";
        _getch();
        main_menu();
    }


}

void Admin_Dash()
{
    int option;
    system("CLS");
    line();
    cout << "\n\t\tWelcome Admin";
    line();

    cout << "\n\n\t\t1) View Class Records";
    cout << "\n\t\t2) View Parent Records";
    cout << "\n\t\t3) View Student Page";
    cout << "\n\t\t4) Create Report";
    cout << "\n\n\t\tEnter your choice: ";
    cin >> option;

    switch (option)
    {
    case 1: {
        Class_Records();
        break;
    }
    case 2: {
        Parent_Page();
        break;
    }
    case 3: {
        student_screen();
        break;
    }
    case 4: {
        report();
        break;
    }
    default:cout << "\nInvalid option, please choose between 1 and 4";
        _getch();
        system("CLS");
        break;
    }


}

void Class_Records()
{
    int option;
    system("CLS");
    line();
    cout << "Welcome to Class Record Menu!" << endl;
    cout << "\n\t\t\t1) View Details";
    cout << "\n\t\t\t2) Edit Student Records";
    line();

    cout << "\nEnter your choice: ";
    cin >> option;

    switch (option)
    {
    case 1: {
        displayStudent();
        break;
    }
    case 2: {
        editStudent(search_name);
        break;
    }
    default:cout << "\nInvalid option, please choose between 1 and 2";
        _getch();
        system("CLS");
        break;
    }

}

void Parent_Page()
{
    int option;

    system("CLS");
    line();
    cout << "Welcome to Parent Record Menu!" << endl;
    cout << "\n\t\t\t1) View Details";
    cout << "\n\t\t\t2) Edit Parent Account";
    line();

    cout << "\nEnter your choice: ";
    cin >> option;

    switch (option)
    {
    case 1: {

        break;
    }
    case 2: {

        break;
    }
    default:cout << "\nInvalid option, please choose between 1 and 2";
        _getch();
        system("CLS");
        break;
    }
}


void report()
{
    int choice;
    system("CLS");
    cout << "Student Report Sheet";

    cout << "What class is the student from?";
    cout << "\n\t\t\t1. Class 101";
    cout << "\n\t\t\t2. Class 102";
    cout << "\n\t\t\t3. Class 103";
    cout << "Please enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1: {

        class101.open("class_101.txt", ios::in | ios::binary);
        cout << "\n\t\t\tAll Student Record in Class 101\n";

        if (class101.is_open())
        {
            string line;
            while (getline(class101, line))
            {
                cout << line << endl;
            }
            _getch();
            class101.close();
        }

        break;
    }
    case 2: {

        class102.open("class_102.txt", ios::in | ios::binary);
        cout << "\n\t\t\tAll Student Record in Class 101\n";

        if (class102.is_open())
        {
            string line;
            while (getline(class102, line))
            {
                cout << line << endl;
            }
            _getch();
            class102.close();
        }
        break;
    }
    case 3: {
        class103.open("class_103.txt", ios::in | ios::binary);
        cout << "\n\t\t\tAll Student Record in Class 101\n";

        if (class103.is_open())
        {
            string line;
            while (getline(class103, line))
            {
                cout << line << endl;
            }
            _getch();
            class103.close();
        }

        break;
    }


    default:cout << "\nPlease enter correct choice\n";
        _getch();
        system("CLS");
        break;
    }
}

