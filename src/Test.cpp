#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include "large_numbers.h"

void testPrintLargeNumberOne() {

	std::ostringstream out{};
	printLargeDigit(1, out);
	std::string result = out.str();
	ASSERT_EQUAL("   \n  |\n   \n  |\n   \n", result);
}

void testPrintLargeNumberTwo() {

	std::ostringstream out{};
	printLargeDigit(2, out);
	std::string result = out.str();
	ASSERT_EQUAL(" - \n  |\n - \n|  \n - \n", result);
}


void testPrintLargeNumberThree() {
	std::ostringstream out{};
	printLargeDigit(3, out);
	std::string result = out.str();
	ASSERT_EQUAL(" - \n  |\n - \n  |\n - \n", result);
}

void testPrintLargeNumberFour() {
	std::ostringstream out{};
	printLargeDigit(4, out);
	std::string result = out.str();
	ASSERT_EQUAL("   \n| |\n - \n  |\n   \n", result);
}


void testPrintLargeNumberFive() {
	std::ostringstream out{};
	printLargeDigit(5, out);
	std::string result = out.str();
	ASSERT_EQUAL(" - \n|  \n - \n  |\n - \n", result);
}


void testPrintLargeNumberSix() {
	std::ostringstream out{};
	printLargeDigit(6, out);
	std::string result = out.str();
	ASSERT_EQUAL(" - \n|  \n - \n| |\n - \n", result);
}



void testPrintLargeNumberSeven() {
	std::ostringstream out{};
	printLargeDigit(7, out);
	std::string result = out.str();
	ASSERT_EQUAL("-- \n  |\n   \n  |\n   \n", result);
}



void testPrintLargeNumberEight() {
	std::ostringstream out{};
	printLargeDigit(8, out);
	std::string result = out.str();
	ASSERT_EQUAL(" - \n| |\n - \n| |\n - \n", result);
}


void testPrintLargeNumberThreeThousendFourHundredAndSixtyEight() {
	std::ostringstream out{};
	printLargeNumber(3468, out);
	std::string result = out.str();
	ASSERT_EQUAL(" -     -  - \n  || ||  | |\n -  -  -  - \n  |  || || |\n -     -  - \n", result);
}


void testPrintLargeNumberScaledThreeThousendFourHundredAndSixtyEight() {
	std::ostringstream out{};
	printLargeNumber(3468, out, 2);
	std::string result = out.str();
	ASSERT_EQUAL(" --      --  -- \n   ||  ||   |  |\n   ||  ||   |  |\n --  --  --  -- \n   |   ||  ||  |\n   |   ||  ||  |\n --      --  -- \n", result);
}

void testPrintLargeNumberNine() {
	std::ostringstream out{};
	printLargeDigit(9, out);
	std::string result = out.str();
	ASSERT_EQUAL(" - \n| |\n - \n  |\n - \n", result);
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	//TODO add your test here
	s.push_back(CUTE(testPrintLargeNumberOne));
	s.push_back(CUTE(testPrintLargeNumberTwo));
	s.push_back(CUTE(testPrintLargeNumberThree));
	s.push_back(CUTE(testPrintLargeNumberFour));
	s.push_back(CUTE(testPrintLargeNumberFive));
	s.push_back(CUTE(testPrintLargeNumberSix));
	s.push_back(CUTE(testPrintLargeNumberSeven));
	s.push_back(CUTE(testPrintLargeNumberEight));
	s.push_back(CUTE(testPrintLargeNumberNine));
	s.push_back(CUTE(testPrintLargeNumberThreeThousendFourHundredAndSixtyEight));
	s.push_back(CUTE(testPrintLargeNumberScaledThreeThousendFourHundredAndSixtyEight));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



