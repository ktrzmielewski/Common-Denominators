#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


class Fracts
{

public:
    static std::string convertFrac(std::vector<std::vector<unsigned long long>>& lst);
};

int gcd(long long int a, long long int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

unsigned long long lcm(unsigned long long a, unsigned long long b)
{
    return (a / gcd(a, b)) * b;
}

std::string Fracts::convertFrac(std::vector<std::vector<unsigned long long>>& lst) {
    std::string ans;
    unsigned long long firstDenom = lst[0][1];
    unsigned long long secondDenom = lst[1][1];
    unsigned long long currentDenom = 1;

    std::cout << "Before" << std::endl;
    for (auto number : lst) {
        std::cout << number[0] << ' ' << number[1] << std::endl;

        currentDenom = lcm(number[1], currentDenom);
    }

    std::cout << "After" << std::endl;
    for (auto number : lst) {
        unsigned long long multiplier = currentDenom / number[1];
        number[0] *= multiplier;
        number[1] *= multiplier;
        std::cout << number[0] << ' ' << number[1] << std::endl;
        ans += ('(' + std::to_string(number[0]) + ',' + std::to_string(number[1]) + ')');
    }

    return ans;
}

int main() {
    // Basic test case
    std::vector<std::vector<unsigned long long>> r1 = { {1, 2}, {1, 3}, {1, 4} };

    // Other test cases
    /*std::vector<std::vector<unsigned long long>> r1 = { {69, 130} ,{87, 1310},{3, 4} };*/
    /*std::vector<std::vector<unsigned long long>> r1 = { {27115, 5262}, {87546, 11111111}, {43216, 255689} };*/

    std::string ans1 = Fracts::convertFrac(r1);

    return 0;
}