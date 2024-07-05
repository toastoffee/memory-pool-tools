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
#include <cstdlib>
#include <system_error>

#ifndef MEMORY_POOL_TOOLS_MEMORY_POOL_HPP
#define MEMORY_POOL_TOOLS_MEMORY_POOL_HPP

template<class T>
class MemoryPool {
public:
    explicit MemoryPool(long long nums);

    T* New();

    void Delete(T* obj);

private:
    void* _freeList;
    char* _pool;
    size_t _poolSize;
    long long _nums;
};

template<class T>
MemoryPool<T>::MemoryPool(long long int nums) :
_freeList(nullptr), _pool(nullptr), _poolSize(0), _nums(nums){ }

template<class T>
T *MemoryPool<T>::New() {
    T* allocate = nullptr;
    if(_freeList)
    {
        allocate = (T*)_freeList;
        _freeList = *(void**)_freeList;
    }
    else{
        // malloc new memory space
        if(_poolSize == 0){
            size_t objSize = sizeof(T) < sizeof(void*) ? sizeof(void*) : sizeof(T);
            _poolSize = sizeof(T) * _nums;
            _pool = (char*) malloc(_poolSize);

            if(_pool == nullptr){
                throw std::bad_alloc();
            }
        }

        allocate = (T*)_pool;
        size_t objSize = sizeof(T) < sizeof(void*) ? sizeof(void*) : sizeof(T);
        _poolSize -= objSize;
    }
    new(allocate) T();
    if(allocate == nullptr){
        int n = 0;
    }
    return allocate;
}

template<class T>
void MemoryPool<T>::Delete(T *obj) {
    obj->~T();
    *(void**)obj = _freeList;
    _freeList = obj;
}


#endif //MEMORY_POOL_TOOLS_MEMORY_POOL_HPP
