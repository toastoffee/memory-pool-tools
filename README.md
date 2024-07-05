# memory-pool-tools
a simple c++11 implementation of memory pool

### better-memory-allocation

use it if you need to generate lots of heap object of same class

```c++
// 1. construct the pool
MemoryPool<TestClass> pool(1000);

// 2. New the object with the pool
std::vector<TestClass*> objects;
for(size_t i = 0; i < 10000; ++i){
  objects.push_back(pool.New());
}

// 3. Delete it when not needed
for(size_t i = 0; i < 10000; ++i){
  pool.Delete(objects[i]);
}
```

