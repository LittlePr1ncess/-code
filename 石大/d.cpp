#include<bits/stdc++.h>
using namespace std;
int nxt[1000010];char s[1000005];
int gcd(int x)
{
	return x;
}
int main()
{
	//freopen("a.txt","r",stdin);
    //string s;
    
    int step=1,n;
	cin>>s; 
        int len=strlen(s);
        //memset(nxt,0,sizeof(0));
        int i=0,j=1;
        while(j<len)  //先写出next数组
        {
            if(s[i]!=s[j]&&i!=0)
            {
                i=nxt[i-1];
            }
            else if(s[i]!=s[j]&&i==0)
            {
                nxt[j]=0;
                j++;
                //j=gcd(j);
            }
            else if(s[i]==s[j])
            {
                nxt[j]=i+1;
                j++,i++;
            }
        }
        int l=len-nxt[len-1];
        //printf("%d ",l);
		if(l==len)	cout<<"-1";
        else {
        
        
        	for(int i=0; i<l; i++)
        	{
           	 cout<<s[i];
        	}
		}
        
        //printf("\n");

    return 0;
}

