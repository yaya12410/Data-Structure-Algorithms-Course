ADT = Abstract Data Type\
Data Type:\
1-Representation of data.\
2-Operation on data.

Example:\
int x;  ---->>>>   assume int takes 2 bytes in storage the first bit is for sign +VE or -VE and the rest of the 15 bits is for the number\
Operations allowed on the int x are + - * / % ++ --

What is Abstract?\
Hidden from us, more related to Object Oriented Programming.

List -> 8, 3, 9, 4, 6, 10, 12\
        0  1  2  3  4  5   6\
Things that we have to store in order to represent this list:\
1-Space for storing these elements.\
2-Capacity that is maximum capacity.\
3-Size which is the number of elements we are having.

Operations on a list:\
.add(element) or .append(element), .add(index, element) or .insert(index, element), .remove(index), .set(index, element) or .replace(index, element), get(index), .search(key) or .contain(key), .sort()

So the concept of ADT, is to define data, and operations on data together, and let it be used as data type by hiding all its internal details.