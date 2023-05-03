#include <bits/stdc++.h>
using namespace std;

int Knapsack(int W, int index_of_nth_item, int weight[], int value[])
{
	if (index_of_nth_item < 0 || W == 0) return 0;
	if (weight[index_of_nth_item] > W) return Knapsack(W, index_of_nth_item - 1, weight, value);
	int include_nth_item = value[index_of_nth_item] + Knapsack(W - weight[index_of_nth_item], index_of_nth_item - 1, weight, value);
	int exclude_nth_item = Knapsack(W, index_of_nth_item - 1, weight, value);
	return max(include_nth_item, exclude_nth_item);
}

int main()
{
    int n, W;
    cin >> n >> W;
	int value[n], weight[n];
    for (int i = 0; i < n; i++) cin >> weight[i] >> value[i];
	cout << Knapsack(W, n - 1, weight, value) << endl;
	return 0;
}
