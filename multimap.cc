#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <algorithm>

typedef std::pair<std::string,int> intpair;

std::string numberAsString(int i, bool upper);
void print(const std::multimap<std::string,int> &mm);

void print(const std::multimap<std::string,int> &mm)
{
  std::cout << std::setiosflags(std::ios::left);
  for (auto iter = mm.cbegin(); iter != mm.cend(); iter++)
    std::cout << std::setw(6) << (*iter).first << " " << (*iter).second << std::endl;
  std::cout << std::endl;
}

std::string numberAsString(int i, bool upper)
{
  std::string ret;
  switch (i)
  {
    case 1:  ret = "one";   break;
    case 2:  ret = "two";   break;
    case 3:  ret = "three"; break;
    case 4:  ret = "four";  break;
    case 5:  ret = "five";  break;
    case 6:  ret = "six";   break;
    case 7:  ret = "seven"; break;
    case 8:  ret = "eight"; break;
    case 9:  ret = "nine";  break;
    case 10: ret = "ten";   break;
    default: ret = "zero";
  }
  if (upper) std::transform(ret.begin(), ret.end(),ret.begin(), ::toupper);
  return ret;
}

typedef std::multimap<std::string,int>::iterator IT;
typedef std::pair<IT,IT> ITPAIR;

int main()
{
  std::multimap<std::string,int> mm;

  for (int i = 0; i<=10; i++)
  {
    mm.insert(intpair(numberAsString(i%4,false),i%4));    
    mm.insert(intpair(numberAsString(i%4,true),i%4));    
  }

  print(mm);

  std::cout << "Remove all the elements with key \"TWO\"" << std::endl;
  ITPAIR ret = mm.equal_range("TWO");
  mm.erase(ret.first,ret.second);

  print(mm);
}
