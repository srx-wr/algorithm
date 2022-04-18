#include <iostream>
#include <string>
using namespace std;

bool isBetterornum(char s) {
	if (s >= 'a' && s <= 'z' ||
	        s >= 'A' && s <= 'Z' ||
	        s >= '0' && s <= '9'
	   )
		return true;
	return false;
}

bool isPalindrome(string s) {
	if (s.size() == 0)
		return true;
	for (auto &ch : s) {
		if (ch >= 'a' && ch <= 'z')
			ch -= 32;
	}
	int begin = 0;
	int end = s.size() - 1;

	while (begin < end) {
		if (begin < end && !isBetterornum(s[begin])) {
			begin++;
		}
		if (begin < end && !isBetterornum(s[end])) {
			--end;
		}
		if (s[begin] != s[end]) {
			return false;
		}
		begin++;
		end--;
	}
	return true;
}

int main() {
	string s;
	getline(cin, s);
	bool ret = isPalindrome(s);
	cout << ret << endl;
	return 0;

}