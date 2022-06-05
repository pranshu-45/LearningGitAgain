#include <bits/stdc++.h>
using namespace std;

unsigned long long power(unsigned long long x,int y,int p)
{
    unsigned long long res=1;
    x=x%p;
    while(y>0)
    {
        if(y&1)
            res=(res*x)%p;

        x=(x*x)%p;
        y=y>>1;        
    }
    return res;
}

unsigned long long modInverse(unsigned long long x,int p)
{
    return power(x,p-2,p);
}

int main()
{
    int t;
    cin >> t;
    int mod=1e9+7;
    vector<int> fac(101);
    fac[0]=1;
    for(int i=1;i<=100;i++)
        fac[i]=(fac[i-1]*i)%mod;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        unsigned long long a=(modInverse(fac[k],mod)%mod);
        unsigned long long b=(modInverse(fac[n-k],mod)%mod);
        unsigned long long c=fac[n];
        unsigned long long ans=((c*(a%mod)%mod)*(b%mod))%mod;
        int res=ans;
        cout << a << " " << b << " " << c << "\n";
        cout << res << " " << ans << "\n";
    }
    return 0;
}

// long long int nCr(int a,int b)b
// {
//     if(a<b)
//         return 0;
//     int n=a;
//     int k=b;
//     if(b>n-b)
//         k=n-b;
//     long long int ans=1;
//     for(int i=1;i<=k;i++)
//     {
//         long long int x=(n-k+i);
//         if(x%i==0)
//             ans*=x/i;
//         else if(ans%i==0)
//         {
//             ans/=i;
//             ans*=x;
//         }
//         else
//         {
//             ans=(ans*x)/i;
//         }
//     }
//     return ans;
// }