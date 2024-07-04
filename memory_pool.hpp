/**
  ******************************************************************************
  * @file           : memory_pool.hpp
  * @author         : toastoffee
  * @brief          : None
  * @attention      : None
  * @date           : 2024/7/4
  ******************************************************************************
  */

#include <cstddef>

#ifndef MEMORY_POOL_TOOLS_MEMORY_POOL_HPP
#define MEMORY_POOL_TOOLS_MEMORY_POOL_HPP

template<class T>
class MemoryPool {
    MemoryPool(long long nums);

    T* New();

    void Delete(T* obj);

private:
    void* _freeList;
    char* _pool;
    size_t _reminder;
    long long _nums;
};

template<class T>
MemoryPool<T>::MemoryPool(long long int nums) :
_freeList(nullptr), _pool(nullptr), _reminder(0), _nums(nums){ }

template<class T>
T *MemoryPool<T>::New() {
    T* allocate = nullptr;
    if(_freeList)
    {
        allocate = (T*)_freeList;
        _freeList = *(void**)_freeList;
    }
    else{
        if( _reminder < sizeof(T)){
            _reminder = sizeof(T) * _nums;
            
        }
    }
}

template<class T>
void MemoryPool<T>::Delete(T *obj) {
    obj->~T();
    *(void**)obj = _freeList;
    _freeList = obj;
}


#endif //MEMORY_POOL_TOOLS_MEMORY_POOL_HPP
