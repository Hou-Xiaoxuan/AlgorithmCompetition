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
    freopen("D:\\CODE\\code_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_prictice\\in.txt","r",stdin);  
    #endif
    //start
    int a[7];
    while(1)
    {
        int flag=0;
        for(int i=1;i<=6;i++)
            cin>>a[i],flag+=a[i];//λ�������������������
        if(flag==0) break;

        int cnt[6]={0};
        int ans=a[4]+a[5]+a[6];
        cnt[1]+=a[5]*11;
        cnt[2]+=a[4]*5;

        ans+=a[3]/4;
        if(a[3]%4){
            ans++;
            int t=a[3]%4;
            if(t==1) cnt[2]+=5,cnt[1]+=7;
            else if(t==2) cnt[2]+=3,cnt[1]+=6;
            else if(t==3) cnt[2]+=1,cnt[1]+=5;
        }
        
        if(a[2]>cnt[2]){//�����Ҫ��λ�ø��࣬
            a[2]-=cnt[2];//����a[2]�ǻ���Ҫ����
            ans+=a[2]/9;
            if(a[2]%9){
                ans++;
                cnt[1]+=4*(9-(a[2]%9));
            }
        }
        else{//������˵Ļ���ʣ��λ�ø�cnt[1]
            cnt[1]+=(cnt[2]-a[2])*4;
        }

        if(a[1]>cnt[1]){
            a[1]-=cnt[1];
            ans+=a[1]/36;
            if(a[1]%36) ans++;
        }
        
        cout<<ans<<endl;
    }

    return 0;
}