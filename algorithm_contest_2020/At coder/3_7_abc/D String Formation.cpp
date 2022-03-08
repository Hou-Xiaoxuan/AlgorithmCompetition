/*应该是线段树，好像见过，但是不大会做*/
/*记得补题：D，E*/ //E题补不动了……

//题解： 双端队列，每反转奇数次，先尾部添加《=》向头部添加，代码不过三十行
//还是体现在思维上啊，就算不用双端队列，思维对的话也是做的出来的。
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