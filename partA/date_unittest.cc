#include "gtest/gtest.h"
#include "date.h"

class DateTest : public ::testing::Test {
 public:
  void SetUp( ) { 
    // code here will execute just before the test ensues 
	first_day = Date(2018, 9, 4);
	last_day = Date(2018, 12, 11);
  some_day1 = Date(2016, 1, 1);
  some_day2 = Date(2016, 3, 1);
  }
 protected:
  Date first_day;          // first day of classes
  Date last_day;           // last day of classes
  Date some_day1;
  Date some_day2;
};

TEST_F(DateTest, EpochConstructorTests) {
  Date epoch_small_days(1633046400);
  EXPECT_EQ(epoch_small_days.GetDate(), "2021-10-01") << "GetDate is not properly";
}

TEST_F(DateTest, TodayConstructorTests) {
  std::time_t t = std::time(0);
  std::tm* now = std::localtime(&t);
  int current_year_ = now->tm_year + 1900;
  int current_month_ = now->tm_mon + 1;
  int current_day_ = now->tm_mday;
  Date correct_today(current_year_, current_month_, current_day_);

  Date today;
  EXPECT_EQ(today.GetDate(), correct_today.GetDate());
}

TEST_F(DateTest, GetDateTests) {
  Date ind_day(1776, 7, 4);
  EXPECT_EQ(first_day.GetDate(), "2018-09-04") << "GetDate is not properly";
  EXPECT_EQ(ind_day.GetDate(), "1776-07-04") << "GetDate is not properly";
}

TEST_F(DateTest, GetUsDateTests) {
  Date ind_day(1776, 7, 4);
  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "GetUsDate is not properly";
  EXPECT_EQ(ind_day.GetUsDate(), "07-04-1776") << "GetDate is not properly";
}

TEST_F(DateTest, PrintDateTests) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  
  std::string expected_out_1 = "1999-12-31\n";
  std::string expected_out_2 = "1776-07-04\n";
  std::string expected_out_3 = "2018-10-31\n";
  
  testing::internal::CaptureStdout();
  y2k.PrintDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout(); // You must do this EVERY TIME, or else it will segfault
  ind_day.PrintDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  best_holiday.PrintDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, PrintDateTestsWithoutNewline) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  
  std::string expected_out_1 = "1999-12-31";
  std::string expected_out_2 = "1776-07-04";
  std::string expected_out_3 = "2018-10-31";
  
  testing::internal::CaptureStdout();
  y2k.PrintDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  ind_day.PrintDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  best_holiday.PrintDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

/**
  *
  * Note, this is the only provided test case which actually uses our test fixture
  * 
  * However, it is illegal to mix TEST() and TEST_F() in the same test case (file).
  *
  */
  
TEST_F(DateTest, DaysBetweenTests) {
  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "First day of class not setup properly";
  EXPECT_EQ(last_day.GetUsDate(), "12-11-2018") << "Last day of class not setup properly";
  EXPECT_EQ(some_day1.GetUsDate(), "01-01-2016") << "some_day1 of class not setup properly";
  EXPECT_EQ(some_day2.GetUsDate(), "03-01-2016") << "some_day1 of class not setup properly";

  EXPECT_EQ(first_day.DaysBetween(last_day), 98) << "Days between is not calculated properly";
  EXPECT_EQ(some_day2.DaysBetween(some_day1), 60) << "Days between is not calculated properly";
}

TEST_F(DateTest, DaysBetweenSymmetry) {
  int d1 = some_day2.DaysBetween(some_day1);
  int d2 = some_day1.DaysBetween(some_day2);
  EXPECT_EQ(d1, d2) << "DaysBetween not symmetric";
}

TEST_F(DateTest, OperatorMinusTests) {
  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "First day of class not setup properly";
  EXPECT_EQ((first_day - 1).GetUsDate(), "09-03-2018") << "Operator- is not calculated properly";
  EXPECT_EQ((first_day - (-1)).GetUsDate(), "09-05-2018") << "Operator- is not calculated properly";
  EXPECT_EQ((first_day - 0).GetUsDate(), "09-04-2018") << "Operator- is not calculated properly";
}

TEST_F(DateTest, OperatorPlusTests) {
  EXPECT_EQ(first_day.GetUsDate(), "09-04-2018") << "First day of class not setup properly";
  EXPECT_EQ((first_day + 1).GetUsDate(), "09-05-2018") << "Operator+ is not calculated properly";
  EXPECT_EQ((first_day + (-1)).GetUsDate(), "09-03-2018") << "Operator+ is not calculated properly";
  EXPECT_EQ((first_day + (0)).GetUsDate(), "09-04-2018") << "Operator+ is not calculated properly";
}

TEST_F(DateTest, OperatorPlusMinusLargeDays) {
  Date ref(2000, 1, 1);
  Date next_year = ref + 365;
  EXPECT_EQ(next_year.GetDate(), "2000-12-31");

  Date prev_year = ref - 365;
  EXPECT_EQ(prev_year.GetDate(), "1999-01-01");
}

TEST_F(DateTest, PrintUsDateTests) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  
  std::string expected_out_1 = "12-31-1999\n";
  std::string expected_out_2 = "07-04-1776\n";
  std::string expected_out_3 = "10-31-2018\n";
  
  testing::internal::CaptureStdout();
  y2k.PrintUsDate(true);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout(); // You must do this EVERY TIME, or else it will segfault
  ind_day.PrintUsDate(true);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  best_holiday.PrintUsDate(true);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, PrintUsDateTestsWithoutNewline) {
  Date y2k(1999, 12, 31);              // y2k
  Date ind_day(1776, 7, 4);            // US Independence
  Date best_holiday(2018, 10, 31);     // Halloween
  
  std::string expected_out_1 = "12-31-1999";
  std::string expected_out_2 = "07-04-1776";
  std::string expected_out_3 = "10-31-2018";
  
  testing::internal::CaptureStdout();
  y2k.PrintUsDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  ind_day.PrintUsDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();
  
  testing::internal::CaptureStdout();
  best_holiday.PrintUsDate(false);
  std::string output3 = testing::internal::GetCapturedStdout();
  
  EXPECT_EQ(output1, expected_out_1);
  EXPECT_EQ(output2, expected_out_2);
  EXPECT_EQ(output3, expected_out_3);
}

TEST_F(DateTest, LeadingZeroTest) {
  Date d(2024, 4, 6);
  std::string result1 = d.GetUsDate();
  std::string result2 = d.GetDate();

  testing::internal::CaptureStdout();
  d.PrintUsDate(false);
  std::string output1 = testing::internal::GetCapturedStdout();
  testing::internal::CaptureStdout();
  d.PrintDate(false);
  std::string output2 = testing::internal::GetCapturedStdout();

  EXPECT_EQ(result1, "04-06-2024") << "GetUsDate missing leading zeroes";
  EXPECT_EQ(result2, "2024-04-06") << "GetDate missing leading zeroes";
  EXPECT_EQ(output1, "04-06-2024") << "PrintUsDate missing leading zeroes";
  EXPECT_EQ(output2, "2024-04-06") << "PrintDate missing leading zeroes";
}

TEST_F(DateTest, InvalidDateTest) {
  Date invalid_date1(2023, 2, 31); 
  Date invalid_date2(-1, 2, 3);
  Date invalid_date3(2018, 2, 30);
  EXPECT_EQ(invalid_date3.GetDate(), "1-01-01");
  EXPECT_EQ(invalid_date1.GetDate(), "1-01-01");
  EXPECT_EQ(invalid_date2.GetDate(), "-1-02-03");
}

/**
  *
  * NOPE!  Can't test PRIVATE methods
  *
  */
/*
TEST(DateTest, ConvertFromDays) {
	Date convert_first_day = ConvertToDays(2458365);
	EXPECT_STREQ(convert_first_day.GetUsDate(), "09-04-2018");
}
*/
