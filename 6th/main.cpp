/*
競プロ典型90問　第6問　s
https://atcoder.jp/contests/typical90/submissions/23191468
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<char, int> P;

int N, K;
string s;

int main()
{

	cin >> N >> K;
	cin >> s;

	priority_queue<P, vector<P>, greater<P>> pq;
	//前からN - K + 1個をまず入れる。
	for (int i = 0; i < N - K + 1; i++)
		pq.push(make_pair(s[i], i));

	string ans = "";
	int topIdx = -1;
	for (int i = 0; i < K; i++)
	{
		P top;
		while (true)
		{
			top = pq.top();
			pq.pop();
			if (top.second > topIdx)
				break;
		}
		ans += top.first;
		topIdx = top.second;
		pq.push(make_pair(s[N - K + 1 + i], N - K + 1 + i));
	}
	cout << ans << endl;

	return 0;
}