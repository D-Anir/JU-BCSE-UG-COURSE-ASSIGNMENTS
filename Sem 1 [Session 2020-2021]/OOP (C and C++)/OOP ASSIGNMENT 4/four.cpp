#include <iostream>
#include <string.h>

using namespace std;

class String {
	int len;
	char *s;
public:
	String() //default constructor
	{
		len = 0;
		s = new char[len + 1];
		strcpy(s, "");
	}
	String(char* temp) //assigning a string to a object using constructor
	{
		len = 0;
		while (temp[len] != '\0')
			++len;
		s = new char[len + 1];
		char* ss = new char[len + 1];
		strcpy(ss, temp);
		strcpy(s, ss);
		delete[] ss;
	}
	String(String& a) //copy constructor
	{
		len = a.len;
		s = new char[len + 1];
		char* ss = new char[len + 1];
		strcpy(ss, a.s);
		strcpy(s, ss);
		delete[] ss;
	}
	void operator=(const String& a) //overloading assignment operator
	{
		s = a.s;
		len = a.len;
	}
	friend String operator+(String& a, String& b)  //overloading + operator
	{
		char* temp;
		temp = new char[a.len + b.len + 1];
		int i = 0;
		while (i < a.len) {
			temp[i] = a.s[i];
			++i;
		}
		int j = 0;
		while (j < b.len) {
			temp[i] = b.s[j];
			++i;
			++j;
		}
		temp[i] = '\0';
		String c(temp);
		delete[] temp;
		return c;
	}
	friend bool operator>(String& a, String& b) //overloading > operator
	{
		if (strcmp(a.s, b.s) > 0)
			return true;
		return false;
	}
	friend bool operator<(String& a, String& b) //overloading < operator
	{
		if (strcmp(a.s, b.s) < 0)
			return true;
		return false;
	}
	friend bool operator==(String& a, String& b) //overloading ++ operator
	{
		if (strcmp(a.s, b.s) == 0)
			return true;
		return false;
	}
	friend ostream& operator<<(ostream& out, String& a) //overloading << operator
	{
		out << a.s;
		return out;
	}
};

int main() {

	char s1[] = "hello ", s2[] = "world";
	String a(s1);
	String b(s2);
	String c;
	c = a + b;
	cout << c << "\n";
	String d = b;
	if (d == b) {
		cout << "Equal\n";
	}

	return 0;
}