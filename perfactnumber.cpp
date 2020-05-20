#include<iostream>
#include<vector>
using namespace std;

void printPerfectNumber(int n, vector<int> pnumber)
{
    int sum = 0;
    for(auto i = pnumber.begin(); i<pnumber.end()-1;++i)
    {
        sum +=*i;        
    }
    
    if(n == sum)
    {
        cout<<"---------------------"<<endl;
        for(auto i = pnumber.begin(); i<pnumber.end()-1;++i)
            cout<<*i<<", "; 
        cout<<" '"<<n<< "'"<<endl;
        cout<<"This "<<n<<" is peferct Number"<<endl;
        cout<<"---------------------"<<endl;
    }
    //else
    //    cout<< n <<" is not perfect Number"<<endl;    
   
}
int main()
{
    vector<int> pnumber;
    int n = 1, max = 1000, mul = 0;
    cout<<"Define a function of perfect number"<<endl;    
    while(n<=max)
    {
        pnumber.clear();
        for(int i = 1; i<=n; ++i)
        {
            for(int j = 1 ; j<=n; ++j)
            {
                mul = i*j;
                if(n == mul)
                    pnumber.push_back(i); 
            }
            
        }
 
        printPerfectNumber(n,pnumber);
        
        ++n;
    } 
    
}