#include <stdio.h>
#include <string.h>

int max(int arr[], int n){
    int m = 0; 
    for (int i = 0; i < n; i++){
        if (arr[i] > m) m = arr[i];
    }
    return m;
}

struct votes{
    int candidate;
    int votes;
};
typedef struct votes votes;

void bubbleSort(votes arr[], int n)
{
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j].votes < arr[j + 1].votes){
                votes temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            } 
        }       
    }
}

void printarr(int arr[], int n){
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int n,k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int maximum = max(arr, n);
    int freq[maximum+1]; 
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < n; i++){
        freq[arr[i]]++;
    }
    votes votes_arr[maximum+1];
    int num_candidates = 0;
    for (int i = 1; i <= maximum; i++){
        if (freq[i] > 0){
            votes v;
            v.candidate = i; 
            v.votes = freq[i];
            votes_arr[num_candidates] = v;
            num_candidates++;
        }
    }
    bubbleSort(votes_arr, num_candidates);
    for (int i = 0; i < k; i++){
        printf("%d ", votes_arr[i].candidate);
    }
}