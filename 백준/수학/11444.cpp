#include <iostream>
#include <map>
using namespace std;

#define DIV 1000000007

map<long long, long long> arr;

long long fibo(long long n)
{
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  if (n == 2)
    return 1;

  if (arr.find(n) != arr.end())
    return arr[n];

  if (n % 2 == 0)
  {
    long long m = n / 2;
    long long temp1 = fibo(m - 1);
    long long temp2 = fibo(m);
    arr[n] = (temp2 * temp2 + 2 * temp1 * temp2) % DIV;
    return arr[n];
  }
  long long m = (n + 1) / 2;
  long long temp1 = fibo(m);
  long long temp2 = fibo(m - 1);
  arr[n] = (temp1 * temp1 + temp2 * temp2) % DIV;
  return arr[n];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long n;
  cin >> n;
  cout << fibo(n);
}