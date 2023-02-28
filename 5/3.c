#include <stdio.h>
#include <string.h>

int update_freq(int freq[], int k, char alpha, int adding){
    int i = (int)(alpha-97);
    if (adding){
        if (i < k) freq[i]--;
    }
    else{
        if (i < k) freq[i]++;
    }
}

int check(int freq[], int k){
    for (int i = 0; i < k; i++){
         if (freq[i] > 0) return 0;
    }
    return 1;
}

void printarr(int arr[], int n){
    for (int i = 0; i < n;i++) printf("%d ");
    printf("\n");
}

int n_window(int n, int k, char *str){
    int count = 0, l = 0, r = 0;
    int freq[k];
    for (int i = 0; i < k; i++) freq[i] = 1;
    update_freq(freq, k, str[0], 1);
    while (r < n){
        if (check(freq, k)){
            while (check(freq, k)){
                count += n - r;
                update_freq(freq, k, str[l], 0);
                l++;
            }
        }
        else{
            r++;
            update_freq(freq, k, str[r], 1);
        }
    }
    return count;
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    char str[n];
    scanf("%s", str);
    printf("%d", n_window(n, k, str));
    return 0;
}