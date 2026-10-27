# include<stdio.h>
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
    
    return 0;
}

int create(int m, int n, int a[m][n])
{
    int i,j;
    printf("Enter values for matrix \n");
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("Enter the value at (%d,%d):",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    return 0;
}

int addition(int t1, int t2, int A[t1][3], int B[t2][3], int C[t1+t2][3])
{
    if(A[0][0]==B[0][0] && A[0][1]==B[0][1])
    {
        if(t1==0 && t2==0)
        {
            return printf("Check for zero matrix");
        }

        else{
            C[0][0]=A[0][0];
            C[0][1]=A[0][1];

            int i=1,j=1,k=1;
            while(i<=t1 && j<=t2)
            {
                if(A[i][0]==B[i][0])
                {
                    if(A[i][1]==B[i][1])
                    {
                        int temp = A[i][2] + B[j][2];
                        if(temp!=0)
                        {
                            C[k][0]=A[i][0];
                            C[k][1]=A[i][1];
                            C[k][2]=temp;
                        }
                        i+=1,j+=1,k+=1;
                    }

                    else if(A[i][1]<B[j][1])
                    {
                        C[k][0]=A[i][0];
                        C[k][1]=A[i][1];
                        C[k][2]=A[i][2];
                        i+=1,k+=1;
                    }

                    else if(A[i][1]>B[j][1])
                    {
                        C[k][0]=B[j][0];
                        C[k][1]=B[j][1];
                        C[k][2]=B[j][2];
                        j+=1,k+=1;
                    }
                }

                else if(A[i][0]<B[j][0])
                    {
                        C[k][0]=A[i][0];
                        C[k][1]=A[i][1];
                        C[k][2]=A[i][2];
                        i+=1,k+=1;
                    }
                
                else if(A[i][0]>B[j][0])
                    {
                        C[k][0]=B[j][0];
                        C[k][1]=B[j][1];
                        C[k][2]=B[j][2];
                        j+=1,k+=1;
                    }
            }

            while(i<=t1)
            {
                C[k][0]=A[i][0];
                C[k][1]=A[i][1];
                C[k][2]=A[i][2];
                i+=1,k+=1;
            }

            while(j<=t2)
            {
                C[k][0]=B[j][0];
                C[k][1]=B[j][1];
                C[k][2]=B[j][2];
                j+=1,k+=1;
            }

            C[0][2]= k-1;
        }
        
        printf("----------- THE ADDITION IS -------------------\n");
        printf("%d %d %d\n", C[0][0], C[0][1], C[0][2]);

    	for(int i = 1; i <= C[0][2]; i++)
    	{
        	printf("%d %d %d\n", C[i][0], C[i][1], C[i][2]);
    	}
    	
    }
    return 0;
}

int main()
{
    int m1,n1;
    printf("Enter the dimensions for matrix A:");
    scanf("%d %d",&m1, &n1);
    int A[m1][n1];
    create(m1, n1, A);

    int m2,n2;
    printf("Enter the dimensions for matrix B:");
    scanf("%d %d",&m2, &n2);
    int B[m2][n2];
    create(m2, n2, B);

    int C[m1*n1][3];
    int D[m2*n2][3];

    compact(m1, n1, A, C);
    compact(m2, n2, B, D);

    int t1= C[0][2];
    int t2= D[0][2];

    int E[t1+t2+1][3];

    addition(t1, t2, C, D, E);



}