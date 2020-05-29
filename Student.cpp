#include <iostream>
#include <string>
using namespace std;
class Student
{
    public:
        //construct student
        //Student();
        //~Student();
    
        string name;
        int roll_number;
};
int main()
{
    Student cStudent;
    cStudent.name = "House";
    cStudent.roll_number =  10;
    cout<<cStudent.name<<endl;
    cout<<cStudent.roll_number<<endl;
    return 0;
}