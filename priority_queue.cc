#include <iostream>
#include <queue>

int main()
{
  std::priority_queue<int> pq;

  for (int i = 0; i < 25; i++)
    pq.push(i%10);

  std::cout << "The size of the queue is " << pq.size() << std::endl;
  std::cout << "Pop out each of the elements" << std::endl;
  while (!pq.empty()) 
  {
    std::cout << "Popped off " << pq.top() << std::endl;
    pq.pop(); 
  }
}
