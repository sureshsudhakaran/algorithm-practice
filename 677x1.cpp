#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ans,m,dig,n,T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        m=0;
        dig=n%10;
        while(n)
        {
            m++;
            n/=10;
        }
        ans=10*(dig-1);
        ans+=m*(m+1)/2;
        cout<<ans<<"\n";
    }
    return 0;
}
