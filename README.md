## Bloom filter

### Overview

This is a c++ implementation of a [Bloom Filter](https://en.wikipedia.org/wiki/Bloom_filter). You can read more about the implementation details in the [bloom-filter](https%3A%2F%2Folivif.github.io%2Fcategories%2F%23bloom%20filter) blog post series.

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



