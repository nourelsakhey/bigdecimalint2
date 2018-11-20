#include "BigDecimalInt.h"


BigDecimalInt::BigDecimalInt(string decStr)
{
	s1 = decStr;
	if (s1[0] == '-')
	{
		s1.erase(0, 1);
		check = true;
	}
}
BigDecimalInt::BigDecimalInt(int decInt)
{

}
void BigDecimalInt::plusminusplus(BigDecimalInt anotherDec) {
	for (int i = s1.length() - 1; i >= 0; i--)
	{
		if (anotherDec.s1[i] > s1[i] - carry)
		{   number = (s1[i] - '0' - carry) + 10 - (anotherDec.s1[i] - '0');
			carry = 1;
		}
		else
		{
			number = (s1[i] - '0' - carry) - (anotherDec.s1[i] - '0');
		}
		temp = number + '0';
		decimal = temp + decimal;
	}
	decimal = '-' + decimal;
}
void BigDecimalInt::plusminusminus(BigDecimalInt anotherDec) {
	for (int i = s1.length() - 1; i >= 0; i--)
	{
		if (anotherDec.s1[i]-carry >= s1[i] )
			{
				number= (anotherDec.s1[i] - '0' )-carry  - (s1[i] - '0');		
			}
			else
			{
			number = (anotherDec.s1[i] - '0' - carry)+10 - (s1[i] - '0');
				carry = 1;
			}
			temp = number + '0';
			decimal = temp + decimal;
	}
	decimal = '-' + decimal;
}
void BigDecimalInt::minusplusminus(BigDecimalInt anotherDec) {
	for (int k = anotherDec.s1.length() - 1; k >= 0; k--)
	{
		if ((anotherDec.s1[k] - '0' + s1[k] - '0' + carry) >= 10)
		{
			number = (anotherDec.s1[k] - '0') + (s1[k] - '0') + carry - 10;
			carry = 1;
		}
		else
		{
			number = (anotherDec.s1[k] - '0' )+ (s1[k] - '0' )+ carry;
			carry = 0;
		}
		temp = number + '0';
		decimal = temp + decimal;
	}
	if (carry == 1) { 
		decimal = "1" + decimal;
		decimal = '-' + decimal;
	}
	else{
		decimal = '-' + decimal;
	}

}
void BigDecimalInt::plusplusplus(BigDecimalInt anotherDec){
	for (int k = anotherDec.s1.length() - 1; k >= 0; k--)
	{
		if ((anotherDec.s1[k] - '0' + s1[k] - '0' + carry) >= 10)
		{
			number = anotherDec.s1[k] - '0' + s1[k] - '0' + carry - 10;
			carry = 1;
		}
		else
		{
			number = anotherDec.s1[k] - '0' + s1[k] - '0' + carry;
			carry = 0;
		}
		temp = number + '0';
		decimal = temp + decimal;
	}
	if (carry == 1) {
		decimal = "1" + decimal;
	}
}
void equalsize(string s1, BigDecimalInt b2)
{
	if (s1.length() > b2.s1.length())
	{
		for (int i = 0; i <= (s1.length() - b2.s1.length()); i++)
		{
			b2.s1 = '0' + b2.s1;
		}
	}
	else if (s1.length() < b2.s1.length())
	{
		for (int i = 0; i <= (b2.s1.length() - s1.length()); i++)
		{
			s1 = '0' + s1;
		}
	}
}
bool checkbigger(string s1, BigDecimalInt b1)
{
	for (int i = 0; i < s1.length(); i++)
	{
		if (b1.s1[i] == s1[i])
			continue;
		else if (s1[i] > b1.s1[i])
			return true;
		else
			return false;
	}
	return true;
}
ostream& operator<< (ostream & out, BigDecimalInt b1)
{
	for (int j = 0;j < b1.s1.length(); j++)
	{
		out << b1.s1[j] << " ";
	}
	return out;
}
BigDecimalInt BigDecimalInt:: operator+ (BigDecimalInt anotherDec)
{
	equalsize(s1, anotherDec);
	if (!check && !anotherDec.check)
	{
		plusplusplus(anotherDec);
		return BigDecimalInt(decimal);
	}
	else if (!anotherDec.check && check)
	{
		if (checkbigger(s1, anotherDec) == true)
		{
			plusminusplus(anotherDec);
			return BigDecimalInt('-'+ decimal);
		}
		else {
			plusminusminus(anotherDec);
			return BigDecimalInt(decimal);
		}
			}
	else if (anotherDec.check && !check) {
		if (checkbigger(s1, anotherDec) == true)
		{			plusminusplus(anotherDec);
			return BigDecimalInt(decimal);
		}
		else {
			
				plusminusminus(anotherDec);
				return BigDecimalInt('-' + decimal);
		}
		
	}
	else if (anotherDec.check && check)
	{
		minusplusminus(anotherDec);
		return BigDecimalInt('-' + decimal);
	}
}
BigDecimalInt BigDecimalInt :: operator- (BigDecimalInt anotherDec)
{
	decimal = "";
	carry = 0;
	equalsize(s1, anotherDec);
	if (!anotherDec.check && !check)
		{
			if (checkbigger(s1, anotherDec) == true) {
				
				plusminusplus(anotherDec);
				return BigDecimalInt(decimal);
			}
		
			else {
				
				plusminusminus(anotherDec);
				return BigDecimalInt('-' + decimal);
			}
	}
	
	else if (anotherDec.check && !check)
	{
		plusplusplus(anotherDec);
		return BigDecimalInt( decimal);
	}
	else if (!anotherDec.check && check)
	{
		minusplusminus(anotherDec);
		return BigDecimalInt('-' + decimal);
	}
	else if (anotherDec.check && check)
		{
			if (checkbigger(s1, anotherDec) == true) {
				plusminusplus(anotherDec);
				return BigDecimalInt('-' + decimal);
			}
			else {
				plusminusminus(anotherDec);
				return BigDecimalInt( decimal);
			}
	}
}
BigDecimalInt::~BigDecimalInt()
{
}

