#include <iostream>
#include <vector>

// Sieve of Eratosthenes algorithm to find prime numbers up to n
std::vector<bool> sieve(int n) {
    std::vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    return isPrime;
}

int findLargestPrime(int n) {
    std::vector<bool> isPrime = sieve(n);

    // Starting from n, find the largest prime number
    for (int i = n; i >= 2; --i) {
        if (isPrime[i]) {
            return i;
        }
    }

    // If no prime found, return -1 or handle it as needed
    return -1;
}

int main() {
    int n;
    std::cout << "Enter a positive integer (n): ";
    std::cin >> n;

    if (n <= 1) {
        std::cout << "There is no prime number less than or equal to " << n << std::endl;
    }
    else {
        int largestPrime = findLargestPrime(n);
        if (largestPrime != -1) {
            std::cout << "The largest prime number less than or equal to " << n << " is: " << largestPrime << std::endl;
        }
        else {
            std::cout << "No prime number found." << std::endl;
        }
    }

    return 0;
}
