Templates are very usefel in case we have to create a class which have some attributes that we are not certain about their data types, so we declare it as attributes of data type T which stands for template, this will take any data type that will be sent to it.\
Templates are often used as the following example:\
template<class T> ------>>>>>>> this is written before the class and it ends with class termination ";".\
and inside we declare any attribute that we want to as of data type T, as in the following example:\
T variable;\
In case you only declare methods inside the class and define them outside, you would need to define the function as the following example:\
template<class T>\
////Declare your function and you're now able to use T as the template.