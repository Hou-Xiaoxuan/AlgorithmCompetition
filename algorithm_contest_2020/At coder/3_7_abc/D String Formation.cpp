/*Ӧ�����߶�����������������ǲ������*/
/*�ǵò��⣺D��E*/ //E�ⲹ�����ˡ���

//��⣺ ˫�˶��У�ÿ��ת�����Σ���β����ӡ�=����ͷ����ӣ����벻����ʮ��
//����������˼ά�ϰ������㲻��˫�˶��У�˼ά�ԵĻ�Ҳ�����ĳ����ġ�
#include<bits/stdc++.h>
using namespace std;
char s[100005];
int main()
{
    cin>>s;
   
   deque<char> de;
    for(int i=0;i<strlen(s);i++)
        de.push_back(s[i]);
    int n;  cin>>n;
    int cnt=0,tmp;
    while(n--)
    {
        cin>>tmp;
        if(tmp==1){
            cnt++;
            continue;
        }
        else
        {
            int i;
            char ch;
            cin>>i>>ch;
            if(i==1){
                if(cnt&1)
                    de.push_back(ch);
                else
                    de.push_front(ch);    
            }
            else if(i==2){
                if(cnt&1)
                    de.push_front(ch);
                else 
                    de.push_back(ch);
            }
        }
    }
    
    if(cnt&1)
        {
            while(!de.empty()){
                cout<<de.back();
                de.pop_back();
            }
        }
        else
        {
            while(!de.empty()){
                cout<<de.front();
                de.pop_front();
            }
        }
    return 0;
}