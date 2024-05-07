#include <stdio.h>
int main()
{
    int a[10], n, i, beg = 0, mid, end, key;
    printf("enter the array size\n");
    scanf("%d", &n);
    printf("enter the elements of the array\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("enter the search element\n");
    scanf("%d", &key);
    beg = 0;
    end = n - 1;
    while (beg <= end)
    {
        mid = (beg + end) / 2;
        if (key == a[mid])
        {
            printf("%d is found at %dth position\n", key, mid + 1);
            break;
        }
        else if (a[mid] < key)
        {
            beg = mid + 1;
        }
        else
        {
            end = n - 1;
        }
    }
    return 0;
}