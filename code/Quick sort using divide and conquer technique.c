Program:
#include <stdio.h>
int partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;
    while (i <= j) {
        while (i <= high && a[i] <= pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}
void quickSort(int a[], int low, int high) {
    int pos;
    if (low < high) {
        pos = partition(a, low, high);
        quickSort(a, low, pos - 1);
        quickSort(a, pos + 1, high);
    }
}
int main() {
    int a[50], n, i;
    printf("Enter number of elements:\n");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    quickSort(a, 0, n - 1);
    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);
    printf("\n");
    return 0;
}

