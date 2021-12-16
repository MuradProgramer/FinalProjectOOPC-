#pragma once
#include "All_C_Libraries.h"
#include "ClassIngredientsCount.h"
using namespace std;

namespace KITCHEN
{
	class Kitchen {
		vector<MEALS::Dish*> dishes;
	public:

		Kitchen(vector<MEALS::Dish*> dishes) : dishes(dishes) {}

		// getters
		vector<MEALS::Dish*> GetDishes() noexcept { return dishes; }

		// setter
		void SetDishes(vector<MEALS::Dish*> dishes) {
			this->dishes = dishes;
		}

		// methods
		int index_of_ingredient_in_stock(const vector<IngredientsCount>& stock, const string& name) noexcept {
			for (int i = 0; i < stock.size(); i++)
				if (stock[i].ingredient->GetName() == name)
					return i;
			return -1;
		}

		void ShowMealsInKitchen(const vector<IngredientsCount> stock) noexcept { // const vector<Mcls::IngredientsCount>& stock
			if (dishes.size() == 0) {
				system("cls");
				system("Color 4");
				cout << "\n\n\n\t\t\t" << char(17) << " N O   D I S H E S   Y E T " << char(16) << endl;
				return;
			}

			system("Color E");
			cout << "\t\t\t\t";
			for (int i = 0; i < 61; i++)
				cout << char(254);
			cout << endl;
			cout << "\t\t\t\t" << char(219) << "   @ @ @ @    @    @ @ @     @     @   @ @ @ @    @ @ @    " << char(219) << endl;
			cout << "\t\t\t\t" << char(219) << "   @      @       @          @     @   @         @         " << char(219) << endl;
			cout << "\t\t\t\t" << char(219) << "   @      @   @    @ @ @     @ @ @ @   @ @ @      @ @ @    " << char(219) << endl;
			cout << "\t\t\t\t" << char(219) << "   @      @   @         @    @     @   @               @   " << char(219) << endl;
			cout << "\t\t\t\t" << char(219) << "   @ @ @ @    @    @ @ @     @     @   @ @ @ @    @ @ @    " << char(219) << endl;
			cout << "\t\t\t\t";
			for (int i = 0; i < 61; i++)
				cout << char(254);
			cout << "\n\n";

			int index = 0;
			for (int i = 0, k = 1; i < dishes.size(); i++)
			{
				bool check = true;
				for (auto j : dishes[i]->GetIngredients())
				{
					if (j->GetIngredient()->GetName() == "Mushrooms") {
						if (j->GetCountInMeal() > stock[index_of_ingredient_in_stock(stock, "Mushrooms")].count_in_stock) {
							check = false;
							break;
						}
					}

					if (j->GetIngredient()->GetName() == "Meat") {
						if (j->GetCountInMeal() > stock[index_of_ingredient_in_stock(stock, "Meat")].count_in_stock) {
							check = false;
							break;
						}
					}

					if (j->GetIngredient()->GetName() == "Spices") {
						if (j->GetCountInMeal() > stock[index_of_ingredient_in_stock(stock, "Spices")].count_in_stock) {
							check = false;
							break;
						}
					}
						
					if (j->GetIngredient()->GetName() == "Cheese") {
						if (j->GetCountInMeal() > stock[index_of_ingredient_in_stock(stock, "Cheese")].count_in_stock) {
							check = false;
							break;
						}
					}
						
					if (j->GetIngredient()->GetName() == "Tomatoe") {
						if (j->GetCountInMeal() > stock[index_of_ingredient_in_stock(stock, "Tomatoe")].count_in_stock) {
							check = false;
							break;
						}
					}
						
					if (j->GetIngredient()->GetName() == "Leaves") {
						if (j->GetCountInMeal() > stock[index_of_ingredient_in_stock(stock, "Leaves")].count_in_stock) {
							check = false;
							break;
						}
					}

					if (j->GetIngredient()->GetName() == "Sausage") {
						if (j->GetCountInMeal() > stock[index_of_ingredient_in_stock(stock, "Sausage")].count_in_stock) {
							check = false;
							break;
						}
					}

					if (j->GetIngredient()->GetName() == "Butter") {
						if (j->GetCountInMeal() > stock[index_of_ingredient_in_stock(stock, "Butter")].count_in_stock) {
							check = false;
							break;
						}
					}
				}

				if (check == false) {
					dishes[i]->SetCanAccessToBuyMealUser(false);
					index++;
					continue;
				}
				else {
					dishes[i]->SetCanAccessToBuyMealUser(true);
				}


				cout << "\t\t\t";
				for (int i = 0; i < 11; i++)
					cout << char(254);
				cout << endl;
				cout << "\t\t\t" << char(219) << " DISH: " << k++ << " " << char(219) << endl;
				cout << "\t\t\t";
				for (int i = 0; i < 11; i++)
					cout << char(254);
				cout << endl;
				cout << "\t" << char(4) << " NAME: " << dishes[i]->GetName() << endl;
				cout << "\t" << char(4) << " AMOUNT: " << dishes[i]->GetAmount() << " $" << endl;
				cout << "\t" << char(4) << " index for buy: " << index + 1 << endl;
				cout << "\t" << char(4) << " INGREDIENTS: ";
				for (auto j : dishes[i]->GetIngredients())
				{
					cout << j->GetIngredient()->GetName() << " ";
				}
				cout << "\n\n\n";
				index++;
			}
		}
	};
}