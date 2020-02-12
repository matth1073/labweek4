#include "checkingmodule.h"
#include <iostream>
#include <string>

using namespace std; 


char menu()
{
	char choice; 
	while (true) {
		cout << "Main Menu (Enter one of the following)" << endl;
		cout << "\t(D)eposit, (W)ithdrawal, (L)oan, (Q)uit" << endl << endl;
		cout << "\tChoice ==> "; cin >> choice; choice = tolower(choice); cout << endl;
		if (choice == 'd' || choice == 'w' || choice == 'l' || choice == 'q') {
			return choice;
		}
		else {
			cout << "Please enter a valid choice" << endl << endl; 
		}
	}
}

void deposit(float& account, float amount){
	account += amount;
}

void withdrawal(float& account, float amount)
{
	account -= amount; 
}

int getCreditScore()
{
	int creditScore; 
	while (true) {
		cout << "What is your credit rating ? [300 - 850] ==> " << endl;
		cin >> creditScore; cout << endl; 
		if (creditScore >= 300 && creditScore <= 850) {
			return creditScore;
		}
		else {
			cout << "Invalid credit score, choose value from 300 to 850" << endl << endl; 
		}

	}
}

int getLoanMonths()
{
	int loanMonths;
	while (true) {
		cout << "How many months for the loan? ==> "; cin >> loanMonths; cout << endl;
		switch (loanMonths) {
			case 12:
			case 24:
			case 36:
			case 60:
				return loanMonths;
		}
		cout << "Invalid loanMonths" << endl; 
	}
}

float getInterestRate(int creditScore)
{
	if (creditScore >= 300 && creditScore <= 500) {
		return 0.05;
	}
	else if (creditScore > 500 && creditScore <= 700) {
		return 0.03;
	}
	else if (creditScore > 700 && creditScore <= 850) {
		return 0.01;
	}
}

float validAmount(string prompt)
{
	float amount; 
	while (true) {
		cout << "How much do you want to " << prompt << "==> "; cin >> amount;
		if (amount < 0) {
			cout << "You must enter an amount greater than ZERO" << endl; 
		}
		else {
			cout << endl; 
			return amount; 
		}
	}
}

float validAmount(float& account, string prompt)
{
	float amount; 
	while (true) {
		cout << "Amount currently in account $" << account << endl;
		cout << "How much do you want to " << prompt << "==> "; cin >> amount;
		if (amount < 0) {
			cout << "You must enter an amount greater than ZERO" << endl;
			continue; 
		}
		else if (amount > account) {
			cout << "Insufficient funds, please try again" << endl; 
		}
		else {
			return amount; 
		}
	}
}

void calculateLoan(float amount, int creditScore, float interestRate, int loanMonths)
{
	float loanAmount; 
	cout << "Credit Score : " << creditScore << endl; 
	cout << "Interest Rate : " << interestRate << endl;
	cout << "Principal : " << amount << endl; 
	cout << "Months : " << loanMonths << endl; 
	cout << "Your total loan amount is "; 
	loanAmount = amount * pow((1 + interestRate / 12), (loanMonths / 12));
	cout << loanAmount << endl;
}

void outputAccount(float account)
{
	cout << endl; 
	cout << "\tAccount Balance" << endl;
	cout << "\t===============" << endl;
	cout << "\t" << account << endl << endl; 
}
