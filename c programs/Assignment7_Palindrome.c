#include<stdio.h>

int checkPalindrome(char str[],int n)
{
	int i,j,temp=1;
	for(i=0,j=n-1;i<n/2,j>=n/2;i++,j--)
	{
		if(str[i]!=str[j])
		{
			temp=0;
			break;
		}
	}
	if(temp==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void testCheckOccurenceFunction(char str[],int n,int expectedOutcome)
{
 	if(checkPalindrome(str,n)==expectedOutcome)
	{
	  	printf("succesful for %s\n",str);
	}	
	else
	{
	  	printf("unsuccesful for %s\n",str);		
	}
}
int main()
{
 	/*char str[]="aaa";
 	int i;
 	for(i=1;i<=5;i++)
 	{
	    testCheckOccurenceFunction(str,3,1);
	    str[0]=str[0]+1;
	    str[1]=str[1]+3;
	    str[2]=str[2]+1;
	}
	char str1[]="abc";
	for(i=1;i<=5;i++)
 	{
	    testCheckOccurenceFunction(str1,3,0);
	    str1[0]=str1[1]+2;
	    str1[1]=str1[2]+3;
	    str1[2]=str1[0]+1;
	}*/
	int expectedOutcome,n;
	char ch[20];
	FILE* ptr;
    ptr = fopen("Assignment7_palindrome.txt", "r"); 
    if (ptr == NULL) {
        printf("file can't be opened \n");
    }
    
    fscanf(ptr,"%s",ch);
    fscanf(ptr,"%d",&n);
    fscanf(ptr,"%d",&expectedOutcome);
    testCheckOccurenceFunction(ch,n,expectedOutcome);
	fclose(ptr);
	return 0;
}
