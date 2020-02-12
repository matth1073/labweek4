#pragma once
#include <string>
#include <iostream>

using namespace std; 

char menu(); 
void deposit(float& account, float amount);
void withdrawal(float& account, float amount);
int getCreditScore(); 
int getLoanMonths(); 
float getInterestRate(int creditScore);
float validAmount(string prompt);
float validAmount(float& account, string prompt);
void calculateLoan(float amount, int creditScore, float interestRate, int loanMonths);
void outputAccount(float account);