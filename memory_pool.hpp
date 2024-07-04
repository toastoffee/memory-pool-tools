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
};


#endif //MEMORY_POOL_TOOLS_MEMORY_POOL_HPP
