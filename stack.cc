#include <iostream>
#include <stack>

int main()
{
  std::stack<int> s;

  std::cout << "Push integers 0-10 inclusive onto the stack" << std::endl;
  for (int i = 0; i <=10; i++)
  {
    std::cout << "Pushed " << i << " onto the stack" << std::endl;
    s.push(i);
  }

  std::cout << "The size of the stack is " << s.size() << std::endl;
  std::cout << "The top of the stack is " << s.top() << std::endl;

  std::cout << "Pop all the elements off the stack" << std::endl;
  while (!s.empty())
  {
    std::cout << "Popped off " << s.top() << std::endl;
    s.pop();
  }
}
