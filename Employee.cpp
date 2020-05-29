#include <iostream>
#include <string>
 
class Employee{
public:
        //construct Employee
        Employee(int Salary, int Workday)
        {
            mySalary = Salary;
            myWorkday = Workday;
        };
        int mySalary;
        int myWorkday;        
        GetInfo(int Salary, int Workday);        
        AddSal();
        AddWork(); 
        
};
Employee::GetInfo(int Salary, int Workday)
{
    mySalary = Salary;
    myWorkday = Workday;
    AddSal();
    AddWork();
   cout<<"Salaray/hours/day: "<<mySalary<<endl;
   cout<<"Workday: "<<myWorkday<<endl;
   cout<<"Total "<<mySalary * myWorkday<< endl;
} 
Employee::AddWork()
{
    if(myWorkday >=6)
    {        
        myWorkday += 5;       
    }    
} 
Employee::AddSal()
{
    if(mySalary<=500)
    {
        mySalary += 10;
    }    
}        
int main()
{   
    Employee *mObj = new Employee(0,0);
    mObj->GetInfo(400, 10); 
    return 0;
}