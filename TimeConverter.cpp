///////////////////////////////////////////////////////////////////////////////Time Converter/////////////////////////////////////////////////////////////////////////
//http://www.cplusplus.com/forum/beginner/229109/ --> Find if value is inside an array.
//http://softpixel.com/~cwright/programming/datatypes.c.php --> Fix for very huge numbers as input/output.
//Formulas used to calculate everything are from the internet so some may not be 100% accurate.
//https://stackoverflow.com/questions/32980467/validate-input-using-regex --> Check if input is numeric.
//https://stackoverflow.com/questions/30306993/integer-matching-regex-pattern-not-working --> Check if input is 'int'.
//https://stackoverflow.com/questions/7663709/how-can-i-convert-a-stdstring-to-int --> Convert 'string' to 'int'.
//https://stackoverflow.com/questions/17341870/correct-use-of-stdcout-precision-not-printing-trailing-zeros --> Set number of trailing symbols after decimal point.
//https://stackoverflow.com/questions/18041615/keep-looping-until-user-enters-a-blank-line --> Fix for empty input when user presses only the ENTER key on each step.
//https://stackoverflow.com/questions/2310939/remove-last-character-from-c-string --> Remove last char from string.

#include <iostream>
#include <string>
#include <regex>
#include <iomanip>

#define N 11

using namespace std;

int calculate(string, string, long long int, long long int);

int main() {
	cout << "This program can convert between the following time measurements: " << endl;
	cout << endl;
	cout << "milliseconds" << endl;
	cout << "seconds" << endl;
	cout << "minutes" << endl;
	cout << "hours" << endl;
	cout << "days" << endl;
	cout << "weeks" << endl;
	cout << "months" << endl;
	cout << "years" << endl;
	cout << "decades" << endl;
	cout << "centuries" << endl;
	cout << "millennia" << endl;
	cout << endl;
	string arr[N] = { "milliseconds", "seconds", "minutes", "hours", "days", "weeks", "months", "years", "decades", "centuries", "millennia" };
	string from = "";
	do
	{
		cout << "Please enter a measurement from the list from which to convert from: ";
		getline(cin, from);
	} while (find(begin(arr), end(arr), from) == end(arr) || from.empty());
	string to;
	do
	{
		cout << "Please enter a measurement from the list to which to convert to: ";
		getline(cin, to);
	} while (find(begin(arr), end(arr), to) == end(arr) || to.empty());
	long long int value = 0;
	string input = "";
	regex regexValueNumber("^(0|[1-9][0-9]*)$");
	bool isValueANumber = regex_match(input, regexValueNumber);
	do
	{
		cout << "Please input an integer value for the measurement: ";
		getline(cin, input);
		isValueANumber = regex_match(input, regexValueNumber);
	} while (!isValueANumber || input.empty());
	value = stoi(input);
	long long int precision = 0;
	string trailingDigits = "";
	regex regexPrecisionNumberInt("^(0|[1-9][0-9]*)$");
	bool isPrecisionAnInt = regex_match(trailingDigits, regexPrecisionNumberInt);
	do
	{
		cout << "Please input an integer value for the precision: ";
		getline(cin, trailingDigits);
		isPrecisionAnInt = regex_match(trailingDigits, regexPrecisionNumberInt);
	} while (!isPrecisionAnInt || trailingDigits.empty());
	precision = stoi(trailingDigits);
	cout << endl;
	cout << "Converting " << value << " from " << from << " to " << to << " with precision " << precision << "." << endl;
	cout << endl;
	calculate(from, to, value, precision);
	system("pause");

	return 0;
}

int calculate(string from, string to, long long int value, long long int precision) {
	long double result = 0.0;
	string fromText = "";
	string toText = "";

	// Milliseconds to everything else.
	if ((from == "milliseconds") && (to == "seconds")) {
		result = value / 1000.0;
	}
	else if ((from == "milliseconds") && (to == "minutes")) {
		result = value / 60000.0;
	}
	else if ((from == "milliseconds") && (to == "hours")) {
		result = value / 3600000.0;
	}
	else if ((from == "milliseconds") && (to == "days")) {
		result = value / 86400000.0;
	}
	else if ((from == "milliseconds") && (to == "weeks")) {
		result = value / 604800000.0;
	}
	else if ((from == "milliseconds") && (to == "months")) {
		result = value / 2629740000.0;
	}
	else if ((from == "milliseconds") && (to == "years")) {
		result = value / 31556900000.0;
	}
	else if ((from == "milliseconds") && (to == "decades")) {
		result = value / 315360000000.0;
	}
	else if ((from == "milliseconds") && (to == "centuries")) {
		result = value / 3153600000000.0;
	}
	else if ((from == "milliseconds") && (to == "millennia")) {
		result = value / 31536000000000.0;
	}

	if (from == "milliseconds") {
		if (value == 1) {
			fromText = "millisecond";
		}
		else {
			fromText = "milliseconds";
		}
		if (round(result) == 1.0) {
			if ((to != "millennia") || (to != "centuries")) {
				toText = to.substr(0, to.length() - 1);
			}
			if (to == "millennia")
			{
				toText = "millennium";
			}
			if (to == "centuries") {
				toText = "century";
			}
		}
		else {
			toText = to;
		}
	}

	// Seconds to everything else.
	if ((from == "seconds") && (to == "milliseconds")) {
		result = value * 1000.0;
	}
	else if ((from == "seconds") && (to == "minutes")) {
		result = value / 60.0;
	}
	else if ((from == "seconds") && (to == "hours")) {
		result = value / 3600.0;
	}
	else if ((from == "seconds") && (to == "days")) {
		result = value / (24 * 3600.0);
	}
	else if ((from == "seconds") && (to == "weeks")) {
		result = value / 604800.0;
	}
	else if ((from == "seconds") && (to == "months")) {
		result = value / 2629740.0;
	}
	else if ((from == "seconds") && (to == "years")) {
		result = value / 31556900.0;
	}
	else if ((from == "seconds") && (to == "decades")) {
		result = value / 315360000.0;
	}
	else if ((from == "seconds") && (to == "centuries")) {
		result = value / 3153600000.0;
	}
	else if ((from == "seconds") && (to == "millennia")) {
		result = value / 31536000000.0;
	}

	if (from == "seconds") {
		if (value == 1) {
			fromText = "second";
		}
		else {
			fromText = "seconds";
		}
		if (round(result) == 1.0) {
			if ((to != "millennia") || (to != "centuries")) {
				toText = to.substr(0, to.length() - 1);
			}
			if (to == "millennia")
			{
				toText = "millennium";
			}
			if (to == "centuries") {
				toText = "century";
			}
		}
		else {
			toText = to;
		}
	}

	// Minutes to everything else.
	if ((from == "minutes") && (to == "milliseconds")) {
		result = value * 60000.0;
	}
	else if ((from == "minutes") && (to == "seconds")) {
		result = value / 0.016667;
	}
	else if ((from == "minutes") && (to == "hours")) {
		result = value / 60.0;
	}
	else if ((from == "minutes") && (to == "days")) {
		result = value * 0.000694;
	}
	else if ((from == "minutes") && (to == "weeks")) {
		result = value / 10.080;
	}
	else if ((from == "minutes") && (to == "months")) {
		result = value / 43829.0;
	}
	else if ((from == "minutes") && (to == "years")) {
		result = value / 525948.3;
	}
	else if ((from == "minutes") && (to == "decades")) {
		result = value / 5259487.66;
	}
	else if ((from == "minutes") && (to == "centuries")) {
		result = value / 52594870.66;
	}
	else if ((from == "minutes") && (to == "millennia")) {
		result = value / 525948700.66;
	}

	if (from == "minutes") {
		if (value == 1) {
			fromText = "minute";
		}
		else {
			fromText = "minutes";
		}
		if (round(result) == 1.0) {
			if ((to != "millennia") || (to != "centuries")) {
				toText = to.substr(0, to.length() - 1);
			}
			if (to == "millennia")
			{
				toText = "millennium";
			}
			if (to == "centuries") {
				toText = "century";
			}
		}
		else {
			toText = to;
		}
	}

	// Hours to everything else.
	if ((from == "hours") && (to == "milliseconds")) {
		result = value * 3600000.0;
	}
	else if ((from == "hours") && (to == "seconds")) {
		result = (value * 3600000) / 1000.0;
	}
	else if ((from == "hours") && (to == "minutes")) {
		result = value * 60.0;
	}
	else if ((from == "hours") && (to == "days")) {
		result = value * 0.041667;
	}
	else if ((from == "hours") && (to == "weeks")) {
		result = value * 0.005952;
	}
	else if ((from == "hours") && (to == "months")) {
		result = value * 0.001369;
	}
	else if ((from == "hours") && (to == "years")) {
		result = value * 0.000114;
	}
	else if ((from == "hours") && (to == "decades")) {
		result = value / 87600.0;
	}
	else if ((from == "hours") && (to == "centuries")) {
		result = value / 876000.0;
	}
	else if ((from == "hours") && (to == "millennia")) {
		result = value / 8760000.0;
	}

	if (from == "hours") {
		if (value == 1) {
			fromText = "hour";
		}
		else {
			fromText = "hours";
		}
		if (round(result) == 1.0) {
			if ((to != "millennia") || (to != "centuries")) {
				toText = to.substr(0, to.length() - 1);
			}
			if (to == "millennia")
			{
				toText = "millennium";
			}
			if (to == "centuries") {
				toText = "century";
			}
		}
		else {
			toText = to;
		}
	}

	// Days to everything else.
	if ((from == "days") && (to == "milliseconds")) {
		result = value * 86400000.0;
	}
	else if ((from == "days") && (to == "seconds")) {
		result = value * 86400.0;
	}
	else if ((from == "days") && (to == "minutes")) {
		result = value * 1440.0;
	}
	else if ((from == "days") && (to == "hours")) {
		result = value / 0.041667;
	}
	else if ((from == "days") && (to == "weeks")) {
		result = value * 0.142857;
	}
	else if ((from == "days") && (to == "months")) {
		result = value * 0.032855;
	}
	else if ((from == "days") && (to == "years")) {
		result = value * 0.002738;
	}
	else if ((from == "days") && (to == "decades")) {
		result = value / 3652.42;
	}
	else if ((from == "days") && (to == "centuries")) {
		result = value / 36520.42;
	}
	else if ((from == "days") && (to == "millennia")) {
		result = value / 365200.42;
	}

	if (from == "days") {
		if (value == 1) {
			fromText = "day";
		}
		else {
			fromText = "days";
		}
		if (round(result) == 1.0) {
			if ((to != "millennia") || (to != "centuries")) {
				toText = to.substr(0, to.length() - 1);
			}
			if (to == "millennia")
			{
				toText = "millennium";
			}
			if (to == "centuries") {
				toText = "century";
			}
		}
		else {
			toText = to;
		}
	}

	// Weeks to everything else.
	if ((from == "weeks") && (to == "milliseconds")) {
		result = value * 604800000.0;
	}
	else if ((from == "weeks") && (to == "seconds")) {
		result = value * 604800.0;
	}
	else if ((from == "weeks") && (to == "minutes")) {
		result = value * 10080.0;
	}
	else if ((from == "weeks") && (to == "hours")) {
		result = value * 168.0;
	}
	else if ((from == "weeks") && (to == "days")) {
		result = value * 7.0;
	}
	else if ((from == "weeks") && (to == "months")) {
		result = value * 0.229985;
	}
	else if ((from == "weeks") && (to == "years")) {
		result = value * 0.019165;
	}
	else if ((from == "weeks") && (to == "decades")) {
		result = value / 521.775;
	}
	else if ((from == "weeks") && (to == "centuries")) {
		result = value / 5210.775;
	}
	else if ((from == "weeks") && (to == "millennia")) {
		result = value / 52100.775;
	}

	if (from == "weeks") {
		if (value == 1) {
			fromText = "week";
		}
		else {
			fromText = "weeks";
		}
		if (round(result) == 1.0) {
			if ((to != "millennia") || (to != "centuries")) {
				toText = to.substr(0, to.length() - 1);
			}
			if (to == "millennia")
			{
				toText = "millennium";
			}
			if (to == "centuries") {
				toText = "century";
			}
		}
		else {
			toText = to;
		}
	}

	// Months to everything else.
	if ((from == "months") && (to == "milliseconds")) {
		result = value * 2629740000.0;
	}
	else if ((from == "months") && (to == "seconds")) {
		result = value * 2629740.0;
	}
	else if ((from == "months") && (to == "minutes")) {
		result = value * 43829.0;
	}
	else if ((from == "months") && (to == "hours")) {
		result = value * 730.483333;
	}
	else if ((from == "months") && (to == "days")) {
		result = value * 30.436806;
	}
	else if ((from == "months") && (to == "weeks")) {
		result = value * 4.348115;
	}
	else if ((from == "months") && (to == "years")) {
		result = value * 0.083333;
	}
	else if ((from == "months") && (to == "decades")) {
		result = value / 120.0;
	}
	else if ((from == "months") && (to == "centuries")) {
		result = value / 1200.0;
	}
	else if ((from == "months") && (to == "millennia")) {
		result = value / 12000.0;
	}

	if (from == "months") {
		if (value == 1) {
			fromText = "month";
		}
		else {
			fromText = "months";
		}
		if (round(result) == 1.0) {
			if ((to != "millennia") || (to != "centuries")) {
				toText = to.substr(0, to.length() - 1);
			}
			if (to == "millennia")
			{
				toText = "millennium";
			}
			if (to == "centuries") {
				toText = "century";
			}
		}
		else {
			toText = to;
		}
	}

	// Years to everything else.
	if ((from == "years") && (to == "milliseconds")) {
		result = value * 31556900000.0;
	}
	else if ((from == "years") && (to == "seconds")) {
		result = value * 31556900.0;
	}
	else if ((from == "years") && (to == "minutes")) {
		result = value * 525948.333333;
	}
	else if ((from == "years") && (to == "hours")) {
		result = value * 8765.805556;
	}
	else if ((from == "years") && (to == "days")) {
		result = value * 365.241898;
	}
	else if ((from == "years") && (to == "weeks")) {
		result = value * 52.177414;
	}
	else if ((from == "years") && (to == "months")) {
		result = value * 12.000008;
	}
	else if ((from == "years") && (to == "decades")) {
		result = value / 10.0;
	}
	else if ((from == "years") && (to == "centuries")) {
		result = value / 100.0;
	}
	else if ((from == "years") && (to == "millennia")) {
		result = value / 1000.0;
	}

	if (from == "years") {
		if (value == 1) {
			fromText = "year";
		}
		else {
			fromText = "years";
		}
		if (round(result) == 1.0) {
			if ((to != "millennia") || (to != "centuries")) {
				toText = to.substr(0, to.length() - 1);
			}
			if (to == "millennia")
			{
				toText = "millennium";
			}
			if (to == "centuries") {
				toText = "century";
			}
		}
		else {
			toText = to;
		}
	}

	// Decades to everything else.
	if ((from == "decades") && (to == "milliseconds")) {
		result = value * 315360000000.0;
	}
	else if ((from == "decades") && (to == "seconds")) {
		result = value * 315360000.0;
	}
	else if ((from == "decades") && (to == "minutes")) {
		result = value * 5259487.66;
	}
	else if ((from == "decades") && (to == "hours")) {
		result = value * 87600.0;
	}
	else if ((from == "decades") && (to == "days")) {
		result = value * 3652.42;
	}
	else if ((from == "decades") && (to == "weeks")) {
		result = value * 521.775;
	}
	else if ((from == "decades") && (to == "months")) {
		result = value * 120.0;
	}
	else if ((from == "decades") && (to == "years")) {
		result = value * 10.0;
	}
	else if ((from == "decades") && (to == "centuries")) {
		result = value / 10.0;
	}
	else if ((from == "decades") && (to == "millennia")) {
		result = value / 100.0;
	}

	if (from == "decades") {
		if (value == 1) {
			fromText = "decade";
		}
		else {
			fromText = "decades";
		}
		if (round(result) == 1.0) {
			if ((to != "millennia") || (to != "centuries")) {
				toText = to.substr(0, to.length() - 1);
			}
			if (to == "millennia")
			{
				toText = "millennium";
			}
			if (to == "centuries") {
				toText = "century";
			}
		}
		else {
			toText = to;
		}
	}

	// Centuries to everything else.
	if ((from == "centuries") && (to == "milliseconds")) {
		result = value * 3153600000000.0;
	}
	else if ((from == "centuries") && (to == "seconds")) {
		result = value * 3155760000.0;
	}
	else if ((from == "centuries") && (to == "minutes")) {
		result = value * 52594870.66;
	}
	else if ((from == "centuries") && (to == "hours")) {
		result = value * 876000.0;
	}
	else if ((from == "centuries") && (to == "days")) {
		result = value * 36500.0;
	}
	else if ((from == "centuries") && (to == "weeks")) {
		result = value * 5214.2857142857;
	}
	else if ((from == "centuries") && (to == "months")) {
		result = value * 1200.0;
	}
	else if ((from == "centuries") && (to == "years")) {
		result = value * 100.0;
	}
	else if ((from == "centuries") && (to == "decades")) {
		result = value * 10.0;
	}
	else if ((from == "centuries") && (to == "millennia")) {
		result = value / 10.0;
	}

	if (from == "centuries") {
		if (value == 1) {
			fromText = "century";
		}
		else {
			fromText = "centuries";
		}
		if (round(result) == 1.0) {
			if ((to != "millennia") || (to != "centuries")) {
				toText = to.substr(0, to.length() - 1);
			}
			if (to == "millennia")
			{
				toText = "millennium";
			}
			if (to == "centuries") {
				toText = "century";
			}
		}
		else {
			toText = to;
		}
	}

	// Millennia to everything else.
	if ((from == "millennia") && (to == "milliseconds")) {
		result = value * 31536000000000.0;
	}
	else if ((from == "millennia") && (to == "seconds")) {
		result = value * 31536000000.0;
	}
	else if ((from == "millennia") && (to == "minutes")) {
		result = value * 525948700.66;
	}
	else if ((from == "millennia") && (to == "hours")) {
		result = value * 8760000.0;
	}
	else if ((from == "millennia") && (to == "days")) {
		result = value * 365200.42;
	}
	else if ((from == "millennia") && (to == "weeks")) {
		result = value * 52100.775;
	}
	else if ((from == "millennia") && (to == "months")) {
		result = value * 12000.0;
	}
	else if ((from == "millennia") && (to == "years")) {
		result = value * 1000.0;
	}
	else if ((from == "millennia") && (to == "decades")) {
		result = value * 100.0;
	}
	else if ((from == "millennia") && (to == "centuries")) {
		result = value * 10.0;
	}

	if (from == "millennia") {
		if (value == 1) {
			fromText = "millennium";
		}
		else {
			fromText = "millennia";
		}
		if (round(result) == 1.0) {
			if ((to != "millennia") || (to != "centuries")) {
				toText = to.substr(0, to.length() - 1);
			}
			if (to == "millennia")
			{
				toText = "millennium";
			}
			if (to == "centuries") {
				toText = "century";
			}
		}
		else {
			toText = to;
		}
	}

	cout << fixed;
	cout << setprecision(precision);
	cout << value << " " << fromText << " = " << result << " " << toText << endl;

	return 0;
}