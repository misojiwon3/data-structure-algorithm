#include <stdio.h>

void quickSort(int *l, int first, int last);
int partition(int *list, int left, int right);
void printList(int *list);

#define SWAP(x, y, temp) ((temp)=(x), (x)=(y), (y)=(temp))
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
    int pivot, temp, start, end;
    
    pivot = list[first];
    start = first;
    end = last + 1;
    
    while(start < end) {
        do {
            start++;
        } while(list[start] < pivot);
        do {
            end--;
        } while(pivot < list[end]);
        
        printf(">> start %d, end %d, pivot %d\n", start, end, pivot);
        
        if (start < end) {
            SWAP(list[start], list[end], temp);
        }
    }
    
    SWAP(list[first], list[end], temp);
    
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
