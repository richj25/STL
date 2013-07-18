#include <iostream>
#include <array>

template <class T>
void print(const T container)
{
  for (typename T::const_iterator it = container.cbegin(); it != container.cend(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;
}

int main()
{
  std::array<int,10> a;

  std::cout << "Fill an array of size 10 with fives" << std::endl;
  a.fill(5);

  print(a);

  for (int i = 0; i < 10; i++)
    a[i] = i;

  print(a);

  std::cout << "Access entry 15 using at" << std::endl;

  try {
    auto it = a.at(15); 
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
