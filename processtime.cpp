#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;

void sample_loop(int i)
{
    do
    {
        i--;
    } while (i > 0 );
}

int main()
{
    int i;
    cout << "The Program has started Execution!";
    cout << endl;
    cout<<"Enter the maximum time you like:"<<endl<<">";
    cin>>i;
    auto start = high_resolution_clock::now();

    cout << "The program has entered to excute the simple fuction which will take time to execute!!";

    ios_base::sync_with_stdio(false);


    sample_loop(i);

    cout << endl;

    auto end = high_resolution_clock::now();


    double time_taken = duration_cast<nanoseconds>(end - start).count();

    time_taken *= 1e-9;

    cout << "Time taken by program is : " << fixed << time_taken << setprecision(9);
    cout << " sec" << endl;
    return 0;
}