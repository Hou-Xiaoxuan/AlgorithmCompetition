#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define x first
#define y second 
using namespace std;
using LL=long long;
using ULL=unsigned long long;
using LD=long double;
using P=pair<double,double>;
const int inf=0x3f3f3f3f;
const LL LLinf=0x3f3f3f3f3f3f3f3f;

// |a[i]-a[j]|+|a[i]+a[j]|==a[i]>a[j]?2*a[i]:2*|a[j]|;
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("D:/CODE/algorithm_contest/in.txt","r",stdin);  
    #endif
    
    int t;
    cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vector<LL> d(2*n+1);
        bool flag=true;
        for(int i=1;i<=n*2;i++){
            cin>>d[i];
        }
        sort(d.begin()+1,d.end());
        for(int i=1;i<=2*n;i+=2)
            if(d[i]!=d[i+1]){//每个数必须出现偶数次(d[a]==d[-a])
                flag=false;
                break;
            }
        if(flag==false or d[1]<2*n or d[1]%2==1){//d[1]=2*sum,必须大于2*n且为偶数
            cout<<"No"<<endl;
            continue;
        }
        
        // d[i]==d[i-1]-2*(i-1)*a[i-1]+2*(i-1)*a[i]
        flag=true;;
        vector<LL> a(n+1);
        LL sum_dd=0;
        for(int i=2;i<=n;i++)
        {
            if( (d[2*i-1]-d[2*i-3])%(i*2-2)!=0 or (d[2*i-1]-d[2*i-3])/(i*2-2)==0){//必须正好分配，且不为0(每次必须增加)
                // 不是整数or相等
                flag=false;
                break;
            }
            a[i]=a[i-1]+(d[2*i-1]-d[2*i-3])/(i*2-2);
            sum_dd+=a[i];
        }
        if(flag==true)
        {
            LL sum=d[1]/2-sum_dd;
            if(sum>0 and sum%n==0) cout<<"Yes"<<endl;//a[1]!=0
            else cout<<"No"<<endl;
        }
        else cout<<"No"<<endl;
    }
    return 0;
}
