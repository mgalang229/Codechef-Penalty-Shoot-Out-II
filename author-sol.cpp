#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);                         
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		string penalty;
		cin >> penalty;
		int len = 2 * n;
		int rem_a = n;
		int rem_b = n;
		int score_a = 0;
		int score_b = 0;
		int ans = len;
		for (int i = 0; i < len; i++) {
			char res = penalty[i];
			// for every odd/even turn increment the point (if it's a goal) and decrement the turns of teams A and B
			if (i % 2 == 0) {
				if (res == '1') {
					score_a++;					
				}
				rem_a--;
			} else {
				if (res == '1') {
					score_b++;
				}
				rem_b--;
			}
			// check if the score of one team is already greater than the combined score of the other and its remaining turns
			if ((score_a > score_b + rem_b) || (score_b > score_a + rem_a)) {
				ans = i + 1;
				break;
			}
		}
		cout << ans << '\n';
	}
	return 0
}
