#include <bits/stdc++.h>

using namespace std;

struct Book {
	string title, author;
	int year;
};

int main() {
	list <Book> l;
	Book book = { "Title", "Author", 1234 };
	l.push_back(book);
	book.title = "Title111";
	l.push_front(book);
	
	list <Book> :: iterator it;
	it = l.begin();
	
	for (it = l.begin(); it != l.end(); it++) {
		book = *it;
		cout << book.title << endl;
	}
	
	it = l.begin();
	advance(it, 1);
	l.erase(it);
	for (it = l.begin(); it != l.end(); it++) {
		book = *it;
		cout << book.title << endl;
	}
	
	
	return 0;
}
