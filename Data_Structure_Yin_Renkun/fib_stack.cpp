#include <iostream>
#include <string>

int fib(int n)
{
    static int depth = 0;

    const auto tab = [n]
        { return std::string(depth * 4, ' ') + " fib(" + std::to_string(n) + ") "; };

    const auto noisy_ret = [&tab](int r)
        { std::cout << tab() << ": return " << r << '\n'; --depth; return r; };

    ++depth;
    std::cout << tab() << ": begin\n";

    if (n < 2) return noisy_ret(0);
    else if (n == 2) return noisy_ret(1);
    else
    {
        std::cout << tab() << "== fib(" << n - 1 << ") + fib(" << n - 2 << ")\n";

        std::cout << tab() << ": call fib(" << n - 1 << ")\n";
        const int fn1 = fib(n - 1);
        std::cout << tab() << ": fib(" << n - 1 << ") returned " << fn1 << '\n';

        std::cout << tab() << ": call fib(" << n - 2 << ")\n";
        const int fn2 = fib(n - 2);
        std::cout << tab() << ": fib(" << n - 2 << ") returned " << fn2 << '\n';

        std::cout << tab() << "== fib(" << n - 1 << ") + fib(" << n - 2 << ") == " << fn1 + fn2 << '\n';
        return  noisy_ret(fn1 + fn2);
    }
}
int main()
{
    std::cout << "main: call fib(6)\n";
    const int f6 = fib(6);
    std::cout << "main: fib(6) returned " << f6 << '\n';
}
