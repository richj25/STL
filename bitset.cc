#include <iostream>
#include <bitset>
#include <string>

int main()
{
  std::bitset<8> first(std::string("10101010"));
  std::bitset<8> second, third, fourth;

  std::cout << "The first set = " << first << std::endl;
  std::cout << "Flip the first set to make the second" << std::endl;
  second = first.flip();
  std::cout << "The second set = " << second << std::endl;
  std::cout << "Flip the first set back and  use the ~(not) operator to make the second" << std::endl;
  second = ~first.flip();
  std::cout << "The second set = " << second << std::endl;
  std::cout << "first AND second = " << (first & second) << std::endl;
  std::cout << "first OR second = " << (first | second) << std::endl;
  std::cout << "first XOR second = " << (first ^ second) << std::endl;
  std::cout << "shift the first set left by one" << std::endl;
  std::cout << "The first set = " << (first<<=1) << std::endl;
  std::cout << "first AND second = " << (first & second) << std::endl;
  std::cout << "first OR second = " << (first | second) << std::endl;
  std::cout << "first XOR second = " << (first ^ second) << std::endl;
}
