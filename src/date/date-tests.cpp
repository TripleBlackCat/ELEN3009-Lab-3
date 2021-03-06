#include "date.h"
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

// Exercise 2.1
// Comment out this test after inspecting the output.
// Tests which require manual verification should not be lumped
// with tests which are automatically verified!
//TEST_CASE("Date has uninitialised state") {	 
//    // make some prior memory allocations - which will be the case in a typical program
//    auto i = {1.0,1.3,1.4,1.5,1.6,1.7,1.8,1.9,10.2,11.0,1.2,1.3,1.23};
//    auto i2 = 1.0;
//    
//    Date today;	
//    std::cout << "Today is: " << endl;
//    printDate(today);
//}

// Write code to make this test pass
TEST_CASE("Valid Date is initialised correctly") {
	Date heritage_day{24, Month::September, 2000};
	CHECK(heritage_day.day() == 24);
	CHECK(heritage_day.month() == Month::September);
	CHECK(heritage_day.year() == 2000);
}


// Exercise 2.2
TEST_CASE("Invalid Date is rejected"){
	CHECK_THROWS_AS(Date testDate(99, Month::September, 2000), InvalidDate);
	CHECK_THROWS_AS(Date testDate(29, Month::February, 1999), InvalidDate);
	CHECK_THROWS_AS(Date testDate(31, Month::April, 1999), InvalidDate);
	CHECK_THROWS_AS(Date testDate(31, Month::June, 1999), InvalidDate);
	CHECK_THROWS_AS(Date testDate(31, Month::September, 1999), InvalidDate);
	CHECK_THROWS_AS(Date testDate(31, Month::November, 1999), InvalidDate);
}

// Exercise 2.3
TEST_CASE("Identical Dates are Equal") {
	Date date_1(1, Month::January, 2000);
	Date date_2(1, Month::January, 2000);
	CHECK(date_1 == date_2);	
}

TEST_CASE("Days do not Match"){
	Date date_1(28, Month::February, 2000);
	Date date_2(27, Month::February, 2000);
	CHECK_FALSE(date_1 == date_2);
}

TEST_CASE("Months do not Match"){
	Date date_1(5, Month::May, 1994);
	Date date_2(5, Month::April, 1994);
	CHECK_FALSE(date_1 == date_2);
}

TEST_CASE("Years do not Match"){
	Date date_1(5, Month::April, 1993);
	Date date_2(5, Month::April, 1994);
	CHECK_FALSE(date_1 == date_2);
}

// Exercise 2.4
TEST_CASE("Days Increase Correct"){
	Date date_1(1, Month::January, 2000);
	Date date_2(2, Month::January, 2000);
	date_1.increaseDay();
	CHECK(date_1 == date_2);
	
	Date date_3(31, Month::January, 2000);
	Date date_4(1, Month::February, 2000);
	date_3.increaseDay();
	CHECK(date_3 == date_4);
	
	Date date_5(31, Month::December, 1999);
	Date date_6(1, Month::January, 2000);
	date_5.increaseDay();
	CHECK(date_5 == date_6);
}


// Exercise 2.5
TEST_CASE("Default Constructors"){
	Date testDate1(1, Month::January, 1900);
	Date defaultDate1;
	CHECK(testDate1 == defaultDate1);
	
	Date::setDefaultDate(5,Month::August,1900);
	Date defaultDate2;
	Date testDate2(5, Month::August, 1900);
	CHECK(testDate2 == defaultDate2);
}
