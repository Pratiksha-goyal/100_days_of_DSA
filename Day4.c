#include <stdio.h>

int main() {
    int n;
    printf("array size:");
    scanf("%d",&n);
    int arr[n];
    printf("enter ther element: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int x;
    for(int i=0;i<n/2;i++){
        x=arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=x;
        
    }
    
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    return 0;
}