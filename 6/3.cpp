#include <iostream>
#include <stack>
using namespace std;

int largest_rectangular_area(int arr[], int n){
    stack<int> s;
    int top, area_top, max = 0;
    int i =0;
    while (i < n){
        if (s.empty() || arr[s.top()] <= arr[i]){
            cout << "pushing index" << i << endl;
            s.push(i++);
        }
        else{
            top = s.top();
            cout << "popping index " << top << endl;
            s.pop();
            area_top = arr[top] * (s.empty() ? i : i - s.top() - 1);
            if (max < area_top) max = area_top;
        }
    }
    while (!s.empty()){
        top = s.top();
        s.pop();
        area_top = arr[top] * (s.empty() ? i : i - s.top() - 1);
        if (max < area_top) max = area_top;

    }
    return max;

}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << largest_rectangular_area(arr, n);
    return 0;
}