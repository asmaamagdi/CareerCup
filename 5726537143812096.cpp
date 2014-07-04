#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v2;

int BS(int s, int e, int x)
{
    while(s <= e)
    {
        int m = (s + e) / 2;
        if(v2[m] == x)
        {
            return m;
        }
        if(v2[m] > x)
        {
            e = m-1;
        }
        else
        {
            s = m+1;
        } 
    }
    return -1;
}

int main()
{
    int n, i;
    while(cin>>n)
    {
        vector<int>v(n);
        for(i=0; i<n; i++)
        {
            cin>>v[i];
        }
        
        v2 = v;
        sort(v2.begin(), v2.end());
        
        for(i=0; i<n; i++)
        {
            int j = BS(0, v2.size(), v[i]);

            if(j+1 < v2.size())
                cout<<v2[j+1];
            else
                cout<<-1;
            cout<<" ";
            
            v2.erase(v2.begin() + j);
        }
        cout<<endl;
    }
   return 0;
}

/*
input: 
1
8 58 71 18 31 32 63 92 43 3 91 93 25 80 28 
7
8 16 22 13 4 36 9
output: 
18 63 80 25 32 43 80 93 80 25 93 -1 28 -1 -1 
9 22 36 36 9 -1 -1

*/
