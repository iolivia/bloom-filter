## Bloom filter

### Overview

This is a c++ implementation of a [Bloom Filter](https://en.wikipedia.org/wiki/Bloom_filter). You can read more about the implementation details in the [bloom-filter](https://olivif.github.io/categories/#bloom-filter) blog post series.

### Features

```c++
// Put an element into the Bloom filter
void put(std::string input);

// Check if the item is present
// If true - the item *might* be present
// If false - the item is definitely not present
bool isMaybePresent(std::string input) const;
```

### Example

```c++
// Create the filter
int size = 10000; // the size of the filter - i.e. number of underlying bits used
int k = 3; // the number of hashing functions to use
auto bloomFilter = BloomFilter(size, k);

// Put items in
bloomFilter.put("ABC");
bloomFilter.put("JKDJKD");
bloomFilter.put("UDIG");

// Check if items are present
bool isMaybePresent;

isMaybePresent = bloomFilter.isMaybePresent("ABC");
isMaybePresent = bloomFilter.isMaybePresent("EFG");
```

### Contributing 

For any bugs, questions or contributions, start an issue [here](https://github.com/olivif/bloom-filter/issues). 
