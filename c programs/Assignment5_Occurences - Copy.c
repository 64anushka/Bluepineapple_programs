#include<stdio.h>
int arr[10];
int* checkOccurence(int num)
{
	int i,rem=1;
	for(i=0;i<=9;i++)
	{
		arr[i]=0;
	}
	while(num!=0)
	{
		rem=num%10;
		arr[rem]=arr[rem]+1;
		num=num/10;
	}
	
	return arr;
}
void testCheckOccurenceFunction(int num,int *expectedOutcome)
{
	int* a=checkOccurence(num);
	int i=0,count=0;
 	while(i<=9)
	{
	   if(arr[i]!=expectedOutcome[i])  	
	   {
	   	   break;
	   }
	   i++;
	   count++;
    }
	if(count==10)
	{
		printf("Successful for %d\n",num);
		}
		else
		{
		    printf("Unsuccessful for %d\n",num);
		}
}
int main()
{
    /*int e[10]={0,0,0,0,0,0,0,0,0,0},i,num=111;
    for(i=0;i<9;i++)
    {
        e[i]=0;
        e[i+1]=3;
        testCheckOccurenceFunction(num,e);
        num+=111;
    } */
	FILE *ptr;
    ptr = fopen("Assignment5_somenumbers.txt", "r");

    //read file into array
    int ExpectedArray[10];
    int i,num;

	fscanf(ptr,"%d",&num);
    for (i = 0; i < 10; i++)
    {
        fscanf(ptr, "%d", &ExpectedArray[i]);
    }
    testCheckOccurenceFunction(num,ExpectedArray);
   

	return 0;
}
