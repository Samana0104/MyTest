#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
using namespace std;

enum class B
{
    a = 1,
    b,
    c,
    d
};

#define MULTILINE_DEF(a, b)  \
    if ((a) > 2)             \
    {                        \
        auto temp = (b) / 2; \
        (b) += 10;           \
    }

class ClassTest
{
private:

public:
};

struct ABC
{
    int          abc;
    double       cde;
    int_fast32_t egf;
};

void test1(int a, int b, int c, int d, int e) {}

void test2() {}

void test3() {}

namespace Stand
{
    void testC() {};
}  // namespace Stand

class CD
{
private:
    void ADA() {};
};

namespace LevelOneNamespace
{
    namespace LevelTwoNamespace
    {

        template <typename T, int size>
        bool is_sorted(T (&array)[size])
        {
            return std::adjacent_find(array, array + size, std::greater<T>()) == array + size;
        }

        std::vector<uint32_t> returnVector(uint32_t *                    LongNameForParameter1,
                                           double *                      LongNameForParameter2,
                                           const float                   LongNameForParameter3,
                                           const std::map<string, int> & LongNameForParameter4)
        {

            // TODO: This is a long comment that allows you to understand how
            // long comments will be trimmed. Here should be deep thought but
            // it's just not right time for this

            for (auto & i : LongNameForParameter4)
            {
                auto b = someFunctionCall(static_cast<int16_t>(*LongNameForParameter2),
                                          reinterpret_cast<float *>(LongNameForParameter2));
                i.second++;
            }

            do
            {
                if (true && true && false)
                    a--;
                else
                    a++;
            }
            while (false);


            return {};
        }

    }  // namespace LevelTwoNamespace
}  // namespace LevelOneNamespace

template <typename T>
class Test
{
private:
    T dasd;

public:
    T   Test2();
    int Test3() {};

protected:
};

template <typename T>
T Test<T>::Test2()  // asd
{}

struct demo
{
    int          a;
    int          b;
    const char * c;
};

#if Foo
    #include <foo>
#endif

class D
{
public:
    int dae()
    {
        1;
        return 2;
    }

    int dade() {};

    int daee()
    {
        int a = 2;
        return 3;
    }
};

class asd
{
private:
    int a = 2;

public:
    asd()
        : a(3)
    {
        int a;
        int b = 3;
    }
};

int main()
{
    int dec = 1'000'000;
    int a;
    int d = 3 * 1 + 2 / 3 | 1;
    int asd;
    int list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::srand(std::time(0));

    demo de[] = {
        {56,  23, "Hello"},
        {-1,  63, "world"},
        { 7,   5,    "!!"},
        {10,   3,    "!!"},
        {20, 231, "asdas"}
    };

    std::vector<int> a {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 1, 3, 13, 1, 31, 31,
                        1, 2, 2, 3, 3, 3, 3, 3, 3, 3,  3,  3,  3, 3, 3,  3, 3};

    const int         dd = 3;
    const int         cc = 45;
    const int * const bb = &dd;

    do
    {
        std::random_shuffle(list, list + 9);
    }
    while (is_sorted(list));

    int score = 0;

    do
    {
        std::cout << "Current list: ";
        std::copy(list, list + 9, std::ostream_iterator<int>(std::cout, " "));

        int rev;
        while (true)
        {
            std::cout << "\nDigits to reverse? ";
            std::cin >> rev;
            if (rev > 1 && rev < 10)
                break;
            std::cout << "Please enter a value between 2 and 9.";
        }

        ++score;
        std::reverse(list, list + rev);
    }
    while (!is_sorted(list));
    cout << "Congratulations, you sorted the list.\n"
         << "You needed " << score << " reversals." << std::endl;
    return 0;
}
