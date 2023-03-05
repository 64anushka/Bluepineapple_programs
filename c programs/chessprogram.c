#include<stdio.h>
int checkQueenAttack(int qPosition1,int qPosition2,int hPosition1,int hPosition2)
{
	int i;	
	for(i=0;i<=7;i++)
	{
		if(qPosition1==hPosition1 && i==hPosition2)
		{
			return 1;
		}
		else if(i==hPosition1 && qPosition2==hPosition2)
		{
			return 1;
		}
	}	
	int q1=qPosition1,q2=qPosition2,h1=hPosition1,h2=hPosition2;
	for(i=0;i<=7;i++)
	{
		if(q1<0)
		{
			q1=7;
		}
		if(q1>7)
		{
			q1=0;
		}
		if(q2<0)
		{
			q2=7;
		}
		if(q2>7)
		{
			q2=0;
		}
		if(q1==hPosition1 && q2==hPosition2)
		{
			return 1;
		}
		q1--;
		q2++;
	}
	q1=qPosition1,q2=qPosition2,h1=hPosition1,h2=hPosition2;//4 3 6 6
	for(i=0;i<=7;i++)
	{
		if(q1<0)
		{
			q1=7;
		}
		if(q1>7)
		{
			q1=0;
		}
		if(q2<0)
		{
			q2=7;
		}
		if(q2>7)
		{
			q2=0;
		}
		if(q1==hPosition1 && q2==hPosition2)
		{
			return 1;
		}
		q1++;
		q2++;
	}
	return 0;
}
int checkHorseAttack(int qPosition1,int qPosition2,int hPosition1,int hPosition2)
{
	if(hPosition1+1==qPosition1 &&  hPosition2+2==qPosition2)
	{
		return 2;
	}
	else if(hPosition1+1==qPosition1 && hPosition2-2==qPosition2)
	{
		return 2;
	}
	else if(hPosition1-1==qPosition1 && hPosition2+2==qPosition2)
	{
		return 2;
	}
	else if(hPosition1-1==qPosition1 && hPosition2-2==qPosition2)
	{
		return 2;
	}
	else if(hPosition1+2==qPosition1 && hPosition2+1==qPosition2 )
	{
		return 2;
	}
	else if(hPosition1+2==qPosition1 && hPosition2-1==qPosition2)	
	{
		return 2;
	}
	else if(hPosition1-2==qPosition1 && hPosition2+1==qPosition2)
	{
		return 2;
	}
	else if(hPosition1-2==qPosition1 &&hPosition2-1==qPosition2)
	{
		return 2;
	}
	else
	{
		return 0;	
	}
}
int solve(int qPosition1,int qPosition2,int hPosition1,int hPosition2)
{
	int result;
	result=checkQueenAttack(qPosition1,qPosition2,hPosition1,hPosition2);
	if(result==0)
		result=checkHorseAttack(qPosition1,qPosition2,hPosition1,hPosition2);
//	if(result==1)
//	{
//		printf("Queen can attack\n");
//	}
//	else if(result==2)
//	{
//		printf("Horse can attack\n");
//	}
//	else
//	{
//		printf("both are safe\n");
//	}
	return result;
}
void testSolve(int qPosition1,int qPosition2,int hPosition1,int hPosition2,int expectedOutcome)
{
	int result=solve(qPosition1,qPosition2,hPosition1,hPosition2);
	//printf("%d",result);
	if(result==expectedOutcome)
	{
		printf("Test Case Successful\n");
	}
	else
	{
		printf("Test Case Failed\n");
	}
}
int main()
{
	int i,j;
	for(i=0;i<=5;i++)
	{
		testSolve(0,0,i,i,1);
	}
	for(i=0;i<=5;i++)
	{
		if(i==0 || i==3)
			testSolve(i,i,1,2,2);
		else if(i==1 || i==2)
			testSolve(i,i,1,2,1);
		else
			testSolve(i,i,1,2,0);	
	}
}