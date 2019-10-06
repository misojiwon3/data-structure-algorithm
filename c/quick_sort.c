#include <stdio.h>

void quickSort(int *l, int first, int last);
void swap(int *a, int *b);
int partition(int *list, int left, int right);
void printList(int *list);

#define MAX 22

int main()
{
    int arr[MAX] = {12, 9, 3, 21, 18, 18, 2, 34, 82, 23, 63, 1, 100, 4, 29, 8, 13, 7, 33, 20, 77, 15};
    
    quickSort(arr, 0, MAX - 1);
    
    printf("정렬된 배열 : ");
    for (int j = 0; j < MAX; j++) {
        printf("%d ", arr[j]);
    }
    printf("\n");
    
    return 0;
}

int partition(int *list, int first, int last) {
    printList(list);
    int pivot = list[first];
    int start = first;
    int end = last + 1;
    
    while(start < end) {
        do {
            start++;
        } while(list[start] < pivot);
        do {
            end--;
        } while(pivot < list[end]);
        
        printf(">> start %d, end %d, pivot %d\n", start, end, pivot);
        
        if (start < end) {
            swap(&list[start], &list[end]);
        }
    }
    
    swap(&list[first], &list[end]);
    
    printList(list);
    
    return end;
}

void quickSort(int *l, int left, int right) {
    if (left < right) {
        int pivot = partition(l, left, right);
        
        quickSort(l, left, pivot - 1);
        quickSort(l, pivot + 1, right);
    }
}

void printList(int *list) {
    int len = sizeof(list);
    
    for (int j = 0; j < len; j++) {
        printf("%d ", list[j]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int tmp;
    
    tmp = *a;
    *a = *b;
    *b = tmp;
}
