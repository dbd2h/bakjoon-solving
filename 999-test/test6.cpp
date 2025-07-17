#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>

using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(nullptr);
   cout.tie(nullptr);


   int n, m;
   cin >> n >> m;

   vector<vector<int>> v(n, vector<int>(m));
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         cin >> v[i][j];
      }
   }

   vector<pair<int, int>> wall;
   for (int i = 0; i < 2; i++) {
      int a, b;
      cin >> a >> b;

      wall.push_back({ a,b });

   }

   sort(wall.begin(), wall.end());

   bool isVertical = false;

   if (wall[0].second == wall[1].second) {
      isVertical = true;
   }

   vector<vector<int>> dp(n, vector<int>(m));
   for(int i=0;i<n;i++)
   {
        for(int j=0;j<m;j++)
        {
            dp[i][j]=-1000000;
        }
   }
   dp[0][0] = v[0][0];

   // 행 채우기. 벽이 수평일 때 막힘
   for (int i = 1; i < n; i++) {
      if (!isVertical && wall[0].second == 0 && i >= wall[0].first) {
         continue;
      }
      dp[i][0] = dp[i - 1][0] + v[i][0];
   }

   // 열 채우기. 벽이 수직일 때 막힘

   for (int i = 1; i < m; i++) {
      if (isVertical && wall[0].first == 0 && i >= wall[0].second) {
         continue;
      }
      dp[0][i] = dp[0][i - 1] + v[0][i];
   }



   // 벽이 없을 떄
   if (isVertical && wall[0].first == wall[1].first) {
      for (int i = 1; i < n; i++) {
         for (int j = 1; j < m; j++) {
            dp[i][j] = max(dp[i - 1][j] + v[i][j], dp[i][j - 1] + v[i][j]);
            
         }
      }

      cout << dp[n - 1][m - 1];
      return 0;
   }

   


   // 벽이 수직 -> second가 같고 first가 다른 경우
   // 벽이 수평 -> first가 같고 second가 다른 경우



   if (isVertical) {
      // 벽이 수직 -> second가 같고 first가 다른 경우
      for (int i = 1; i < n; i++) {
         for (int j = 1; j < m; j++) {
            if (j == wall[0].second && wall[0].first <= i && i < wall[1].first) {

               if (dp[i - 1][j] != 0) {
                  dp[i][j] = dp[i - 1][j] + v[i][j];
               }
               else dp[i][j] = 0;;

            }
            else {


               dp[i][j] = max(dp[i - 1][j] + v[i][j], dp[i][j - 1] + v[i][j]);
            }
         }
      }
   }
   else {
      // 벽이 수평 -> first가 같고 second가 다른 경우
      for (int i = 1; i < n; i++) {
         for (int j = 1; j < m; j++) {
            if (i == wall[0].first && wall[0].second <= j && j < wall[1].second) {
               if (dp[i][j - 1] != 0) {
                  dp[i][j] = dp[i][j - 1] + v[i][j];
               }
               else continue;
            }
            else dp[i][j] = max(dp[i - 1][j] + v[i][j], dp[i][j - 1] + v[i][j]);
         }
      }
   }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }

   if (dp[n - 1][m - 1] == 0) {
      cout << "Entity";
   }
   else cout << dp[n - 1][m - 1];


   return 0;
}




/*


선을 맞대고, 이미 지나간 상태일 때, 이전값을 불러오지 않게 하기.

벽이 x축에 평행할 수도, y축에 평행할 숟 있음

x축에 평행할 때
(2,1), (2,4)일 때, x좌표가 2이면서 y좌표가 1 이상~4미만이 아닐 때
(a,b) (a,c)일 때, x좌표가 a이면서 y좌표가 b 미만 c 이상일 때
-> 위에서 끌어오는 값 사용불가

y축에 평행할 때
(a,b),(c,b)일 때 y좌표가 b이면서 y좌표가 a 이상 b 미만일 때
-> 왼쪽에서 끌어오는 값 사용불가



반례

4 6
1 3 3 10 3 5
8 1 8 7 6 9
10 2 2 3 7 2
6 3 1 2 10 1
4 0 4 4


4 6
1 3 3 10 3 5
8 1 8 7 6 9
10 2 2 3 7 2
6 3 1 2 10 1
0 1 4 1

*/

