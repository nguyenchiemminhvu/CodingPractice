// https://codejam.lge.com/contest/problem/1250/2

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cstdint>
#include <climits>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

int64_t minElectricBill(
    int64_t cur_bat, 
    int64_t cap_bat, 
    int64_t num_day, 
    const std::vector<int64_t>& possible_charge, 
    const std::vector<int64_t>& consume, 
    const std::vector<int64_t>& price_rate)
{
	std::cout << "cur_bat: " << cur_bat << std::endl;
    std::cout << "cap_bat: " << cap_bat << std::endl;
    std::cout << "num_day: " << num_day << std::endl;

    std::cout << "possible_charge: ";
    for (const auto& charge : possible_charge) {
        std::cout << charge << " ";
    }
    std::cout << std::endl;

    std::cout << "consume: ";
    for (const auto& c : consume) {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    std::cout << "price_rate: ";
    for (const auto& rate : price_rate) {
        std::cout << rate << " ";
    }
    std::cout << std::endl;
    
    return 0;
}

int32_t main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T;
    std::cin >> T;

    for (int64_t t = 0; t < T; t++)
    {
        int64_t N, C, B;
        std::cin >> N >> B >> C;

        std::vector<int64_t> P(N, 0);
        std::vector<int64_t> F(N, 0);
        std::vector<int64_t> D(N, 0);

        for (int i = 0; i < N; i++)
        {
            std::cin >> P[i];
        }

        for (int i = 0; i < N; i++)
        {
            std::cin >> F[i];
        }

        for (int i = 0; i < N; i++)
        {
            std::cin >> D[i];
        }

        std::cout << minElectricBill(B, C, N, P, D, F) << std::endl;
    }

    return 0;
}