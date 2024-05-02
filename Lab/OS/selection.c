#include <stdio.h>
int main()
{
    int arr[] = {34, 44, 15, 17, 23, 19, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<n-1; i++){
        int min = i;
        for(int j= i+1; j<n; j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }

    printf("Sorted array: ");
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}