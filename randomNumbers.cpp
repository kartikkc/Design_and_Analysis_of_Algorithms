// #include <bits/stdc++.h>
// using namespace std;

// int linearCongruentialMethod(long long int Xo, long long int m, long long int a, long long int c, long long int n, long long int maxR)
// {
//     long long int last = Xo;

//     for (int i = 1; i < n; i++)
//     {
//         // Follow the linear congruential method
//         last = ((last * a) + c) % m;

//         // to bound our ans in range [0, maxR-1]
//         last = last % maxR;
//         return last;
//     }
// }

// // Driver Code
// int main()
// {
//     long long int Xo = 5784;  // Seed value
//     long long int m = 759571; // Modulus parameter
//     long long int a = 39;     // Multiplier term
//     long long int c = 9747;   // Increment term

//     int n = 5;
//     linearCongruentialMethod(Xo, m, a, c, n, 500000);
//     return 0;
// }

#include <bits/stdc++.h>
#include <fstream>

using namespace std;

template <class Template>
class LinearCongurential
{
    Template _min; 
    Template _max; 
    Template _a;   // multiplier term
    Template _c;   // increment term
    Template _mod; // modulus parameter

public:
    Template Xo;

    // linear congurent modulus function

    LinearCongurential(T min, T max, T seed, T a, T c, T mod) : _min(min), _max(max), Xo(seed), _a(a), _c(c), _mod(mod){};

    Template operator()()
    {
        // lgc function
        Xo = (_a * Xo + _c) % _mod;

        // bound to limit
        return (Xo % (_max - _min + 1)) + _min;
    }
};

template <class Template>
class RandomNumFileGen
{
public:
    void operator()(const string &filename, int len, LinearCongurential<Template> &generator)
    {
        // Create a new file
        ofstream file(filename);

        // write first num as no of numbers in the file
        file << len << endl;

        // Generate the random numbers and write them to the file
        for (int i = 0; i < len; i++)
        {
            file << generator() << endl;
        }

        file.close();

        cout << "Generated " << len << " random numbers in " << filename << endl;
    }
};

int main()
{
    // init
    int arr[] = {5, 10, 20, 100, 500, 1000, 2500, 10000, 25000, 50000, 75000, 100000};
    int n = sizeof(arr) / sizeof(arr[0]);

    // init lcg function
    LinearCongurential<long long int> func(0, LONG_LONG_MAX, 5784, 39, 71, 75957137);

    // Generate files
    for (int i = 0; i < n; i++)
    {
        RandomNumFileGen<long long int> generator;
        generator("random_" + to_string(arr[i]) + ".txt", arr[i], func);
    }

    return 0;
}