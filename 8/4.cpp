#include <iostream>
#include <map>
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;

    map <int, int> mp;
    int  i, k;
    while (q > 0){
        cin >> i >> k;
        auto x = mp.lower_bound(k);
        switch(i){
            case 1:
                if (mp.find(k) == mp.end()) mp[k] = 1;
                else mp.erase(k);
                break;
            case 2:
                if (x == mp.end()) cout << -1 << endl;
                else cout << endl << x->first << endl;
                break;
            case 3:
                if (x == mp.end()){
                    x--;
                    cout << endl << x->first << endl;
                }
                else if (x == mp.find(k)) cout << endl << x->first << endl;
                else if (x == mp.begin()) cout << endl << -1 << endl;
                else{
                    x--;
                    cout << endl << x->first << endl;
                }
                break;
        }
        q--;
    }
    return 0;
}