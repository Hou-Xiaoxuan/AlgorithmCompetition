#include<bits/stdc++.h>
using namespace std;
#define make_pair m_k
typedef long long LL;
typedef unsigned long long ULL;
//���⣺dp+ȥ�أ�ͳ��dp[i][j]//ǰi������j�������и��� ֻ��Ҫ��ȥ dp��s��i���ϴγ��֡���j��������
char s[1005];
LL dp[1005][1005]={0};
const LL mod=1e9+7;
int main()
{
    
    int n,k;cin>>n>>k;
    cin>>s+1;
    int pre[30]={0};
    dp[0][0]=1;//Ĭ�Ͽ��ַ���1
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++){
            dp[i][0]=1;
            dp[i][j]=dp[i-1][j]+dp[i-1][j-1];//ѡ���i���벻ѡ���i���ĺ;����ظ����������ظ�������ѡ��i����
            if(pre[s[i]-'a']!=0) dp[i][j]-=dp[pre[s[i]-'a']-1][j-1];//ֻҪȥ����һ�γ���is[i]ʱ����Ϊjʱѡ����s[i]d����
            dp[i][j]%=mod;//��Ϊ��һ�γ��ֵ���һ��һ�������һ�飬�����ظ�
        }
        pre[s[i]-'a']=i;//s[i]�ϴγ��ֵ�λ��
    }
    LL ans=dp[n][k];
    if(ans<0) ans+=mod;
    cout<<ans<<endl;
    return 0;
}
