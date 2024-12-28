## 第1章 C++和标准库速成
1. 模块 [链接](https://www.yuque.com/u32705961/huhki7/grl76kdrnc39o1mg)
2. 头文件

:::info
1. 在C中，标准库头文件的名称通常以.h结尾，如<stdio.h>，不使用名称空间
2. 在C++中，标准库头文件的名称省略了.h后缀，如<iostream>,所有文件都在std名称空间和std的子名称空间中定义
3. C中的标准库头文件在C++中依然存在，但使用以下两个版本
+ 不使用.h后缀，改用前缀c；这是推荐使用的版本，这些头文件将所有内容放在std名称空间中
+ 使用.h后缀，不使用名称空间

:::

3. main函数要么没有参数，要么有两个参数

```cpp
int main(int argc, char* argv[])
// argc给出了传递给程序的实参数目，argv包含了这些实参，注意argv[0]可能是程序的名称，也可能是空字符串，
// 所以不应该使用它，相反应当使用特定于平台的功能检索程序名。重要的是要记住，实际参数从索引1开始。
```

4. std::endl会把当前缓冲区中的所有内容刷新，不建议过度使用std::endl
5. 嵌套的名称空间

```cpp
namespace MyLibraries::Networking::FTP {} // c++17之后支持
namespace MyLibraries {
    namespace Networking {
        namespace FTP {
            
        }
    }
}
// 名称空间别名
namespace MyFTP = MyLibraries::Networking::FTP
```

6. 字面量，数字和字符串  1 “test"
7. 统一初始化 int i {1}
8. 数值极限

:::tips
在C中，可以使用各种宏定义，例如INT_MAX, 尽管这些方法在C++中仍然可以使用，但推荐的做法是使用定义在<limits>中的类模板std::numeric_limits

:::

```cpp
numeric_limits<int>::max();
numeric_limits<int>::min();
numeric_limits<int>::lowest();

min()和lowest()之间的区别，对一个整数，最小值等于最低值，然而对于浮点类型来说，
最小值表示该类型能表示的最小正数，最低值表示最小负数，即-max();
```

9. 枚举，enum class pieceType , 不能自动转换为整数，枚举值名不会自动超出封闭的作用域
10. 三向比较运算符 <=> ，太空飞船操作符

```cpp
//告诉你一个值是否等于、小于或大于另一个值。 返回的不是Bool类型，而是一个枚举
//如果操作数是整数类型，则结果是所谓的强排序
strong_ordering::less   // 第一个操作数小于第二个
strong_ordering::greater
strong_ordering::equal

// 如果操作数是浮点类型，结果是一个偏序
partial_ordering::less
partial_ordering::greater
partial_ordering::equivalent
partial_ordering::unordered  // 如果有一个操作数是非数字或者两个操作数都是非数字

// 弱排序。针对自己的类型
weak_ordering::less   // 第一个操作数小于第二个
weak_ordering::greater
weak_ordering::equaivalent

<compare>
std::is_eq(), std::id_neq(), std::is_lt(), std::is_lteq(), std::gt(), std::gteq()

int i {11};
strong_ordering result {i <=> 0};
```

11. 函数返回类型的推断

```cpp
auto addNumbers(int number1, int number2)
{
    return number1 + number2;
}
```

12. **__func__**表示当前函数名称

```cpp
cout << format("Entering function {}", __func__) << std::endl;
```

13. 属性

```cpp
[[fallthrough]], swith case 中穿刺
[[nodiscard("描述")]] 使编译器在该函数被调用却没有对返回的值进行任何处理时发出警告
[[maybe_unused]] 某些内容没使用时不警告
[[noreturn]] 意味着它永远不会将控制权返回给调用点
[[deprecated("描述")]] 将某些内容标记为已弃用，仍可以使用但不鼓励
[[likely]] [[unlikely]] 来标记if 和 switch 语句的分支
```

12. std::array, 固定大小 std::array<int, 3>
13. std::vector, 动态
14. std::pair
15. std::optional, 保留特定类型的值，或者不包含任何值

```cpp
std::optional<int> getData(bool giveIt)
{
    if (giveIt)
    {
        return 32
    }
    return nullopt
}
std::optional<int> data1 {getData(true)}
std::optional<int> data2 {getData(false)}
// 可以使用has_value()判断一个optional是否有值，或者简单将optional用在if语句中
data1.has_value()
if(data2){}
// 如果optional有值，可以使用value()或解引用运算符访问它
data1.value();
*data1
// 如果对一个空的optional使用value()，会抛出std::bad_optional_access异常
// value_or()可以用来返回optional的值，如果optional为空，则返回指定的值
data2.value_or(0);
// 不能将引用保存在optional中，optional<T&>是无效的，可以保存指针
```

16. 结构化绑定

```cpp
// 结构化绑定允许声明多个变量，这些变量使用数组、结构体、pair或元组中的元素以初始化
array values {1, 2, 3};
auto [x, y, z] {values} //必须使用auto ,不能用 int 数量必须匹配

struct Point {double m_x, m_y, m_z;};
Point point;
point.m_x = 1.0; point.m_y = 2.0; point.m_z = 3.0;
auto [x, y, z] {point}

pair myPair {"hello" ,5};
auto [theString, theInt] {myPair};

// 通过使用auto& 或 const auto& 代替 auto
```

17. 初始化列表

```cpp
// 利用初始化列表，可轻松地编写能接收可变数量参数的函数
import <initializer_list>

int makeSum(initializer_list<int> values)
{
    int total {0};
    for (int value : values)
    {
        total += value;        
    }
    return total;
}
```

18. 字符串

:::info
+ C风格字符串：用字符数组表示字符串
+ C++风格字符串：将C风格的表示封装到一种易于使用和更安全地string类型中

:::

19. const

:::info
const int * ip

int const * ip

int * const ip

const 关键字作用于其直接左侧内容

const 出现在*左边，表示被指物是常量，出现在*右边，表示指针是常量

:::

20. constexpr常量表达式，编译器求值的表达式
21. RVO和NRVO返回值优化和命名返回值优化，避免复制从函数返回对象
22. const_cast,为变量添加和取消const属性， std::as_const()的辅助方法，as_const()等价于const_cast<const T&>(obj)
23. auto去除了引用和const限定符，从而会创建副本
24. decltype，把表达式作为实参，计算出表达式的类型

## 第2章 使用string和string_view
1. 在C中，字符串表示为字符的数组，字符串的最后一个字符时\0
2. 原始字符串字面量 R""
3. 数值转换为字符串 std::to_string
4. 字符串转换为数值 

```cpp
std::stoi
std::stol
std::stoul
std::stoll
std::stoull
std::stof
std::stod
std::stold
```

5. c++也提供了许多低级数值转换函数，这些函数不执行内存分配，也不直接使用std::string, 而使用调用者分配的缓冲区

```cpp
//数值转换为字符串
to_chars_result to_chars(char* first, char* last, IntegerT value, int base = 10)
//IntegerT 是任何有符号或无符号的整数类型或char类型。
// 结果是to_chars_result
struct to_chars_result{
    char* ptr;
    errc ec;
}
//如果转换成功，ptr成员将等于所写字符尾后一位置的指针。如果转换失败则等于last
// 类似的还有浮点类型的
to_chars(char* first, char* last, FloatT value);
to_chars(char* first, char* last, FloatT value, chars_format format)
to_chars(char* first, char* last, FloatT value, chars_format format, int precision);

enum class chars_format
{
    scientific,
    fixed,
    hex,
    general = fixed | scientific
}

// 字符串转换为数字 from_chars
```

6. 在c++17之前，为接收只读字符串的函数选择形参类型已知是问题，是const char*吗，如果使用std::string，则必须调用c_str()来获取，如果形参是const std::string& 则必须用string，如果传递一个字符串字面量，编译器将默认创建一个临时字符串对象（其中包含字符串字面量的副本），并将该对象传递给函数
7. std::string_view基本上是const std::sting& 的简单替代品，但不会产生开销，它从不复制字符串
8. 无法从std::string_view隐式构建一个string，要么使用一个显示的string构造函数，要么使用string_view.data()
9. 永远不要使用std::string_view保存临时字符串的视图。
10. 字符串格式化

```cpp
std::format()
// 第一个参数是待格式化字符串，后续参数为填充占位符
std::format([index][:specifier])
// 可以省略所有占位符中的index，也可以为所有占位符指定从零开始的索引
auto s1 {std::format("Read {} bytes from {}",n , "file.txt")};
auto s1 {std::format("Read {0} bytes from {1}",n , "file.txt")};
// 不允许混合使用手动和自动索引
// 格式说明符，前缀是:
[[fill]align][sign][#][0][width][.precision][type]
[[fill]align] // 说明使用哪个字符作为填充字符，然后值在其字段中对齐方式
// < 左对齐  > 右对齐 ^ 居中
cout << format("{:_>7}", i)
cout << format("{:5}, i"); [width]
[sign] 
// -表示只显示负号 +表示显示正号和负号 space表示对于负数使用负号，整数使用空格
[#]
// 启用所谓的备用格式
[type] 指定给定值要被格式化的类型
[percision] 只能用于浮点和字符串类型，浮点类型要输出的小数位数，或者字符串要输出的字符数
[0] 将0插入格式化结果中，以达到[width]指定的最小宽度

// 支持自定义类型
// 可以扩展C++20格式库以添加对自定义类型的支持，涉及编写std::formatter类模版的特化版本，
// 该模版包含两个方法模版 parse()和format()
// parse方法负责解析范围[context.begin(), context.end())内的格式说明符。它应该将解析格式
// 说明符的结果存储在formatter类的数据成员中，并且返回一个迭代器，该迭代器指向解析格式说明符
// 字符串结束后的下一个字符。
// format()方法根据parse()解析的格式规范格式化第一个实参。将结果写入context.out()，并返回一个
// 指向输出末尾的迭代器
```

## 第3章 编码风格
## 第4章 涉及专业的C++程序
## 第5章 面向对象设计
## 第6章 设计可重用代码
## 第7章 内存管理
1. 智能指针，智能指针离开作用域或被重置时，会自动释放所占用的资源。
2. unique_ptr

```cpp
std::make_unique() // 创建unique_ptr
get() // 获得底层指针
reset() // 释放底层指针，并根据需要将其改成另一个指针
release() // 断开unique_ptr与底层指针的连接，返回底层指针，将智能指针设置为nullptr
// unique_ptr代表唯一拥有权，无法复制，但是可以用移动语义将一个unique_ptr移动到另一个
// 默认情况下，unique_ptr使用标准的new和delete运算符来分配和释放内存，可以将其改为自己的分配和
// 释放函数

```

3. shared_ptr

```cpp
std::make_shared() // 创建shard_ptr
get() 
reset() // 只在最后一个shared_ptr销毁时，才释放
use_count() // 共享实例数量

enable_shared_from_this //允许对象调用方法，以安全地返回指向自己的shared_ptr或weak_ptr。
// shared_from_this()
// weak_from_this()
仅当对象的指针已经存储在shared_ptr时，才能使用对象上的shared_from_this()
```

4. weak_ptr

```cpp
weak_ptr的构造函数将一个shard_ptr或另一个weak_ptr作为参数，为了访问weak_ptr中保存的指针，
需要将weak_ptr转换为shared_ptr，
lock() 返回一个shared_ptr
```

## 第8章 熟悉类和对象
1. 只要没有显示定义拷贝构造函数，编译器就会自动生成一个，只要定义了任何构造函数，编译器就不会生成默认构造函数。
2. 拷贝构造函数是在对象初始化时使用，拷贝赋值运算符是在赋值时使用。

## 第9章 精通类和对象
1. C++允许某个类将其他类、其他类的成员函数或非成员函数声明为友元，友元可以访问类的protected、private数据成员和方法
2. 复制和交换
3. 左值是可以获取其地址的一个量，字面量、临时对象或临时值是右值
4. 仅当类没有用户声明的拷贝构造函数、拷贝赋值运算符、移动赋值运算符或析构函数时，编译器才会为类自动生成默认的移动构造函数。
5. 仅当类没有用户声明的拷贝构造函数、移动构造函数、拷贝赋值运算符或析构函数时，才会自动生成移动赋值运算符。
6. std::exchange()用新值替换原来的值，并返回原来的值
7. 如果一个函数内部要复制参数，那么使用值传递，如果传入一个左值参数，它只会被复制一次，如果传递一个右值，则不会进行复制，右值在传递给参数的时候也是移动不是复制

## 第10章 揭秘继承技术
## 第11章 零碎的工作
