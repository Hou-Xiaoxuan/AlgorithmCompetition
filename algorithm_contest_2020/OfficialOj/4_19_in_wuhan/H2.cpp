//#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<int,int>
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;
#define JJ {flag=1;break;}//jojo win
#define DD {flag=2;break;}//dio win
#define DJ {flag=3;break;}// tie
//����Ҳ��ͨ����˵��ԭ���� Ҫ���ַ�������ʽ�������ֳ��ַ���������
struct node{
    int a;
    char p;
    int ord;
    node(int aa=0,char pp='\0',int oo=0):a(aa),p(pp),ord(oo){};
    bool operator<(const node s)const{
        return ord<s.ord;
    }
};
void show_atack(vector<node> &s,int cnt)
{
    for(int i=1;i<=cnt;i++)
        cout<<s[i].a<<" "<<s[i].ord<<" "<<s[i].p<<endl;

}
char s1[20005],s2[20005];
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
        vector<node> atack(n*2+1);//������
        cin>>(s1+1)>>(s2+1);
        int cnt=0;//��������
        char *s=s1;
        for(int i=1;i<=n;i++)//����jojo����
        {
            //cin>>s[i];
            if(i>=3 and s[i]=='a' and s[i-1]=='r' and s[i-2]=='o')//�ж��ǲ�����A
                atack[++cnt]=node(1,'J',i);
            if(i>=9 and s[i]=='o')//�ж��ǲ��Ǵ�
                if(s[i]=='o' and s[i-1]=='u' and s[i-2]=='d' and s[i-3]=='u' and s[i-4]=='l' and s[i-5]=='a' and s[i-6]=='w' and s[i-7]=='a' and s[i-8]=='z')
                    atack[++cnt]=node(2,'J',i);
            
        }
        s=s2;
        for(int i=1;i<=n;i++)//����dio����
        {
            //cin>>s[i];
            if(i>=4 and s[i]=='a' and s[i-1]=='d' and s[i-2]=='u' and s[i-3]=='m')
                atack[++cnt]=node(1,'D',i);//�ж��ǲ�����A
            if(i>=9 and s[i]=='o')//�ж��ǲ��Ǵ�
                if(s[i]=='o' and s[i-1]=='u' and s[i-2]=='d' and s[i-3]=='u' and s[i-4]=='l' and s[i-5]=='a' and s[i-6]=='w' and s[i-7]=='a' and s[i-8]=='z')
                    atack[++cnt]=node(2,'D',i);    
        }

        sort(atack.begin()+1,atack.begin()+cnt+1);//����������ʱ��˳������
        vector<node> &at=atack;// //atack ̫���������û���
        int flag=-1;
        for(int i=1;i<=cnt;i++)//��ʼ��������
        {
            if(at[i].ord==at[i+1].ord)//same time
            {
                node s=at[i],t=at[i+1];
                i++;//һ���������ܣ�����i+=1;
                if(s.p=='J') swap(s,t);//��֤s�� Dio

                if(s.a==2) DD//���ж�dio��û�д�
                else if(t.a==2) JJ//dio�޴������£��ж�jojo�Ƿ񿪴�
                else{//���˶�û��˵������Ƕ�����A�����Լ�һ��Ѫ
                    H_D--;
                    H_J--;
                }
            }
            else//not the same
            {
                node s=at[i];
                if(s.p=='J'){//jojo's
                    if(s.a==2) JJ//jojo  ����jj win
                    else H_D--;//dio��Ѫ
                }
                else if(s.p=='D')
                {//dio's
                    if(s.a==2) DD//dio����dio win
                    else H_J--;//jojo��Ѫ
                }
            }
            if(H_J and H_D) continue;
            else if(H_J<=0 and H_D<=0) DJ//ͬʱ��0��tie
            else if(H_J<=0) DD//jojo����
            else if(H_D<=0) JJ//dio����
        }

        if(flag==-1)//û��������ֵ��0
        {
            if(H_D==H_J) cout<<"Kono Dio da"<<endl;
            else if(H_D<H_J) cout<<"Wryyyyy"<<endl;//jojo win
            else if(H_D>H_J)cout<<"Hinnjaku"<<endl;
        }
        else if(flag==1) cout<<"Wryyyyy"<<endl;//jojo win
        else if(flag==2) cout<<"Hinnjaku"<<endl;
        else if(flag==3) cout<<"Kono Dio da"<<endl;
        show_atack(at,cnt);
    }
    
    return 0;
}