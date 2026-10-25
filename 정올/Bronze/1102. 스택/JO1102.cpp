#include<iostream>
#include<stack>
using namespace std;

int n;

int main(){
    cin >> n;
    stack<int> stk;
    while(n--){
        char c;
        cin >> c;

        if(c == 'i'){
            int x;
            cin >> x;
            stk.push(x);
        }

        else if(c == 'o'){
            if(stk.empty()){
                cout << "empty" << '\n';
            }
            else{
                cout << stk.top() << '\n';
                stk.pop();
            }
        }

        else{
            cout << stk.size() << '\n';
        }
    }
}
