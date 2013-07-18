#include <iostream>
#include <forward_list>

bool divisible_by_three(int n);
void print(std::forward_list<int> fl);

void print(std::forward_list<int> fl)
{
  for (auto it = fl.begin(); it != fl.end(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;
}

bool divisible_by_three(int n)
{
  return !(n%3);
}

struct is_odd
{
  bool operator()(int n)
  {
    return (n%2);
  }
};

int main()
{
  std::forward_list<int> fl, fl2;

  std::cout << "Make a forward list with integers 0-10 inclusive" << std::endl;
  for (int i = 0; i <= 10; i++)
    fl.push_front(i);

 
  std::cout << "Insert 12 in the first position" << std::endl; 
  auto it = fl.before_begin();
  fl.insert_after(it,12);

  std::cout << "The size of the list is " << std::distance(fl.begin(),fl.end()) << std::endl;
 
  print(fl); 

  std::cout << "Remove all the odd elements" << std::endl;

  fl.remove_if(is_odd());

  print(fl);

  std::cout << "Remove all the elements divisible by 3" << std::endl;

  fl.remove_if(divisible_by_three);

  print(fl);

  std::cout << "Sort the list in ascending order" << std::endl;

  fl.sort();

  print(fl);

  std::cout << "Create a second list of odd numbers" << std::endl;

  for (int i = 0; i < 10; i++)
    if (i%2) fl2.push_front(i);
  fl2.reverse();

  print(fl2);

  std::cout << "Merge the two lists" << std::endl;
  fl.merge(fl2);

  print(fl);
}
