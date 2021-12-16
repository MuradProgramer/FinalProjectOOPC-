#pragma once
#include "All_C_Libraries.h"

#define TIMELEN 50

using namespace std;

namespace DATABASE
{
	namespace ADMIN {
		class Admin {
			string username;
			string password;
		public:
			Admin(const string& username, const string& password) : username(username), password(password) {}

			// getters
			string GetUsername() noexcept { return username; }

			string GetPassword() noexcept { return password; }

			// setters
			void SetUsername(const string& username) { this->username = username; }

			void SetPassword(const string& password) { this->password = password; }

			// show
			void ShowAdmin() {
				cout << "_______ ADMIN ______\n";
				cout << "USERNAME: " << username << endl;
				cout << "PASSWORD: " << '*' * password.length() << "\n\n";
			}
		};
	}

	namespace USER {
		class User {
			string username;
			string password;
			char* connected_date;
			vector<string> buyed_meals;
		public:

			User(const string& username, const string& password, const vector<string> buyed_meals) : username(username), password(password), buyed_meals(buyed_meals) {
				time_t now = time(0);
				char* buffer = new char[TIMELEN];
				ctime_s(buffer, TIMELEN, &now);
				connected_date = buffer;
			}

			// getters
			string GetUsername() noexcept { return username; }

			string GetPassword() noexcept { return password; }

			string GetConnectedDate() noexcept { return connected_date; }

			vector<string> GetUserHistoryOne() noexcept { return buyed_meals; }

			// setters
			void SetFullName(const string& username) { this->username = username; }

			void SetPassword(const string& password) { this->password = password; }

			void SetConnectedDate() {
				time_t now = time(0);
				char* buffer = new char[TIMELEN];
				ctime_s(buffer, TIMELEN, &now);
				connected_date = buffer;
			}

			void SetUserHistoryOne(const vector<string> buyed_meals) { this->buyed_meals = buyed_meals; }

			// show
			void ShowUser() noexcept {
				cout << "------ USER ----\n";
				cout << "USERNAME: " << username << endl;
				cout << "PASSWORD: " << "********" << endl;
				cout << "CONNECTED DATE: " << connected_date;
				cout << "BUYED MEALS: ";
				for (int i = 0; i < buyed_meals.size(); i++)
				{
					cout << buyed_meals[i] << " ";
				}
				cout << "\n\n";
			}

			// add
			void AddNameOFMealToVector(const string& name_of_meal) noexcept {
				buyed_meals.push_back(name_of_meal);
			}
		};
	}
}