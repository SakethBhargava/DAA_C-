#include <iostream>
using namespace std;
struct node
{
    int fr, to, cost;
}
p[6];
int c = 0, temp1 = 0, temp = 0;
void prims(int *a, int b[][3], int i, int j)
{
    a[i] = 1;
    while (c < 6)
    {
        int min = 99;
        for (int i = 0; i < 3; i++)
        {
            if (a[i] == 1)
            {
                for (int j = 0; j < 3; )
                {
                    if (b[i][j] >= min || b[i][j] == 0)
                    {
                        j++;
                    }
                    else if (b[i][j] < min)
                    {
                        min = b[i][j];
                        temp = i;
                        temp1 = j;
                    }
                }
            }
        }
        a[temp1] = 1;
        p[c].fr = temp;
        p[c].to = temp1;
        p[c].cost = min;
        c++;       
        b[temp][temp1] = b[temp1][temp]=1000;
    }
    for (int k = 0; k < 6; k++)
    {
        cout<<"source node:"<<p[k].fr<<endl;
        cout<<"destination node:"<<p[k].to<<endl;
        cout<<"weight of node"<<p[k].cost<<endl;
        cout<<endl;
    }
}
int main()
{
    int a[3];
    for (int i = 0; i < 3; i++)
    {
        a[i] = 0;
    }
    int b[3][3];
    for (int i = 0; i < 3; i++)
    {
        cout<<"enter values for row "<<(i+1)<<" :"<<endl;
        for (int j = 0; j < 3; j++)
        {
            cin>>b[i][j];
        }
    }
    prims(a, b, 0, 0);
}