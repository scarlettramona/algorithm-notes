
#include <iostream>
#include <set>
#include <string>


using namespace std; 
int main()
{
    set<string> myset{"hello"};
 
    for (int i{2}; i; --i)
    {
        if (auto [iter, success] = myset.insert("Hello"); success) 
            cout << "Insert is successful. The value is "
                      << quoted(*iter) << ".\n";
        else
            cout << "The value " << quoted(*iter)
                      << " already exists in the set.\n";
    }
 
    struct BitFields
    {
        // C++20: default member initializer for bit-fields
        int b : 4 {1}, d : 4 {2}, p : 4 {3}, q : 4 {4};
    };
 
    {
        const auto [b, d, p, q] = BitFields{};
        cout << b << ' ' << d << ' ' << p << ' ' << q << '\n';
    }
 
    {
        const auto [b, d, p, q] = []{ return BitFields{4, 3, 2, 1}; }();
        cout << b << ' ' << d << ' ' << p << ' ' << q << '\n';
    }
 
    {
        BitFields s;
 
        auto& [b, d, p, q] = s;
        cout << b << ' ' << d << ' ' << p << ' ' << q << '\n';
 
        b = 4, d = 3, p = 2, q = 1;
        cout << s.b << ' ' << s.d << ' ' << s.p << ' ' << s.q << '\n';
    }
}