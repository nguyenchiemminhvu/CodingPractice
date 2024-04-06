// https://c...content-available-to-author-only...e.com/contest/problem/1250/1
 
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cstdint>
#include <climits>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
 
bool canGoThrough(
    int64_t health, 
    int64_t max_health, 
    int64_t num_room, 
    const std::vector<int64_t>& obstacles, 
    const std::vector<int64_t>& recovery, 
    const std::string& recover_type)
{
    for (int64_t i = 0; i < num_room; i++)
    {
        if (obstacles[i] >= health)
        {
            return false; // Player can't pass the room
        }
 
        health -= obstacles[i];
 
        if (recover_type[i] == '+')
        {
            health += recovery[i]; // Player recovers health
        }
        else
        {
            health = (health > max_health / recovery[i]) ? health : max_health;
        }

        if (health > max_health)
            return true;
    }
 
    return true; // Player can pass all the rooms
}

int64_t findMinHealth(
    int64_t max_health, 
    int64_t num_room, 
    const std::vector<int64_t>& obstacles, 
    const std::vector<int64_t>& recovery, 
    const std::string& recover_type)
{
    int64_t res = max_health;
    int64_t left = 0;
    int64_t right = max_health + 1;
    while (left <= right)
    {
        int64_t mid = left + (right - left) / 2;
        if (canGoThrough(mid, max_health, num_room, obstacles, recovery, recover_type))
        {
            res = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return res;
}
 
int32_t main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int64_t T;
    std::cin >> T;
    for (int64_t t = 0; t < T; t++)
    {
        int N;
        std::cin >> N;
        std::vector<int64_t> D(N, 0);
        std::string S;
        std::vector<int64_t> R(N, 0);
 
        int64_t max_health = 0;
        for (int64_t i = 0; i < N; i++)
        {
            std::cin >> D[i];
            max_health += D[i];
        }
 
        std::cin >> S;
 
        for (int64_t i = 0; i < N; i++)
        {
            std::cin >> R[i];
        }

        std::cout << findMinHealth(max_health, N, D, R, S) << std::endl;
    }
 
    return 0;
}