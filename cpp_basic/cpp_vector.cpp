#include <iostream>
#include <vector>



int main(){
    //默认构造
    std::vector<int> vec;
    //指定大小和默认值
    std::vector<int> vec2(5, 10); //5个元素，每个元素值为10
    //使用初始化列表
    std::vector<int> vec3 = {1, 2, 3, 4, 5};
    //拷贝构造
    std::vector<int> vec4(vec3);
    //移动构造
    //vec4被移到之后访问会出现问题
    std::vector<int> vec5(std::move(vec4));


    for(int temp : vec2){
        std::cout << temp << " ";
    }

    //大小和容量
    std::cout << "\nSize of vec3: " << vec3.size() << std::endl;
    std::cout << "Capacity of vec3: " << vec3.capacity() << std::endl;

    //插入，删除元素
    vec3.push_back(6); //在末尾添加元素6
    vec3.pop_back();   //删除末尾元素

    //在指定位置插入元素
    //vec3.begin()表示开始位置
    vec3.insert(vec3.begin() + 2, 10); //在下标2位置插入10

    //删除指定位置元素
    vec3.erase(vec3.begin() + 1); //删除下标1位置元素

    //清空之后，size为0但是capacity不变
    vec3.clear();
    //为了防止溢出，如何解决
    {
        std::vector<int> empty_vec;
        empty_vec.swap(vec3); //vec3变为空，capacity变为0
    }

    //访问vector元素
    /*
        operator[]: 不进行边界检查，访问越界会导致未定义行为
        at(): 进行边界检查，访问越界会抛出out_of_range
        front(): 返回第一个元素
        back(): 返回最后一个元素
    */
    std::vector<int> vec6 = {1, 2, 3, 4, 5};
    std::cout << "Element at index 2: " << vec6[2] << std::endl;
    std::cout << "Element at index 3: " << vec6.at(3) << std::endl;
    std::cout << "First element: " << vec6.front() << std::endl;
    std::cout << "Last element: " << vec6.back() << std::endl;


    //遍历vector
    /*
        
    */







    return 0;
}