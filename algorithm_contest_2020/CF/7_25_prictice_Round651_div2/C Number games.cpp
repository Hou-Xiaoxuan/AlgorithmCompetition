#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
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
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    /*
    *能将数字保持为大于3的偶数的人获胜
    *有没有奇数因子？
    */
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       bool flag=false;//Ashishgup
       if(n==1) 
            flag=true;
        else if(n<=3)
            flag=false;
        else if (n%2==1)
            flag=false;
        else
        {
            // i guess it's false
            int tmp=n;
            while(tmp%2==0 and tmp>1) tmp/=2;
            if(tmp==1) flag=true;
            else if(n/tmp>=4) flag=false;
            else
            {
                //如果tmp为质数，那么没办法了。如果不是质数，就可以获胜。
                // if(tmp==3) flag=true;
                if(tmp==3) flag=true;
                if(tmp==5) flag=true;
                if(tmp==7) flag=true;
                for(int i=3;i<=sqrt(tmp);i+=2)
                {
                    if(tmp%i==0){
                        flag=false;
                        break;
                    }
                    flag=true;
                }
            } 
        }
        if(flag==false) cout<<"Ashishgup"<<endl;
        else cout<<"FastestFinger"<<endl;
   }
    return 0;
}