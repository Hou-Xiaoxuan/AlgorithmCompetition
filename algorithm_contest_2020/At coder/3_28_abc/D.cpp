#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;
#define k_p make_pair


int main()
{
    int n,x,y;
    while(cin>>n>>x>>y)
    {
        vector<int> cnt(n);
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
            {
                cnt[min( j-i, abs(x-i)+abs(y-j)+1)]++;//throuhg the x-y or not
            }
        for(int i=1;i<=n-1;i++)
            cout<<cnt[i]<<endl;

    }
    return 0;
}
