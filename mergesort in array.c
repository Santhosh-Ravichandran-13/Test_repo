#include <stdio.h>

void merge(int arr[], int l, int m, int h)
{
    int temp[100];
    int i = l;
    int j = m + 1;
    int k = l;

    while(i <= m && j <= h)
    {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i <= m)
        temp[k++] = arr[i++];

    while(j <= h)
        temp[k++] = arr[j++];

    for(i = l; i <= h; i++)
        arr[i] = temp[i];
}

void mergeSort(int arr[], int l, int h)
{
    if(l < h)
    {
        int m = l + (h - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, h);

        merge(arr, l, m, h);
    }
}

int main()
{
    int arr[100];
    int n, i;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, n - 1);

    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
