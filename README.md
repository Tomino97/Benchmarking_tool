# Priority_queue_benchmark
  Simple benchmarking tool, which combines repeated measurement (using ‹clock_gettime›) and statistical processing of the measured data.
  Two implementations of priority queue use <vector> and <list> for the representation of its members.
  
Both files expect input in format:
  ./a.out string 20 10000
  - the string could be in format ‹random›, ‹ascending› and ‹descending› which controls the numbers that are inserted into the priority queue
  - the first number specifies the size (bound)
  - the second number specifies how many elements to insert
