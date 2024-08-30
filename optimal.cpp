//  We can optimize the above code using memoization. We will store the results of the subproblems in a 4D dp array. The dp array will store the results of the subproblems based on the current index, number of skips, and recharge available. If the subproblem is already solved, then we will return the result from the dp array. Otherwise, we will calculate the result and store it in the dp array. Here is the optimized code:

#include <bits/stdc++.h>
using namespace std;

int dp[12][100001][12][12]; // if power is greater than 100000, then you can use vector instead of array

bool isPossible(int ind, int curr_pow, int skips, int recharge, vector<int> &powers, bool isSkipPrev, int init_pow)
{
    // base case
    if (ind > 10)
        return true;
    // cout << ind << " " << curr_pow << " " << skips << " " << recharge << " " << isSkipPrev << " " << dp[ind][curr_pow][skips][recharge] << endl;
    // memoization
    if (dp[ind][curr_pow][skips][recharge] != -1)
    {
        return dp[ind][curr_pow][skips][recharge];
    }
    // if Abhimanyu  had not skipped the previous enemy, then calculate the power of the next enemy
    if (ind == 3 || ind == 7)
    {
        if (!isSkipPrev)
        {
            powers[ind] += powers[ind - 1] / 2;
        }
    }
    // if the power of the enemy is less than or equal to the power of Abhimanyu , then Abhimanyu  can defeat the enemy
    if (powers[ind] <= curr_pow)
    {
        curr_pow -= powers[ind];
        return dp[ind][curr_pow][skips][recharge] = isPossible(ind + 1, curr_pow, skips, recharge, powers, false, init_pow);
    }
    else
    {
        bool canSkip = false;
        // if the number of skips is greater than 0, then skip the enemy
        if (skips > 0)
        {
            canSkip = isPossible(ind + 1, curr_pow, skips - 1, recharge, powers, true, init_pow);
        }
        bool canRecharge = false;
        // if the recharge is available and the power of the enemy is less than or equal to the initial power of Abhimanyu , then recharge the power and defeat the enemy
        if (recharge > 0 && init_pow >= powers[ind])
        {
            canRecharge = isPossible(ind + 1, init_pow - powers[ind], skips, recharge - 1, powers, false, init_pow);
        }

        return dp[ind][curr_pow][skips][recharge] = canSkip || canRecharge;
    }
}

int main()
{

    int inti_pow, skips, recharge;
    cout << "Enter Abhimanyu 's initial power, number of skips & recharge allowed: ";
    cin >> inti_pow >> skips >> recharge;

    vector<int> enemy_powers(11);
    cout << "Enter the powers of 11 enemies of each circle: ";
    for (int &x : enemy_powers)
        cin >> x;
    bool can_win_Abhimanyu = true;
    if (skips < 11)
    {
        memset(dp, -1, sizeof dp);
        can_win_Abhimanyu = isPossible(0, inti_pow, skips, recharge, enemy_powers, false, inti_pow);
    }
    cout << (can_win_Abhimanyu ? "Abhimanyu can win the battle!" : "Abhimanyu can't win the battle!") << endl;
    return 0;
}

/*
Time Complexity: O(11×100001×12×12) ie. O(1)
Space Complexity: O(11×100001×12×12) as the dp array is of constant size ie. O(1)

Test Case 1:
Input:
Enter Abhimanyu's initial power, number of skips & recharge allowed: 25 2 1
Enter the powers of 11 enemies of each circle: 9 7 11 5 6 12 15 8 9 4 3
Output:
Abhimanyu can't win the battle!

Test Case 2:
Input:
Enter Abhimanyu's initial power, number of skips & recharge allowed: 25 3 2
Enter the powers of 11 enemies of each circle: 9 7 11 5 6 12 15 8 9 4 3
Output:
Abhimanyu can win the battle!
*/