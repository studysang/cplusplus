#include<iostream>
#include<vector>
using namespace std;

bool isTwoSmallNumber(int n)
{
    int mul = 0;
    for(int i = 1; i< n ; ++i)
    {
        for( int j = 1 ; j< n; ++j)
        {
            mul = i*j;            
            if(mul == n && (i!=1||j!=1))
            {                
                return true;
            }
                            
        }
    }
    return false;
}
bool isAvailable(int n, int div)
{
    int temp = 0;
    temp = n%div;
    if(temp == 0)
        return true;
    else
    return false;
}
void PrintPrimeFactor(int n, vector<int>prime)
{
    double div = 0;
    vector<int> factor;
    auto i = prime.begin();
    while(true)
    {
        if(isAvailable(n,(*i)))
        {
            div = n/(*i);
            factor.push_back(*i);
            if(!isTwoSmallNumber(div))
            {     
                factor.push_back(div);       
                break;
            } 
            n = div;
        }
        else{
            ++i;
        }
    }
    /*
    for(auto i = prime.begin();i !=prime.end(); ++i)
    {        
        cout<<div<<" " << n <<" " << *i<<" " << endl;       
    }
     */
    cout<<"prime factor "<<endl;
    for(auto i = factor.begin();i!=factor.end();++i)
    {
        cout<<*i <<" ";        
    }
    cout<<endl;
}
int main(){
    int n = 48;
    vector<int> prime;
    //store prime number to calculate the prime factor  
    for(int i = 2;i<n; ++i)
    {
        if(isTwoSmallNumber(i) == false)
        {          
            prime.push_back(i);
            //cout<<i<< endl;
        }
    }
    //print prime number
    for(auto i = prime.begin();i !=prime.end(); ++i);
        //cout<< *i<<endl;
    //print prime factor 
    //this function pass number to be divided by prime number
    // to find prime factor and with prime number vector
    PrintPrimeFactor(n, prime);
    return 0;
}