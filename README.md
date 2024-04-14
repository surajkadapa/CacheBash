<!-- language: lang-none -->
            ______           __         ____             __  
           / ____/___ ______/ /_  ___  / __ )____ ______/ /_ 
          / /   / __ `/ ___/ __ \/ _ \/ __  / __ `/ ___/ __ \
         / /___/ /_/ / /__/ / / /  __/ /_/ / /_/ (__  ) / / /
         \____/\__,_/\___/_/ /_/\___/_____/\__,_/____/_/ /_/ 

---

A cache simulator written with only the standard C library that can simulate direct mapped and fully associative cache(FIFO), with more cache schemes and replacement algorithims to be added soon.

![](https://github.com/surajkadapa/CacheBash/actions/workflows/makefile.yml/badge.svg)
---

# What is a cache?
Cache is a component between the CPU and the Main Memory(usually the RAM), and it stores recently accessed data since most of the computers in todays day and age spend most of their time moving data in and out of the memory and that is usually the slowest operation. \
Cache is a block of memory with data likely to be used again. A hardware cache is implemented using different schemes for replacement.\
Caches are relatively small to be cost effective. Nevertheless, they are highly effective in many areas since computer programs access data with a high degree of locality of reference.\
A cache hit occurs when the requested data from a program is present in the cache.\
A cache miss occurs when the requested data from a program is not present in the cache, and depending on the cache policy it will bring the data from the main memory to the cache.

---
# How to compile and run CacheBash
To install this simulator first run the following command in the terminal of your choice
```
git clone https://github.com/surajkadapa/CacheBash.git
```
Then, navigate to the directory and run make like below
```
cd CacheBash
make
```
Make sure you have the Make utility installed.\
Once make runs successfully run the following command to launch the simulator!
```
./bin/cache_simulator
```

---
# How to use CacheBash
Initially, when the simulator starts up it will ask for the cache size(in powers of 2), memory size(in powers of 2), and the offset bits\
![Alt text](https://github.com/surajkadapa/CacheBash/blob/main/graphics/startuo.png) \
Then it will require the scheme(2 for now) for the cache \
![Alt text](https://github.com/surajkadapa/CacheBash/blob/main/graphics/options.png) \
The instruction format will be shown \
![Alt text](https://github.com/surajkadapa/CacheBash/blob/main/graphics/inst_format.png) \
And the cache memory table will also be shown \
![Alt text](https://github.com/surajkadapa/CacheBash/blob/main/graphics/init_cachetable.png) \
Finally, we give the data we want to load(in hex) and it will be processed in the back following the graphic below and the output will be shown with also with the cache table after updating with the cache miss and hit percentages \
![Alt text](https://github.com/surajkadapa/CacheBash/blob/main/graphics/breakdown_graphic.jpg) \
![Alt text](https://github.com/surajkadapa/CacheBash/blob/main/graphics/updated_cachetable.png) \
The load data can be given continously and the hit and miss percentages will be calculated accordingly and the cache table will the updated with each instruction.
