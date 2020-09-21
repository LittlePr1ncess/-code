#include<stdio.h>
#include<string.h>
 char s[1005];
 int div(int chu)
{
    int i,j,mod;
    char d[1005];
    for(i=0,mod=0,j=0 ; s[i]!=0 ; i++,j++)
    {
        mod=mod*10+s[i]-'0';
        d[j]=mod/chu+'0';
        mod%=chu;
    }
    d[j]='\0';
    if(mod==0)
    {
        i=0;
        while(d[i]=='0')
            i++;
        strcpy(s,d+i);
        return 1;
    }
    else
        return 0;
}
 int main()
{
    int i,j;
    char ans[1005];
    while(1)
    {
        scanf("%s",s);
        if(s[0]=='-')
            return 0;
        if(s[1]==0)
        {
            printf("1%s\n",s);
            continue;
        }
        j=0;
        for(i=9;i>1;i--)
        {
            if(div(i))
            {
                ans[j++]=i;
                i++;
            }
        }
        if(strlen(s)>1)
            printf("There is no such number.");
        else
            for(i=j-1;i>=0;i--)
                printf("%d",ans[i]);
        printf("\n");
 
    }
    return 0;
}
