#include <iostream>
#include <vector>

using namespace std;

void display(int q, vector<int> sequence, int repeat)
{
    cout<<q<<'.';
    int i;
    for(i=0; i<sequence.size(); i++)
    {
        if(repeat == i)
            cout<<'(';
        cout<<sequence[i];
    }
    if(repeat >= 0)
        cout<<')';
    cout<<endl;
}

int main()
{
   int n, m, q, r;
   while(cin>>n>>m)
   {
       vector<int> sequence;
       vector<int> index(m, -1);
       q = n / m;
       int i, repeat = -1;
       for(i=0; i<m; i++)
       {
           int t = n % m;
           if(index[t] != -1)
           {
               repeat = index[t];
               
               break;
           }
           
           index[t] = i;
           n = t * 10;
           sequence.push_back(n / m);
       }
       
       display(q, sequence, repeat);
   }
   
   return 0;
}

/*
input:
10 3 12 7 19 11 16 6 3227 555
output:
3.(3)
1.(714285)
1.(72)
2.(6)
5.8(144)
*/
