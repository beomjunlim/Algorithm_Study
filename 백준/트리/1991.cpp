#include <iostream>
#include <vector>
using namespace std;

pair<char, char> node[27];

void preorder(char cur)
{
  if (cur == '.')
    return;

  cout << cur;
  preorder(node[cur - 'A'].first);
  preorder(node[cur - 'A'].second);
}

void inorder(char cur)
{
  if (cur == '.')
    return;

  inorder(node[cur - 'A'].first);
  cout << cur;
  inorder(node[cur - 'A'].second);
}

void postorder(char cur)
{
  if (cur == '.')
    return;

  postorder(node[cur - 'A'].first);
  postorder(node[cur - 'A'].second);
  cout << cur;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    char a, b, c;
    cin >> a >> b >> c;

    node[a - 'A'].first = b;
    node[a - 'A'].second = c;
  }
  preorder('A');
  cout << '\n';
  inorder('A');
  cout << '\n';
  postorder('A');
}