#pragma once
#include "All_C_Libraries.h"
#include "NameSpaceException.h"
#include "NameSpaceIngredient.h"
#include "NameSpaceRecipetItem.h"
using namespace std;

namespace MEALS
{
	class Dish {
	protected:
		vector<RECIPETITEM::RecipetItem*> ingredients;
		string name;
		double amount;
		bool can_buy_by_user;
	public:

		Dish() = default;

		Dish(vector<RECIPETITEM::RecipetItem*> ingredients, string name) : can_buy_by_user(true) {
			SetIngredients(ingredients);
			SetName(name);
			SetAmount();
		}

		//getter 
		vector<RECIPETITEM::RecipetItem*> GetIngredients() noexcept { return ingredients; }

		bool GetCanAccessToBuyMealUser() noexcept { return can_buy_by_user; }

		string GetName() noexcept { return name; }

		double GetAmount() noexcept { return amount; }

		//setter
		void SetCanAccessToBuyMealUser(const bool& condition) { can_buy_by_user = condition; }

		void SetIngredients(vector<RECIPETITEM::RecipetItem*> ings) {
			for (int i = 0; i < ings.size(); i++)
				ingredients.push_back(ings[i]);
		}

		void SetName(string name) {
			this->name.clear();
			this->name = name;
			name.clear();
		}

		void SetAmount() {
			for (int i = 0; i < ingredients.size(); i++)
				amount += ingredients[i]->GetCountInMeal() * ingredients[i]->GetIngredient()->GetAmount();
		}

		// methods
		void addIngredient(INGREDIENT::Ingredient* ingredient, int count_in_meal) noexcept {
			RECIPETITEM::RecipetItem* newRecipetItem = new RECIPETITEM::RecipetItem(ingredient, count_in_meal);
			ingredients.push_back(newRecipetItem);
		}

		virtual void printRecipe() const {
			cout << "\n\n\n";
			cout << setw(82) << " @ @ @    @ @ @     @ @ @    @    @ @ @    @ @ @   \n";
			cout << setw(82) << " @    @   @       @               @    @   @       \n";
			cout << setw(82) << " @ @ @    @ @     @          @    @ @ @    @ @     \n";
			cout << setw(82) << " @   @    @       @          @    @        @       \n";
			cout << setw(82) << " @    @   @ @ @     @ @ @    @    @        @ @ @   \n";
			cout << endl;

			cout << setw(92) << " ____________________________________________________________________\n\n";
			cout << setw(54) << "     ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ " << name << " ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ \n\n";
			for (int i = 0; i < ingredients.size(); i++) {
				ingredients[i]->ShowRecipedItem();
			}
			cout << setw(92) << " ____________________________________________________________________\n\n";

			cout << setw(108) << " ----------------------------- \n";
			cout << setw(100) << "| Total Amount Of Meal: " << amount << " $ |" << endl;
			cout << setw(109) << " ----------------------------- \n\n";
		}

	};

	/////////////// STANDART FOR BUY

	class Pizza : public Dish {
	public:
		Pizza() : Dish() {}
		Pizza(vector<RECIPETITEM::RecipetItem*> ingredients) : Dish(ingredients, "pizza") {}
	};

	class Kabab : public Dish {
	public:
		Kabab() : Dish() {}
		Kabab(vector<RECIPETITEM::RecipetItem*> ingredients) : Dish(ingredients, "Kabab") {}
	};

	class Dolma : public Dish {
	public:
		Dolma() : Dish() {}
		Dolma(vector<RECIPETITEM::RecipetItem*> ingredients) : Dish(ingredients, "Dolma") {}
	};

	////////////// CAN TO ADD

	class Plov : public Dish {
	public:
		Plov() : Dish() {}
		Plov(vector<RECIPETITEM::RecipetItem*> ingredients) : Dish(ingredients, "Plov") {}
	};

	class Bozbash : public Dish {
	public:
		Bozbash() : Dish() {}
		Bozbash(vector<RECIPETITEM::RecipetItem*> ingredients) : Dish(ingredients, "Bozbash") {}
	};

}