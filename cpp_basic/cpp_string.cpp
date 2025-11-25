#include <iostream>
#include <string>
#include <cstring>
#include <cctype>



int main(){
    std::string str1 = "Hello, ";
    std::string str2(str1);
    //从str1的下标0开始，到下标3结束（不包括4）
    std::string str3(str1, 0, 4);
    //使用重复字符初始化
    std::string str4(5, 'A');


    //字符串相加
    std::string str5 = str1 + "World!";
    str5.append(" Welcome to C++ programming.");
    str5 = "aaa";
    str5 += "bbb";

    //查找字符串
    size_t pos = str5.find("bb");
    if (pos != std::string::npos){
        std::cout << "Found 'bb' at position: " << pos << std::endl;
    }else{  
        std::cout << "'bb' not found." << std::endl;
    }


    //字符串替换
    str5.replace(0, 3, "ccc"); //将下标0开始的3个字符替换为"ccc"
    std::cout << "After replacement: " << str5 << std::endl;


    //截取子字符串
    std::string subStr = str5.substr(0, 3); //从下标0开始，截取3个字符
    std::cout << "Substring: " << subStr << std::endl;




    //字符串长度
    std::cout << "Length of str5: " << str5.length() << std::endl;
    std::cout << "Length of str5: " << str5.size() << std::endl;

    //字符串容量
    std::cout << "Capacity of str5: " << str5.capacity() << std::endl;

    //字符串流
    






    return 0;
}