#include<bits/stdc++.h>
using namespace std;
//�����׳����������ݲ�ͬ�ĵط�����������Ҳ�ǵ����ġ����� x����9��������2����x+1��������2�ĸ���һ������9
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int p;cin>>p;
        int ans=0;
        for(int i=2;i*i<=p;i++)
        {
            if(p%i) continue;
            int cnt=0;
            while(p%i==0) {p/=i; cnt++;}
            int tmp=0;
            for(int j=i;;j+=i)
            {
                int n=j;
                while(n%i==0) {n/=i; tmp++;}//tmpΪj�Ľ׳���i�ĸ���
                if(tmp>=cnt){
                    ans=max(ans,j);
                    break��
                }
            }
        }
    cout<<max(ans,p)<<endl;//if(p>ans)˵�����ʣ��һ���ϴ������û�м��㣬��������Ľ׳˷���ȫ������
    }
    
    return 0;
}