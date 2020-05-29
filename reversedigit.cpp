#include <iostream>

using namespace std;
int main()
{
    //write a program to reverse the digits a number using pointer
    int digits[5] = {1,2,3,4,5};    
    
    int *pReverse = &digits[4];
    
    cout<<*pReverse--<<*pReverse--<<*pReverse--<<*pReverse--<<*pReverse--<<endl;
    
    return 0;
}