// we don't know when Abhimanyu can skip the enemy or recharge his power. So, we will try all the possibilities and check if he can win or not.
// To try all the possibilities, we will use recursion. We will try to skip the enemy and recharge the power and check if he can win or not.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
// In this problem, there doesn't mention any constraints so in case all power equals to INT_MAX, we can use long long.
// Suppose, 3,4 and 7,8 enemy powers 2147483647. So Abhimanyu can't skip 3rd and 7th enemy. so, half of the power of 3rd and 7th enemy is 1073741823 and will added with 4th and 8th enemy which is greater than INT_MAX. So, we can use long long.

bool isPossible(int ind, ll curr_pow, int skips, int recharge, vector<ll> &powers, bool isSkipPrev, ll init_pow)
{
    // base case
    if (ind > 10)
        return true;
    // if Abhimanyu had not skipped the previous enemy, then calculate the power of the next enemy
    if (ind == 3 || ind == 7)
    {
        if (!isSkipPrev)
        {
            powers[ind] += powers[ind - 1] / 2;
        }
    }
    // if the power of the enemy is less than or equal to the power of Abhimanyu , then Abhimanyu can defeat the enemy
    if (powers[ind] <= curr_pow)
    {
        curr_pow -= powers[ind];
        return isPossible(ind + 1, curr_pow, skips, recharge, powers, false, init_pow);
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
        // if the recharge is available and the power of the enemy is less than or equal to the initial power of Abhimanyu, then recharge the power and defeat the enemy
        if (recharge > 0 && init_pow >= powers[ind])
        {
            canRecharge = isPossible(ind + 1, init_pow - powers[ind], skips, recharge - 1, powers, false, init_pow);
        }
        return canSkip || canRecharge;
    }
}

int main()
{

    ll inti_pow;
    int skips, recharge;
    cout << "Enter Abhimanyu's initial power, number of skips & recharge allowed: ";
    cin >> inti_pow >> skips >> recharge;

    vector<ll> enemy_powers(11);
    cout << "Enter the powers of 11 enemies of each circle: ";
    for (ll &x : enemy_powers)
        cin >> x;
    bool can_win_Abhimanyu = true;
    // if skips are greater than 10, then Abhimanyu definitely wins the battle
    if (skips < 11)
    {
        can_win_Abhimanyu = isPossible(0, inti_pow, skips, recharge, enemy_powers, false, inti_pow);
    }
    cout << (can_win_Abhimanyu ? "Abhimanyu can win the battle!" : "Abhimanyu can't win the battle!") << endl;
    return 0;
}

/*

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