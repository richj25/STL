#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <algorithm>

typedef std::pair<std::string,int> intpair;

std::string numberAsString(int i, bool upper);
void print(const std::map<std::string,int> &intmap);

void print(const std::map<std::string,int> &intmap)
{
  std::cout << std::setiosflags(std::ios::left);
  for (auto iter = intmap.cbegin(); iter != intmap.cend(); iter++)
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

int main()
{
  std::map<std::string,int> intmap;

  for (int i = 0; i<=10; i++)
  {
    intmap.insert(intpair(numberAsString(i,false),i));    
    intmap.insert(intpair(numberAsString(i,true),i));    
  }

  print(intmap);

  std::cout << "Use the \"[]\" operator" << std::endl;
  std::cout << "Get value associated with \"three\"" << std::endl;
  std::cout << "The value associate with \"three\" is " << intmap["three"] << std::endl;

  std::cout << "Get value associated with \"asdf\"" << std::endl;
  std::cout << "The value associate with \"asdf\" is " << intmap["asdf"] << std::endl;

  print(intmap);

  std::cout << "Erase element with key \"asdf\"" << std::endl;
  intmap.erase("asdf");
  print(intmap);

  std::cout << "Use the \"at\" method" << std::endl;
  std::cout << "Get value associated with \"three\"" << std::endl;
  std::cout << "The value associate with \"three\" is " << intmap.at("three") << std::endl;
  
  std::cout << "Get value associated with \"asdf\"" << std::endl;
  try 
  {
    std::cout << "The value associate with \"asdf\" is " << intmap.at("asdf") << std::endl;
  } catch (std::exception &e) {
    std::cout << "There is no key \"asdf\" in the map" << std::endl;
  }
}
