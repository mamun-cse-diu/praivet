#include<stdio.h>

int main(void)
{
    int n_node = 0;

    printf("Enter node number : ");
    scanf("%d",&n_node);

    int arr[n_node][n_node];

    char n1  = 'A',n2 = 'A';

    for(int i = 0; i<n_node; i++){
        printf("Relationship between %c and ",n1);
        for(int j =0; j<n_node; j++){
            printf("%c : ",n2);
            scanf("%d",&arr[i][j]);
            n2++;
        }
        n1++;
        n2 = 'A';
    }

    printf("\n\n\n  ");

    n1 = 'A',n2 = 'A';

    for(int i = 0; i<n_node; i++){
        printf("%c ",n1);
        n1++;
    }

    printf("\n");

    for(int i = 0; i<n_node; i++){
        printf("%c ",n2);
        for(int j =0; j<n_node; j++){
            printf("%d ",arr[i][j]);
        }
        n2++;
        printf("\n");
    }
}
