#include <stdio.h>
int compact(int m, int n, int A[m][n], int B[m*n][3])
{
    int i, j;
    B[0][0] = m;
    B[0][1] = n;
    int k = 1;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (A[i][j] != 0)
            {
                B[k][0] = i;
                B[k][1] = j;
                B[k][2] = A[i][j];
                k++;
            }
        }
    }
    B[0][2]=k-1;

    if(k>m*n/2)
    {
        printf("The matrix is not sparse\n");
        return 0;
    }
    else{
        printf("The compact representation of the sparse matrix is:\n");
        for(i=0; i<k; i++)
        {
            for(j=0; j<3; j++)
            {
                printf("%d ",B[i][j]);
            }
            printf("\n");
        }
        
    }
    
    return 0;
}

int main()
{
    int m,n;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d",&m,&n);

    int A[m][n];
    int B[m*n][3];
    int i,j;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("Enter the element at position (%d,%d): ",i,j);
            scanf("%d",&A[i][j]);
        }
    }
    return compact(m,n,A,B);
}