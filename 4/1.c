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
        if (a[i].start < b[j].start){
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
    slot new_slots[n];
    int num = 0;
    for (int i =0; i < n;i++){
        if (num == 0){
            new_slots[num] = slots[i];
            num++;
        }
        else{
            if (slots[i].start >= new_slots[num-1].start && slots[i].start <= new_slots[num - 1].end){
                
                if (slots[i].end > new_slots[num-1].end){
                    new_slots[num-1].end = slots[i].end;
                }
            }
            else{
                new_slots[num] = slots[i];
                num++;
            }
        }
    }
    printf("%d\n", num);
    for (int i = 0; i < num; i++) printf("%d %d\n", new_slots[i].start, new_slots[i].end);
    return 0;
}