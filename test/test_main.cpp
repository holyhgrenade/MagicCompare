#include <cassert>
#include <iostream>
#include <cstdlib>
#include <cmath>

#include "magic_compare.hpp"

typedef void (*test)(void);

void testCreation()
{
  using Integer = MagicCompare<int>;
  int fixNum = 5;
  Integer first(fixNum);
  Integer second = first;
  Integer third(second);
  
  assert(first.getComp());
  assert(first.getComp());
  assert(first.getComp());

  assert(first.getLeft() == fixNum);
  assert(first.getLeft() == fixNum);
  assert(first.getLeft() == fixNum);
  
  assert(first.getRight() == fixNum);
  assert(first.getRight() == fixNum);
  assert(first.getRight() == fixNum);
}

void testBoolConversion()
{
  using Integer = MagicCompare<int>;
  Integer magic(5);
  bool compResult = magic;
  assert(compResult);
}

void testSmallerThan()
{
  using Float = MagicCompare<double>;
  Float lhs(5);
  Float rhs(3);
  double min = 1;
  double max = 7;
  assert(min < rhs);
  assert(rhs < lhs);
  assert(lhs < max);
}

void testGreaterThan()
{
  using Float = MagicCompare<double>;
  Float lhs(5);
  Float rhs(3);
  double min = 1;
  double max = 7;
  assert(lhs > rhs);
  assert(max > lhs);
  assert(rhs > min);
}

void testSmallerThanOrEq()
{
  using Integer = MagicCompare<int>;
  Integer first(5);
  Integer second(3);
  int min = 1;
  int max = 7;
  assert(min <= second);
  assert(second <= first);
  assert(second <= second);
  assert(second <= max);
}

void testGreaterThanOrEq()
{
  using Integer = MagicCompare<int>;
  Integer first(5);
  Integer second(3);
  int min = 1;
  int max = 7;
  assert(second >= min);
  assert(first >= second);
  assert(second >= second);
  assert(max >= first);
}

void testEq()
{
  using Integer = MagicCompare<int>;
  Integer first(5);
  Integer second(5);
  int third = 4;
  assert(first == second);
  assert(!(first == third)); 
}

void testNeq()
{
  using Integer = MagicCompare<int>;
  Integer first(5);
  Integer second(5);
  int third = 4;
  assert(!(first != second));
  assert(first != third);
}

void testChain()
{
  using Integer = MagicCompare<int>;
  Integer first(5);
  Integer second(3);
  Integer third(2);
  Integer fourth(10);
  Integer fifth (10);
  bool result = 1 < first > (second > third) < (fourth >= fifth) > 5 == first;
  assert(result == true);
  result = 1 > first > (second > third) < (fourth >= fifth) > 5 == first;
  assert(result == false);  
  result = 1 < first < (second > third) < (fourth >= fifth) > 5 == first;
  assert(result == false);
  result = 1 < first > (second < third) < (fourth <= fifth) > 5 == first;
  assert(result == false);
  result = 1 < first > (second > third) > (fourth >= fifth) > 5 == first;
  assert(result == false);
  result = 1 < first > (second > third) < (fourth < fifth) > 5 == first;
  assert(result == false);
  result = 1 < first > (second > third) < (fourth >= fifth) < 5 == first;
  assert(result == false);
  result = 1 < first > (second > third) < (fourth >= fifth) > 5 != first;
  assert(result == false); 
}

void testIncrement()
{
  using Integer = MagicCompare<int>;
  Integer first(5);
  ++first;
  assert(first == 6);
  assert((first++) == 6);
  assert(first == 7);
}

void testDecrement()
{
  using Integer = MagicCompare<int>;
  Integer first(5);
  --first;
  assert(first == 4);
  assert((first--) == 4);
  assert(first == 3);
}

void testSum()
{
  using Integer = MagicCompare<int>;
  Integer first(5);
  Integer second(3);
  assert(first + second == 8);
  first += second;
  assert(first == 8);
  first += 2;
  assert(first == 10);
}

void testDiff()
{
  using Integer = MagicCompare<int>;
  Integer first(5);
  Integer second(3);
  assert(first - second == 2);
  first -= second;
  assert(first == 2);
  first -= 2;
  assert(first == 0);  
}

void testMult()
{
  using Integer = MagicCompare<int>;
  Integer first(5);
  Integer second(3);
  assert(first * second == 15);
  assert(first * 3 == 15);
  first *= second;
  assert(first == 15);
  first *= 2;
  assert(first == 30);  
}

void testDiv()
{
  using Integer = MagicCompare<int>;
  Integer first(6);
  Integer second(3);
  assert(first / second == 2);
  assert(first / 3 == 2);
  first /= second;
  assert(first == 2);
  first /= 2;
  assert(first == 1);
}

void testMathFunctions()
{
  using Float = MagicCompare<double>;
  Float num(1.56); // approximately pi/2 but below
  assert(1 > sin(num) > 0.9);
  assert(sin(num) < exp(num) < 9);
  assert(sin(num) > cos(num) > 0);
}

void mainTest(int numOfTest) {
  test mainTests[] = {&testCreation,
                      &testBoolConversion,
                      &testSmallerThan,
                      &testGreaterThan,
                      &testSmallerThanOrEq,
                      &testGreaterThanOrEq,
                      &testEq,
                      &testNeq,
                      &testChain,
                      &testIncrement,
                      &testDecrement,
                      &testSum,
                      &testDiff,
                      &testMult,
                      &testDiv,
		      &testMathFunctions,
                      };	

  mainTests[numOfTest]();
}

int main(int argc, char **argv) {
  if(argc != 2) {
    std::cerr<<"Test needs exactly 1 arguments"<<std::endl;
  } else {
    mainTest(atoi(argv[1]));
  }
}
