#include <iostream>
using namespace std;
int main()
{
    int a,b,c;
    cout<<"enter the three numbers :";
    cin>>a>>b>>c;
    if(a>b && a>c)
        cout<<"largest number :"<<a;
        if(b>c && b>a)
            cout<<"largest number :"<<b;
            if(c>a && c>b)
                cout<<"largest number :"<<c;
}