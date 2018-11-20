#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class BigDecimalInt
{
private:
	int carry = 0;
	bool check = false;
	string s1;
	string decimal = "";
	char temp;
	string temp_2 = "1";
	int number;
public:
	BigDecimalInt(string decStr); // Initialize from string
	BigDecimalInt(int decInt); // Initialize from integer
	friend void equalsize(string, BigDecimalInt);
	friend bool checkbigger(string, BigDecimalInt);
	BigDecimalInt operator+ (BigDecimalInt anotherDec);
	BigDecimalInt operator- (BigDecimalInt anotherDec);
	friend ostream& operator<< (ostream & out, BigDecimalInt b1);
	void plusminusplus(BigDecimalInt anotherDec);//takes two postive and add them
	void plusminusminus(BigDecimalInt anotherDec);//takes a postive number and a negative number and add them
	void minusplusminus(BigDecimalInt anotherDec);
	void plusplusplus(BigDecimalInt anotherDec);

	virtual ~BigDecimalInt();

};


