#include <iostream>
#include <string>
#include "checkingmodule.h"

using namespace std;

int main() {
	float account = 100.0f;
	float amount;
	string prompt; 
	char choice; 
	int creditScore; 
	float interestRate; 
	int loanMonths; 

	while (true) {
		choice = menu(); 
		if (choice == 'q') {
			cout << "Goodbye" << endl;
			break;
		}
		switch (choice){
			case 'd':
				amount = validAmount("deposit");
				deposit(account, amount);
				outputAccount(account);
				break;
		
			case 'w':
				amount = validAmount(account, "withdrawal");
				withdrawal(account, amount);
				outputAccount(account);
				break;

			case 'l':
				creditScore = getCreditScore();
				interestRate = getInterestRate(creditScore);
				loanMonths = getLoanMonths(); 
				amount = validAmount("borrow");
				calculateLoan(amount, creditScore, interestRate, loanMonths);
				break;
		}
	}


}