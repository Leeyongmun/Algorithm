#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<cstring>
#include <set>
#include <map>
#include <stack>
#include <cctype>
#include <string>
using namespace std;
using ll = long long;

int n, k;

struct Customer {
	int id, counter, finish;
};

struct Cmp {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
		if (a.first != b.first) return a.first > b.first;
		return a.second > b.second;
	}
};

bool cmp(const Customer& a, const Customer& b) {
	if (a.finish != b.finish) return a.finish < b.finish;
	return a.counter > b.counter;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;

	for (int i = 1; i <= k; i++) {
		pq.push({ 0, i });
	}

	vector<Customer> customers(n);

	for (int i = 0; i < n; i++) {
		int id, w;
		cin >> id >> w;

		auto p = pq.top();
		pq.pop();
		int finish = p.first + w;
		int counter = p.second;
		customers[i] = { id, counter, finish };
		pq.push({ finish, counter });
	}

	sort(customers.begin(), customers.end(), cmp);

	ll ret = 0;

	for (int i = 0; i < n; i++) {
		ret += (ll)(i + 1) * customers[i].id;
	}

	cout << ret;
}
