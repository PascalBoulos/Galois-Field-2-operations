#include <vector>

vector<short> bitwiseAnd(vector<short> a, vector<short> b) {
	vector<short> c (a.size());
	for (unsigned int i = 0; i < a.size(); ++i)
	{
		c[i] = a[i] & b[i];
	}
	return c;
}

vector<short> gf2derivative(vector<short> f){
	vector<short> oddMask (f.size());

	for (int i = f.size() - 2; i >= 0; i -= 2) {
		oddMask[i] = 1;
	}

	vector<short> fp = bitwiseAnd(oddMask, f);
	fp.insert(fp.begin(), 0);
	fp.pop_back();

	return fp;
}

