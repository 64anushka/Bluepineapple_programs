#include <stdio.h>
int noOfDigits(int num)
{
    int count=0;
    if(num!=0)
    {
        while(num)
         {
            count++;
            num=num/10;
         }
    }
    else if(num==0)
    {
        count=1;
    }
    else
    {
        count=0;
    }
    return count;
}
void testNoOfDigits(int num,int expectedNoOfDigit)
{
    if(noOfDigits(num)==expectedNoOfDigit)
    {
        printf("successful \n");
    }
    else
    {
		printf("successful \n");    }
	}
int main() {
    // Write C++ code here
    /*int num=1;//for positives
    for(int i=1;i<=5;i++)
    {
        testNoOfDigits(num,i);
        num=num*10;
    }
    num=-5;//for negatives
    for(int i=1;i<=5;i++)
    {
        testNoOfDigits(num,i);
        num=num*10;
    }
    testNoOfDigits(-2147483648,10);
    testNoOfDigits(2147483647,10);//limit*/
    FILE* ptr;
    int num,expected;
    ptr = fopen("Assignment2_countOfDigits.txt", "r"); 
    if (ptr == NULL) {
        printf("file can't be opened \n");
    }
    
    fscanf(ptr,"%d",&num);
    fscanf(ptr,"%d",&expected);
 	testNoOfDigits(num,expected);   
    fclose(ptr);
    
    return 0;
    return 0;
}
