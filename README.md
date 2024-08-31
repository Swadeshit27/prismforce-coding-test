# Prismforce ASDE Algorithm Test

## Question

Imagine Abhimanyu in Chakravyuha. There are 11 circles in the Chakravyuha surrounded by different enemies. Abhimanyu is located in the innermost circle and has to cross all the 11 circles to reach Pandavas army back. 

1. Each circle is guarded by different enemy where enemy is equipped with k1, k2……k11 powers Abhmanyu start from the innermost circle with p power Abhimanyu has a boon to skip fighting enemy a times 

2. Abhmanyu can recharge himself with power b times 
Battling in each circle will result in loss of the same power from Abhimanyu as the enemy. 

3. If Abhmanyu enter the circle with energy less than the respective enemy, he will lose the battle.

5. k3 and k7 enemies are endured with power to regenerate themselves once with half of their initial power and can attack Abhimanyu from behind if he is battling in iteratively next circle 


##  TestCases
*Test Case 1:*

- initialPower = 17
- skips = 3
- recharges = 3
- EnemyPowers = [7, 8, 5, 4, 10, 9, 11, 6, 2, 3, 7]

```bash
    17 3 3
    7 8 5 4 10 9 11 6 2 3 7
```

**OUTPUT**
`Abhimanyu can win the battle!`


*Test Case 2 :*

- initialPower = 25
- skips = 2
- recharges = 1
- EnemyPowers = [9, 7, 11, 5, 6, 12, 15, 8, 9, 4, 3]

```bash
    25 2 1
    9 7 11 5 6 12 15 8 9 4 3
```
**OUTPUT**
`Abhimanyu can't win the battle!`

## Time & space Complexity

1. Time complexity: `O(1)`
2. Space complexity: `O(1)`