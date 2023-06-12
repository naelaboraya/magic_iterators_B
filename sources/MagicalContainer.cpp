#include "MagicalContainer.hpp"
#include <iostream>
#include <algorithm>

using namespace std;
using namespace ariel;

// void MagicalContainer::addElement(int number) {
//     auto it = std::upper_bound(this->_elems.begin(), this->_elems.end(), number);
//     this->_elems.insert(it, number);
// }

// void MagicalContainer::addElement(int number) {
//     auto it = std::upper_bound(this->_elems.begin(), this->_elems.end(), number);
//     this->_elems.insert(it, number);

//     if (std::find(this->ascending_elems.begin(), this->ascending_elems.end(), number) == this->ascending_elems.end()) {
//         auto ascIt = std::lower_bound(this->ascending_elems.begin(), this->ascending_elems.end(), number);
//         this->ascending_elems.insert(ascIt, number);
//     }

//     if (this->side_cross_elems.empty()) {
//         this->side_cross_elems.push_back(number);
//     } else {
//         auto crossIt = std::find_if(this->side_cross_elems.begin(), this->side_cross_elems.end(), [number](int elem) {
//             return number < elem;
//         });
//         this->side_cross_elems.insert(crossIt, number);
//     }

//     if (number > 1 && std::all_of(this->prime_elems.begin(), this->prime_elems.end(), [number](int prime) { return number % prime != 0; })) {
//         this->prime_elems.push_back(number);
//     }
// }

void MagicalContainer::addElement(int number){
    this->_elems.push_back(number);
    if(isPrime(number)){
        this->prime_elems.push_back(number);
    }
    this->ascending_elems.push_back(number);
    std::sort(this->ascending_elems.begin(), this->ascending_elems.end());
    this->side_cross_elems.push_back(number);
    sidecrossSort(this->side_cross_elems);
}




void MagicalContainer::removeElement(int number) {
        // this->_elems.
        
        //     for (auto it = this->_elems.begin(); it != this->_elems.end(); ++it) {
                
        //         if (*it == number) {
        //             this->_elems.erase(it);
        //             break;
        //         }
        //         throw std::runtime_error("element not found");
        //     }
        // }
        auto it = std::find(this->_elems.begin(), this->_elems.end(), number);
        if (it != this->_elems.end()){
        this->_elems.erase(it);}
        else {
            throw std::runtime_error("zbve");
        }
}
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& container) : _container(container) , index(0){}
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& container) : _container(container) , index(0){}
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container) : _container(container) , index(0){}
