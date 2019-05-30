#include <vector>

vector<short> concatenateVectors(vector<short> a, vector<short> b) {
	a.reserve(a.size() + b.size()); // preallocate memory
	a.insert(a.end(), b.begin(), b.end());
	return a;
}


vector<short> lastN(vector<short> x, int n) {
	if (n < x.size()) {
		vector<short>::const_iterator first = x.end() - n;
		vector<short>::const_iterator last = x.end();
		vector<short> newVec(first, last);
		return newVec;
	}
	else {
		padVector(x, n);
		vector<short> newVec = x;
		return newVec;
	}

}

int gf2degree(vector<short> a) {
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == 1) {
			return a.size() - i - 1;
		}
	}
}



void padVector(vector<short>& v, const size_t num, const int padding = 0) {
	if (num > v.size()) {
		vector<short> a(num - v.size(), padding);

		v = concatenateVectors(a, v);

	}
}

vector<short> gf2division(vector<short> a, vector<short> b, vector<short> & restant) {

	restant = a;

	vector<short> resultat;

	int nA = a.size();
	int nB = b.size();
	int degreeB = gf2degree(b);
	
	b = lastN(b, degreeB + 1);

	for (int i = 0; i < nA - degreeB ; ++i) {
		bool isGo = restant[i] == 1;
		resultat.push_back(short(isGo));

		if (isGo){
			for (int iB = 0; iB < b.size(); iB++) {
				restant[i + iB] = (restant[i + iB] != b[iB]);
			}
		}
		
	}
	padVector(resultat, a.size());
	return resultat;
}
