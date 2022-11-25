#include "gtest/gtest.h"

TEST(mssl, upper_case1) 
{
  const auto result = mssl::upper_case('c');
  const auto ref = 'C';

  EXPECT_EQ(result, ref);
}
TEST(mssl, upper_case2)
{
  const auto result = mssl::upper_case('¤²');
  const auto ref = '¤²';

  EXPECT_EQ(result, ref);
}
TEST(mssl, upper_case3)
{
  const auto result = mssl::upper_case('!');
  const auto ref = '!';

  EXPECT_EQ(result, ref);
}
TEST(mssl, upper_case4)
{
  const auto result = mssl::upper_case('123');
  const auto ref = '123';

  EXPECT_EQ(result, ref);
}
TEST(mssl, upper_case5)
{
  const auto result = mssl::upper_case(-123);
  const auto ref = -123;

  EXPECT_EQ(result, ref);
}
TEST(mssl, upper_case6)
{
  const auto result = mssl::upper_case(' ');
  const auto ref = ' ';

  EXPECT_EQ(result, ref);
}
TEST(mssl, upper_case7)
{
  const auto result = mssl::upper_case("¤¡¤¤¤§");
  const auto ref = "¤¡¤¤¤§";

  EXPECT_EQ(result, ref);
}
TEST(mssl, upper_case_inplace1)
{
  std::string result = "abcdef";
  mssl::upper_case_inplace(result);
  const auto ref = "ABCDEF";

  EXPECT_EQ(result, ref);
}
TEST(mssl, upper_case_inplace2)
{
  std::string result = "abc¤¡de¤§f!";
  mssl::upper_case_inplace(result);
  const auto ref = "ABC¤¡DE¤§F!";

  EXPECT_EQ(result, ref);
}
TEST(mssl, upper_case_inplace3)
{
  std::string result = "abc _¤¡de¤§f!";
  mssl::upper_case_inplace(result);
  const auto ref = "ABC _¤¡DE¤§F!";

  EXPECT_EQ(result, ref);
}
TEST(mssl, compare_icase1)
{
  EXPECT_TRUE(mssl::compare_icase('c', 'C'));
}
TEST(mssl, compare_icase2)
{
  EXPECT_FALSE(mssl::compare_icase('c', '!'));
}
TEST(mssl, compare_icase3)
{
  EXPECT_TRUE(mssl::compare_icase('¤²', '¤²'));
}
TEST(mssl, compare_icase4)
{
  EXPECT_FALSE(mssl::compare_icase('¤²', '¤³'));
}
TEST(mssl, contain1)
{
  EXPECT_TRUE(mssl::contain("abwer!we", "!"));
}
TEST(mssl, contain2)
{
  EXPECT_TRUE(mssl::contain("abwer!we", '!'));
}
TEST(mssl, contain3)
{
  EXPECT_TRUE(mssl::contain("±è¹Î¼®", '±è'));
}
TEST(mssl, contain4)
{
  EXPECT_TRUE(mssl::contain("±è ¹Î¼®", '±è '));
}
TEST(mssl, contain5)
{
  EXPECT_FALSE(mssl::contain("±è ¹Î¼®", '¸¸'));
}
TEST(mssl, contain6)
{
  EXPECT_TRUE(mssl::contain("±è ¹Î¼®", "¹Î¼®"));
}
TEST(mssl, contain7)
{
  EXPECT_FALSE(mssl::contain("±è ¹Î¼®", "±è¹Î"));
}
TEST(mssl, contain8)
{
  const std::string_view str = "±è¹Î¼®ÀÌ ÇÑ±¹¸»°ú ¿µ¾î¸¦ ÇÑ´Ù. Hello, ³ªÀÇ nameÀº ¹Î¼®";
  EXPECT_TRUE(mssl::contain(str, "±è¹Î", "Hello", "Àº"));
}
TEST(mssl, contain9)
{
  const std::string_view str = "±è¹Î¼®ÀÌ ÇÑ±¹¸»°ú ¿µ¾î¸¦ ÇÑ´Ù. Hello, ³ªÀÇ nameÀº ¹Î¼®";
  EXPECT_FALSE(mssl::contain(str, "±è¼®", "Hello", "Àº"));
}
TEST(mssl, contain10)
{
  const std::string_view str = "abcd¤¡¤§¤·¤©¤¤¤²";
  EXPECT_TRUE(mssl::contain(str, '¤§'));
}
TEST(mssl, contain11)
{
  const std::string_view str = "abcd¤¡¤§¤·¤©¤¤¤²";
  EXPECT_FALSE(mssl::contain(str, '¤»'));
}
TEST(mssl, contain_icase1)
{
  EXPECT_TRUE(mssl::contain_icase("aBWEr!we", "bw"));
}
TEST(mssl, contain_icase2)
{
  EXPECT_TRUE(mssl::contain_icase("aBWEr!we", "bweR!"));
}
TEST(mssl, contain_icase3)
{
  EXPECT_FALSE(mssl::contain_icase("aBWEr!we", "TA"));
}
TEST(mssl, contain_icase4)
{
  const std::string_view str = "Three colors : red blue orange";

  EXPECT_TRUE(mssl::contain_icase(str, "colors", "red", "blue"));
}
TEST(mssl, contain_icase5)
{
  const std::string_view str = "Three colors : red blue orange";

  const std::string target1 = "RED";
  const char* target2 = "Orange";
  const std::string_view target3 = "Three";
  EXPECT_TRUE(mssl::contain_icase(str, target1, target2, target3));
}
TEST(mssl, contain_icase6)
{
  const std::string_view str = "Three colors : red blue orange";

  const std::string target1 = "RED,";
  const char* target2 = "Orange";
  const std::string_view target3 = "Three";
  EXPECT_FALSE(mssl::contain_icase(str, target1, target2, target3));
}
TEST(mssl, contain_icase7)
{
  EXPECT_TRUE(mssl::contain_icase("aBWEr!we", 'W'));
}
TEST(mssl, contain_icase8)
{
  EXPECT_TRUE(mssl::contain_icase("aBWEr!we", 'A'));
}
TEST(mssl, contain_icase9)
{
  EXPECT_FALSE(mssl::contain_icase("aBWEr!we", 'X'));
}
TEST(mssl, find_nth_position1)
{
  const auto str = "abcdefg";
  const auto result = mssl::find_nth_position(str, 'f',1);
  constexpr auto ref = 5;
  EXPECT_EQ(result, ref);
}
TEST(mssl, find_nth_position2)
{
  const auto str = "a b c @ # _";
  const auto result = mssl::find_nth_position(str, ' ',1);
  constexpr auto ref = 1;
  EXPECT_EQ(result, ref);
}
TEST(mssl, find_nth_position3)
{
  const auto str = "a,b!c";
  const auto result = mssl::find_nth_position(str, ',',1);
  constexpr auto ref = 1;
  EXPECT_EQ(result, ref);
}
TEST(mssl, find_nth_position4)
{
  const auto str = "a,b!c";
  const auto result = mssl::find_nth_position(str, '!',1);
  constexpr auto ref = 3;
  EXPECT_EQ(result, ref);
}
TEST(mssl, find_nth_position5)
{
                  //0123456789
  const auto str = "b c@b cbcb";
  const auto result = mssl::find_nth_position(str, "b c",1);
  constexpr auto ref = 0;
  EXPECT_EQ(result, ref);
}
TEST(mssl, find_nth_position6)
{                 //0123456789
  const auto str = "a@b*cb*c@b*c";
  const auto result = mssl::find_nth_position(str, "b*c",1);
  constexpr auto ref = 2;
  EXPECT_EQ(result, ref);
}
TEST(mssl, find_nth_position7)
{                 //01 3456789
  const auto str = "a¤¡b*c @ # _,!";
  const auto result = mssl::find_nth_position(str, "¤¡",1);
  constexpr auto ref = 1;
  EXPECT_EQ(result, ref);
}
TEST(mssl, find_nth_position8)
{
                  //0123456                  
  const auto str = "afcdeff";
  const auto result = mssl::find_nth_position(str, 'f', 3);
  constexpr auto ref = 6;
  EXPECT_EQ(result, ref);
}
TEST(mssl, find_nth_position9)
{
                  //0123456789
  const auto str = "b c@b cbcb";
  const auto result = mssl::find_nth_position(str, "b c", 2);
  constexpr auto ref = 4;
  EXPECT_EQ(result, ref);
}
TEST(mssl, find_nth_position10)
{                 //0123456789
  const auto str = "a@b*cb*c@b*c";
  const auto result = mssl::find_nth_position(str, "b*c", 3);
  constexpr auto ref = 9;
  EXPECT_EQ(result, ref);
}
TEST(mssl, find_nth_position_icase1)
{
  const auto str = "abcdefg";
  const auto result = mssl::find_nth_position_icase(str, 'F',1);
  constexpr auto ref = 5;
  EXPECT_EQ(result, ref);
}
TEST(mssl, find_nth_position_icase2)
{
  const auto str = "a b c @ # _";
  const auto result = mssl::find_nth_position_icase(str, ' ',1);
  constexpr auto ref = 1;
  EXPECT_EQ(result, ref);
}
TEST(mssl, find_nth_position_icase3)
{
  const auto str = "a,b!c";
  const auto result = mssl::find_nth_position_icase(str, ',',1);
  constexpr auto ref = 1;
  EXPECT_EQ(result, ref);
}
TEST(mssl, find_nth_position_icase4)
{
  const auto str = "a,b!c";
  const auto result = mssl::find_nth_position_icase(str, '!',1);
  constexpr auto ref = 3;
  EXPECT_EQ(result, ref);
}
TEST(mssl, find_nth_position_icase5)
{
  const auto str = "a b c @ # _,!";
  const auto result = mssl::find_nth_position_icase(str, "B C",1);
  constexpr auto ref = 2;
  EXPECT_EQ(result, ref);
}
TEST(mssl, find_nth_position_icase6)
{
  const auto str = "a@b*c @ # _,!";
  const auto result = mssl::find_nth_position_icase(str, "B*C",1);
  constexpr auto ref = 2;
  EXPECT_EQ(result, ref);
}
TEST(mssl, find_nth_position_icase7)
{
  const auto str = "a¤¡b*c @ # _,!";
  const auto result = mssl::find_nth_position_icase(str, "¤¡",1);
  constexpr auto ref = 1;
  EXPECT_EQ(result, ref);
}
TEST(mssl, find_nth_position_icase8)
{
                  //0 2 4
  const auto str = "±è¹Î¼®";
  const auto result = mssl::find_nth_position_icase(str, "¹Î",1);
  constexpr auto ref = 2;
  EXPECT_EQ(result, ref);
}
TEST(mssl, find_nth_position_icase9)
{
  const auto str = "¤¡¤¤¤§¤«¤²";
  const auto result = mssl::find_nth_position_icase(str, "¤§",1);
  constexpr auto ref = 4;
  EXPECT_EQ(result, ref);
}
TEST(mssl, find_nth_position_icase10)
{
                  //0123456789
  const auto str = "aFcfefgfwf";
  const auto result = mssl::find_nth_position_icase(str, 'F', 3);
  constexpr auto ref = 5;
  EXPECT_EQ(result, ref);
}
TEST(mssl, find_nth_position_icase11)
{
                  //0123456789
  const auto str = "B@b*c b*CB*c";
  const auto result = mssl::find_nth_position_icase(str, "B*C", 3);
  constexpr auto ref = 9;
  EXPECT_EQ(result, ref);
}

TEST(mssl, find_r_nth_position1)
{
                        //0123456789
  std::string_view str = "he2he5he89";
  std::string_view target = "he";

  const auto result = mssl::find_r_nth_position(str, target, 1);
  constexpr auto ref = 6;
  EXPECT_EQ(result, ref);
}
TEST(mssl, find_r_nth_position2)
{
                        //0123456789
  std::string_view str = "hehheehehh";
  std::string_view target = "he";

  const auto result = mssl::find_r_nth_position(str, target, 2);
  constexpr auto ref = 3;
  EXPECT_EQ(result, ref);
}
TEST(mssl, find_r_nth_position3)
{
                        //0123456789
  std::string_view str = "hehheehehh";
  std::string_view target = "he";

  const auto result = mssl::find_r_nth_position(str, target, 3);
  constexpr auto ref = 0;
  EXPECT_EQ(result, ref);
}
TEST(mssl, find_r_nth_position4)
{
  std::string_view str = "012he56he9";
  std::string_view target = "he";

  const auto pos = mssl::find_r_nth_position(str, target, 2);
  constexpr auto ref = 3;
  EXPECT_EQ(pos, ref);
}
TEST(mssl, find_r_nth_position5)
{
  std::string_view str = "012he56he9";
  std::string_view target = "he";

  const auto pos = mssl::find_r_nth_position(str, target, 3);
  constexpr auto ref = mssl::fail_to_find;
  EXPECT_EQ(pos, ref);
}
TEST(mssl, parse_by1)
{
  const auto str = " Easy Example of Parsing ";
  const auto result = mssl::parse_by(str, ' ');
  const std::vector<std::string_view> ref = { "Easy","Example","of","Parsing" };

  EXPECT_EQ(result, ref);
}
TEST(mssl, parse_by2)
{
  const auto str = " ÇÑ±Û·Î µÈ ½¬¿î ¿¹½Ã ";
  const auto result = mssl::parse_by(str, ' ');
  const std::vector<std::string_view> ref = { "ÇÑ±Û·Î","µÈ","½¬¿î","¿¹½Ã" };

  EXPECT_EQ(result, ref);
}
TEST(mssl, parse_by3)
{
  const auto str = " Delimiter   appears  consecutively  ";
  const auto result = mssl::parse_by(str, ' ');
  const std::vector<std::string_view> ref = { "Delimiter","appears","consecutively" };

  EXPECT_EQ(result, ref);
}
TEST(mssl, parse_by4)
{
  const auto str = "  Delimiter   appears  consecutively  ";
  const auto result = mssl::parse_by(str, ' ');
  const std::vector<std::string_view> ref = { "Delimiter","appears","consecutively" };

  EXPECT_EQ(result, ref);
}

TEST(mssl, remove1)
{
  const auto str = "°ú ¿¬ ¶ç ¾î ¾² ±â ¸¦ Àü ºÎ ¾ø ¾Ù ¼ö ÀÖ À» °Í ÀÎ °¡? ";
  const auto result = mssl::remove(str, " ");
  constexpr auto ref = "°ú¿¬¶ç¾î¾²±â¸¦ÀüºÎ¾ø¾Ù¼öÀÖÀ»°ÍÀÎ°¡?";
  EXPECT_EQ(result, ref);
}
TEST(mssl, remove2)
{
  const auto str = "°ú¿¬aaaÇÑ±Û°úaaa¿µ¾î°¡aa¼¯¿©bdeÀÖ´Ù¸é?";
  const auto result = mssl::remove(str, "aaa");
  constexpr auto ref = "°ú¿¬ÇÑ±Û°ú¿µ¾î°¡aa¼¯¿©bdeÀÖ´Ù¸é?";
  EXPECT_EQ(result, ref);
}
TEST(mssl, remove_inplace1)
{
  std::string str = "Å×½ºÆ®aa ÇÏ´Â°Ô aa»ýa°¢aº¸´Ùaa ½±Áöaa¾Ê±º";
  mssl::remove_inplace(str, "a");
  constexpr auto ref = "Å×½ºÆ® ÇÏ´Â°Ô »ý°¢º¸´Ù ½±Áö¾Ê±º";
  EXPECT_EQ(str, ref);
}
TEST(mssl, replace1)
{
  std::string str = "abcbdbe";
  mssl::replace_inplace(str, "b", "ff");
  constexpr auto ref = "affcffdffe";
  EXPECT_EQ(str, ref);
}
TEST(mssl, replace2)
{
  std::string str = "abcbdbe";
  mssl::replace_inplace(str, "b", "fffff");
  constexpr auto ref = "afffffcfffffdfffffe";
  EXPECT_EQ(str, ref);
}
TEST(mssl, replace3)
{
  std::string str = "abcbdbeb";
  mssl::replace_inplace(str, "b", "¹Î¼®");
  constexpr auto ref = "a¹Î¼®c¹Î¼®d¹Î¼®e¹Î¼®";
  EXPECT_EQ(str, ref);
}
TEST(mssl, replace_inplace1)
{
  std::string str = "my dog dog dog and dog and dog";
  mssl::replace_inplace(str, "dog", "world");
  constexpr auto ref = "my world world world and world and world";
  EXPECT_EQ(str, ref);
}
TEST(mssl, double_to_str1)
{
  const auto d = 3.14;
  const auto result = mssl::double_to_str(d, std::setprecision(16));
  constexpr auto ref = "3.14";
  EXPECT_EQ(ref, result);
}
TEST(mssl, double_to_str2)
{
  const auto d = 3.14;
  const auto result = mssl::double_to_str(d, std::setprecision(16), std::showpoint);
  constexpr auto ref = "3.140000000000000";
  EXPECT_EQ(ref, result);
}
TEST(mssl, double_to_str3)
{
  const auto d = 3.14;
  const auto result = mssl::double_to_str(d, std::fixed, std::setprecision(10), std::showpoint);
  constexpr auto ref = "3.1400000000";
  EXPECT_EQ(ref, result);
}
TEST(mssl, is_digit1)
{
  EXPECT_TRUE(mssl::is_natural_number("00123534523968439"));
}
TEST(mssl, is_integer1)
{
  EXPECT_TRUE(mssl::is_integer("-00123534523968439"));
}
TEST(mssl, is_integer2)
{
  EXPECT_TRUE(mssl::is_integer("+123534523968439"));
}
TEST(mssl, is_integer3)
{
  EXPECT_FALSE(mssl::is_integer("123.534523968439"));
}
TEST(mssl, is_real_number1)
{
  EXPECT_TRUE(mssl::is_real_number("123.534523968439"));
}
TEST(mssl, is_real_number2)
{
  EXPECT_TRUE(mssl::is_real_number("-123.534523968439"));
}
TEST(mssl, is_real_number3)
{
  EXPECT_FALSE(mssl::is_real_number("-123..534523968439"));
}
TEST(mssl, is_real_number4)
{
  EXPECT_FALSE(mssl::is_real_number("-123.53452396843.9"));
}
TEST(mssl, is_real_number5)
{
  EXPECT_TRUE(mssl::is_real_number("-123."));
}
TEST(mssl, str_to_value1)
{
  const auto str = "-123.4523";
  const auto result = mssl::str_to_value<double>(str);
  constexpr auto ref = -123.4523;
  EXPECT_EQ(result, ref);
}
TEST(mssl, str_to_value2)
{
  const auto str = "-1";
  const auto result = mssl::str_to_value<unsigned int>(str);
  constexpr unsigned int ref = -1; //maximum of unsigned int
  EXPECT_EQ(result, ref);
}
TEST(mssl, str_to_value3)
{
  const auto str = "-1";
  const auto result = mssl::str_to_value<std::string>(str);
  const std::string ref = "-1";
  EXPECT_EQ(result, ref);
}
