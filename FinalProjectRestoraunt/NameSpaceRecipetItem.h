#pragma once
#include "All_C_Libraries.h"
#include "NameSpaceException.h"
#include "NameSpaceIngredient.h"

using namespace std;

namespace RECIPETITEM
{
	class RecipetItem {
		INGREDIENT::Ingredient* ingredient;
		int count_in_meal;
	public:
		RecipetItem(INGREDIENT::Ingredient* ingredient, int count_in_meal) : ingredient(ingredient) {
			SetCountInMeal(count_in_meal);
		}

		// Getter
		INGREDIENT::Ingredient* GetIngredient() noexcept { return ingredient; }

		int GetCountInMeal() noexcept { return  count_in_meal; }

		// Setter
		void SetCountInMeal(const int& count_in_meal) throw(MyException::InvalidArgumentException) {
			if (count_in_meal < 0)
				throw MyException::InvalidArgumentException("Count is smaller than 0", __LINE__, "FinalProject.cpp");
			this->count_in_meal = count_in_meal;
		}

		// show
		void ShowRecipedItem() const {
			ingredient->ShowIngredient();
			cout << "| Count In Meal: " << count_in_meal << endl;
		}
	};
}