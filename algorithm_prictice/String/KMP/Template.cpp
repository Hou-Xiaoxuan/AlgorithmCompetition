/*
 * @Author: LinXuan
 * @Date: 2021-09-01 22:37:35
 * @Description: 
 * @LastEditors: LinXuan
 * @LastEditTime: 2021-09-01 22:37:35
 * @FilePath: /Algorithm/algorithm_prictice/String/KMP/Template.cpp
 */
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
// kmp是对模式串进行预处理
char s[N],p[N];//模式串p
int kmp[N];//kmp[j]指包括j在内的最长匹配
int main()
{
    cin>>(s+1)>>(p+1);
    int lens=strlen(s+1),lenp=strlen(p+1);
    kmp[1]=0;
    /*get next array*/
    int j=0;
    for(int i=2;i<=lenp;i++)
    {
        //j的最小值就是0
        /*
        *j表示目前位置的匹配长度。如果p[j+1]-p[i]不匹配的话，至少p[i-1]-p[j]是匹配的
        *那么，看看i-1和谁是匹配的，尝试匹配i和下一项。
        *理解：就是在数现在匹配到几位的时候，不必每次都从0开始数，可以想看上一位可以数到几，接着往下数就可以了
        * */
        while(j>0 and p[j+1]!=p[i])//如果匹配不上，就退而求其次
            j=kmp[j];
        if(p[j+1]==p[i])//匹配上，则长度+1；
            j++;
        kmp[i]=j;
    }
    j=0;
    for(int i=1;i<=lens;i++)
    {
        while(j>0 and s[i]!=p[j+1]) j=kmp[j];//j的最小值就是0
        
        if(p[j+1]==s[i]) j++;

        if(j==lenp) cout<<i-j+1<<endl;
    }
    for(int i=1;i<=lenp;i++) cout<<kmp[i]<<' ';
    cout<<endl;
    return 0;
}

/*从0开始的版本*/
/*
        vector<int> kmp(needle.size(), 0);
        int j = 0; // 当前匹配长度
        for(int i=1; i<needle.size(); i++)
        {
            while(j>0 and needle[j] != needle[i])
                j = kmp[j - 1];

            if(needle[j] == needle[i]) j++;
            kmp[i] = j;
        }

        j = 0;
        for(int i=0; i<haystack.size(); i++)
        {
            while(j>0 and haystack[i] != needle[j])
                j = kmp[j - 1];
            if(haystack[i] == needle[j]) j++;

            if(j == needle.size()){
                return i - needle.size() + 1;
            }
        }
*/
