#include "solution.h"

#include <unordered_map>
#include <unordered_set>
using namespace sol1153;
using namespace std;

/*takeaways
  - we don't really perform the conversions but just check if it's
    possible to transform from s1 to s2
  - s2 can't use up all 26 different chars or we can't transform
    at all
    - this is crucial!
    - let say s1=aabbcc...zz, s2=zzyyxx...aa
    - so we can't convert aa to zz as now s1 will have 4 z's
    - you can't convert aa to any temp char first and then z either,
      as that will result in the number of the temp char to become 4
      in s1 as well
   - use a map to record how a char in s1 should be mapped in s2;
     make sure the following same chars observe the mapping

*/
bool Solution::canConvert(string s1, string s2)
{
  if (s1 == s2)
    return true;
  if (s1.size() != s2.size())
    return false;
  auto used = unordered_set(s2.begin(), s2.end());

  /* this is the most curcial logic  */
  if (used.size() == 26)
    return false;

  /*record the very first occurrence of a char in s1
    and how it maps to a char to s2
    - same chars in s1 come in after this occurrence should
      follow the same mapping or s1 can't be converted
      to s2
  */
  auto m = unordered_map<char, char>();

  for (auto i = 0; i < s1.size(); i++)
    if (m.count(s1[i]) == 0)
      /* establish the mapping for the very f
         irst occurrence */
      m[s1[i]] = s2[i];
    else if (m[s1[i]] != s2[i])
      /* doesn't agree with the mapping we establish */
      return false;

  return true;
}