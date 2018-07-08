#include <cstdio>
#include <algorithm>
using namespace std;

long long d[100001][3];
long long a[100001][2];
int main(void)
{
	int T;
	scanf("%d", &T);

	while (T--) {
		int n;
		scanf("%d", &n);

		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i][0]);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i][1]);
		}

		d[0][0] = d[0][1] = d[0][2] = 0;

		for (int i = 1; i <= n; i++) {
			d[i][0] = max(max(d[i - 1][0], d[i - 1][1]), d[i - 1][2]);
			d[i][1] = max(d[i - 1][0], d[i - 1][2]) + a[i][0];
			d[i][2] = max(d[i - 1][0], d[i - 1][1]) + a[i][1];
		}

		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			ans = max(max(ans, d[i][0]), max(d[i][1], d[i][2]));
		}
		printf("%lld\n", ans);
	}

	return 0;
}