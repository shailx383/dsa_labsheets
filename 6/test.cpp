#include <iostream>
#include <stack>
using namespace std;

struct indexed_list{
    int data;
    int index;
};
typedef struct indexed_list list;

int *num_steps_to_nge(int arr[], int n){
    int *ans = new int[n];
    stack <list> s;
    for (int i = 2*n - 1; i >= 0; i--){
        while (!s.empty() && arr[i%n] >= s.top().data ) s.pop();
        if (i < n){
            if (!s.empty()){
                int diff = s.top().index - (i%n);
                ans[i] = diff > 0 ? diff : diff + n;
            }
            else ans[i] = -1;
        }
        list elt;
        elt.data = arr[i%n];
        elt.index = i%n;
        s.push(elt);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i =0; i < n; i++) cin >> arr[i];
    int *result = num_steps_to_nge(arr, n);
    for (int i =0; i < n ; i++) cout << result[i] << " ";
    return 0;
}