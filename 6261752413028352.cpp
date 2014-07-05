#include <iostream>
#include <vector>
using namespace std;

vector<int> getSequence(vector<int> a, vector<int> b)
{
    vector<int> v, va, vb;
    int ia, ib, na, nb;
    ia=ib=0;
    na=a.size();
    nb=b.size();

    int suma = 0, sumb = 0;
    
    while(ia<na && ib<nb)
    {
        if(a[ia] == b[ib])
        {
            //v.push_back(suma > sumb ? suma : sumb);
            suma > sumb ? v.insert(v.end(), va.begin(), va.end()) : v.insert(v.end(), vb.begin(), vb.end());
            v.push_back(a[ia]);
            ia++;
            ib++;
            va.clear();
            vb.clear();
            suma = sumb = 0;
            continue;
        }
        if(a[ia] < b[ib])
       {
           suma += a[ia];
           va.push_back(a[ia++]);
       }
       else
      {
           sumb += b[ib];
           vb.push_back(b[ib++]);
       }
    }
    va.clear();
    vb.clear();
    suma = sumb = 0;

    while (ia<na)
    {
        suma += a[ia];
        va.push_back(a[ia++]);
    }


    while (ib<nb)
    {
        sumb += b[ib];
        vb.push_back(b[ib++]);
    }
     suma > sumb ? v.insert(v.end(), va.begin(), va.end()) : v.insert(v.end(), vb.begin(), vb.end());
    
    //v.push_back(suma > sumb ? suma : sumb);

    return v;
}

int main() {
	int na, nb, i;
    while(cin>>na)
    {
        vector<int> a(na);

        for(i=0; i<na; i++)
            cin>>a[i];

        cin>>nb;

        vector<int> b(nb);

        for(i=0; i<nb; i++)
            cin>>b[i];

      vector<int> v = getSequence(a, b);


    for(i=0; i<v.size(); i++)
        cout<<v[i]<<" ";

     cout<<endl;

    }
	return 0;
}


/*
Input:

13 3 5 7 9 20 25 30 40 55 56 57 60 62
11 1 4 7 11 14 25 44 47 55 57 100

Output:



3 5 7 9 20 25 44 47 55 56 57 10






*/