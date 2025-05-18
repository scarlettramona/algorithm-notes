#include <vector>
#include <stdexcept>
#include <iostream>
#include <unordered_map> 

using namespace std; 

int nthLowestSelling(const std::vector<int>& sales, int n) 
{
    
    if(sales.empty())
        throw std::invalid_argument("sales is empty");
    
    
        
    // freqs of everything
    
    std:: unordered_map<int, int> frequencies;
    frequencies.reserve(sales.size()); 

    for (int id : sales)
    {
        ++frequencies[id];
    }

    


    std::vector<std::pair<int,int>> books;
    books.reserve(frequencies.size());

    for (auto& [id, count] : frequencies)
    {
        books.emplace_back(count, id);
    }



    std::nth_element(books.begin(), books.begin() + (n - 1), books.end(), [](auto &a, auto&b) {return (a.first < b.first)});

    return books[n -1].second;
};

#ifndef RunTests
int main()
{
    std::vector<int> input = { 11, 99, 44, 77, 99, 11, 33, 44, 77, 11, 99, 44, 11, 99, 11 };

    int x = nthLowestSelling(input, 2);
    std::cout << x;
}
#endif