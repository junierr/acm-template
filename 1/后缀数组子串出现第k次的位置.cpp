#include<bits/stdc++.h>
#define lcon l,mid,i<<1
#define rcon mid+1,r,i<<1|1
using namespace std;
typedef long long ll;

const int maxn = 2e5+5;
int sa[maxn], tax[maxn], rankk[maxn], tp[maxn], Height[maxn], lg[maxn], Y[maxn];
int dp[maxn][20];
int root[maxn], lc[maxn * 20], rc[maxn * 20], val[maxn * 20], cnt;
char s[maxn];


void Qsort(int n, int m) { //»ùÊýÅÅÐò 
	for (int i = 0; i < m; i++) tax[i] = 0;
	for (int i = 0; i < n; i++) tax[rankk[i]]++;
	for (int i = 0; i < m; i++) tax[i] += tax[i - 1];
	for (int i = n - 1; i >= 0; i--) sa[--tax[rankk[tp[i]]]] = tp[i];
}
void qqq(int n, int m) {
	for (int i = 0; i < n; i++)
		rankk[i] = s[i], tp[i] = i;
	Qsort(n, m);
	for (int k = 1; k <= n; k <<= 1) {
		int p = 0;
		for (int i = n - k; i < n; i++) tp[p++] = i;
		for (int i = 0; i < n; i++) if (sa[i] >= k) tp[p++] = sa[i] - k;
		Qsort(n, m);
		swap(rankk, tp);
		p = 1;
		rankk[sa[0]] = 0;
		for (int i = 1; i < n; i++)
			rankk[sa[i]] = (tp[sa[i - 1]] == tp[sa[i]] && tp[sa[i - 1] + k] == tp[sa[i] + k]) ? p - 1 : p++;
		if (p >= n)
			break;
		m = p;
	}
}
void get_height(int n) {
	int j, k = 0;
	for (int i = 0; i <= n; i++)
		rankk[sa[i]] = i;
	for (int i = 0; i < n; i++) {
		if (k)k--;
		j = sa[rankk[i] - 1];
		while (s[i + k] == s[j + k])
			k++;
		Height[rankk[i]] = k;
	}
}
void RMQ(int n) {
	for (int i = 1; i <= n; i++)
		dp[i][0] = Height[i];
	for (register int j = 1; (1 << j) <= n; j++) {
		for (register int i = 1; i + (1 << j) - 1 <= n; i++)
			dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
	}
	lg[0] = -1;
	for (int i = 1; i <= n; i++) {
		if ((i&(i - 1)) == 0)
			lg[i] = lg[i - 1] + 1;
		else
			lg[i] = lg[i - 1];
	}
}
int queryR(int l, int r) {
	int k = lg[r - l + 1];
	return min(dp[l][k], dp[r - (1 << k) + 1][k]);
}
void build(int l, int r, int &i) {
	i = ++cnt;
	val[i] = 0;
	if (l == r)
		return;
	int mid = l + r >> 1;
	build(l, mid, lc[i]);
	build(mid + 1, r, rc[i]);
}
void update(int k, int l, int r, int &i) {
	lc[++cnt] = lc[i], rc[cnt] = rc[i], val[cnt] = val[i] + 1;
	i = cnt;
	if (l == r)
		return;
	int mid = l + r >> 1;
	if (k <= mid)
		update(k, l, mid, lc[i]);
	else
		update(k, mid + 1, r, rc[i]);
}
int query(int u, int v, int k, int l, int r) {
	if (l == r)
		return l;
	int x = val[lc[v]] - val[lc[u]];
	int mid = l + r >> 1;
	if (x >= k)
		return query(lc[u], lc[v], k, l, mid);
	else
		return query(rc[u], rc[v], k - x, mid + 1, r);
}
int main(){
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, q, w = 0;
		cnt=0;
		scanf("%d%d", &n, &q);
		scanf("%s", s);
		qqq(n + 1, 256);
		get_height(n);
		for (int i = 1; i <= n; i++)
			Y[++w] = sa[i];
		for (int i = n; i >= 1; i--)
			rankk[i] = rankk[i - 1];
		RMQ(n);
		sort(Y + 1, Y + 1 + w);
		w = unique(Y + 1, Y + 1 + w) - Y - 1;
		build(1, n, root[0]);
		for (int i = 1; i <= n; i++) {
			int pos = lower_bound(Y + 1, Y + 1 + w, sa[i]) - Y;
			root[i] = root[i - 1];
			update(pos, 1, w, root[i]);
		}
		while (q--) {
			int l, r, k, len;
			scanf("%d%d%d", &l, &r, &k);
			len = r - l + 1;
			int x = rankk[l], y = rankk[l];
			int L = x + 1, R = n;
			while (L <= R) {
				int mid = (L + R) >> 1;
				if (queryR(L, mid) >= len)
					y = mid, L = mid + 1;
				else
					R = mid - 1;
			}
			L = 2, R = x;
			while (L <= R) {
				int mid = (L + R) >> 1;
				if (queryR(mid, R) >= len)
					x = mid - 1, R = mid - 1;
				else
					L = mid + 1;
			}
			if(y-x+1<k) printf("-1\n");
			else printf("%d\n", Y[query(root[x - 1], root[y], k, 1, w)]+1);
		}
	}
	return 0;
}
