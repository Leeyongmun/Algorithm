#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    long long r = (long long)times[times.size() - 1] * n;
    long long l = 1;
    
    while(l <= r){
        long long mid = (l + r) / 2;
        
        long long cnt = 0;
        
        for(int i = 0; i < times.size(); i++){
            cnt += mid / times[i];
        }
        
        if(cnt >= n){
            answer = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    
    return answer;
}