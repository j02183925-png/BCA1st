
#include <stdio.h>

int main()
{
    int a[10][10], b[10][10], r[10][10];
    int r1, c1, r2, c2;
    int i, j, k, choice;

    printf("\n1. Addition");
    printf("\n2. Subtraction");
    printf("\n3. Transpose");
    printf("\n4. Multiplication");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 1 || choice == 2 || choice == 4)
    {
        printf("Enter rows and columns of matrix A: ");
        scanf("%d %d", &r1, &c1);

        printf("Enter rows and columns of matrix B: ");
        scanf("%d %d", &r2, &c2);

        if (r1 < 1 || r1 > 10 || c1 < 1 || c1 > 10 ||
            r2 < 1 || r2 > 10 || c2 < 1 || c2 > 10)
        {
            printf("Invalid matrix dimensions.\n");
            return 0;
        }

        if ((choice == 1 || choice == 2) &&
            (r1 != r2 || c1 != c2))
        {
            printf("Addition/Subtraction not possible.\n");
            return 0;
        }

        if (choice == 4 && c1 != r2)
        {
            printf("Multiplication not possible.\n");
            return 0;
        }

        printf("Enter matrix A elements:\n");

        for (i = 0; i < r1; i++)
        {
            for (j = 0; j < c1; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }

        printf("Enter matrix B elements:\n");

        for (i = 0; i < r2; i++)
        {
            for (j = 0; j < c2; j++)
            {
                scanf("%d", &b[i][j]);
            }
        }

        if (choice == 1 || choice == 2)
        {
            for (i = 0; i < r1; i++)
            {
                for (j = 0; j < c1; j++)
                {
                    if (choice == 1)
                        r[i][j] = a[i][j] + b[i][j];
                    else
                        r[i][j] = a[i][j] - b[i][j];
                }
            }

            printf("Result matrix:\n");

            for (i = 0; i < r1; i++)
            {
                for (j = 0; j < c1; j++)
                {
                    printf("%d\t", r[i][j]);
                }
                printf("\n");
            }
        }

        else if (choice == 4)
        {
            for (i = 0; i < r1; i++)
            {
                for (j = 0; j < c2; j++)
                {
                    r[i][j] = 0;

                    for (k = 0; k < c1; k++)
                    {
                        r[i][j] += a[i][k] * b[k][j];
                    }
                }
            }

            printf("Multiplication result:\n");

            for (i = 0; i < r1; i++)
            {
                for (j = 0; j < c2; j++)
                {
                    printf("%d\t", r[i][j]);
                }
                printf("\n");
            }
        }
    }

    else if (choice == 3)
    {
        printf("Enter rows and columns of matrix: ");
        scanf("%d %d", &r1, &c1);

        if (r1 < 1 || r1 > 10 || c1 < 1 || c1 > 10)
        {
            printf("Invalid matrix dimensions.\n");
            return 0;
        }

        printf("Enter matrix elements:\n");

        for (i = 0; i < r1; i++)
        {
            for (j = 0; j < c1; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }

        printf("Transpose of matrix:\n");

        for (i = 0; i < c1; i++)
        {
            for (j = 0; j < r1; j++)
            {
                printf("%d\t", a[j][i]);
            }
            printf("\n");
        }
    }

    else
    {
        printf("Invalid choice.\n");
    }

    return 0;
}
