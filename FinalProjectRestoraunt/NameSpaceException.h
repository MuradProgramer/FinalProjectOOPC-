#pragma once
#include "All_C_Libraries.h"

#define TAB "\t\t\t"

using namespace std;

namespace MyException
{
	class Exception {
	protected:
		int line;
		string text;
		string source;
		time_t now;
	public:
		Exception(const string& text, const int& line, const string& source) : text(text), line(line), source(source) {}

		virtual void showException() const {
			system("cls");
			*(const_cast<time_t*>(&now)) = time(0);
			char buffer[50];
			ctime_s(buffer, 50, &now);
			cout << TAB << "____ EXCEPTON ____\n";
			cout << TAB << "TEXT: " << text << endl;
			cout << TAB << "LINE: " << line << endl;
			cout << TAB << "SOURCE: " << source << endl;
			cout << TAB << "TIME: " << buffer << endl;
		}
	};

	class DatabaseException : public Exception {
	public:
		DatabaseException(const string& text, const int& line, const string& source) : Exception(text, line, source) {}
	};

	class InvalidArgumentException : public Exception {
	public:
		InvalidArgumentException(const string& text, const int& line, const string& source) : Exception(text, line, source) {}
	};

	class Error404 : public Exception {
	public:
		Error404(const string& text, const int& line, const string& source) : Exception(text, line, source) {}
	};
}