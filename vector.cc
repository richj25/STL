// This file demonstrates the use of vector and a number of its member functions
// also the standard algorithms bind2nd, bind1st, bind, copy, sort, transform,
// unique, rotate and distance

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

class Myclass {
public:
  int n;
  std::string str;
  Myclass(int i = 0);
};

std::string numberasstring(int i);
void print(const std::vector<Myclass> &vec);
bool compareints(const Myclass& m1, const Myclass& m2);
bool comparestrings(const Myclass& m1, const Myclass& m2);
bool equal(const Myclass& m1, const Myclass& m2);

Myclass::Myclass(int i)
{
  n = i;
  str = numberasstring(i);
}

bool compareints(const Myclass& m1, const Myclass& m2)
{
  return m1.n < m2.n;
}

bool comparestrings(const Myclass& m1, const Myclass& m2)
{
  return m1.str < m2.str;
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

bool equal(const Myclass& m1, const Myclass& m2) 
{
  return (m1.n == m2.n);
}

struct equalto : public std::binary_function <Myclass,int,bool>
{
  bool operator()(Myclass item, int i) const
  {
    return (item.n == i);
  }
};

struct add : public std::binary_function <Myclass,int,Myclass>
{
  Myclass operator()(Myclass item, int i) const
  {
    item.n += i;
    item.str = numberasstring(item.n);
    return item;
  }
};

struct subtract: public std::binary_function <int,Myclass,Myclass>
{
  Myclass operator()(int i, Myclass item) const
  {
    item.n -= i;
    item.str = numberasstring(item.n);
    return item;
  }
};

void print(const std::vector<Myclass> &vec)
{
  std::cout << std::setiosflags(std::ios::left);
  std::cout << "Print out the numbers and strings contained in the objects in the vector" << std::endl;
  for (std::vector<Myclass>::const_iterator iter = vec.begin(); iter != vec.end(); iter++)
    std::cout << std::setw(6) << (*iter).n << " ";
  std::cout << std::endl;

  // the for loop is more readable if you use auto
  for (auto iter = vec.cbegin(); iter != vec.cend(); ++iter)
    std::cout << std::setw(6) << (*iter).str << " ";
  std::cout << std::endl << std::endl;
}

int main()
{
  std::vector<Myclass>  myclassvec;

  for (int i = 1; i <= 10; i++)
  {
    myclassvec.push_back(Myclass(i));
  }

  print(myclassvec);

  std::cout << "The size of the vector is " << myclassvec.size() << std::endl;
  std::cout << "The maximum size the vector could be is " << myclassvec.max_size() << std::endl;
  std::cout << "The current capacity of the vector is " << myclassvec.capacity() << std::endl << std::endl;

  std::cout << "Shrink the vector to fit" << std::endl;
  myclassvec.shrink_to_fit();

  std::cout << "The current capacity of the vector is " << myclassvec.capacity() << std::endl << std::endl;

  std::cout << "Reserve additional capacity" << std::endl;
  myclassvec.reserve(25);

  std::cout << "The current capacity of the vector is " << myclassvec.capacity() << std::endl << std::endl;

  std::cout << "Resize the vector" << std::endl;

  myclassvec.resize(25);
  std::cout << "The current size of the vector is " << myclassvec.capacity() << std::endl << std::endl;

  print(myclassvec);

  std::cout << "Assign 3 to elements 11-23" << std::endl << std::endl;
  for (auto i = 11; i != 23; i++)
    myclassvec[i] = 3;

  print(myclassvec);

  std::cout << "Create new vector from elements 12-21" << std::endl << std::endl;
  auto first = myclassvec.begin() + 12;
  auto last = myclassvec.begin() + 22;
  std::vector<Myclass> newmyclassvec(first,last);

  std::cout << "Add one to each element of new vector" << std::endl << std::endl;
  first = newmyclassvec.begin();
  last = newmyclassvec.end();
  std::transform(first,last,first,std::bind2nd(add(),1));

  std::cout << "Subtract 2 from elements 1-8" << std::endl << std::endl;
  first = newmyclassvec.begin() + 1;
  last = newmyclassvec.end() - 1;
  std::transform(first,last,first,std::bind1st(subtract(),2));

  std::cout << "Add 4 to elements 2-7" << std::endl;
  first = newmyclassvec.begin() + 2;
  last = newmyclassvec.end() - 2;
  std::transform(first,last,first,std::bind(add(),std::placeholders::_1,4));

  std::cout << "Subtract 3 from elements 3-6" << std::endl;
  first = newmyclassvec.begin() + 3;
  last = newmyclassvec.end() - 3;
  std::transform(first,last,first,std::bind(subtract(),3,std::placeholders::_1));

  print(newmyclassvec);

  std::cout << "Replace elements 12-21 in original vector with the contents of the new vector" << std::endl << std::endl;
  std::copy(newmyclassvec.begin(),newmyclassvec.end(),myclassvec.begin()+12);
 
  print(myclassvec);

  std::cout << "Sort elements 10-20 by the integers" << std::endl << std::endl;
  std::sort(myclassvec.begin()+10, myclassvec.begin()+20,compareints);

  print(myclassvec);

  std::cout << "Sort the whole vector by the strings" << std::endl << std::endl;
  std::sort(myclassvec.begin(),myclassvec.end(),comparestrings);

  print(myclassvec);

  std::cout << "Count all the threes" << std::endl;
  int count = std::count_if(myclassvec.begin(),myclassvec.end(),bind(equalto(),std::placeholders::_1,3));
  std::cout << "There are " << count << " threes in the vector." << std::endl << std::endl;

  std::cout << "Remove all adjacent duplicates and sort by integers" << std::endl;
  std::vector<Myclass>::iterator it = std::unique(myclassvec.begin(),myclassvec.end(),equal);
  myclassvec.resize(std::distance(myclassvec.begin(),it));
  std::sort(myclassvec.begin(),myclassvec.end(),compareints);

  print(myclassvec);

  std::cout << "Rotate the vector left by five elements" << std::endl << std::endl;
  std::rotate(myclassvec.begin(),myclassvec.begin()+5,myclassvec.end());

  print(myclassvec);
}
