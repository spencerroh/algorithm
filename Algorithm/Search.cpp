// [l, r]
// ������ �Ʒ� ������ ������ �� m�� ã�´�.
// - l ~ m�� P�� ������.
// - m + 1 ~ r�� P�� �������� ����.
// ��) bool �迭�� �Ʒ��� ���� �־����� �� m�� ã�´�.
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