#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_k make_pair
#define   P  pair<int,int>
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;
double f[1005][1005]={0};//ʣ��i�׺�j��ʱӢ�ĸ���
//������⡭��
int main()
{
    //IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\code_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_prictice\\in.txt","r",stdin);  
    #endif
    int w,b;
    while(cin>>w>>b)
    {
        for(int i=0;i<=w;i++)
            memset(f[i],0,sizeof(double)*(b+1));
        for(int i=1;i<=w;i++) f[i][0]=1;
        for(int i=1;i<=w;i++)//��
            for(int j=1;j<=b;j++)//��
            {
                //����i��j�ڣ����ܻ�������
                f[i][j]+=double(i)/(i+j);//����ֱ��Ӯ
                if(j>=2)//���ܲ�Ӯ��Ȼ�����鵽����������һֻ��������ȥһֻ����û��ϵ������i-1��j-2�ڵĸ���
                    f[i][j]+=(double(j)/(i+j))*(double(j-1)/(i+j-1))*(double(i)/(i+j-2))*f[i-1][j-2];
                if(j>=3)//���鵽���󣬵�������һֻ�����ǿ���i��j-3�ڵĸ��ʡ���
                    f[i][j]+=(double(j)/(i+j))*(double(j-1)/(i+j-1))*(double(j-2)/(i+j-2))*f[i][j-3];
            }
        printf("%.9f\n",f[w][b]);
    }
    
    return 0;
}