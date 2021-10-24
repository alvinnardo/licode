package main

import "fmt"

func main() {
    // int/ float/ bool/ string都属于值类型，使用这些类型的变量直接指向存在内存中的值
    // 比如int是32b的字

    // 使用=将一个变量的值赋值给另一个变量，实际上是在内存中将i的值进行了拷贝
    // 值类型的变量值存放在栈中

    // 更复杂的数据通常会使用多个字，一般使用引用类型保存
    // 一个引用类型的变量存储的是值所在的内存地址，或内存地址中第一个字所在的位置
    // 这个内存地址称为指针，实际上也被存在另外的某一个值中
    // 当使用复制语句，只有引用（地址）被复制

    // 全局变量允许声明但不使用，其它变量声明后必须使用
    /*
     * 多变量的声明和赋值
     */
     var a, b int
     var c string
     a, b, c = 5, 7, "abc" // 赋值可以在一行
     fmt.Println(a, b, c)

     // a, b, c := 5, 7, "abc" // 初始化声明

     d, e := 1, 2
     d, e = e, d
     fmt.Println(d, e)

     // 空白标识符_被用于标识符
     // val, err = Func1(var1) 并行赋值用于函数返回值

}
