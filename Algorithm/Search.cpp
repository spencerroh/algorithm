// [l, r]
// 문제가 아래 조건을 만족할 때 m을 찾는다.
// - l ~ m은 P를 만족함.
// - m + 1 ~ r은 P를 만족하지 않음.
// 예) bool 배열이 아래와 같이 주어졌을 때 m을 찾는다.
//    [T, T, T, T, F, F, F]c
//              ^------- m
template <class Predict>
int ParametricSearch(int l, int r, Predict p)
{
	if (l == r)
		return p(l) ? l : -1;

	int m = (l + r + 1) / 2;

	if (p(m))
		return ParametricSearch(m, r, p);
	else
		return ParametricSearch(l, m - 1, p);
}