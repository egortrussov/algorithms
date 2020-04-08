#include <bits/stdc++.h>

using namespace std;

string s;

void delDouble() {
	while (s.find("Ee") != -1) {
		int inx = s.find("Ee");
		s.erase(inx + 1, 1);
		s[inx] = 'I';
	}
	while (s.find("Oo") != -1) {
		int inx = s.find("Oo");
		s.erase(inx + 1, 1);
		s[inx] = 'U';
	}
	while (s.find("ee") != -1) {
		int inx = s.find("ee");
		s.erase(inx + 1, 1);
		s[inx] = 'i';
	}
	while (s.find("oo") != -1) {
		int inx = s.find("oo");
		s.erase(inx + 1, 1);
		s[inx] = 'u';
	}
	
}

bool isSing(int x) {
	if ((tolower(s[x - 1]) >= 'a' && tolower(s[x - 1]) <= 'z') || (tolower(s[x + 1]) >= 'a' && tolower(s[x + 1]) <= 'z')) return false;
		else return true;
}

bool isLetter(int x) {
	return tolower(s[x]) >= 'a' && tolower(s[x]) <= 'z';
}

void delArt() {
	s = " " + s;
	s += " ";
	
	int i = 1;
	while (i < s.size()) {
		if (tolower(s[i]) == 'a' && !isLetter(i - 1) && !isLetter(i + 1)) 
			s.erase(i, 1);
		else 
			i++;
	}
	
	i = 1;
	while (i < s.size() - 1) {
		if (tolower(s[i]) == 'a' && tolower(s[i + 1]) == 'n' && !isLetter(i - 1) && !isLetter(i + 2)) 
			s.erase(i, 2);
		else 
			i++;
	}
	
	i = 1;
	while (i < s.size() - 2) {
		if (tolower(s[i]) == 't' && tolower(s[i + 1]) == 'h' && tolower(s[i + 2]) == 'e' && !isLetter(i - 1) && !isLetter(i + 3)) 
			s.erase(i, 3);
		else 
			i++;
	}
	
	
	s.erase(s.length() - 1, 1);
	s.erase(0, 1);
}

int main() {
	getline(cin, s);
	
	delArt();
	
	
	while (s.find("c") != -1) {
		int inx = s.find("c"), len = s.size();
		if (inx < len - 1) {
			if (s[inx + 1] == 'i' || s[inx + 1] == 'e') {
				s[inx] = 's';
			} else if (s[inx + 1] == 'k') {
				s.erase(inx, 1);
			} else s[inx] = 'k';
		} else {
			s[inx] = 'k';
		}
	} 
	while (s.find("C") != -1) {
		int inx = s.find("C"), len = s.size();
		if (inx < len - 1) {
			if (s[inx + 1] == 'i' || s[inx + 1] == 'e') {
				s[inx] = 'S';
			} else if (s[inx + 1] == 'k') {
				s[inx + 1] = 'K';
				s.erase(inx, 1);
			} else s[inx] = 'K';
		} else {
			s[inx] = 'K';
		}
	} 
	
	delDouble();
	int i = 0;
	while (i < s.size()) {
		if (tolower(s[i]) == tolower(s[i + 1]) && (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')) {
			s.erase(i + 1, 1);
		} else i++;
		delDouble();
	}
	
	s += " ";
	s = " " + s;
	i = 0;
	while (i < s.size()) {
		if (s[i] == 'e') {
			if (s[i + 1] == ' ' && s[i - 1] != ' ') {
				s.erase(i, 1);
			} else i++;
		} else i++;
	}
	
	while (s.find("  ") != -1) {
		s.erase(s.find("  "), 1);
	}
	while (s[0] == ' ') s.erase(0, 1);
	while (s[s.size() - 1] == ' ') s.erase(s.size() - 1, 1);
	
	
	
	cout << s;
	
	
	
	return 0;
}
