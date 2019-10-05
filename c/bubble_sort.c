//
//  bubble_sort.c
//  
//
//  Created by 이한승 on 05/10/2019.
//

#include <stdio.h>

void bubble_sort(int list[]);

#define MAX 10

int main() {
    int arr[MAX] = {2, 10, 7, 4, 9, 5, 1, 3, 8, 6};
    printf("초기 배열 :");
    for(int i = 0; i < MAX; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    bubble_sort(arr);
    
    printf("최종 정렬된 배열 : ");
    for(int j = 0; j < MAX; j++)
    {
        printf("%d ", arr[j]);
    }
    printf("\n");
    
    return 0;
}

void bubble_sort(int list[])  //인접한 두 수를 비교, 교환하며 정렬하는 방식
{
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX - 1; j++) { // index를 벗어나지 않기 위해 MAX - 1
            if (list[j] > list[j + 1]) {
                int temp = list[j + 1];
                list[j + 1] = list[j];
                list[j] = temp;
            }
        }
        printf("%d번째 정렬 : ", i + 1);
        for(int k=0; k < MAX; k++)
        {
            printf("%d ", list[k]);
        }
        printf("\n");
    }
}


