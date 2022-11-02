#define max_length 10
#include <iostream>

int fibonacci(int N)  // рекурсивная функция
{
  if (N == 1 || N == 2)
    return 1; // первые 2 числа равны 1
  return fibonacci(N - 1) + fibonacci(N - 2); // складываем предыдущие 2 числа
}
int main()
{
  int N;
  fibonacci(10);
  return 0;
}
