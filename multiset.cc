#include <iostream>
#include <set>

template <class T>
void print(T& container)
{
  for (typename T::iterator it = container.begin(); it != container.end(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;
}

typedef std::multiset<int>::iterator IT;
typedef std::pair<IT,IT> ITPAIR;

int main()
{
  std::multiset<int> ms;

  for (int i = 0; i < 30; i++)
    ms.insert(i%8);

  print(ms);

  std::cout << "find the first element containing 3 and iterate forward" << std::endl;

  for (auto it = ms.find(3); it != ms.end(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;


  std::cout << "Remove all the fives" << std::endl;
  ITPAIR ret = ms.equal_range(5);

  ms.erase(ret.first,ret.second);

  print(ms);
}
