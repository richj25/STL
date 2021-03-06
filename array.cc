#include <iostream>
#include <array>

template <class T>
void print(const T container)
{
//  replace the old familiar for loop with range-base for loop
//  for (typename T::const_iterator it = container.cbegin(); it != container.cend(); it++)
//    std::cout << *it << " ";
  for (auto elem : container)
    std::cout << elem << " ";
  std::cout << std::endl;
}

int main()
{
  std::array<int,10> a;

  std::cout << "Fill an array of size 10 with fives" << std::endl;
  a.fill(5);

  print(a);

  std::cout << "Now fill the array with 0-9 " << std::endl;
  for (int i = 0; i < 10; i++)
    a[i] = i;

  print(a);

  std::cout << "Access entry 15 using at" << std::endl;

  try {
    auto it = a.at(15); 
    std::cout << "Entry 15 contains " << it << std::endl;
  } catch (std::exception &e) {
    std::cout << "There is no entry 15" << std::endl;
  }

  std::cout << "Create a second array of size 10 and fill it with sevens" << std::endl;
  std::array<int,10> a2;
  a2.fill(7);

  print(a2);

  std::cout << "Swap the first array with the second" << std::endl;

  a.swap(a2);

  std::cout << "Print the first array" << std::endl;

  print(a);

  std::cout << "Print the second array" << std::endl;

  print(a2);
}
