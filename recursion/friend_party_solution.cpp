#include<iostream>
using namespace std;
/**
 * Given n friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.
 * Input Format
 * In the function an integer N is passed as parameter.
 * Output Format
 * Return an integer representing the total no. of ways

 * Sample Input
 * 3
 * Sample Output
 * 4
 */


int findWays(int n) {
    if (n == 1 || n == 2 || n == 0) {
        return n;
    }
    int solo = findWays(n - 1);
    int paired = findWays(n - 2) * (n - 1);
    return solo + paired;
}

int main() {
    int n = 3;
    cout << findWays(n);
    return 0;
}