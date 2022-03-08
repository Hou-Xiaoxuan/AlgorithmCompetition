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
// kmp�Ƕ�ģʽ������Ԥ����
char s[N],p[N];//ģʽ��p
int kmp[N];//kmp[j]ָ����j���ڵ��ƥ��
int main()
{
    cin>>(s+1)>>(p+1);
    int lens=strlen(s+1),lenp=strlen(p+1);
    kmp[1]=0;
    /*get next array*/
    int j=0;
    for(int i=2;i<=lenp;i++)
    {
        //j����Сֵ����0
        /*
        *j��ʾĿǰλ�õ�ƥ�䳤�ȡ����p[j+1]-p[i]��ƥ��Ļ�������p[i-1]-p[j]��ƥ���
        *��ô������i-1��˭��ƥ��ģ�����ƥ��i����һ�
        *��⣺������������ƥ�䵽��λ��ʱ�򣬲���ÿ�ζ���0��ʼ���������뿴��һλ�����������������������Ϳ�����
        * */
        while(j>0 and p[j+1]!=p[i])//���ƥ�䲻�ϣ����˶������
            j=kmp[j];
        if(p[j+1]==p[i])//ƥ���ϣ��򳤶�+1��
            j++;
        kmp[i]=j;
    }
    j=0;
    for(int i=1;i<=lens;i++)
    {
        while(j>0 and s[i]!=p[j+1]) j=kmp[j];//j����Сֵ����0
        
        if(p[j+1]==s[i]) j++;

        if(j==lenp) cout<<i-j+1<<endl;
    }
    for(int i=1;i<=lenp;i++) cout<<kmp[i]<<' ';
    cout<<endl;
    return 0;
}

/*��0��ʼ�İ汾*/
/*
        vector<int> kmp(needle.size(), 0);
        int j = 0; // ��ǰƥ�䳤��
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
