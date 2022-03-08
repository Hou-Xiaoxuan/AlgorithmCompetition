//#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<int,int>
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;
//补题通过，说明是 技能条的读入出了问题
//手写的读入有问题，换成 string.find()就能ac
#define JJ {flag=1;break;}//jojo win
#define DD {flag=2;break;}//dio win
#define DJ {flag=3;break;}// tie
struct node{
    int a;
    char p;
    int ord;
    node(int aa=0,char pp='\0',int oo=0):a(aa),p(pp),ord(oo){};
    bool operator<(const node s)const{
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
        vector<node> at(n+1);//技能条
        int cnt=0;//技能总数
        /*
        vector<char> s(n+1);
        for(int i=1;i<=n;i++)//读入jojo技能
        {
            cin>>s[i];
            if(i>=3 and s[i]=='a' and s[i-1]=='r' and s[i-2]=='o')//判断是不是普A
                atack[++cnt]=node(1,'J',i);
            if(i>=9 and s[i]=='o')//判断是不是大
            {
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
                atack[++cnt]=node(1,'D',i);//判断是不是普A
            if(i>=9 and s[i]=='o')//判断是不是大
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
        */
        string a,b;cin>>a>>b;
        int pos=0;
        while(1){
            pos=a.find("ora",pos);
            if(pos==string::npos) break;
            at[++cnt]=node(1,'J',pos+=2);
        }
        pos=0;
        while(1){
            pos=a.find("zawaluduo",pos);
            if(pos==string::npos) break;
            at[++cnt]=node(2,'J',pos+=8);
        }
        pos=0;
        while(1){
            pos=b.find("muda",pos);
            if(pos==string::npos) break;
            at[++cnt]=node(1,'D',pos+=3);
        }
        pos=0;
        while(1){
            pos=b.find("zawaluduo",pos);
            if(pos==string::npos) break;
            at[++cnt]=node(2,'D',pos+=8);
        }
        sort(at.begin()+1,at.begin()+cnt+1);//技能条按照时间顺序排序
        int flag=-1;
        for(int i=1;i<=cnt;i++)//开始读技能条
        {
            if(at[i].ord==at[i+1].ord)//same time
            {
                node s=at[i],t=at[i+1];
                i++;//一次两个技能，所以i+=1;
                if(s.p=='J') swap(s,t);//保证s是 Dio

                if(s.a==2) DD//先判断dio有没有大
                else if(t.a==2) JJ//dio无大的情况下，判断jojo是否开大
                else{//俩人都没大，说明这次是都是普A，各自减一滴血
                    H_D--;
                    H_J--;
                }
            }
            else//not the same
            {
                node s=at[i];
                if(s.p=='J'){//jojo's
                    if(s.a==2) JJ//jojo  开大，jj win
                    else H_D--;//dio减血
                }
                else if(s.p=='D')
                {//dio's
                    if(s.a==2) DD//dio开打，dio win
                    else H_J--;//jojo减血
                }
            }
            if(H_J and H_D) continue;
            else if(H_J<=0 and H_D<=0) DJ//同时归0，tie
            else if(H_J<=0) DD//jojo先死
            else if(H_D<=0) JJ//dio先死
        }

        if(flag==-1)//没有人生命值归0
        {
            if(H_D==H_J) cout<<"Kono Dio da"<<endl;
            else if(H_D<H_J) cout<<"Wryyyyy"<<endl;//jojo win
            else if(H_D>H_J)cout<<"Hinnjaku"<<endl;
        }
        else if(flag==1) cout<<"Wryyyyy"<<endl;//jojo win
        else if(flag==2) cout<<"Hinnjaku"<<endl;
        else if(flag==3) cout<<"Kono Dio da"<<endl;
    }

    return 0;
}