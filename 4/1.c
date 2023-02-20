#include <stdio.h>

struct slot{
    int start;
    int end;
};
typedef struct slot slot;

void merge(slot arr[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    slot a[n1], b[n2];
    for (int i = 0; i < n1; i++) a[i] = arr[l+i];
    for (int j = 0; j < n2; j++) b[j] = arr[m + j + 1];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2){
        if (a[i].end < b[j].end){
            arr[k] = a[i];
            i++;
        }
        else{
            arr[k] = b[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        arr[k] = a[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = b[j];
        j++;
        k++;
    }
}

void mergeSort(slot arr[], int l, int r){
    if (l < r){
        int m = l + (r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void result(slot arr[], int n){
    int count = 0, i = 0;
    slot final[n];
    for (i = 0; i < n; i++){
        printf("\ncurrent: %d %d\nnext: %d %d\n", arr[i].start, arr[i].end, arr[i+1].start, arr[i+1].end);
        if (arr[i].end >= arr[i+1].start){
            slot s;
            s.start = arr[i].start;
            s.end = arr[i+1].end;
            final[count] = s;
            count++;
        }
        else{
            slot s;
            s.start = arr[i].start;
            s.end = arr[i].end;
            final[count] = s;
            count++;
        }
    }
    printf("%d\n", count);
    for (int i = 0; i < count; i++) printf("%d %d\n", final[i].start, final[i].end);
    return;
}

int main(){
    int n;
    scanf("%d", &n);
    slot slots[n];
    for (int i = 0; i < n; i++){
        slot s;
        scanf("%d %d", &s.start, &s.end);
        slots[i] = s;
    }
    mergeSort(slots, 0, n-1);
    printf("\n");
    result(slots, n);
    
    return 0;
}