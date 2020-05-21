#include <iostream>
#include <ctime>
using namespace std;

void isLeapYear(int year);
int main()
{    
    
    struct tm *inputdate{0}, *date{0};
    char buffer1 [26],buffer2 [26];
    
    time_t t = time(0);
    inputdate = localtime(&t);
    inputdate->tm_year = 2000-1900;
    inputdate->tm_mon = 4;
    inputdate->tm_mday = 20; 
    
    time_t mynow = mktime(inputdate);
    char *mydate = ctime(&mynow);
    
    //change date format to YYYY/MM/DD
    strftime(buffer1, 26, "%Y/%m/%d", inputdate); 
    cout<<"My Birthday is: "<<mydate;
    cout<<"My Birthday(YYYY/MM/DD) is: "<<buffer1<<endl<<endl;
    int myyear = inputdate->tm_year;
    
    //get current calendar date and time
    time_t now = time(0);
    date = localtime(&t);
    char *dt = ctime(&now);
    
    //change date format to YYYY/MM/DD
    strftime(buffer2, 26, "%Y/%m/%d", date); 
    cout<<"Today is: "<<dt;
    cout<<"Today(YYYY/MM/DD) is: "<<buffer2<<endl<<endl;
    int thisyear = date->tm_year;   
    
    //print age
    cout<<"My age is: "<<thisyear - myyear<<endl<<endl;
    
    for(int i = 2000; i<2021; ++i)
    {
        isLeapYear(i);
    }
    cout<<endl;   
    
    return 0;
}
void isLeapYear(int year)
{
    if(year%4 ==0)
        cout<<"This "<<year<<" Leap year"<<endl;
}