////// LIBRARIES OF PROGRAM
#include "All_C_Libraries.h"

////// HEADERS FILES
#include "NameSpaceException.h"
#include "NameSpaceDataBase.h"
#include "NameSpaceIngredient.h"
#include "NameSpaceRecipetItem.h"
#include "NameSpaceMeals.h"
#include "NameSpaceKitchen.h"
#include "ClassIngredientsCount.h"

using namespace std;

// defines
#define TIMELEN 50
#define TAB "\t\t\t"
#define DDEFAULT_ING_COUNT 100
#define clear system("cls")

namespace Mcls
{
	void writepsw(char*& _destination, const int& _size) {
		char b;
		cout << "\t\t\t" << char(16) << " Enter password: ";
		for (int i = 0; i < _size; i++)
		{
			b = _getch();
			if (int(b) == 13) {
				_destination[i] = '\0';
				cout << endl;
				break;
			}
			if (int(b) == 8) {
				i -= 2;
				continue;
			}
			_destination[i] = b;
			_putch('*');
		}
		cout << endl;
	}

	int index_of_ingredient_in_stock(const vector<IngredientsCount>& stock, const string& name) {
		for (int i = 0; i < stock.size(); i++)
			if (stock[i].ingredient->GetName() == name)
				return i;
		return -1;
	}

	int IndextUsernameOfAdmin(vector<DATABASE::ADMIN::Admin*> administrators, const string& username) {
		for (int i = 0; i < administrators.size(); i++)
			if (administrators[i]->GetUsername() == username)
				return i;
		return -1;
	}

	int IndextUsernameOfUser(vector<DATABASE::USER::User*> users, const string& username) {
		for (int i = 0; i < users.size(); i++)
			if (users[i]->GetUsername() == username)
				return i;
		return -1;
	}

	bool IsExistUsernameOfAdmin(vector<DATABASE::ADMIN::Admin*> administrators, const string& username) {
		for (int i = 0; i < administrators.size(); i++)
			if (administrators[i]->GetUsername() == username)
				return true;
		return false;
	}

	bool IsExistUsernameOfUser(vector<DATABASE::USER::User*> users, const string& username) {
		for (int i = 0; i < users.size(); i++)
			if (users[i]->GetUsername() == username)
				return true;
		return false;
	}

	void ShowStock(vector<IngredientsCount> stock) {
		clear;
		system("Color E");
		cout << "\t\t\t";
		for (int i = 0; i < 59; i++)
			cout << char(254);
		cout << "\n\t\t\t" << char(219) << "    @ @ @ @   @ @ @ @ @    @ @ @ @     @ @ @ @   @    @  " << char(219) << endl;
		cout << "\t\t\t" << char(219) << "  @               @       @       @   @          @   @   " << char(219) << endl;
		cout << "\t\t\t" << char(219) << "    @ @ @         @       @       @   @          @ @     " << char(219) << endl;
		cout << "\t\t\t" << char(219) << "          @       @       @       @   @          @   @   " << char(219) << endl;
		cout << "\t\t\t" << char(219) << "  @ @ @ @         @        @ @ @ @     @ @ @ @   @    @  " << char(219) << endl;
		cout << "\t\t\t";
		for (int i = 0; i < 59; i++)
			cout << char(254);
		cout << "\n\n";

		for (int i = 0; i < stock.size(); i++)
		{
			cout << "\t\t\t\t\t     " << char(4) << " " << stock[i].ingredient->GetName() << ":  " << stock[i].count_in_stock << "\n\n";
		}

		cout << endl;
	}

	void start() throw(MyException::Exception) {		

		#pragma region DATAS

		double budget_of_restoraunt = 1000;
		double daily_expenses = 0;
		double daily_income = 0;

		vector<DATABASE::ADMIN::Admin*> admins;
		admins.push_back(new DATABASE::ADMIN::Admin("bluefire", "programer"));
		admins.push_back(new DATABASE::ADMIN::Admin("admin", "parol"));

		vector<DATABASE::USER::User*> users;
		users.push_back(new DATABASE::USER::User("user", "parol", vector<string> {}));
		users.push_back(new DATABASE::USER::User("ramazan", "copier", vector<string> {}));

		vector<IngredientsCount> stock;
		stock.push_back(IngredientsCount(new INGREDIENT::Tomatoe(), DDEFAULT_ING_COUNT));
		stock.push_back(IngredientsCount(new INGREDIENT::Cheese(), DDEFAULT_ING_COUNT));
		stock.push_back(IngredientsCount(new INGREDIENT::Spices(), DDEFAULT_ING_COUNT));
		stock.push_back(IngredientsCount(new INGREDIENT::Meat(), DDEFAULT_ING_COUNT));
		stock.push_back(IngredientsCount(new INGREDIENT::Leaves(), DDEFAULT_ING_COUNT));

		vector<INGREDIENT::Ingredient*> ingredients_for_add_in_admin_panel;
		ingredients_for_add_in_admin_panel.push_back(new INGREDIENT::Mushrooms());
		ingredients_for_add_in_admin_panel.push_back(new INGREDIENT::Sausage());
		ingredients_for_add_in_admin_panel.push_back(new INGREDIENT::Butter());

		vector<RECIPETITEM::RecipetItem*> forpizza;
		forpizza.push_back(new RECIPETITEM::RecipetItem(new INGREDIENT::Tomatoe(), 2));
		forpizza.push_back(new RECIPETITEM::RecipetItem(new INGREDIENT::Cheese(), 3));
		forpizza.push_back(new RECIPETITEM::RecipetItem(new INGREDIENT::Spices(), 4));

		vector<RECIPETITEM::RecipetItem*> forkabab;
		forkabab.push_back(new RECIPETITEM::RecipetItem(new INGREDIENT::Meat(), 3));
		forkabab.push_back(new RECIPETITEM::RecipetItem(new INGREDIENT::Spices(), 3));

		vector<RECIPETITEM::RecipetItem*> fordolma;
		fordolma.push_back(new RECIPETITEM::RecipetItem(new INGREDIENT::Leaves(), 20));
		fordolma.push_back(new RECIPETITEM::RecipetItem(new INGREDIENT::Meat(), 2));

		vector<RECIPETITEM::RecipetItem*> forplov;
		forplov.push_back(new RECIPETITEM::RecipetItem(new INGREDIENT::Cheese(), 5));
		forplov.push_back(new RECIPETITEM::RecipetItem(new INGREDIENT::Meat(), 3));

		vector<RECIPETITEM::RecipetItem*> forbozbash;
		forbozbash.push_back(new RECIPETITEM::RecipetItem(new INGREDIENT::Spices(), 12));
		forbozbash.push_back(new RECIPETITEM::RecipetItem(new INGREDIENT::Tomatoe(), 4));
		forbozbash.push_back(new RECIPETITEM::RecipetItem(new INGREDIENT::Meat(), 3));


		vector<MEALS::Dish*> dishes;
		dishes.push_back(new MEALS::Pizza(forpizza));
		dishes.push_back(new MEALS::Dolma(fordolma));
		dishes.push_back(new MEALS::Kabab(forkabab));


		vector<MEALS::Dish*> dishes_for_add_in_admin_panel;
		dishes_for_add_in_admin_panel.push_back(new MEALS::Plov(forplov));
		dishes_for_add_in_admin_panel.push_back(new MEALS::Bozbash(forbozbash));

		KITCHEN::Kitchen kitchhen(dishes);

		#pragma endregion

		char select;
		label_first_menu_admin_or_guest:
		system("Color A");
		clear;

		cout << "\n\n\n\t\t\t";
		for (int i = 0; i < 22; i++)
			cout << char(254);
		cout << "\n\t\t\t" << char(219) << " As Admin press [1] " << char(219) << endl;
		cout << TAB << char(219) <<        " As User press  [2] " << char(219) << "\n\t\t\t";
		for (int i = 0; i < 22; i++)
			cout << char(254);
		cout << "\n\n" << char(4) << " Enter your select: ";

		select = _getch();

		//////// IF SELECT IS ADMIN
		if (select == '1') {
			char username[50];
			char* password = new char[50];
		label_logadmin:
			clear;
			system("Color C");

			cout << "\n\n\n\t\t\t" << char(16) << " Enter username: ";
			cin >> username;

			writepsw(password, 50);

			if (IsExistUsernameOfAdmin(admins, username)) {
				if (admins[IndextUsernameOfAdmin(admins, username)]->GetPassword() == password) {
					/////////////////////////////// ADMIN MENU
				label_selecttion_in_adminmenu:
					clear;
					system("Color 9");

					cout << "\n\n\n\t\t\t";
					for (int i = 0; i < 23; i++)
						cout << char(254);
					cout << "\n\t\t\t" << char(219) << " Show Stock      [1] " << char(219) << endl;
					cout << "\t\t\t" << char(219) <<   " Show Meals      [2] " << char(219) << endl;
					cout << "\t\t\t" << char(219) <<   " Show Budget     [3] " << char(219) << endl;
					cout << "\t\t\t" << char(219) <<   " Add Ingredient  [4] " << char(219) << endl;
					cout << "\t\t\t" << char(219) <<   " Add new Meal    [5] " << char(219) << endl;
					cout << "\t\t\t" << char(219) <<   " Show Users      [6] " << char(219) << endl;
					cout << "\t\t\t" << char(219) <<   " Back          [ESC] " << char(219) << "\n\t\t\t";
					for (int i = 0; i < 23; i++)
						cout << char(254);

					cout << "\n\n\n" << char(4) << " Enter your select what u want to do: ";
					char select_admin_menu = _getch();

					//////////////////////// SHOW STOCK
					if (select_admin_menu == '1') {
						ShowStock(stock);

						cout << endl;
						cout << TAB;
						for (int i = 0; i < 25; i++)
							cout << char(254);
						cout << '\n' << TAB << char(219) << " PRESS ANY KEY TO BACK " << char(219) << '\n' << TAB;
						for (int i = 0; i < 25; i++)
							cout << char(254);
						cout << endl;
						char select_anykey_to_back = _getch();
						goto label_selecttion_in_adminmenu;
					}

					//////////////////////// SHOW MEALS
					else if (select_admin_menu == '2') {
						clear;
						kitchhen.ShowMealsInKitchen(stock);

						cout << TAB;
						for (int i = 0; i < 25; i++)
							cout << char(254);
						cout << '\n' << TAB << char(219) << " PRESS ANY KEY TO BACK " << char(219) << '\n' << TAB;
						for (int i = 0; i < 25; i++)
							cout << char(254);
						cout << endl;
						char select_anykey_to_back = _getch();
						goto label_selecttion_in_adminmenu;
					}

					/////////////////////// SHOW BUDGET
					else if (select_admin_menu == '3') {
					label_third_selection_admin_panel:
						clear;
						system("Color E");

						cout << "\n\n\n\t\t\t" << char(4) << " Restoraunt's budget " << char(16) << " " << budget_of_restoraunt << " $" << endl;
						cout << "\t\t\t" << char(4) << " Restoraunt's daily expenses " << char(16) << " " << daily_expenses << " $" << endl;
						cout << "\t\t\t" << char(4) << " Restoraunt's daily income " << char(16) << " " << daily_income << " $" << endl;
						
						cout << endl;
						cout << TAB;
						for (int i = 0; i < 25; i++)
							cout << char(254);
						cout << '\n' << TAB << char(219) << " PRESS ANY KEY TO BACK " << char(219) << '\n' << TAB;
						for (int i = 0; i < 25; i++)
							cout << char(254);
						cout << endl;
						char select_anykey_to_back = _getch();
						if (int(select_anykey_to_back) == 42) {
							budget_of_restoraunt += rand() % 200;
							clear;
							system("Color 4");
							cout << "\n\n\n\t\t\t" << char(17) << " C H E A T   A C T I V A T E D " << char(16) << endl;
							Sleep(500);
							goto label_third_selection_admin_panel;
						}
						goto label_selecttion_in_adminmenu;
					}

					/////////////////////// AddIngredient 
					else if (select_admin_menu == '4') {
					label_add_or_increase_ingredient:
						system("Color B");
						clear;

						cout << "\n\n\n\t\t\t";
						for (int i = 0; i < 27; i++)
							cout << char(254);
						cout << "\n\t\t\t" << char(219) << " Increase Ingredient [1] " << char(219) << endl;
						cout << "\t\t\t" << char(219)   << " Add New Ingredient  [2] " << char(219) << endl;
						cout << "\t\t\t" << char(219)   << " Back              [ESC] " << char(219) << "\n\t\t\t";
						for (int i = 0; i < 27; i++)
							cout << char(254);

						cout << "\n\nWhat do u want to do? ";
						char select_add_or_increase_ingredient = _getch();

						//////////////////// IF SELECT IS INCREASE INGREDIENT
						if (select_add_or_increase_ingredient == '1') {
						label_increase_ingredient:
							clear;
							system("Color B");

							/// <DESIGN>
							cout << "\n\n\t\t" << char(201);
							for (int i = 0; i < 39; i++)
								cout << char(205);
							cout << char(187) << "\n\t\t" << char(186) << " I N G R E D I E N T S  I N  S T O C K " << char(186) << "\n\t\t" << char(200);
							for (int i = 0; i < 39; i++)
								cout << char(205);
							cout << char(188);

							cout << "\n\n\t\t\t";
							for (int i = 0; i < 15; i++)
								cout << char(254);
							cout << endl;
							for (int i = 0; i < stock.size(); i++)
							{
								cout << "\t\t\t" << char(219) << " [" << i + 1 << "] " << stock[i].ingredient->GetName() << right << setw(9 - stock[i].ingredient->GetName().length()) << char(219) << endl;
							}
							cout << "\t\t\t" << char(219) << " [ESC] Back  " << char(219) << "\n\t\t\t";
							for (int i = 0; i < 15; i++)
								cout << char(254);
							/// </DESIGN>
							
							cout << "\n\n" << char(4) << " Which ingredient do you want to increase? ";
							char select_ingredient_to_increase = _getch();

							///////////////////// IF ADMIN NEEDS TO BACK
							if (int(select_ingredient_to_increase) == 27)
								goto label_add_or_increase_ingredient;


							else if (int(select_ingredient_to_increase) > 48 && int(select_ingredient_to_increase) <= stock.size() + 48) {
								int selected_ingredient = int(select_ingredient_to_increase) - 49;

								cout << "\n" << char(4) << " Enter count of ingredients which you need to increase: ";
								long long int count_increased_ingredients;
								cin >> count_increased_ingredients;

								if (count_increased_ingredients <= 0) {
									clear;
									system("Color 4");
									cout << "\n\n\n\t\t\t" << char(17) << " Y O U R   S E L E C T  I S  <  0 " << char(16) << endl;
									Sleep(3000);
									goto label_increase_ingredient;
								}
								if (count_increased_ingredients * stock[selected_ingredient].ingredient->GetAmount() > budget_of_restoraunt) {
									clear;
									system("Color 4");
									cout << "\n\n\n\t\t\t" << char(17) << " YOU CANT BUY THIS INGREDIENT SO MUCH, YOUR BUDGET HAS'T MONEY TO BUY IT " << char(16) << endl;
									Sleep(3000);
									goto label_increase_ingredient;
								}
								else {
									stock[selected_ingredient].count_in_stock += count_increased_ingredients;
									budget_of_restoraunt -= count_increased_ingredients * stock[selected_ingredient].ingredient->GetAmount();
									daily_expenses += count_increased_ingredients * stock[selected_ingredient].ingredient->GetAmount();
									clear;
									system("Color A");
									cout << "\n\n\n\t\t\t" << char(17) << " Y O U   S U C C E S F U L Y   I N C R E A S E D   I N G R E D I E T " << char(16) << endl;
									Sleep(3000);
									goto label_selecttion_in_adminmenu;
								}
							}

							///////////////////// IF SELECT IS WRONG
							else 
								goto label_increase_ingredient;

						}

						//////////////////// IF SELECT IS ADD NEW INGREDIENT
						else if (select_add_or_increase_ingredient == '2') {

							/////////// IF ADMIN CAN'T ADD NEW INGREDIENTS  --- (eger butun elave edile bilecek ingredientler elave olunubsa)
							if (ingredients_for_add_in_admin_panel.size() == 0) {
								clear;
								system("Color 4");
								cout << "\n\n\n\t\t\t" << char(17) << " Y O U   C A N T   A D D   N E W   I N G R E D I E N T " << char(16) << endl;
								Sleep(3000);
								goto label_add_or_increase_ingredient;
							}

						label_add_new_ingredient:
							clear;
							system("Color B");

							/// <DESIGN>
							cout << "\n\n\t\t" << char(201);
							for (int i = 0; i < 61; i++)
								cout << char(205);
							cout << char(187) << "\n\t\t" << char(186) << " I N G R E D I E N T S   W H I C H   U   C A N   T O   A D D " << char(186) << "\n\t\t" << char(200);
							for (int i = 0; i < 61; i++)
								cout << char(205);
							cout << char(188);

							cout << "\n\n\t\t\t";
							for (int i = 0; i < 17; i++)
								cout << char(254);
							cout << endl;
							for (int i = 0; i < ingredients_for_add_in_admin_panel.size(); i++)
							{
								cout << "\t\t\t" << char(219) << " [" << i + 1 << "] " << ingredients_for_add_in_admin_panel[i]->GetName() << right << setw(11 - ingredients_for_add_in_admin_panel[i]->GetName().length()) << char(219) << endl;
							}
							cout << "\t\t\t" << char(219) << " [ESC] Back    " << char(219) << "\n\t\t\t";
							for (int i = 0; i < 17; i++)
								cout << char(254);
							/// </DESIGN>

							cout << "\n\n" << char(4) << " Which Product do you want to add to stock? ";
							char select_ingredient_to_add_in_admin_panel = _getch();

							///////////////////// IF ADMIN NEEDS TO BACK
							if (int(select_ingredient_to_add_in_admin_panel) == 27)
								goto label_add_or_increase_ingredient;

							else if (int(select_ingredient_to_add_in_admin_panel) > 48 && int(select_ingredient_to_add_in_admin_panel) <= ingredients_for_add_in_admin_panel.size() + 48) {
								int selected_ingredient = int(select_ingredient_to_add_in_admin_panel) - 49;

								cout << "\n" << char(4) << " Enter count of ingredients which you selected to add: ";
								long long int count_increased_ingredients;
								cin >> count_increased_ingredients;

								if (count_increased_ingredients <= 0) {
									clear;
									system("Color 4");
									cout << "\n\n\n\t\t\t" << char(17) << " Y O U R   S E L E C T  I S  <  0 " << char(16) << endl;
									Sleep(3000);
									goto label_add_new_ingredient;
								}
								if (count_increased_ingredients * ingredients_for_add_in_admin_panel[selected_ingredient]->GetAmount() > budget_of_restoraunt) {
									clear;
									system("Color 4");
									cout << "\n\n\n\t\t\t" << char(17) << " YOU CANT BUY THIS INGREDIENT SO MUCH, YOUR BUDGET HAS'T MONEY TO BUY IT " << char(16) << endl;
									Sleep(3000);
									goto label_add_new_ingredient;
								}
								else { 
									stock.push_back(IngredientsCount(ingredients_for_add_in_admin_panel[selected_ingredient], count_increased_ingredients));
									budget_of_restoraunt -= count_increased_ingredients * ingredients_for_add_in_admin_panel[selected_ingredient]->GetAmount();
									daily_expenses += count_increased_ingredients * ingredients_for_add_in_admin_panel[selected_ingredient]->GetAmount();
									ingredients_for_add_in_admin_panel.erase(ingredients_for_add_in_admin_panel.begin() + selected_ingredient);
									clear;
									system("Color A");
									cout << "\n\n\n\t\t\t" << char(17) << " Y O U   S U C C E S F U L Y   A D D E D   I N G R E D I E T " << char(16) << endl;
									Sleep(3000);
									goto label_add_or_increase_ingredient;
								}
							}

							else
								goto label_add_new_ingredient;

						}

						//////////////////// IF SELECT IS BACK
						else if (int(select_add_or_increase_ingredient) == 27)
							goto label_selecttion_in_adminmenu;

						//////////////////// IF SELECT IS WRONG
						else
							goto label_add_or_increase_ingredient;
					}

					/////////////////////// ADD NEW DISH
					else if (select_admin_menu == '5') {
						label_add_new_meal:
						clear;
						system("Color B");
						
						/// <DESIGN>
						cout << "\n\n\t\t" << char(201);
						for (int i = 0; i < 49; i++)
							cout << char(205);
						cout << char(187) << "\n\t\t" << char(186) << " M E A L S   W H I C H   U   C A N   T O   A D D " << char(186) << "\n\t\t" << char(200);
						for (int i = 0; i < 49; i++)
							cout << char(205);
						cout << char(188);

						cout << "\n\n\t\t\t";
						for (int i = 0; i < 17; i++)
							cout << char(254);
						cout << endl;
						for (int i = 0; i < dishes_for_add_in_admin_panel.size(); i++)
						{
							cout << "\t\t\t" << char(219) << " [" << i + 1 << "] " << dishes_for_add_in_admin_panel[i]->GetName() << right << setw(11 - dishes_for_add_in_admin_panel[i]->GetName().length()) << char(219) << endl;
						}
						cout << "\t\t\t" << char(219) << " [ESC] Back    " << char(219) << "\n\t\t\t";
						for (int i = 0; i < 17; i++)
							cout << char(254);
						/// </DESIGN>

						cout << "\n\n" << char(4) << " Which meal do you want to add? ";
						char select_which_meal_add = _getch();

						if (int(select_which_meal_add) == 27)
							goto label_selecttion_in_adminmenu;

						else if (int(select_which_meal_add) > 48 && int(select_which_meal_add) <= dishes_for_add_in_admin_panel.size() + 48) {
							int selected_ingredient = int(select_which_meal_add) - 49;

							if (dishes_for_add_in_admin_panel[selected_ingredient]->GetAmount() > budget_of_restoraunt) {
								clear;
								system("Color 4");
								cout << "\n\n\n\t\t\t" << char(17) << " Y O U R   B U D G E T   H A S' T   M O N E Y   T O   A D D   I T " << char(16) << endl;
								Sleep(3000);
								goto label_add_new_meal;
							}
							else {
								dishes.push_back(dishes_for_add_in_admin_panel[selected_ingredient]);
								kitchhen.SetDishes(dishes);
								budget_of_restoraunt -= dishes_for_add_in_admin_panel[selected_ingredient]->GetAmount();
								daily_expenses += dishes_for_add_in_admin_panel[selected_ingredient]->GetAmount();
								dishes_for_add_in_admin_panel.erase(dishes_for_add_in_admin_panel.begin() + selected_ingredient);
								clear;
								system("Color A");
								cout << "\n\n\n\t\t\t" << char(17) << " Y O U   S U C C E S F U L Y   A D D E D   M E A L " << char(16) << endl;
								Sleep(3000);
								goto label_selecttion_in_adminmenu;
							}
						}

						else
							goto label_add_new_meal;
					}

					/////////////////////// SHOW USERS
					else if (select_admin_menu == '6') {
						clear;
						system("Color E");
						for (int i = 0; i < users.size(); i++)
						{
							users[i]->ShowUser();
						}

						cout << endl;
						cout << TAB;
						for (int i = 0; i < 25; i++)
							cout << char(254);
						cout << '\n' << TAB << char(219) << " PRESS ANY KEY TO BACK " << char(219) << '\n' << TAB;
						for (int i = 0; i < 25; i++)
							cout << char(254);
						cout << endl;
						char select_anykey_to_back = _getch();
						goto label_selecttion_in_adminmenu;
					}

					/////////////////////////////// COME TO MENU
					else if (int(select_admin_menu) == 27)
						goto label_first_menu_admin_or_guest;

					/////////////////////////////// IF SELECT IS WRONG
					else
						goto label_selecttion_in_adminmenu;

				}
				///////// IF THE PASSWORD WRONG
				else {
					try
					{
						throw MyException::DatabaseException("Wrong Password.", __LINE__, "FinalProject.cpp");
					}
					catch (MyException::DatabaseException ex)
					{
						for (int i = 0; i < 5; i++)
						{
							clear;
							if (i % 2 == 0)
								system("Color 4");
							else
								system("Color F");
							ex.showException();
							Sleep(500);
						}
						
					}
					goto label_logadmin;
				}
			}
			///////// IF THE USERNAME IS NOT FOUND

			else {

				try
				{
					throw MyException::Error404("Username is not found.", __LINE__, "FinalProject.cpp");
				}
				catch (MyException::Error404 ex)
				{
					for (int i = 0; i < 5; i++)
					{
						clear;
						if (i % 2 == 0)
							system("Color 4");
						else
							system("Color F");
						ex.showException();
						Sleep(500);
					}

				}

				goto label_logadmin;
			}
		}

		//////// IF SELECT IS USER
		else if (select == '2') {
			char username[50];
			char* password = new char[50];
		label_loguser:
			clear;
			system("Color 6");

			cout << "\n\n\n\t\t\t" << char(16) << " Enter username: ";
			cin >> username;

			writepsw(password, 50);
			
			if (IsExistUsernameOfUser(users, username)) {
				if (users[IndextUsernameOfUser(users, username)]->GetPassword() == password) {
					int index_of_user = IndextUsernameOfUser(users, username);
					users[IndextUsernameOfUser(users, username)]->SetConnectedDate();
					/////////////////////////////// USER MENU
				label_selecttion_in_usermenu:
					clear;
					kitchhen.ShowMealsInKitchen(stock);

					cout << "\n\n\n\t\t" << char(201);
					for (int i = 0; i < 21; i++)
						cout << char(205);
					cout << char(187) << "\n\t\t" << char(186) << " U S E R S   M E N U " << char(186) << "\n\t\t" << char(200);
					for (int i = 0; i < 21; i++)
						cout << char(205);
					cout << char(188);

					cout << "\n\n\t\t\t";
					for (int i = 0; i < 17; i++)
						cout << char(254);
					cout << "\n\t\t\t" << char(219) << " Show      [1] " << char(219) << endl;
					cout << TAB << char(219) <<        " Order     [2] " << char(219) << endl;
					cout << TAB << char(219) <<        " Back    [ESC] " << char(219) << "\n\t\t\t";
					for (int i = 0; i < 17; i++)
						cout << char(254);

					cout << "\n\n\n" << char(4) << " Enter your select what u want to do: ";
					char select_user_menu = _getch();

					//////////////////////// SHOW MEAL
					if (select_user_menu == '1') {
					label_show_meal_in_user_panel:
						cout << "\n" << char(4) << " Which Meal do u want to see? (Enter index for buy) ";
						char select_user_menu = _getch();

						if (int(select_user_menu) - 48 > 0 && int(select_user_menu) - 48 <= kitchhen.GetDishes().size()) {
							int index_of_selected_meal = int(select_user_menu) - 49;
							if (kitchhen.GetDishes()[index_of_selected_meal]->GetCanAccessToBuyMealUser() == false) {
								goto label_show_meal_in_user_panel;
							}
							else {
								clear;
								kitchhen.GetDishes()[index_of_selected_meal]->printRecipe();
							}
						}
						else
							goto label_show_meal_in_user_panel;

						cout << TAB;
						for (int i = 0; i < 25; i++)
							cout << char(254);
						cout << '\n' << TAB << char(219) << " PRESS ANY KEY TO BACK " << char(219) << '\n' << TAB;
						for (int i = 0; i < 25; i++)
							cout << char(254);
						cout << endl;
						char select_anykey_to_back = _getch();
						goto label_selecttion_in_usermenu;
					}

					//////////////////////// BUY MEAL
					else if (select_user_menu == '2') {
					label_buy_meal_in_user_panel_check:
						clear;
						system("Color 9");
						kitchhen.ShowMealsInKitchen(stock);

						cout << char(4) << " Which Meal do u want to BUY? (Enter index for buy) ";
						char select_user_menu = _getch();
						int index_of_selected_meal = int(select_user_menu) - 49;

						if (int(select_user_menu) - 48 > 0 && int(select_user_menu) - 48 <= kitchhen.GetDishes().size()) {
							if (kitchhen.GetDishes()[index_of_selected_meal]->GetCanAccessToBuyMealUser() == false) {
								goto label_buy_meal_in_user_panel_check;
							}
							else {
								goto label_buy_meal_in_user_panel;
							}
						}
						else
							goto label_buy_meal_in_user_panel_check;

						label_buy_meal_in_user_panel:
						cout << "\nDo you want to add ingredient in meal and buy it then when you will added? (YES-[1],  NO-[2]) " << char(16);
						char select_yes_or_no_toadd_ingredient = _getch();

						////////////// IF USER WANTs ADD INGREDIENT (SELECT == YES)
						if (select_yes_or_no_toadd_ingredient == '1') {
						label_add_inginmeal_in_user_menu:
							clear;
							system("Color B");
							
							/// <DESIGN>
							cout << "\n\n\t\t" << char(201);
							for (int i = 0; i < 39; i++)
								cout << char(205);
							cout << char(187) << "\n\t\t" << char(186) << " I N G R E D I E N T S  I N  S T O C K " << char(186) << "\n\t\t" << char(200);
							for (int i = 0; i < 39; i++)
								cout << char(205);
							cout << char(188);

							cout << "\n\n\t\t\t";
							for (int i = 0; i < 15; i++)
								cout << char(254);
							cout << endl;
							for (int i = 0; i < stock.size(); i++)
							{
								cout << "\t\t\t" << char(219) << " [" << i + 1 << "] " << stock[i].ingredient->GetName() << right << setw(9 - stock[i].ingredient->GetName().length()) << char(219) << endl;
							}
							cout << "\t\t\t" << char(219) << " [ESC] Back  " << char(219) << "\n\t\t\t";
							for (int i = 0; i < 15; i++)
								cout << char(254);
							/// </DESIGN>

							cout << "\n\n" << char(4) << " Which ingredient would u like to add? ";
							int money;
							char select_ingredient_to_add_in_usermenu = _getch();

							if (int(select_ingredient_to_add_in_usermenu) > 48 && int(select_ingredient_to_add_in_usermenu) <= stock.size() + 48) {
								int selected_ingredient = int(select_ingredient_to_add_in_usermenu) - 49;

								cout << "\n" << char(4) << " Enter count of ingredients which you need to add: ";
								long long int count_increased_ingredients;
								cin >> count_increased_ingredients;

								if (count_increased_ingredients <= 0) {
									clear;
									system("Color 4");
									cout << "\n\n\n\t\t\t" << char(17) << " Y O U R   S E L E C T  I S  <  0 " << char(16) << endl;
									Sleep(3000);
									goto label_add_inginmeal_in_user_menu;
								}
								if (count_increased_ingredients * stock[selected_ingredient].ingredient->GetAmount() > budget_of_restoraunt) {
									clear;
									system("Color 4");
									cout << "\n\n\n\t\t\t" << char(17) << " YOU CANT BUY THIS INGREDIENT SO MUCH, YOUR BUDGET HAS'T MONEY TO BUY IT " << char(16) << endl;
									Sleep(3000);
									goto label_add_inginmeal_in_user_menu;
								}
								else {
									stock[selected_ingredient].count_in_stock -= count_increased_ingredients;
									budget_of_restoraunt += count_increased_ingredients * stock[selected_ingredient].ingredient->GetAmount();
									daily_income += count_increased_ingredients * stock[selected_ingredient].ingredient->GetAmount();
									clear;
									system("Color A");
									cout << "\n\n\n\t\t\t" << char(17) << " Y O U   S U C C E S F U L Y   A D D E D   I N G R E D I E T " << char(16) << endl;
									Sleep(3000);
									goto label_buy_meal_without_ingredient;
								}
							}

							else if (int(select_ingredient_to_add_in_usermenu) == 27)
								goto label_selecttion_in_usermenu;

							else
								goto label_add_inginmeal_in_user_menu;

							cout << endl;
							Sleep(3000);
							goto label_selecttion_in_usermenu;
						}

						////////////// IF USER DOESNT WANT ADD INGREDIENT (SELECT == NO)
						else if (select_yes_or_no_toadd_ingredient == '2') {
						label_buy_meal_without_ingredient:
							clear;
							system("Color A");

							for (auto j : dishes[index_of_selected_meal]->GetIngredients())
							{
								if (j->GetIngredient()->GetName() == "Mushrooms") {
									stock[index_of_ingredient_in_stock(stock, "Mushrooms")].count_in_stock -= j->GetCountInMeal();
									break;
								}

								if (j->GetIngredient()->GetName() == "Meat") {
									stock[index_of_ingredient_in_stock(stock, "Meat")].count_in_stock -= j->GetCountInMeal();
								}

								if (j->GetIngredient()->GetName() == "Spices") {
									stock[index_of_ingredient_in_stock(stock, "Spices")].count_in_stock -= j->GetCountInMeal();
								}

								if (j->GetIngredient()->GetName() == "Cheese") {
									stock[index_of_ingredient_in_stock(stock, "Cheese")].count_in_stock -= j->GetCountInMeal();
								}

								if (j->GetIngredient()->GetName() == "Tomatoe") {
									stock[index_of_ingredient_in_stock(stock, "Tomatoe")].count_in_stock -= j->GetCountInMeal();
								}

								if (j->GetIngredient()->GetName() == "Leaves") {
									stock[index_of_ingredient_in_stock(stock, "Leaves")].count_in_stock -= j->GetCountInMeal();
								}

								if (j->GetIngredient()->GetName() == "Sausage") {
									stock[index_of_ingredient_in_stock(stock, "Sausage")].count_in_stock -= j->GetCountInMeal();
								}

								if (j->GetIngredient()->GetName() == "Butter") {
									stock[index_of_ingredient_in_stock(stock, "Butter")].count_in_stock -= j->GetCountInMeal();
								}
							}

							budget_of_restoraunt += dishes[index_of_selected_meal]->GetAmount();
							daily_income += dishes[index_of_selected_meal]->GetAmount();

							users[index_of_user]->AddNameOFMealToVector(dishes[index_of_selected_meal]->GetName());

							cout << "\n\n\n\t\t\t" << char(17) << " Y O U   S U C C E F U L Y   B U Y E D   M E A L " << char(16);
							Sleep(3000);
							goto label_selecttion_in_usermenu;
						}

						////////////// IF SELECT IS WRONG
						else
							goto label_buy_meal_in_user_panel;


					}

					/////////////////////////////// COME TO MENU
					else if (int(select_user_menu) == 27)
						goto label_first_menu_admin_or_guest;

					/////////////////////////////// IF SELECT IS WRONG
					else
						goto label_selecttion_in_usermenu;

				}
				///////// IF THE PASSWORD WRONG
				else {
					try
					{
						throw MyException::DatabaseException("Wrong Password.", __LINE__, "FinalProject.cpp");
					}
					catch (MyException::DatabaseException ex)
					{
						for (int i = 0; i < 5; i++)
						{
							clear;
							if (i % 2 == 0)
								system("Color 4");
							else
								system("Color F");
							ex.showException();
							Sleep(500);
						}

					}
					goto label_loguser;
				}
			}
			///////// IF THE USERNAME IS NOT FOUND

			else {

				try
				{
					throw MyException::Error404("Username is not found.", __LINE__, "FinalProject.cpp");
				}
				catch (MyException::Error404 ex)
				{
					for (int i = 0; i < 5; i++)
					{
						clear;
						if (i % 2 == 0)
							system("Color 4");
						else
							system("Color F");
						ex.showException();
						Sleep(500);
					}

				}

				goto label_loguser;
			}

		}

		else if (int(select) == 27) 
			return;

		//////// IF SELECT IS WRONG
		else 
			goto label_first_menu_admin_or_guest;
	}
}


int main() {
	system("Color A");
	srand(time(0));

	Mcls::start();
}


