#include <iostream>
using namespace std;

#define MAX 101

int arr[MAX][MAX];
int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
int dir_num;
int x, y;
int n;

bool InRange(int x, int y, int n)
{
  return (0 < x && x <= n && 0 < y && y <= n);
}

int main()
{

  cin >> n;

  x = y = (n / 2 + 1);
  dir_num = 0;
  int num = 1;
  int move_num=1;
 
 while(InRange(x,y,n)){
    for(int i=0; i<move_num; i++){
        arr[y][x]=num++;
        x=x+dx[dir_num];
        y=y+dy[dir_num];
        if(!InRange(x,y,n))
        break;
    }
    dir_num = (dir_num+1)%4;
    if(dir_num==0||dir_num==2)
    move_num++;
 }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cout << arr[i][j] << " ";
    }
    cout << '\n';
  }
  return 0;
}
