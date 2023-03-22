// #include <stdio.h>
// #include <chrono>

// using namespace std;

// int main () {
//     double sum = 0;
//     double add = 1;

//     // Start measuring time
//     auto begin = chrono::high_resolution_clock::now();

//     int iterations = 1000*1000*1000;
//     for (int i=0; i<iterations; i++) {
//         sum += add;
//         add /= 2.0;
//     }

//     // Stop measuring time and calculate the elapsed time
//     auto end = chrono::high_resolution_clock::now();
//     auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);

//     printf("Result: %.20f\n", sum);

//     printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);

//     return 0;
// }

// #include <stdio.h>
// #include <processthreadsapi.h>

// double get_cpu_time()
// {
//     FILETIME a, b, c, d;
//     if (GetProcessTimes(GetCurrentProcess(), &a, &b, &c, &d) != 0)
//     {
//         //  Returns total user time.
//         //  Can be tweaked to include kernel times as well.
//         return (double)(d.dwLowDateTime |
//                         ((unsigned long long)d.dwHighDateTime << 32)) *
//                0.0000001;
//     }
//     else
//     {
//         //  Handle error
//         return 0;
//     }
// }

// int main()
// {
//     double sum = 0;
//     double add = 1;

//     // Start measuring time
//     double begin = get_cpu_time();

//     int iterations = 1000 * 1000 * 1000;
//     for (int i = 0; i < iterations; i++)
//     {
//         sum += add;
//         add /= 2.0;
//     }

//     // Stop measuring time and calculate the elapsed time
//     double end = get_cpu_time();
//     double elapsed = (end - begin);

//     printf("Result: %.20f\n", sum);

//     printf("Time measured: %.3f seconds.\n", elapsed);

//     return 0;
// }

// CHRONO FROM GFG

#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

// A sample function whose time taken to
// be measured
void fun()
{
    int i;
    do
    {
        i++;
    } while (i < 2000000000);
}

int main()
{
    cout << "The Program has started Execution!";
    cout << endl;
    auto start = high_resolution_clock::now();

    cout << "The program has entered to excute the simple fuction which will take time to execute!!";
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);


    fun();

    cout << endl;

    auto end = high_resolution_clock::now();

    // Calculating total time taken by the program.
    double time_taken = duration_cast<nanoseconds>(end - start).count();

    time_taken *= 1e-9;

    cout << "Time taken by program is : " << fixed << time_taken << setprecision(9);
    cout << " sec" << endl;
    return 0;
}