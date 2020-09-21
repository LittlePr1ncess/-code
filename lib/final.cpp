#include<bits/stdc++.h>
#include <tr1/unordered_map>
using namespace std;
#define MN 105
char S[MN*MN];
std::tr1::unordered_map<std::string, string> dic;
int dfs(char *key,char *a)
{
    for(int i=0;i<strlen(a);i++)
    {
        char nowKey[MN],value[MN];
        int lenKey = strlen(key);
        int k=0;
        for(k=0;k<lenKey;k++)
            nowKey[k] = key[k];
        nowKey[k] = '\0';
        if(lenKey > 0)
        {
            nowKey[lenKey++] = '.';
            nowKey[lenKey] = '\0';
        }
        if(a[i] == '"')
        {
            i++;
            while(a[i] != ':')
            {
                nowKey[lenKey++] = a[i++];
            }
            nowKey[lenKey-1] = '\0';
         }
         i++;
         if(a[i] == '"'){
             int j=7;
             i++;
             strcpy(value,"STRING ");
             while(a[i] != ',' && a[i] != '}'){
                 value[j++] = a[i++];
             }
             value[j-1] = '\0';
             dic[nowKey] = value;
         }else if(a[i] == '{')
         {
             dic[nowKey] = "OBJECT";
             i += dfs(nowKey,a+i+1)+1;
          }
          if(a[i] == '}')
              return i+1;
    }
}

int main()
{
    string str;
    int n,m;
    cin>>n>>m;
    n = n+1;
    int i=0;
    while(n--)
    {
        getline(cin,str);
        for(int k=0;k<str.length();k++)
        {
            if(str[k]=='\\')
                S[i++] = str[++k];
            else if(str[k] == ' ' || str[k] == '\n')
                continue;
            else{
                S[i++] = str[k];
            }
        }
    }
    S[i] = '\0';
    dfs("",S+1);
    for(int j=0;j<m;j++)
    {
        string str2;
        getline(cin,str2);
        if(dic[str2]=="")
            cout << "NOTEXIST" << endl;
        else
            cout << dic[str2] << endl;
    }
    return 0;
}