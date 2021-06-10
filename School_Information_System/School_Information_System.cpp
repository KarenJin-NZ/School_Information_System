// School_Information_System.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Group Assignment - CS103

#include <iostream>
#include<string>
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


//declare structure
struct Teacher //structure for teacher record
{
    string full_name_t;
    char gender_t;
    string dob_t;
    string email_t;
    string contact_no_t;
    int class_no_t;
    int year_t;
    string username_t;
    string password_t;
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
    char gender_s;

};

struct LearningProgress //tbc
{

};


int main()
{
    //title of the project
    cout << "\n\t\t\tSchool Information System";
    line();






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

}

void parent_screen()//Zack
{

}

void admin_screen()//Zack
{

}
