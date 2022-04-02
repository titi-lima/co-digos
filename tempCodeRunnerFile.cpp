#include<functional>
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
typedef struct
{
	char stu[20];
	int x;
}carry;
carry str[1000005],str1[1000005];
int  main()
{
	int n,m,j=0;
	priority_queue<int, vector<int>,greater<int> >k;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf(" %s",str[i].stu);
		if(strcmp(str[i].stu,"removeMin")!=0)
			scanf("%d",&str[i].x);
		if(strcmp(str[i].stu,"insert")==0)
		{
			k.push(str[i].x);
			str1[j++]=str[i];
		}
		else if(strcmp(str[i].stu,"removeMin")==0)
		{
			if(k.empty())
			{
				k.push(1);
				strcpy(str1[j].stu,"insert");
				str1[j++].x=1;
			}
			k.pop();
			str1[j++]=str[i];
		}
		else if(strcmp(str[i].stu,"getMin")==0)
		{
            if(k.empty())
			{
				strcpy(str1[j].stu,"insert");
				str1[j++].x=str[i].x;
				k.push(str[i].x);
				strcpy(str1[j].stu,"getMin");
				str1[j++].x=str[i].x;
			}
			else
			{
				while(k.top()<str[i].x)
				{
					strcpy(str1[j++].stu,"removeMin");
					k.pop();
					if(k.empty())
					{
						strcpy(str1[j].stu,"insert");
						str1[j++].x=str[i].x;
						k.push(str[i].x);
					}
				}
				if(k.top()>str[i].x)
				{
					strcpy(str1[j].stu,"insert");
					str1[j++].x=str[i].x;
					k.push(str[i].x);
				}
				if(k.top()==str[i].x)
				{
					strcpy(str1[j].stu,"getMin");
					str1[j++].x=str[i].x;
				}
			}
		}
	}
	printf("%d\n",j);
	for(int i=0;i<j;i++)
	{
		if(strcmp(str1[i].stu,"removeMin")==0)
			printf("%s\n",str1[i].stu);
		else
			printf("%s %d\n",str1[i].stu,str1[i].x);
	}
}