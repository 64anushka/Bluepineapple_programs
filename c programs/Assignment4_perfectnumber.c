#include<stdio.h>
int perfectNumber(int n)
{
	int arr[n],j=0,sum=0,i;
	for(i=0;i<n;i++)
	{
		arr[i]=0;
	}
	for(i=1;i<n;i++)
	{
		if(n%i==0)
		{
			arr[j++]=i;
		}
	}
	for(i=0;i<n;i++)
	{
		sum+=arr[i];
		if(arr[i]==0)
		{
			break;
		}
	}
	if(sum==n)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void testPerfectNumberFunction(int n,int expectedOutcome)
{
	if(perfectNumber(n)==expectedOutcome)
	{
		printf("Successful for %d\n",n);
	}
	else
	{
		printf("Unsuccessful for %d\n",n);
	}
}
int main()
{
	/*int num=1,expectedOutcome=0,i;
	for(i=1;i<100;i++)
	{
	    if(perfectNumber(i))
	    {
	        printf("%d\t",i);
	    }
	}
	printf("\n\n");
	for(i=1;i<=10;i++)
	{
		if(num==6 || num==28 )
		{
			expectedOutcome=1;
		}
		else
		{
			expectedOutcome=0;
		}
		testPerfectNumberFunction(num,expectedOutcome);
		num++;*/
	int num,expectedOutcome;
	FILE* ptr;
    ptr = fopen("Assignment4_perfectnum.txt", "r"); 
    if (ptr == NULL) {
        printf("file can't be opened \n");
    }
    
    fscanf(ptr,"%d",&num);
    fscanf(ptr,"%d",&expectedOutcome);
	testPerfectNumberFunction(num,expectedOutcome);    
	fclose(ptr);	
	
	return 0;
}