#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <list>
using namespace std;
int get_second_min(stack<int> &s) {
    vector<int>v1;
    vector<int>v2;
    while(!s.empty()){
        v1.push_back(s.top());
        v2.push_back(s.top());
        s.pop();
    }
    sort(v1.begin(),v1.end());
    int mi1=v1[0];
    for(auto x:v1){
        if(x!=mi1){
            mi1=x;
            break;
        }
    }
    for(int i=v2.size()-1;i>=0;i--){
        s.push(v2[i]);
    }
    return mi1;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0;i < n;i++) {
        cin >> v[i];
    }
    //repeat n-1 times
    for (int last = 1;last < n;last+=1) {
        stack<int> s;
        //build s;
        bool distinct = false;
        for (int i = last;i >= 0;i--) {
            s.push(v[i]);
            if (v[i] != v[0]) distinct = true;
        }
        cout << "--use v[" << last << "] to v[0] --" << "\n";
        if (distinct) {
            //call get_second_min if we have at least 2 distinct value
            int answer = get_second_min(s);
            //print result and s
            cout << "result is " << answer << "\n";
            cout << "size of s is " << s.size() << "\n" << "member of s are ";
            while(s.size() > 0) {
            cout << s.top() << " ";
            s.pop();
            }
            cout << "\n";
        } else {
            cout << "skip because s has only one value\n\n\n";
        }
    }
    return 0;
}