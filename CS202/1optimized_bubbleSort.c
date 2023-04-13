//12.01.2023
//19.01.2023
//02.02.2023
//09.02.2023
//16.02.2023
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void bubblesort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        // flag is used for checking whether array is already sorted or not
        bool flag = true;

        for (int j = 0; j < size - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = false;
            }
        }

        if (flag)
        {
            // Array is already sorted break the loop, no further comparison
            break;
        }
    }
}
void main()
{
    int no_of_block;

    printf("\nEnter how many number you want to store : ");
    scanf("%d", &no_of_block);

    // Dynamically memory allocation of size no_of_block
    int *arr = (int *)malloc(no_of_block * sizeof(int));

    printf("\nEnter vlaues in array: ");
    for (int i = 0; i < no_of_block; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nArray before sorting : ");
    for (int i = 0; i < no_of_block; i++)
    {
        printf("%d ", arr[i]);
    }

    // Calling bubblesort function for sorting
    bubblesort(arr, no_of_block);

    printf("\nArray after sorting : ");
    for (int i = 0; i < no_of_block; i++)
    {
        printf("%d ", arr[i]);
    }
}
/*

Enter how many number you want to store : 5

Enter vlaues in array: 6 2 9 1 8

Array before sorting : 6 2 9 1 8
Array after sorting : 1 2 6 8 9

Enter how many number you want to store : 8

Enter vlaues in array: 1 2 3 4 5 6 7 8

Enter vlaues in array: 1 2 3 4 5 6 7 8

Array before sorting : 1 2 3 4 5 6 7 8
Array after sorting : 1 2 3 4 5 6 7 8


Enter how many number you want to store : 10

Enter vlaues in array: 10 9 8 7 6 5 4 3 2 1
Array before sorting : 1 2 3 4 5 6 7 8
Array after sorting : 1 2 3 4 5 6 7 8

Array before sorting : 10 9 8 7 6 5 4 3 2 1
Array after sorting : 1 2 3 4 5 6 7 8 9 10

*/