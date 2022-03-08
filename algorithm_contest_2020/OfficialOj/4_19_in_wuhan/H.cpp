//#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<int,int>
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;
#define JJ {flag=1;break;}
#define DD {flag=2;break;}
#define DJ {flag=3;break;}
struct node{
    int a;
    char p;
    int ord;
    node(int aa=0,char pp='\0',int oo=0):a(aa),p(pp),ord(oo){};
    bool operator<(const node s){
        return ord<s.ord;
    }
};
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\code_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_contest\\in.txt","r",stdin);  
    #endif
    
    int t;cin>>t;
    char zawa[10]="zawaluduo";
    while(t--)
    {
        int n, h; cin>>n>>h;
        int H_D,H_J=H_D=h;
        vector<node> atack(n);
        vector<char> s(2*n+1); int cnt=0;
        for(int i=1;i<=n;i++)//读入jojo技能
        {
            cin>>s[i];
            if(i>=3 and s[i]=='a' and s[i-1]=='r' and s[i-2]=='o')
                atack[++cnt]=node(1,'J',i);
            if(i>=9)
            {
                vector<char> cmps(s.begin()+i-8,i+s.begin());
                bool flag=true;
                for(int j=0;j<9;j++)
                    if(zawa[j]!=s[i-8+j]){
                        flag=false;
                        break;
                    }
                if(flag) atack[++cnt]=node(2,'J',i);
            }
        }
        for(int i=1;i<=n;i++)//读入dio技能
        {
            cin>>s[i];
            if(i>=4 and s[i]=='a' and s[i-1]=='d' and s[i-2]=='u' and s[i-3]=='m')
                atack[++cnt]=node(1,'D',i);
            if(i>=9 and s[i]=='o')
            {
                bool flag=true;
                for(int j=0;j<9;j++)
                    if(zawa[j]!=s[i-8+j]){
                        flag=false;
                        break;
                    }
                if(flag) atack[++cnt]=node(2,'D',i);
            }
        }
        sort(atack.begin()+1,atack.begin()+cnt+1);
        vector<node> &at=atack;
        int flag=-1;
        for(int i=1;i<=cnt;i++)
        {
            if(at[i].ord==at[i+1].ord)//同时发动技能
            {
                i++;
                if(at[i-1].p=='J')//jojo先手
                {
                    if(at[i].a==2) DD//dio开打，win
                    else if(at[i-1].a==2) JJ//dio没大。jj开大，win
                    else//同时减血
                    {
                        H_D--;
                        H_J--;
                        if(H_D and H_J) continue;
                        else if(H_D<=0 and H_J) JJ
                        else if(H_J<=0 and H_D) DD
                        else if(H_J<=0 and H_D<=0) DJ        
                    }
                }
                else//dio先手
                {
                    if(at[i-1].a==2) DD//dio开打，win
                    else H_J--;
                    
                    if(at[i].a==2) JJ//jojo开打，win
                    else H_D--;

                    if(H_D and H_J) continue;
                    else if(H_D<=0 and H_J) JJ
                    else if(H_J<=0 and H_D) DD
                    else if(H_J<=0 and H_D<=0) DJ  
                }
            }
            else//非同时发动技能
            {
                if(at[i].p=='J')//jojo的回合
                {
                    if(at[i].a==1) H_D--;
                    else JJ//有大

                    if(H_D<=0) JJ
                }
                else//dio的回合
                {
                    if(at[i].a==1) H_J--;
                    else DD//有大

                    if(H_J<=0) DD
                }   
            }
            
        }
        if(flag==-1)//没有人生命值归0
        {
            if(H_D==H_J) cout<<"Kono Dio da"<<endl;
            else if(H_D<H_J) cout<<"Wryyyyy"<<endl;//jojo win
            else cout<<"Hinnjaku"<<endl;
        }
        else if(flag==1) cout<<"Wryyyyy"<<endl;//jojo win
        else if(flag==2) cout<<"Hinnjaku"<<endl;
        else if(flag==3) cout<<"Kono Dio da"<<endl;
    }

    return 0;
}