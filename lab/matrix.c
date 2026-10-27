# include<stdio.h>
int add(int m, int n, int p, int q, int a[m][n], int b[p][q])
{
    if(m==p && n==q)
    {
        int i,j;
        int c[m][n];
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                c[i][j] = a[i][j] + b[i][j];
            }
        }

        printf("The result of addition is:\n");
        
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                printf("%d ",c[i][j]);
            }
            printf("\n");
        }
    }
    
    else{
        return printf("The order of both matrix is not same\n");
    }
    
	return 0;
}

int sub(int m, int n, int p, int q, int a[m][n], int b[p][q])
{
	if(m==p && n==q)
    {
        int i,j;
        int c[m][n];
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                c[i][j] = a[i][j] - b[i][j];
            }
        }

        printf("The result of subtraction is:\n");
        
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                printf("%d ",c[i][j]);
            }
            printf("\n");
        }
    }
    
    else{
        return printf("The order of both matrix is not same");
    }
    
	return 0;
}

int mul(int m, int n, int p, int q, int a[m][n], int b[p][q])
{
	if(n==p)
    {
        int i,j,k;
        int c[m][q];
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                c[i][j] =0;
                for(int k=0; k<n; k++)
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        printf("The result of multiplication is:\n");
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                printf("%d ",c[i][j]);
            }
            printf("\n");
        }
    }
    
    else{
        return printf("The order of both matrix is not same");
    }
	return 0;
}

int transpose(int m, int n, int a[m][n])
{
	int i,j;
	int c[n][m];
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			c[j][i] = a[i][j];
		}
	}

    printf("The result of transpose is:\n");

	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			printf("%d ",c[i][j]);
		}
		printf("\n");
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

int main()
{
    printf("Enter the matrix a\n");
    int m,n;
    printf("Enter the row value:");
    scanf("%d",&m);
    printf("Enter the column value:");
    scanf("%d",&n);
    int a[m][n];
    create(m,n,a);
    
    printf("Enter the matrix b\n");
    int p,q;
    printf("Enter the row value:");
    scanf("%d",&p);
    printf("Enter the column value:");
    scanf("%d",&q);
    int b[p][q];
    create(p,q,b);
	
	printf("1. Addition\n");
	printf("2. Subtraction\n");
	printf("3. Multiplication\n");
	printf("4. Transpose\n");
	printf("5. Exit\n");
	
	int x=1;
	while(x==1)
	{
		int choice;
	    printf("Enter the choice:");
	    scanf("%d",&choice);
        switch(choice)
		{
			case 1:
				add(m,n,p,q,a,b);
				break;
		
			case 2:
				sub(m,n,p,q,a,b);
				break;
		
			case 3:
				mul(m,n,p,q,a,b);
				break;
		
			case 4:
				transpose(m,n,a);
				break;
		
            case 5:
				printf("Exit\n");
				x=0;
				break;
			
			default:
				printf("Invalid choice\n");
				break;
			
		}
	}
	
	return 0;
	
}