#include<bits/stdc++.h>
using namespace std;
//�Һ�����������
//B,C ���������WAһ�£���D�Ժ�һ��Сʱ��������һ��������
//��������ö��+��֦��αn^3��˼·һ��ö��a,b,c,���4e5��; ˼·����ö�ٱ���һ�ͱ�����
//�ٷ���⣺ Aö��a��ȡֵ��1~2*a�����A����2*a����ôֱ����A=1��
//          Bö��b��A~2*b��Ȼ��C������ȡֵ��ȫ�����ԣ�O(N*lg N)
void solve1(int a,int b,int c)
{
    int ans=abs(b-a)+abs(c-b);
    int ia,ib,ic;
    for(int i=1;i<=10032;i++)//10000����ȷ��������10032���٣���������ݡ����2e4Ҳ�ܹ�
        for(int j=i;j<=10032;j+=i)//ԭ��������<1e4,�������û���޶���
            for(int k=j;k<=10032;k+=j)
            {
                int detal=abs(i-a)+abs(j-b)+abs(k-c);
                if(ans>=detal)  {
                    ia=i,ib=j,ic=k;
                    ans=detal;
                }
            }
    cout<<ans<<endl<<ia<<" "<<ib<<" "<<ic<<endl;
}
int main()
{
    int T;
    //freopen("D:/code/in.txt","r",stdin);
    cin>>T;
    while(T--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        solve1(a,b,c);
    }
    return 0;
}