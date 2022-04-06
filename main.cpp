#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1153;

/* Example 1:
Input: str1 = “aabcc”, str2 = “ccdee”
Output: true
Explanation: Convert ‘c’ to ‘e’ then ‘b’ to ‘d’
then ‘a’ to ‘c’. Note that the order of conversions matter.
*/

tuple<string, string, bool> testFixture1()
{
  return make_tuple("aabcc", "ccdee", true);
}

/*
Input: str1 = “leetcode”, str2 = “codeleet”
Output: false
Explanation: There is no way to transform str1 to str2.
*/

tuple<string, string, bool> testFixture2()
{
  return make_tuple("leetcode", "codeleet", false);
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - expect to see " << to_string(get<2>(f)) << endl;
  cout << "result: " << to_string(Solution::canConvert(get<0>(f), get<1>(f))) << endl;
}
void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - expect to see " << to_string(get<2>(f)) << endl;
  cout << "result: " << to_string(Solution::canConvert(get<0>(f), get<1>(f))) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}