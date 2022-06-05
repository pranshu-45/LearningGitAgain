#include <bits/stdc++.h>
#include <iostream>
#include <string> 
using namespace std;

vector<int> Sing_Fact(int A)
{
    vector<int> res;
    while(A%2==0)
    {
        res.push_back(2);
        A/=2;
    }
    for(int i=3;i*i<=A;i+=2)
    {
        while(A%i==0)
        {
            res.push_back(i);
            A/=i;
        }
        if(A==1)
            break;
    }
    if(A!=1)
    {
        res.push_back(A);
        A/=A;
    }
    return res;
}

vector<vector<int>> Prime_Fact(vector<int> A)
{
    int n=A.size();
    int amax=A[0];
    for(int i=0;i<n;i++)
        amax=max(amax,A[i]);
    int spf[amax+1];
    for(int i=0;i<=amax;i++)
    {
        spf[i]=i;
    }
    for(int i=2;i<=amax;i+=2)
        spf[i]=2;
    for(int i=3;i*i<amax;i+=2)
    {
        if(spf[i]==i)
        {
            for(int j=i*3;j<=amax;j+=2*i)
                if(spf[j]==j)
                    spf[j]=i;
        }
    }
    vector<vector<int>> res;
    for(auto x:A)
    {
        vector<int> fact;
        //fact.clear();
        while(x!=1)
        {
            fact.push_back(spf[x]);
            x/=spf[x];
        }
        res.push_back(fact);
    }
    return res;
}

int main()
{
    vector<int> A={45};
    vector<vector<int>> ans=Prime_Fact(A);
    int n=A.size();
    for(int i=0;i<n;i++)
    {
        cout << A[i] << ": ";
        for(auto x:ans[i])
            cout << x << " ";
        cout << "\n";
    }

    vector<int> fact=Sing_Fact(49);
    cout << "49: ";
    for(auto x:fact)
        cout << x << " ";
    cout << "\n";

    return 0;
}
