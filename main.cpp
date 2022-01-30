#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

std::vector<int> inputArray();
int jumpingOnClouds(std::vector<int>);

int main()
{
    auto arrayOfBinaryInt = inputArray();
    std::cout << "Minimun number of jumps: " << jumpingOnClouds(arrayOfBinaryInt) << std::endl;
    return 0;
}

std::vector<int> inputArray() {
    int n, temp; std::vector<int> C;
    std::cout << "Input array size: " << std::endl; std::cin >> n;
    std::cout << "Input array of binary integers" << std::endl;
    for (int i = 0; i < n; i++) { std::cin >> temp; C.push_back(temp); }
    try {
        if (C.size() < 2 || C.size() > 100 || C[0] != 0 || C[C.size() - 1] != 1) {
            throw std::invalid_argument("Out of range/not a proper format.");
        }
    }
    catch (std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }
    return C;
};

int jumpingOnClouds(std::vector<int> arrayOfBinaryInt) {
    int minNumberOfJumps = 0, i = 0; 
    for (int i = 0; i < arrayOfBinaryInt.size()-1;)  {
        minNumberOfJumps++; 
        if (arrayOfBinaryInt[i + 2] == 1) { i++; }
        else i += 2;
    }
    return minNumberOfJumps;
}
