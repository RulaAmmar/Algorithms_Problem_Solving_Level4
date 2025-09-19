

#include <iostream>
using namespace std;

short ReadYear() {
    cout << "Please enter a year ?";
    short Year;
    cin >> Year;
    return Year;
}

short ReadMonth() {
    cout << "\nPlease enter a month?";
    short Month;
    cin >> Month;
    return Month;
}

short ReadDay() {
    cout << "\nPlease enter a day? ";
    short Day;
    cin >> Day;
    return Day;
}

void PrintDate(short Day, short Month, short Year) {
    cout <<"\n" <<"Date       :" <<Day << "/" << Month << "/" << Year << "\n";
}

short DayOrder(short Day,short Month,short Year) {

    short a,y,m;

    a = (14 - Month) / 12;

    y = Year - a;

    m = Month + (12 * a) - 2;

   return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

string DayName(short DayOrder) {

    string DaysName[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

    return DaysName[DayOrder];
}

int main()

{
    system("color 89");

    short Year = ReadYear();

    short Month = ReadMonth();

    short Day = ReadDay();

    PrintDate(Day, Month, Year);

    short DayOfWeekOrder = DayOrder(Day, Month, Year);

    cout <<"Day Order  : " <<DayOfWeekOrder<<"\n";

    cout << "Day Name   :" << DayName(DayOfWeekOrder)<<endl;
}

