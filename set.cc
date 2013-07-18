// this file demonstrate the use of std::set and several of it member functions
// also the standard algorithms set_union, set_intersection, set_difference, set_symmetric_difference,
// merge and includes

#include <iostream>
#include <iomanip>
#include <set>
#include <algorithm>

 
class Myclass {
public:
  int n;
  std::string str;
  Myclass(int i = 0);
  bool operator<(const Myclass& m) const;
  bool operator==(const Myclass m) const;
};

std::string numberasstring(int i);

bool Myclass::operator<(const Myclass& m) const
{
  return (n < m.n);
}

bool Myclass::operator==(const Myclass m) const
{
  return (n == m.n);
}

Myclass::Myclass(int i)
{
  n = i;
  str = numberasstring(i);
}

struct more : public std::binary_function <Myclass,Myclass,bool>
{
  bool operator()(const Myclass& m1, const Myclass& m2)
  {
    return (m1.n > m2.n);
  }
};

std::string numberasstring(int i)
{
  switch (i)
  {
    case 1: return "one";
    case 2: return "two";
    case 3: return "three";
    case 4: return "four";
    case 5: return "five";
    case 6: return "six";
    case 7: return "seven";
    case 8: return "eight";
    case 9: return "nine";
    case 10: return "ten";
    default: return "zero";
  }
}

template <class T>
void print(const T container)
{
  std::cout << std::setiosflags(std::ios::left);
  for (typename T::const_iterator iter = container.begin(); iter != container.end(); iter++)
    std::cout << std::setw(6) << (*iter).n << " ";
  std::cout << std::endl;

  //the for loop is more readable if you use auto
  for (auto iter = container.cbegin(); iter != container.cend(); ++iter)
    std::cout << std::setw(6) << (*iter).str << " ";
  std::cout << std::endl << std::endl;
}

typedef std::set<Myclass> settype1;
typedef std::set<Myclass,more> settype2;

int main()
{
  settype1 set1;
  settype2 set2;

  for (int i = 0; i < 30; i++)
    set1.insert(i%7);
   
  for (int i = 0; i < 30; i++)
    set2.insert(i%7);
 
 
  std::cout << "Print type1 set set1 which was built using Myclass < operator" << std::endl << std::endl; 
  print(set1); 

  std::cout << "Print type2 set set2 which was built using template argument" << std::endl << std::endl;
  print(set2);

  std::cout << "Emplace an element initialized with 9 in set1" << std::endl << std::endl; 
  std::cout << "Emplace is not supported for associative containers in GCC 4.7.2" << std::endl << std::endl;
//  set1.emplace(9);
//  print(set1); 

  std::cout << "Find an element initialized with 3 in set1" << std::endl << std::endl;
  if (set1.find(Myclass(3)) != set1.end()) std::cout << "Found the element in set1" << std::endl << std::endl;

  std::cout << "Create a second set of type 1" << std::endl << std::endl;
  settype1 set3;
  for (int i = 0; i < 30; i++)
    set3.insert(i%9);
  
  std::cout << "Print out the first set" << std::endl;
  print(set1); 

  std::cout << "Print out the second set" << std::endl;
  print(set3); 
 
  std::cout << "Print out the intersection of the two" << std::endl;

  settype1 result;
  std::set_intersection(set1.begin(),set1.end(),set3.begin(),set3.end(),std::inserter(result,result.end()));
  print(result); 

  result.clear();
  std::cout << "Print out the union of the two" << std::endl;
  std::set_union(set1.begin(),set1.end(),set3.begin(),set3.end(),std::inserter(result,result.end()));
  print(result);

  std::cout << "Add an element initialized with 9 to the first set" << std::endl << std::endl;
  set1.insert(9);

  result.clear();
  std::cout << "Print out the difference of the two" << std::endl;
  std::set_difference(set1.begin(),set1.end(),set3.begin(),set3.end(),std::inserter(result,result.end()));
  print(result);

  result.clear();
  std::cout << "Print out the symmetric difference of the two" << std::endl;
  std::set_symmetric_difference(set1.begin(),set1.end(),set3.begin(),set3.end(),std::inserter(result,result.end()));
  print(result);

  result.clear();
  std::cout << "Merge the two sets" << std::endl;
  std::merge(set1.begin(),set1.end(),set3.begin(),set3.end(),std::inserter(result,result.end()));
  print(result);

  std::cout << "Remove the element initialized with nine from the first set" << std::endl << std::endl;
  set1.erase(set1.find(9));

  std::cout << "Check if set2 include set1" << std::endl;
  if (std::includes(set3.begin(),set3.end(),set1.begin(),set1.end()))
    std::cout << "set2 includes set1" << std::endl;
  else std::cout << "set2 does not include set1" << std::endl;
}
