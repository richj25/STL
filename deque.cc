#include <iostream>
#include <deque>
#include <algorithm>

void print(std::deque<int> d)
{
  for (auto it = d.begin(); it != d.end(); it++)
    std::cout << (*it) << " ";
  std::cout << std::endl;
}

int fib()
{
  static int f1 = 0;
  static int f2 = 1;;
  int res, ret;
  ret = f1;
  res = f1 + f2;
  f1 = f2;
  f2 = res;
  return ret;
}
int main()
{
  std::deque<int> d;

  std::cout << "Push integers 0-10 inclusive onto the front of the deque" << std::endl;
  for (int i = 0; i <= 10; i++)
  {
    std::cout << "Pushed " << i << " onto the deque" << std::endl;
    d.push_front(i);  
  }

  std::cout << "Pop elements off the back of the deque" << std::endl; 
  while (!d.empty())
  {
    std::cout << "Popped " << d.back() << " off the deque" << std::endl;
    d.pop_back();
  }
 
  std::cout << "Clear the deque" << std::endl;
  d.clear(); 

  std::cout << "Generate a fibonacci sequence" << std::endl;
  d.resize(20,0);
  std::generate(d.begin(), d.end(), fib);

  print(d);

  std::cout << "Print the 1st, 5th, 10th and 15th elements" << std::endl;
  auto it = d.begin();
  std::cout << "1st - " << *it << std::endl;
  std::advance(it,4); 
  std::cout << "5th - " << *it << std::endl;
  std::advance(it,5); 
  std::cout << "10th - " << *it << std::endl;
  std::advance(it,5); 
  std::cout << "15th - " << *it << std::endl;

  std::cout << "Use the [] operator to retrieve the 25th element" << std::endl;
  std::cout << "The 25th element = " << d[24] << std::endl;
  std::cout << "Use the at function to retrieve the 25th element" << std::endl;
  try {
    std::cout << "The 25th element is " << d.at(25) << std::cout; 
  } catch (std::exception &e) {
    std::cout << "There is no 25th element" << std::endl;
  }
}
