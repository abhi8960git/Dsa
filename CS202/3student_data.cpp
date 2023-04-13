#include <iostream>
using namespace std;
static int total = 0;
struct student_data
{
    string name;
    string roll_no;
    float cgpi;
    int semester;
    void take_details();
    void show_details();
};
void student_data::take_details()
{
    cin.ignore();
    cout << "\nName : ";
    getline(cin, name);
    cout << "\nRoll Number : ";
    getline(cin, roll_no);
    cout << "\nCGPI : ";
    cin >> cgpi;
    cout << "\nSemester : ";
    cin >> semester;
}
void student_data::show_details()
{
    cout << "\nName : " << name;
    cout << "\nRoll Number : " << roll_no;
    cout << "\nCGPI : " << cgpi;
    cout << "\nSemester : " << semester;
}
void enter_details(student_data arr[], int size, int number)
{
    if (number > size)
    {
        cout << "\nNo Space is avalible";
    }
    else
    {
        for (int i = total; i < number ; i++)
        {
            total++;
            cout << "\nEnter details of student " << i + 1;
            arr[i].take_details();
        }
    }
}
void display_details(student_data arr[])
{
    if(total==0)
        cout<<"\nNo data found , first add data : ";
    else
    {
    int value;
    cout << "\nEnter 1 to display all student details : ";
    cout << "\nEnter 2 to display according to cgpi : ";
    cin >> value;
    switch (value)
    {
    case 1:
        for (int i = 0; i < total; i++)
        {
            cout << "\nDetails of students " << i + 1;
            arr[i].show_details();
        }
        break;

        case 2:
        float cg;
        cout<<"\nEnter CGPI : ";
        cin>>cg;
        for (int i = 0; i < total; i++)
        {
            if (arr[i].cgpi >= cg)
            {
                // cout << "\nDetails of students " << i + 1;
                arr[i].show_details();
            }
        }
        break;
    default:
        cout<<"\nInvalid choice. ";
        break;
    }
    }
}
int main()
{
    int size = 10;
    student_data arr[size];
    int choice;
    cout << "\nPress 1 to enter details of student if data is empty . ";
    cout << "\nPress 2 to display details of student. ";
    cout << "\nPress 3 to add details of new student. ";
    cout << "\nPress 4 to exit. ";
    while (1)
    {
        cout << "\nEnter choice : ";
        cin >> choice;
        int number;
        switch (choice)
        {
        case 1:
            cout << "\nHow many student you want to add : ";
            cin >> number;
            enter_details(arr, size, number);
            break;
        case 2:
            display_details(arr);
            break;
        case 3:
            number++;
            enter_details(arr, size, number);
            break;
        case 4:
            cout<<"\nProgram ended! ";
            exit(0);
            break;
        default:
            cout << "\nInvlid Choice !";
            break;
        }
    }
    return 0;
}
/*
Press 1 to enter details of student if data is empty . 
Press 2 to display details of student. 
Press 3 to add details of new student. 
Press 4 to exit. 
Enter choice : 1

How many student you want to add : 5

Enter details of student 1
Name : Aditya Ekka

Roll Number : 21bcs119

CGPI : 8.81

Semester : 3

Enter details of student 2
Name : Akshat Kumar

Roll Number : 21bcs103

CGPI : 8.36

Semester : 3

Enter details of student 3
Name : Jaskaran Singh

Roll Number : 21bcs104

CGPI : 8.14

Semester : 3

Enter details of student 4
Name : Vishnu

Roll Number : 21bcs117

CGPI : 7.54

Semester : 3

Enter details of student 5
Name : Vishal Meena

Roll Number : 21bcs121

CGPI : 6.91

Semester : 3

Enter choice : 2

Enter 1 to display all student details :
Enter 2 to display according to cgpi : 1

Details of students 1
Name : Aditya Ekka
Roll Number : 21bcs119
CGPI : 8.81
Semester : 3
Details of students 2
Name : Akshat Kumar
Roll Number : 21bcs103
CGPI : 8.36
Semester : 3
Details of students 3
Name : Jaskaran Singh
Roll Number : 21bcs104
CGPI : 8.14
Semester : 3
Details of students 4
Name : Vishnu
Roll Number : 21bcs117
CGPI : 7.54
Semester : 3
Details of students 5
Name : Vishal Meena
Roll Number : 21bcs121
CGPI : 6.91
Semester : 3
Enter choice : 2

Enter 1 to display all student details :
Enter 2 to display according to cgpi : 2

Enter CGPI : 8.75

Name : Aditya Ekka
Roll Number : 21bcs119
CGPI : 8.81
Semester : 3
Enter choice : 3

Enter details of student 6
Name : Priyadarshan

Roll Number : 21bcs120

CGPI : 7.47

Semester : 3

Enter choice : 2

Enter 1 to display all student details :
Enter 2 to display according to cgpi : 1

Details of students 1
Name : Aditya Ekka
Roll Number : 21bcs119
CGPI : 8.81
Semester : 3
Details of students 2
Name : Akshat Kumar
Roll Number : 21bcs103
CGPI : 8.36
Semester : 3
Details of students 3
Name : Jaskaran Singh
Roll Number : 21bcs104
CGPI : 8.14
Semester : 3
Details of students 4
Name : Vishnu
Roll Number : 21bcs117
CGPI : 7.54
Semester : 3
Details of students 5
Name : Vishal Meena
Roll Number : 21bcs121
CGPI : 6.91
Semester : 3
Details of students 6
Name : Priyadarshan
Roll Number : 21bcs120
CGPI : 7.47
Semester : 3
Enter choice : 4
Program ended !
*/