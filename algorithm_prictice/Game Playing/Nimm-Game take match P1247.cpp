#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<int,int>
#define x first
#define y second 
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;

int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_prictice\\in.txt","r",stdin); 
    #endif
    
    int n;
    while(cin>>n)
    {
        vector<int> a(n+1);
        int sum=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum^=a[i];
        }
        if(sum==0){
            cout<<"lose"<<endl;
            continue;
        }
        int ind=0;
        for(int i=1;i<=n;i++)
        {
            if((a[i]^sum)<a[i]){
                cout<<a[i]-(a[i]^sum)<<" "<<i<<endl;
                ind=i;
                break;
            }
        }
        for(int i=1;i<=n;i++){
            if(i==ind) cout<<(sum^a[i])<<" ";
            else cout<<a[i]<<" ";
        }cout<<endl;
    }

    return 0;
}