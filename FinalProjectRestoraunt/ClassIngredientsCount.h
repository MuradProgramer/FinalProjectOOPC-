#pragma once
#include "All_C_Libraries.h"
#include "NameSpaceIngredient.h"
using namespace std;

class IngredientsCount
{
public:
	INGREDIENT::Ingredient* ingredient;

	int count_in_stock;

	IngredientsCount(INGREDIENT::Ingredient* ingredient, int count_in_stock) : ingredient(ingredient), count_in_stock(count_in_stock) {}
};