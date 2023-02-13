#include <stdio.h>

int binSearch(int n, int r, int l, int target){
	if (r >= l){
        int mid = l + (r-l)/2;
        if (mid*mid == target) return mid;
        else if (mid*mid > target) return binSearch(n, mid-1, l, target);
        else return binSearch(n, r, mid+1, target);
    }
}

int main(){
    long n;
    scanf("%ld", &n);
    printf("%d", binSearch(n, n-1, 0, n));
}