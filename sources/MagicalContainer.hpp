#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP

#include <iostream>
#include <vector>


namespace ariel{

class MagicalContainer{

    private:
        std::vector<int> _elems;
        
        std::vector<int> ascending_elems;
        std::vector<int> side_cross_elems;
        std::vector<int> prime_elems;

    public:
        MagicalContainer(){}
        ~MagicalContainer(){}
        
        //getters : return the vectors 
        std::vector<int> get_elements () const {
            return this->_elems;
        }
        std::vector<int> get_ascending_elements () const {
            return this->ascending_elems;
        }
        std::vector<int> get_prime_elements () const {
            return this->prime_elems;
        }
        std::vector<int> get_cross_elements () const {
            return this->side_cross_elems;
        }
        

    //functions:

        void addElement(int number);
        void removeElement(int number);
        int size() const {return this->_elems.size();}



        class AscendingIterator{
            private:
               MagicalContainer& _container;
               size_t index; 


            public:
             
                AscendingIterator(MagicalContainer& container);
                
                AscendingIterator(const AscendingIterator& other)
		: _container(other._container), index(other.index) {}

	    	AscendingIterator& operator=(const AscendingIterator& other) {
    if (this != &other) {
        if (&_container != &other._container) {
            throw std::runtime_error("Iterators are pointing to different containers");
        }
        _container = other._container;
        index = other.index;
    }
    return *this;
}

                ~AscendingIterator(){}
                
                

                bool operator==(const AscendingIterator& other) const{
                    return this->index == other.index;
                }
                bool operator!=(const AscendingIterator& other) const {
                return !(*this == other);//Not equal
                }
                bool operator>(const AscendingIterator& other) const {
                return this->index > other.index;
                }
                bool operator<(const AscendingIterator& other) const {
                return this->index < other.index;
                }
                int operator*() const {
                return this->_container.ascending_elems[index];
                }
                AscendingIterator& operator++() {
                if(this->index>=(size_t)this->_container.ascending_elems.size()){
                    throw std::runtime_error("out of bounds");
                }    
                ++this->index;
                return *this;
                }
                AscendingIterator begin() {
                    return AscendingIterator(_container);
                }
                AscendingIterator end(){
                    AscendingIterator iterator(_container);
                    iterator.index =(size_t) _container.ascending_elems.size();
                    return iterator;
                }
                
        };

        class SideCrossIterator{
            private:
               MagicalContainer& _container;
               size_t index; 


            public:
                
                SideCrossIterator(MagicalContainer& container);
                
                 SideCrossIterator(const SideCrossIterator& other)
		: _container(other._container), index(other.index) {}

	   	SideCrossIterator& operator=(const SideCrossIterator& other) {
		    if (this != &other) {
			if (&_container != &other._container) {
			    throw std::runtime_error("Iterators are pointing to different containers");
			}
			_container = other._container;
			index = other.index;
		    }
		    return *this;
		}

                ~SideCrossIterator(){}

                bool operator==(const SideCrossIterator& other) const{
                    return this->index == other.index;
                }
                bool operator!=(const SideCrossIterator& other) const {
                return !(*this == other);//Not equal
                }
                bool operator>(const SideCrossIterator& other) const {
                return this->index > other.index;
                }
                bool operator<(const SideCrossIterator& other) const {
                return this->index < other.index;
                }
                int operator*() const {
                return this->_container.side_cross_elems[index];
                }
                SideCrossIterator& operator++() {
                if(this->index >= size_t(this->_container.side_cross_elems.size())){
                    throw std::runtime_error("out of bounds");
                }
                ++this->index;
                return *this;
                }
                SideCrossIterator begin() {
                    return SideCrossIterator(_container);
                }
                SideCrossIterator end(){
                    SideCrossIterator iterator(_container);
                    iterator.index =(size_t) _container.size();
                    return iterator;
                } 

        };

        class PrimeIterator{
            private:
               MagicalContainer& _container;
               size_t index; 


            public:
                
                PrimeIterator(MagicalContainer& container);
                
                PrimeIterator(const PrimeIterator& other)
		: _container(other._container), index(other.index) {}

	    	PrimeIterator& operator=(const PrimeIterator& other) {
		    if (this != &other) {
			if (&_container != &other._container) {
			    throw std::runtime_error("Iterators are pointing to different containers");
			}
			_container = other._container;
			index = other.index;
		    }
		    return *this;
		}


                ~PrimeIterator(){}

                bool operator==(const PrimeIterator& other) const{
                    return this->index == other.index;
                }
                bool operator!=(const PrimeIterator& other) const {
                return !(*this == other);//Not equal
                }
                bool operator>(const PrimeIterator& other) const {
                return this->index > other.index;
                }
                bool operator<(const PrimeIterator& other) const {
                return this->index < other.index;
                }
                int operator*() const {
                return this->_container.prime_elems.at(index);
                }
                PrimeIterator& operator++() {
                if(this->index >= size_t(this->_container.prime_elems.size())){
                    throw std::runtime_error("out of bounds");
                }
                ++this->index;
                return *this;
                }
                PrimeIterator begin() {
                    return PrimeIterator(_container);
                }
                PrimeIterator end(){
                    PrimeIterator iterator(_container);
                    iterator.index =(size_t) _container.prime_elems.size();
                    return iterator;
                }      
        };


    

    


};
    static bool isPrime(int number) {
    if (number < 2) {
        return false;
    }

    for (int i = 2; i * i <= number; ++i) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

static void sidecrossSort(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

    std::vector<int> result;
    std::vector<int>::size_type left = 0;
    std::vector<int>::size_type right = nums.size() - 1;

    while (left <= right) {
        result.push_back(nums[left++]);
        if (left <= right) {
            result.push_back(nums[right--]);
        }
    }

    nums = result;
}

}

#endif
