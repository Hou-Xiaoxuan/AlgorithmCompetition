//��c���d����ˣ�c�ǵ�ˮ�⣬d��������
//ʱ�䲻���ˣ����������ò�ƿ��Բ��������첹�⣬����DP
//���: DP[i][j]��ʾ ǰi����ʱ��j�������������ֵ������01����
#include<bits/stdc++.h>
using namespace std;
int dp[2005][2005],a[2005];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    int n,h,l,r;
    cin>>n>>h>>l>>r;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=h;j++)
            dp[i][j]=-1;
    for(int i=1;i<=n;i++) cin>>a[i];
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<h;j++){ 
               dp[i][j]=max(dp[i-1][(j-(a[i]-1)+h)%h],dp[i-1][(j-a[i]+h)%h]);
               if(j>=l and j<=r and dp[i][j]!=-1) dp[i][j]++;//����Ϸ�����++����Ȼ���ƫ��
           }
    int ans=0;
    for(int i=0;i<=h;i++)
        ans=max(ans,dp[n][i]);
    cout<<ans<<endl;
    return 0;
}