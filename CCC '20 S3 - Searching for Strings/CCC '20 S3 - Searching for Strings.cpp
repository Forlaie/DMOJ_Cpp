#include <iostream>
#include <map>
#include <string>
#include <set>
using namespace std;

bool isPermutation(map<char, int> needle, map<char, int> hsub) {
	for (int i = 0; i < 26; ++i) {
		char letter = 'a' + i;
		if (needle[letter] != hsub[letter]) {
			return false;
		}
	}
	return true;
}

int main()
{
	set<size_t> unique;
	string needle, haystack;
	cin >> needle >> haystack;
	map<char, int> fneedle, fhaystack;
	/*map<size_t, bool> used;
	int count = 0;*/

	for (int i = 0; i < needle.size(); ++i) {
		fneedle[needle[i]]++;
	}

	for (int i = 0; i < haystack.size() - needle.size() + 1; ++i) {
		string hsub = haystack.substr(i, needle.size());
		if (i == 0) {
			for (int j = 0; j < hsub.size(); ++j) {
				fhaystack[hsub[j]]++;
			}
		}
		else {
			fhaystack[haystack[i - 1]]--;
			fhaystack[haystack[i + hsub.size() - 1]]++;
		}

		hash<string> hasher;
		size_t hash = hasher(hsub);

		if (isPermutation(fneedle, fhaystack)) {
			unique.insert(hash);
		}

		/*if (!used[hash] && isPermutation(fneedle, fhaystack)) {
			used[hash] = true;
			count++;
		}*/
	}
	//cout << count;
	cout << unique.size();
}