// This file demonstrated the use of list and several of its member functions
// also the standard algorithms generate and advance
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <list>

class Myclass {
public:
  int n;
  std::string str;  
  Myclass(int i = 0);
  bool operator<(const Myclass m) const;
  bool operator=(const Myclass m) const;
};

std::string numberasstring(int i);
bool intsequal(Myclass& m1, Myclass& m2);
int randomNumber();

bool Myclass::operator=(const Myclass m) const
{
  return (n == m.n);
}

bool Myclass::operator<(const Myclass m) const
{
  return (n < m.n);
}

Myclass::Myclass(int i)
{
  n = i;
  str = numberasstring(i);
}

struct stringslessthan : public std::binary_function <Myclass,Myclass,bool>
{
  bool operator()(Myclass m1, Myclass m2) const
  {
    return (m1.str < m2.str);
  }
};

int randomNumber()
{
  srand(time(NULL));
  return(std::rand()%100); 
}

bool intsequal(Myclass& m1, Myclass& m2)
{
  return (m1.n == m2.n); 
}

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

void print(const std::list<Myclass> &myclasslist)
{
  std::cout << std::setiosflags(std::ios::left);
  std::cout << "Print out the numbers and strings contained in the objects in the vector" << std::endl;
// Replace the old familiar for loop with range-based for loop
//  for (std::list<Myclass>::const_iterator iter = myclasslist.begin(); iter != myclasslist.end(); iter++)
//    std::cout << std::setw(6) << (*iter).n << " ";

   for (auto elem: myclasslist)
     std::cout << std::setw(6) << elem.n << " ";
  std::cout << std::endl;

  // the for loop is more readable if you use auto
  for (auto iter = myclasslist.cbegin(); iter != myclasslist.cend(); ++iter)
      std::cout << std::setw(6) << (*iter).str << " ";
  std::cout << std::endl << std::endl;
} 

int main()
{
  std::list<Myclass> myclasslist;
  std::list<Myclass> myclasslist2;

  if (myclasslist.empty()) std::cout << "The list is empty" << std::endl << std::endl;
 
  std::cout << "Fill the list" << std::endl;
 
  for (int i = 1;i<=10;i++)
    myclasslist.push_back(i);

  print(myclasslist);

  std::cout << "The size of the list is " << myclasslist.size() << std::endl;
  std::cout << "The maximum size of the list is " << myclasslist.max_size() << std::endl;

  std::cout << "Make a new list" << std::endl;
  for (int i = 1;i<=15;i++)
    myclasslist2.push_back(i%4);

  print(myclasslist2);
 
  std::cout << "Splice the second list into the first" << std::endl; 
  myclasslist.splice(myclasslist.end(),myclasslist2); 

  std::cout << "The size of the first list is now " << myclasslist.size() << std::endl;
  std::cout << "The size of the second list is now " << myclasslist2.size() << std::endl << std::endl;
  print(myclasslist);

  std::cout << "Sort by strings" << std::endl << std::endl;
  myclasslist.sort(stringslessthan());

  print(myclasslist);

  std::cout << "Remove duplicate elements" << std::endl << std::endl;
  myclasslist.unique(intsequal);

  print(myclasslist);

  std::cout << "Sort by ints" << std::endl << std::endl;
  myclasslist.sort();

  print(myclasslist);

  std::cout << "Reverse the list" << std::endl << std::endl;
  myclasslist.reverse();

  print(myclasslist);
 
  std::cout << "Resize the list" << std::endl << std::endl;
  myclasslist.resize(15);

  print(myclasslist);

  std::cout << "Assign five elements containg 3 to the second list" << std::endl << std::endl;
  myclasslist2.assign(5,3);

  print(myclasslist2);

  std::cout << "Swap the first list with the second" << std::endl << std::endl;
  myclasslist.swap(myclasslist2);

  std::cout << "The first list is now" << std::endl;
  print(myclasslist);

  std::cout << "The second list is now" << std::endl;
  print(myclasslist2);

  std::cout << "Swap them back" << std::endl << std::endl;
  myclasslist.swap(myclasslist2);

  std::cout << "Generate a list of length 15 using random numbers" << std::endl << std::endl;
  myclasslist2.resize(15);
  std::generate(myclasslist2.begin(),myclasslist2.end(),randomNumber);

  print(myclasslist2);

  std::cout << "Print the first, fifth and last element of first list" << std::endl << std::endl;
  auto first = myclasslist.begin();
  auto fifth = myclasslist.begin();
  std::advance(fifth,4);
  auto last = myclasslist.end();
  last--;

  std::cout << "The length of the list is " << myclasslist.size() << std::endl;  
  std::cout << "The first element is " << (*first).n << " The fifth element is " << (*fifth).n << " The last element is " << (*last).n << std::endl;

  print(myclasslist);

  while (!myclasslist.empty())
  {
    std::cout << "The front of the list is now " << myclasslist.front().n << std::endl;
    myclasslist.pop_front();
  }
}

