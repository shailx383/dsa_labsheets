#include <iostream>
#include <stack>
using namespace std;

struct indexed_list{
    int data;
    int index;
};
typedef struct indexed_list list;

int *num_steps_to_nge(int a[], int n)
{
    stack<list> s;
    int* ans = new int[n];
    for (int i = 2 * n - 1; i >= 0; i--) {
        while (!s.empty() && a[i % n] >= (s.top()).data){
            cout << "popping " << s.top().data << " " << s.top().index << endl; 
            s.pop();
        } 
        if (i < n) {
            if (!s.empty()){
                int d = s.top().index - (i%n);
                ans[i] = d < 0 ? d + n : d;
            }   
            else ans[i] = -1;
        }
        list elt;
        cout << "pushing " << a[i%n] << " " << i%n << endl;
        elt.data = a[i%n];
        elt.index = i%n;
        s.push(elt);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int *result = num_steps_to_nge(arr, n);
    for (int i = 0; i < n; i++) cout << result[i] << " ";
    return 0;
}