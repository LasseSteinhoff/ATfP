
/*  I choosed the problem: Paths in the grid
    First a randomized grid will be computed
    as a fixed sized globally declared array using a const n > 0
    The iterative approach builds up a new grid
    with initializing the trivial cases and then
    maximizing the paths towards the lower right corner.
    The recursive approach works top down by returning
    the lower right corner value without remembering a
    intermediate result.
 */

#include <random>
#include <iostream>
#include <cassert>
using namespace std;

const int n = 3;
int grid[n][n];

int iterativeApproach()
{
int sum[n][n];
sum[0][0]=grid[0][0];
for(int x=1;x<n;x++)
    sum[0][x] = sum[0][x-1] + grid[0][x];
for(int y=1;y<n;y++)
    sum[y][0] = sum[y-1][0] + grid[y][0];

for (int y = 1; y < n; y++)
    for (int x = 1; x < n; x++)
        sum[y][x] = max(sum[y][x-1],sum[y-1][x])+grid[y][x];
return sum[n-1][n-1];
}

int recursiveApproach(int y, int x)
{
    if(x == 0 & y == 0)
        return grid[0][0];
    else if(x == 0)
        return grid[y][x] + recursiveApproach(y - 1, x);
    else if(y == 0)
        return grid[y][x] + recursiveApproach(y , x - 1);
    else
        return grid[y][x] + max(recursiveApproach(y, x - 1), recursiveApproach(y - 1, x));
}

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distribution(1, 10);

    cout << "randomized quadratic grid size n : " << n << endl

    << "Grid : " << endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            grid[i][j]=distribution(gen);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<grid[i][j]<<" ";
        cout<<endl;
    }

    int iterative_result = iterativeApproach();
    int recursive_result = recursiveApproach(n - 1, n - 1);
    assert(iterative_result == recursive_result);

    cout << "The iterative result : " << iterative_result << endl
    << "The recursive result : " << recursive_result;

}

