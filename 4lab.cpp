#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>

void Tolowerance(std::string &npt)
{
    std::transform(npt.begin(), npt.end(), npt.begin(), [] (unsigned char c) { return std::tolower(c);});
}

bool speed_read(std::istream &nt, std::vector<std::string> &tm) {
	while(nt) {
		std::string s;
		char tem = ' ';
		while (!isalpha(tem) && tem != '\n' && nt) {
			tem = nt.get();
		}
		if (tem == '\n') {
			return true;
		}
		nt.unget();
		nt >> s;
		if (s.length() == 0) {
			break;
		}
		Tolowerance(s);
		tm.push_back(s);
	}
	return false;
 }


int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
	std::vector <int> si;
	std::vector <std::string> t;
	std::string tmp;
	speed_read(std::cin, t);
	t.push_back("@");
	si.push_back(t.size());
	while (speed_read(std::cin, t)) {
		si.push_back(t.size());
	}

	size_t n =  t.size();
    std::vector<size_t> pi(n);

    for (size_t i=1; i < n; ++i) {

        size_t j = pi[i-1];
        while ((j > 0) && (t[i] != t[j])) {
            j = pi[j-1];
        }

        if (t[i] == t[j]) {
            ++j;
        }
        pi[i] = j;
     }

	for (size_t i = 0; i < pi.size(); i++) {
		if (pi[i] == si[0] - 1) {
			int num = upper_bound(si.begin(), si.end(), i - si[0] + 2) - si.begin();
				std::cout << num << ", " << i - si[0] - si[num - 1] + 3 << "\n";
		}
	}
}
