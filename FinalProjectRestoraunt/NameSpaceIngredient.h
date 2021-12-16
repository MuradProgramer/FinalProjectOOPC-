#pragma once
#include "All_C_Libraries.h"

#include "NameSpaceException.h"

using namespace std;

namespace INGREDIENT
{

	class Ingredient {
		string name;
		double kCal;
		double amount;
	public:
		Ingredient(const string& name, const double& kCal, const double& amount) : name(name) {
			SetKCal(kCal);
			SetAmount(amount);
		}

		// Getters
		string GetName() noexcept { return name; }

		double GetKCal() noexcept { return kCal; }

		double GetAmount() noexcept { return amount; }


		// setters
		void SetKCal(const double& kCal) throw (MyException::InvalidArgumentException) {
			if (kCal < 0)
				throw MyException::InvalidArgumentException("KCal must be more than 0", __LINE__, "FinalProject.cpp");
			this->kCal = kCal;
		}

		void SetAmount(const double& amount) throw (MyException::InvalidArgumentException) {
			if (amount < 0)
				throw MyException::InvalidArgumentException("KCal must be more than 0", __LINE__, "FinalProject.cpp");
			this->amount = amount;
		}

		// show
		virtual void ShowIngredient() {
			cout << setw(35) << "| Ingredient: " << name << " | " << kCal << " kcal, " << "Amount -> " << amount << " $ ";
		}

		// for abstraction
		virtual ~Ingredient() = 0 {};
	};

	// defaults

	class Meat : public Ingredient {
	public:
		Meat() : Ingredient("Meat", 200, 4.9) {}

		void ShowIngredient() override { Ingredient::ShowIngredient(); }
	};

	class Spices : public Ingredient {
	public:
		Spices() : Ingredient("Spices", 10, 0.25) {}

		void ShowIngredient() override { Ingredient::ShowIngredient(); }
	};

	class Cheese : public Ingredient {
	public:
		Cheese() : Ingredient("Cheese", 150, 1.2) {}

		void ShowIngredient() override { Ingredient::ShowIngredient(); }
	};

	class Tomatoe : public Ingredient {
	public:
		Tomatoe() : Ingredient("Tomatoe", 50, 0.5) {}

		void ShowIngredient() override { Ingredient::ShowIngredient(); }
	};

	class Leaves : public Ingredient {
	public:
		Leaves() : Ingredient("Leaves", 34, 0.1) {}

		void ShowIngredient() override { Ingredient::ShowIngredient(); }
	};

	//// can add

	class Mushrooms : public Ingredient {
	public:
		Mushrooms() : Ingredient("Mushrooms", 20, 0.7) {}

		void ShowIngredient() override { Ingredient::ShowIngredient(); }
	};

	class Sausage : public Ingredient {
	public:
		Sausage() : Ingredient("Sausage", 120, 1.7) {}

		void ShowIngredient() override { Ingredient::ShowIngredient(); }
	};

	class Butter : public Ingredient {
	public:
		Butter() : Ingredient("Butter", 175, 2) {}

		void ShowIngredient() override { Ingredient::ShowIngredient(); }
	};
}