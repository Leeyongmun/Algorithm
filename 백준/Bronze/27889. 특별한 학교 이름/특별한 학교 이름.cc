#include<iostream>
using namespace std;

string s;

int main(){
    cin >> s;
    
    if(s == "NLCS") cout << "North London Collegiate School";
    else if(s == "BHA") cout << "Branksome Hall Asia";
    else if(s == "KIS") cout << "Korea International School";
    else cout << "St. Johnsbury Academy";
}