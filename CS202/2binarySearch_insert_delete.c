#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Bubble Sort
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

// Binary Search
int binarySearch(int *arr, int size, int x)
{
    int start = 0;
    int end = size - 1;
    int mid = start + ((end - start) / 2);
    while (start <= end)
    {
        if (arr[mid] == x)
        {
            return mid;
        }
        if (x > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + ((end - start) / 2);
    }
    return -1;
}

// Value insertion
int insert(int *arr, int size, int value, int position)
{
    // increasing the size of array by 1;
    arr[size] = 0;

    // If last position or last index
    if (position == size)
    {
        arr[size] = arr[size - 1];
        arr[size - 1] = value;
    }
    else
    {
        // If first postion or 0th index
        for (int i = size; i > position - 1; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[position - 1] = value;
    }
    return size + 1;
}

// Present value deletion
int deleteElement(int *arr, int size, int index)
{
    for (int i = index; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
    return size - 1;
}

int main()
{
    int size;
    printf("\nEnter the size of array : ");
    scanf("%d", &size);
    // Dynamic memory allocation
    int *arr = (int *)malloc(size * sizeof(int));
    printf("\nEnter values : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    bubblesort(arr, size);
    printf("\nAfter sorting array is : ");

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    int value;
    printf("\nEnter the value to find in sorted array : ");
    scanf("%d", &value);

    int index = binarySearch(arr, size, value);

    if (index != -1)
    {
        printf("\nFound at index : %d", index);
        size = deleteElement(arr, size, index);
        if (size == 0)
            printf("\nArray is empty. ");
        else
        {
            printf("\nAfter deleting array is : ");
            for (int i = 0; i < size; i++)
            {
                printf("%d ", arr[i]);
            }
        }
    }
    else
    {
        int position;
        printf("\nValue not found. ");
        printf("\nEnter the position to insert: ");
        scanf("%d", &position);
        size = insert(arr, size, value, position);
        printf("\nAfter inserting array is : ");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}

/*
Enter the size of array : 1

Enter values : 1

After sorting array is : 1
Enter the value to find in sorted array : 1

Found at index : 0
Array is empty.

Enter the size of array : 3

Enter values : 1 2 3

After sorting array is : 1 2 3
Enter the value to find in sorted array : 5

Value not found.
Enter the position to insert: 4

After inserting array is : 1 2 3 5

Enter the size of array : 3

Enter values : 1 2 3

After sorting array is : 1 2 3
Enter the value to find in sorted array : 5

Value not found.
Enter the position to insert: 1

After inserting array is : 5 1 2 3

Enter the size of array : 3

Enter values : 1 2 3

After sorting array is : 1 2 3
Enter the value to find in sorted array : 5

Value not found.
Enter the position to insert: 2

After inserting array is : 1 5 2 3
*/