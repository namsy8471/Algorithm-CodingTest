#include <iostream>

using namespace std;

int countTPack(int i, int pack)
{
	return (i % pack == 0) ? i / pack : (i / pack) + 1;
}

pair<int, int> countPenPack(int i, int pack)
{
	return make_pair(i / pack, i % pack);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int participates;

	cin >> participates;

	int s, m, l, xl, xxl, xxxl;

	cin >> s >> m >> l >> xl >> xxl >> xxxl;

	int tPack, pPack;

	cin >> tPack >> pPack;

	int tRet = countTPack(s, tPack) + countTPack(m, tPack)
		+ countTPack(l, tPack) + countTPack(xl, tPack)
		+ countTPack(xxl, tPack) + countTPack(xxxl, tPack);

	pair<int, int> pRet = countPenPack(participates, pPack);

	cout << tRet << '\n';
	cout << pRet.first << ' ' << pRet.second;

	return 0;
}