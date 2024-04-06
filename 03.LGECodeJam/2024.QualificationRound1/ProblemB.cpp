// https://codejam.lge.com/contest/problem/1250/2

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cstdint>
#include <climits>
#include <vector>
#include <unordered_map>
#include <limits>
#include <string>
#include <numeric>
#include <algorithm>

#define ll long long
ll original_bat;
ll cur_bat;
ll cap_bat;
ll num_day;
ll charge[1001];
ll rate[1001];
ll consume[1001];
ll DP[1001][1001];

ll minElectricBill(ll ith_day, ll cur_bat)
{
    if (ith_day >= num_day)
    {
        if (original_bat <= cur_bat)
            return 0;
        return LLONG_MAX;
    }

    if (DP[ith_day][cur_bat] != -1)
    {
        return DP[ith_day][cur_bat];
    }

    ll use_electric = LLONG_MAX;
    ll use_battery = LLONG_MAX;
    use_electric = std::min(use_electric, rate[ith_day] * consume[ith_day] + minElectricBill(ith_day + 1, std::min(cur_bat + charge[ith_day], cap_bat)));
    if (cur_bat >= consume[ith_day])
    {
        use_battery = minElectricBill(ith_day + 1, cur_bat - consume[ith_day]);
    }

    if (use_electric < 0)
    {
        use_electric = LLONG_MAX;
    }

    DP[ith_day][cur_bat] = std::min(use_electric, use_battery);
    return DP[ith_day][cur_bat];
}

int32_t main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    ll T;
    std::cin >> T;

    for (ll t = 0; t < T; t++)
    {
        std::cin >> num_day >> cur_bat >> cap_bat;

        for (ll i = 0; i < num_day; i++)
        {
            std::cin >> charge[i];
        }

        for (ll i = 0; i < num_day; i++)
        {
            std::cin >> rate[i];
        }

        for (ll i = 0; i < num_day; i++)
        {
            std::cin >> consume[i];
        }

        for (ll i = 0; i < num_day; i++)
        {
            for(ll j = 0; j <= cap_bat; j++)
            {
                DP[i][j] = -1;
            }
        }

        original_bat = cur_bat;
        std::cout << minElectricBill(0, cur_bat) << std::endl;
    }

    return 0;
}