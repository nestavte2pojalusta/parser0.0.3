#include "stdafx.h"

#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

int main()
{
	float result, num1, num2;
	char op1, op2 = '*';

	string stroka;
	getline(cin, stroka);
	stroka = "0" + stroka;

	istringstream stream(stroka);

	stream >> result;

	while (stream >> op1) {
		stream >> num1;

		if (op1 == '+') {
			result += num1;
			op2 = '+';
			num2 = num1;
		}

		else if (op1 == '-') {
			result -= num1;
			op2 = '-';
			num2 = num1;
		}

		else if ((op1 == '*') && (op2 == '*')) {
			result *= num1;
		}

		else if ((op1 == '/') && (op2 == '*')) {
			result /= num1;
		}

		else if ((op1 == '*') && (op2 == '+')) {
			result -= num2;
			num2 *= num1;
			result += num2;
			op2 = '+';
		}

		else if ((op1 == '*') && (op2 == '-')) {
			result += num2;
			num2 *= num1;
			result -= num2;
			op2 = '-';
		}

		else if ((op1 == '/') && (op2 == '+')) {
			result -= num2;
			num2 /= num1;
			result += num2;
			op2 = '+';
		}

		else if ((op1 == '/') && (op2 == '-')) {
			result += num2;
			num2 /= num1;
			result -= num2;
			op2 = '+';
		}

		else {
			cout << "Error";
			cin.get();
			return 0;
		}
	}

	cout << result;
	cin.get();
	system("pause");
	return 0;

}
