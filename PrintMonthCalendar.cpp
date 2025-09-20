

#include <iostream>
using namespace std;

short ReadYear() {
	cout << "Please enter a year ? ";
	short Year;
	cin >> Year;
	return Year;
}

short ReadMonth() {
	cout << "\nPlease enter a month ? ";
	short Month;
	cin >> Month;
	return Month;
}

string MonthShortName(short MonthNumber) {

	string arrMonthName[] = { "" ,"Jan", "Feb", "Mar", "Apr", "May", "Jun",
		"Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

	return arrMonthName[MonthNumber];
}

bool IsLeapYear(short Year) {
	
	return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
}

short NumberOfDaysInMonth(short Year,short Month) {

	if (Month < 1 || Month>12) {
		return 0;
	}

	short arrDaysMonth[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : arrDaysMonth[Month];
}

short DayOrder(short Day, short Month, short Year) {

	short a, y, m;

	a = (14 - Month) / 12;

	y = Year - a;

	m = Month + (12 * a) - 2;

	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

void PrintMonthCalendar(short Year,short Month) {

	printf("----------------%s----------------\n\n",MonthShortName(Month).c_str());

	cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat" << "\n";

	short Current = DayOrder(1, Month, Year);

	short NumberOfDays = NumberOfDaysInMonth(Year, Month);

	short i;

	for (i = 0; i < Current; i++) {//???
		cout << "     ";
	}

	for (short j = 1; j <= NumberOfDays; j++) {

		printf("%5d", j);

		if (++i == 7) {
			cout << "\n";
			i = 0;
		}
	}

	printf("\n-----------------------------------\n");
}

int main()
{
	system("color 60");

	short Year = ReadYear();

	short Month = ReadMonth();

	PrintMonthCalendar(Year,Month);
}


