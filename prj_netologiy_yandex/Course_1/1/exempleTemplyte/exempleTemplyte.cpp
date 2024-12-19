п»ї// exempleTemplyte.cpp 

#include <iostream>
#include <string>
#include <malloc.h>


template<typename T>
const T input(const std::string& text, const std::string& x) {

    if  (x == "1") {

        return std::stoi(text);

    } else
    if  (x == "2") {

        return std::stod(text);

    }        
}

template<>
const std::string input (const std::string& text, const std::string& x) {

  
            if (x == "3") {

                return  std::string(text);

            }
            else {
                return std::string("no data");
            }
}


int main()
{
    std::string a, b;
    {
        a = "5";
        b = "1";
        auto s = input<int>(a, b);
        std::cout << s << std::endl;
    }
    {
        a = "7.1";
        b = "2";
        auto s = input<double>(a, b);
        std::cout << s << std::endl;
    }
    {
        a = "7.1.1";
        b = "3";
        auto s = input<std::string>(a, b);
        std::cout << s << std::endl;
    }
}
