#include <stdio.h>
	int arr[100];
void getMatrixElements(int matrix[][10], int row, int column) {

   printf("\nEnter elements: \n");

   for (int i = 0; i < row; ++i) {
   	
      for (int j = 0; j < column; ++j) 
	  {
         printf("Enter a%d%d: ", i + 1, j + 1);
         scanf("%d", &matrix[i][j]);
      }
   }
}
int* multiplyMatrices(int first[][10],
                      int second[][10],
                      int result[][10],
                      int r1, int c1, int r2, int c2) 
{
   for (int i = 0; i < r1; ++i) 
   {
      for (int j = 0; j < c2; ++j) 
	  {
         result[i][j] = 0;
      }
   }
   for (int i = 0; i < r1; ++i) 
   {
      	for (int j = 0; j < c2; ++j) 
	  	{
	        for (int k = 0; k < c1; ++k) 
			{
	           result[i][j] += first[i][k] * second[k][j];
	        }
      	}
   }
   int k=0;
   for(int i=0;i<r1;i++)
   {
	   	for(int j=0;j<c2;j++)
	   	{
	   		arr[k++]=result[i][j];	
		}
   }
   return arr;
}
void testMultiplyMatrices(int first[][10],
                      int second[][10],
                      int result[][10],
                      int r1, int c1, int r2, int c2,int expectedOutcome[])
{
    int i,j,count=0;
    int *arr=multiplyMatrices(first,second,result,r1,c1,r2,c2);
	for(i=0;i<r1*c2;i++)
	{
			if(arr[i]==expectedOutcome[i])
			{
				count++;
			}
			else
			{
				break;
			}
		
	}
	if(count==r1*c2)
	{
		printf("successful\n");
	}
	else
	{
		printf("unsuccessful\n");
		
							}						
}                						  

void display(int res[][10], int row, int column) 
{

   printf("\nOutput Matrix:\n");
   for (int i = 0; i < row; ++i) 
   {
      for (int j = 0; j < column; ++j) 
	  {
         printf("%d  ", res[i][j]);
         if (j == column - 1)
            printf("\n");
      }
   }
}

int main() {
   //int first[10][10], second[10][10], result[10][10], r1, c1, r2, c2,arr[100];
   /*printf("Enter rows and column for the first matrix: ");
   scanf("%d %d", &r1, &c1);
   printf("Enter rows and column for the second matrix: ");
   scanf("%d %d", &r2, &c2);

   while (c1 != r2) {
      printf("Error! Enter rows and columns again.\n");
      printf("Enter rows and columns for the first matrix: ");
      scanf("%d%d", &r1, &c1);
      printf("Enter rows and columns for the second matrix: ");
      scanf("%d%d", &r2, &c2);
   }

   getMatrixElements(first, r1, c1);

   getMatrixElements(second, r2, c2);
	int arr[4]={1,0,0,1};
   //multiplyMatrices(first, second, result, r1, c1, r2, c2);*/
   
    FILE* ptr;
    int r1,c1,r2,c2;
    ptr = fopen("Assignment8_matrix.txt", "r"); 
    if (ptr == NULL) {
        printf("file can't be opened \n");
    }
    
    fscanf(ptr,"%d",&r1);
     fscanf(ptr,"%d",&c1);
      fscanf(ptr,"%d",&r2);
    fscanf(ptr,"%d",&c2);
    //num=getw(ptr);
	int first[r1][c1],second[r2][c2],result[r1][c2],arr[r1*c2];
	int i,j;
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			fscanf(ptr,"%d",&first[i][j]);
			printf("%d   ",first[i][j]);
		}
			printf("\n");
	}
	for(i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
			fscanf(ptr,"%d",&second[i][j]);
			printf("%d   ",second[i][j]);
		}
			printf("\n");
	}
	for(i=0;i<r1*c2;i++)
	{
			fscanf(ptr,"%d",&arr[i]);
			printf("%d   ",arr[i]);
	}
	testMultiplyMatrices(first, second, result, r1, c1, r2, c2,arr);

    fclose(ptr);
   //display(result, r1, c2);

   return 0;
}