#include<bits/stdc++.h>
#include <tr1/unordered_map>
using namespace std;
#define MN 105
char in[MN*MN];
std::tr1::unordered_map<std::string, string> dic;
int dfs(char *key,char *a)
{
    for(int i=0;i<strlen(a);i++)
    {
        char Key1[MN],value[MN];int len = strlen(key), k=0;
        for(k=0;k<len;k++)Key1[k] = key[k];
        Key1[k] = '\0';
        if(len > 0)
        {
            Key1[len++] = '.';
            Key1[len] = '\0';
        }
        if(a[i] == '"')
        {
            i++;
            while(a[i] != ':')Key1[len++] = a[i++];
            Key1[len-1] = '\0';
        }
        i++;
        if(a[i] == '"')
        {
            int j=7;
            i++;
            strcpy(value,"STRING ");
            while(a[i] != ',' && a[i] != '}')value[j++] = a[i++];
            value[j-1] = '\0';dic[Key1] = value;
         }else if(a[i] == '{')
         {
             dic[Key1] = "OBJECT";
             i += dfs(Key1,a+i+1)+1;
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
                in[i++] = str[++k];
            else if(str[k] == ' ' || str[k] == '\n')
                continue;
            else{
                in[i++] = str[k];
            }
        }
    }
    in[i] = '\0';
    dfs("",in+1);
    for(int j=0;j<m;j++)
    {
        string str2;
        getline(cin,str2);
        if(dic[str2]=="")
            cout << "NOTEXIST" << endl;
        else
            cout << dic[str2] << endl;

    }
    system("pause");
    return 0;
}