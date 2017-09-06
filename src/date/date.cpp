// date.cpp
// Implementation of the Date class

#include "date.h"

Date::Date(int D, Month M,int Y)
{
	if(D > 31) throw InvalidDate();
	if((isLeapYear(Y) == false) && (D > 28) && (M == Month::February)) throw InvalidDate();
	if((M == Month::February || M ==  Month::April || M ==  Month::June || M ==  Month::September || M == Month::November) && D > 30) throw InvalidDate();

	_day = D;
	_month = M;
	_year = Y;
}

int Date::day() const
{
	return _day;
}

Month Date::month() const
{
    return _month;
}

int Date::year() const
{
	return _year;
}

bool Date::isLeapYear() const
{
    // leap years must be divisible by 4 but not by 100
    // or divisible by 400
    if(((_year % 4 == 0) && (_year % 100 != 0)) || (_year % 400 == 0))
        return true;
    else
        return false;
}

int Date::daysInMonth() const
{
	switch (_month) {
		case Month::January: 
		case Month::March: 
		case Month::May: 
		case Month::July:
		case Month::August: 
		case Month::October: 
		case Month::December:
			return 31;	
		case Month::April: 
		case Month::June: 
		case Month::September:
		case Month::November:
			return 30;	
		case Month::February:
			if ( isLeapYear() ) return 29;
			else return 28;
		default:
			// should never reach here 
			assert(false); // See: http://www.cplusplus.com/reference/cassert/assert/
            return -1;
	}    
}

// Note, this standalone function is not part of the Date class
void printDate(const Date& date)
{
	cout << date.day() << "/"
		// cast to an integer to allow the month to be sent to the stream
        << static_cast<int>(date.month()) << "/"
		<< date.year()
		<< endl;
}

bool Date::isLeapYear(auto year)
{
	if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        return true;
	else
        return false;
}

bool Date::operator==(const Date& rhs) const
{
	bool condition = false;
	if(_day == rhs._day)
	{
		if(_month == rhs._month)
		{
			if(_year == rhs._year)
			{
				condition = true;
			}
		}
	}
			
	if(condition == true)
		return true;
	else
		return false;
}