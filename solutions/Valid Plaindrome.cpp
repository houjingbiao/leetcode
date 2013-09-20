//version 3: from liancheng
#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>

using namespace std;

class Solution {
public:
    bool isPalindrome(string const& s) {
        auto pred = [] (char ch) { return isalnum (ch); };
        auto left = find_if (s.begin (), s.end (), pred);
        auto right = find_if (s.rbegin (), s.rend (), pred);

        while (left < prev (right.base ())) {
            if (tolower (*left) != tolower (*right)) {
                return false;
            }

            left = find_if (left + 1, s.end (), pred);
            right = find_if (right + 1, s.rend (), pred);
        }

        return true;
    }
};

int main (int argc, char* argv []) {
    for (string s; getline (cin, s); ) {
        cout << Solution ().isPalindrome (s) << endl;
    }

    return 0;
}

//version: improve
class Solution {
public:
	bool isAlphaNumeral(char ch){
		return ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9';
	}
	bool isEqual(char a1, char a2){
		if(a1 >= '0' && a1 <= '9' || a2 >= '0' && a2 <= '9')//for numerial
			return a1 == a2;
		return a1 == a2 || a1 - 'a' == a2 - 'A' || a1 - 'A' == a2 - 'a'; //the latter two item doesn't work for numerial
	}
    bool isPalindrome(string s) {
		if(s.length() == 0 || s.length() == 1) return true;
		int b = 0, e = s.length();
		while(b < e){
			if(!isAlphaNumeral(s[b]))
				b++;
			else if(!isAlphaNumeral(s[e]))
				e--;
			else if(!isEqual(s[b], s[e]))
				return false;
			else
				b++, e--;
		}
		return true;
    }
};


//version 1:
class Solution {
public:
    bool isDigit(char ch){
        if(ch >= '0' && ch <= '9')
            return true;
        return false;
    }
    bool isCharacter(char ch){
        if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
            return true;
        return false;
    }
	bool isEqual(char ch1, char ch2){
		if(isDigit(ch1) || isDigit(ch2))
			return ch1 == ch2;
		else
			return ch1 == ch2 || ch1 - 'a' == ch2 - 'A' || ch1 - 'A' == ch2 - 'a';
	}
    bool isPalindrome(string s) {
        if(s.length() <= 1)
            return true;
        int i = 0, j = s.length()-1;
        while(i < j)
        {
            if(!isDigit(s[i]) && !isCharacter(s[i]))
                i++;
            else if(!isDigit(s[j]) && !isCharacter(s[j]))
                j--;
            else if(isEqual(s[i], s[j]))
                i++,j--;
            else
                return false;
        }
        return true;
    }
};