#include <iostream>
#include <atomic>
#include <thread>
// memory sequence
// ---------- sync ------- sequence
// relaxed    no            no
// release    yes           前面的代码不能优化到release后面(write)

std::atomic<bool> x{false};
std::atomic<bool> y{false};
int z{0};
void write_x_then_y ()
{
  x.store(true, std::memory_order_relaxed);
  y.store(true, std::memory_order_release);
}

void read_y_then_add_z()
{
  while (!y.load(std::memory_order_acquire));
  if (x.load(std::memory_order_relaxed)
      )
  {
    ++z;
  }
}
int main() {
  std::thread th1{read_y_then_add_z};
  std::thread th2{write_x_then_y};
  th1.join();
  th2.join();
  std::cout << z << std::endl;
  return 0;
}
