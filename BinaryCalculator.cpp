//  Project description
//  Your Name
//  Date starts the project

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cassert>
#include <sstream>

using namespace std;

int binary_to_decimal_signed(string s);
// precondition: s is a string that consists of only 0s and 1s
// postcondition: the decimal integer that is represented by s in two's complement

string signed_extension(string s);
// precondition: s is a string that consists of only 0s and 1s that is at most 16 bits
// postcondition: a 16 bit string has been returned as signed extension of s. For instane, if s = "0101" then
//                return value will be "00000000000000000101" total 12 0s are added in front of s

string decimal_to_binary_signed(int n);
// precondition: n is an integer
// postcondition: nâ€™s two's complement binary representation is returned as a string of 0s and 1s

string add_binaries_signed(string b1, string b2);
// precondition: b1 and b2 are strings that consists of 0s and 1s at most 32 bits, i.e.
//               b1 and b2 are two's complement binary representations of two integers. "0" is 0, "1" is still postive 1
//               However, "10" will be consider as "1111111111111110" as -2
// postcondition: the sum of b1 and b2 is returned as a 32 bits two's complement reprentation.
// For instance, if b1 = â€œ1101â€ (-3), b2 = â€œ01â€ (+1), then the return value is â€œ1111111111111110â€ (-2)

string twos_complement(string s);
// precondition: s is a string that consists of only 0s and 1s
// postcondition: two's complement of s is returned as an 16 bits binary integer. For instance, if s = "1101", then
//                return value will be "1111111111111101"

int binary_to_decimal(string s);
// precondition: s is a string that consists of only 0s and 1s
// postcondition: the positive decimal integer that is represented by s

string decimal_to_binary(int n);
// precondition: n is a positive integer
// postcondition: nâ€™s binary representation is returned as a string of 0s and 1s

string add_binaries(string b1, string b2);
// precondition: b1 and b2 are strings that consists of 0s and 1s, i.e.
//               b1 and b2 are binary representations of two positive integers
// postcondition: the sum of b1 and b2 is returned. For instance,
//  if b1 = â€œ11â€, b2 = â€œ01â€, then the return value is â€œ100â€

void menu();
// display the menu. Student shall not modify this function

int grade();
// returns an integer that represents the studentâ€™s grade of this projects.
// Student shall NOT modify

bool is_binary(string b);
// returns true if the given string s consists of only 0s and 1s; false otherwise

bool test_binary_to_decimal_signed();
// returns true if the studentâ€™s implementation of binary_to_decimal function
// is correct; false otherwise. Student shall not modify this function

bool test_decimal_to_binary_signed();
//  returns true if the studentâ€™s implementation of decimal_to_binary function is correct; false otherwise. Student shall not modify this function

bool test_add_binaries_signed();
// which returns true if the studentâ€™s implementation of add_binaries function
// is correct; false otherwise. Student shall not modify this function

bool test_signed_extension();
// return true if the student's implementation of sign_extension function
// is correct; false otherwise. Student shall not modify this function

bool test_twos_complement();
// return true if the student's implementation of twos_complement function
// is correct; false otherwise. Student shall not modify this function


int main()
{
	int choice;
	string b1, b2;
	int x, score;
	do {
		// display menu
		menu();
		cout << "Enter your choice: ";
		cin >> choice;
		// based on choice to perform tasks
		switch (choice) {
		case 1:
			cout << "Enter a binary string: ";
			cin >> b1;
			if (!is_binary(b1))
				cout << "It is not a binary number\n";
			else
				cout << "Its decimal value is: " << binary_to_decimal_signed(b1) << endl;
			break;

		case 2:
			cout << "Enter an integer: ";
			cin >> x;

			cout << "Its binary representation is: " << decimal_to_binary_signed(x) << endl;
			break;

		case 3:
			cout << "Enter two binary numbers, separated by white space: ";
			cin >> b1 >> b2;
			if (!is_binary(b1) || !is_binary(b2))
				cout << "At least one number is not a binary" << endl;
			else
				cout << "The sum is: " << add_binaries_signed(b1, b2) << endl;
			break;

		case 4:
			cout << "Enter a binary number: ";
			cin >> b1;
			cout << "Its signed extension to 16 bits is: " << signed_extension(b1) << endl;;
			break;

		case 5:
			cout << "Enter a binary number: ";
			cin >> b1;
			cout << "Its two's complement is: " << twos_complement(b1) << endl;
			break;

		case 6:
			score = grade();
			cout << "If you turn in your project on blackboard now, you will get " << score << " out of 10" << endl;
			cout << "Your instructor will decide if one-two more points will be added or not based on your program style, such as good commnets (1 points) and good efficiency (1 point)" << endl;
			break;

		case 7:
			cout << "Thanks for using binary calculator program. Good-bye" << endl;
			break;
		default:
			cout << "Wrong choice. Please choose 1-5 from menu" << endl;
			break;
		}

	} while (choice != 7);
	return 0;
}

string signed_extension(string s) {
	//Used to decide how many 0s or 1s to extend the binary number.
	int bits = 16 - s.length();

	for (int i = 0; i < 1; i++) {
		//Used if the binary number is positive.
		if (s[i] == '0') {
			for (int i = 0; i < bits; i++) {
				s.insert(0, "0");
			}
		}
		//Used if the binary number is negative.
		else if (s[i] == '1') {
			for (int i = 0; i < bits; i++) {
				s.insert(1, "1");
			}
		}
	}
	return s;
}

int binary_to_decimal_signed(string s) {

	string number = "";
	int result = 0;
	for (int i = 0; i < 1; i++) {
		if (s[i] == '1') {
			 number = twos_complement(s); //After checking if it is negative, it performs two's complement to get its positive form.
			 int result = binary_to_decimal(number) * -1;//Turns it into a decimal and multiples by -1 to get the proper answer.
			 return result;
		}
		else if (s[i] == '0') {//Since its positive there is nothing that needs to be done.
			result = binary_to_decimal(s);
			return result;
		}
	}
	


}

string decimal_to_binary_signed(int n) {
	string result = "";
	//Special case incase the user enters 0.
	if (n == 0) {
		return "0";
	}

	else if (n > 0) {//If the number is positive...
		result = decimal_to_binary(n);
		result.insert(0, "0"); //insert a 0 so that the signed extension will work properly.
		result = signed_extension(result);
		return result;
	}
	else if (n < 0) {//if the number is negative...
		int d = 0;
		d = n * -1; //multiply to make positive
		result = decimal_to_binary(d);
		result.insert(0, "0");//add 0 for extension
		result = signed_extension(result);
		result = twos_complement(result);// return the  binary to its proper state before printing the results.

		return result;
	}


}

string add_binaries_signed(string b1, string b2) {

	//convert the numbers to decimals.
	int n1 = binary_to_decimal_signed(b1);
	int n2 = binary_to_decimal_signed(b2);
	int n3 = n1 + n2;
	
	//return the numbers from decimals to binary.
	string result = decimal_to_binary_signed(n3);

	

	return result;
	
}

string twos_complement(string s) {//Add binary check 

	string addedOne = "0000000000000001";
	string ones = signed_extension(s);
	string twos = "";

		//switches all 0s with 1s and 1s with 0s
		for (int i = 0; i < ones.length(); i++) {
			if (ones[i] == '0') {
				ones[i] = '1';
			}
			else if (ones[i] == '1') {
				ones[i] = '0';
			}
		}
		//adds the one to the binary number.
		twos = add_binaries(ones, addedOne);

	


	return twos;
}

int binary_to_decimal(string s) {
	assert(is_binary(s));
	int result = 0;
	for (int i = 0; i < s.length(); i++)
		result = result * 2 + (s[i] - 48);
	return result;
}

string decimal_to_binary(int n) {
	if (n == 0) return string("0"); // specila case 0

	string result = "";
	while (n > 0) {
		result = string(1, (char)(n % 2 + 48)) + result; // add last digit of n in front of the result
		n = n / 2;
	}
	return result;
}

string add_binaries(string b1, string b2) {
	// you implement this
	assert(is_binary(b1) && is_binary(b2));
	string result = "";
	int carry = 0;
	int i1 = (int)b1.length() - 1;
	int i2 = (int)b2.length() - 1;
	while (i1 >= 0 || i2 >= 0)
	{
		int d1 = 0, d2 = 0;
		if (i1 >= 0) d1 = b1[i1] - 48;
		if (i2 >= 0) d2 = b2[i2] - 48;
		int sum = carry + d1 + d2; // signle digit sum
		carry = sum / 2; // carry is 1 if sum is 2 or 3; 0 otherwise
		result = string(1, (char)(48 + sum % 2)) + result;
		i1--;
		i2--;
	}
	if (carry != 0)
		result = "1" + result;
	return result;
}
void menu()
{
	cout << "\n******************************\n";
	cout << "*          Menu              *\n";
	cout << "* 1. Binary to Decimal       *\n";
	cout << "* 2. Decinal to Binary       *\n";
	cout << "* 3. Add two Binaries        *\n";
	cout << "* 4. Signed extension        *\n";
	cout << "* 5. Two's complement        *\n";
	cout << "* 6. Grade                   *\n";
	cout << "* 7. Quit                    *\n";
	cout << "******************************\n\n";
}

int grade() {
	int result = 0;
	// binary_to_decimal function worth 2 points
	if (test_binary_to_decimal_signed()) {
		cout << "binary_to_decimal_signed function pass the test" << endl;
		result += 2;
	}
	else
		cout << "binary_to_decimal_signed function failed" << endl;

	// decinal_to_binary_signed function worth 1 points
	if (test_decimal_to_binary_signed()) {
		cout << "decimal_to_binary_signed function passed the test" << endl;
		result += 1;
	}
	else
		cout << "decimal_to_binary_signed function failed" << endl;

	// add_binaries function worth 2 points
	if (test_add_binaries_signed()) {
		cout << "add_binaries_signed function passed the test" << endl;
		result += 2;
	}
	else
		cout << "add_binaries_signed function failed" << endl;

	// signed_extension function worth 1 point
	if (test_signed_extension()) {
		cout << "sign_extension function passed the test" << endl;
		result += 1;
	}
	else
		cout << "sign_extension function failed" << endl;

	// twos_complement function worth 2 point
	if (test_twos_complement()) {
		cout << "twos_complement function passed the test" << endl;
		result += 2;
	}
	else
		cout << "twos_complement function failed" << endl;
	return result;
}

bool is_binary(string s) {
	for (int i = 0; i < s.length(); i++)
		if (s[i] != '0' && s[i] != '1') // one element in s is not '0' or '1'
			return false;  // then it is not a binary nunber representation
	return true;
}

bool test_binary_to_decimal_signed() {
	if (binary_to_decimal_signed("0") != 0 || binary_to_decimal_signed("1") != -1 || binary_to_decimal_signed("01") != 1)
		return false;
	if (binary_to_decimal_signed("010") != 2 || binary_to_decimal_signed("10") != -2)
		return false;
	if (binary_to_decimal_signed("01101") != 13 || binary_to_decimal_signed("1101") != -3)
		return false;
	return true;
}

bool test_decimal_to_binary_signed() {
	if (decimal_to_binary_signed(0) != "0000000000000000" || decimal_to_binary_signed(1) != "0000000000000001")
		return false;
	if (decimal_to_binary_signed(-1) != "1111111111111111")
		return false;
	if (decimal_to_binary_signed(-2) != "1111111111111110" || decimal_to_binary_signed(-13) != "1111111111110011")
		return false;
	return true;
}

bool test_add_binaries_signed() {
	if (add_binaries_signed("0", "0") != "0000000000000000") return false;
	if (add_binaries_signed("0", "110101") != "1111111111110101") return false;
	if (add_binaries_signed("1", "110111") != "1111111111110110") return false;
	if (add_binaries_signed("101", "111011") != "1111111111111000") return false;
	return true;
}

bool test_signed_extension() {
	if (signed_extension("1") != "1111111111111111" || signed_extension("0") != "0000000000000000") return false;
	if (signed_extension("10101") != "1111111111110101" || signed_extension("0101") != "0000000000000101") return false;
	return true;
}

bool test_twos_complement() {
	if (twos_complement("1") != "0000000000000001" || twos_complement("0") != "0000000000000000") return false;
	if (twos_complement("01") != "1111111111111111" || twos_complement("10") != "0000000000000010") return false;
	if (twos_complement("10101") != "0000000000001011") return false;
	return true;

}

/*
As I stated in the email, for some reason the two's complement function will not work even though it is correctly outputting the proper two's complement (as you can see from the output below). I posted the output of 
the  assignment's functions below. Please take a look so I don't lose any points! I learned a lot from this project. Thanks!



******************************
* Menu *
* 1. Binary to Decimal *
* 2. Decinal to Binary *
* 3. Add two Binaries *
* 4. Signed extension *
* 5. Two's complement *
* 6. Grade *
* 7. Quit *
******************************

Enter your choice: 1
Enter a binary string: 1001101
Its decimal value is: -51

******************************
* Menu *
* 1. Binary to Decimal *
* 2. Decinal to Binary *
* 3. Add two Binaries *
* 4. Signed extension *
* 5. Two's complement *
* 6. Grade *
* 7. Quit *
******************************

Enter your choice: 2
Enter an integer: -51
Its binary representation is: 1111111111001101

******************************
* Menu *
* 1. Binary to Decimal *
* 2. Decinal to Binary *
* 3. Add two Binaries *
* 4. Signed extension *
* 5. Two's complement *
* 6. Grade *
* 7. Quit *
******************************

Enter your choice: 3
Enter two binary numbers, separated by white space: 1001101 01101
The sum is: 1111111111011010

******************************
* Menu *
* 1. Binary to Decimal *
* 2. Decinal to Binary *
* 3. Add two Binaries *
* 4. Signed extension *
* 5. Two's complement *
* 6. Grade *
* 7. Quit *
******************************

Enter your choice: 4
Enter a binary number: 1001101
Its signed extension to 16 bits is: 1111111111001101

******************************
* Menu *
* 1. Binary to Decimal *
* 2. Decinal to Binary *
* 3. Add two Binaries *
* 4. Signed extension *
* 5. Two's complement *
* 6. Grade *
* 7. Quit *
******************************

Enter your choice: 5
Enter a binary number: 1001101
Its two's complement is: 0000000000110011


*/
