#include<stdio.h>
int transpose(int t, int A[t+1][3],int B[t+1][3])
{
    B[0][0] = A[0][1];
    B[0][1] = A[0][0];
    B[0][2] = A[0][2];

    if(A[0][2]<=0)
    {
        return -1;
    }
    else
    {
        int q=1;
        int i,j;
        for(i=0; i<A[0][1]; i++)
        {
            for(j=1; j<=A[0][2]; j++)
            {
                if(A[j][1]== i)
                {
                    B[q][0] = A[j][1];
                    B[q][1] = A[j][0];
                    B[q][2] = A[j][2];
                    q+=1;
                }
            }
        }
    }
    printf("%d %d %d\n", B[0][0], B[0][1], B[0][2]);

    for(int i = 1; i <= B[0][2]; i++)
    {
        printf("%d %d %d\n", B[i][0], B[i][1], B[i][2]);
    }
    return 0;
}

int compact(int m, int n, int A[m][n], int B[m*n + 1][3])
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
    int B[m*n + 1][3];
    int i,j;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("Enter the element at position (%d,%d): ",i,j);
            scanf("%d",&A[i][j]);
        }
    }
    compact(m,n,A,B);
    int t = B[0][2];
    int C[t+1][3];
    printf("The transpose of the sparse matrix is:\n");
    transpose(t, B, C);
    return 0;
}