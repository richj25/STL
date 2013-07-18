#include <iostream>
#include <queue>

int main()
{
  std::queue<int> q;

  std::cout << "Fill the queue with integers 0-10 inclusive" << std::endl;
  for (int i=0;i<=10;i++)
  {
    std::cout << "Pushed " << i << " onto the queue." << std::endl;
    q.push(i);
  }

  std::cout << "The size of the queue is " << q.size() << std::endl;
  std::cout << "The front of the queue is " << q.front() << std::endl;
  std::cout << "The back of the queue is " << q.back() << std::endl;

  std::cout << "Pop out all the elements in the queue" << std::endl;
  while (!q.empty()) 
  { 
    std::cout << "Popped off " << q.front() << std::endl; 
    q.pop();
  }
}
