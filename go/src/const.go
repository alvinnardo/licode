package main

// import "fmt"
import "unsafe"

func main() {
    // 语法：const identifier [type] = value
    const a string = "abc"

    // 可以省略type，编译器可以根据变量的值来判断类型
    const b = "abc" 

    // 多个变量声明
    const c1, c2 = "aaa", "bbb"


    // 常量的枚举
    const (
	unknown = 0
	female = 1
	male = 2
    )

    // 常量可以使用len()、cap()、unsafe.Sizeof()函数来计算表达式的值
    // 常量表达式中，函数必须是内置函数，否则编译不过
    const (
	ca = "ab"
	cb = len(a)
	cc = unsafe.Sizeof(ca)
    )
    println(ca, cb, cc)

    /*
     * iota，特殊常量，可以认为是一个可以被编译器修改的常量
     * 在const中iota初始化为零，每新增一行iota计数一次
     */

     const (
	 aa1  = iota // 0
	 bb1        // 1
	 cc1        // 2
	 dd1 = "ha" // 独立值, iota += 1
	 ee1        // "ha"    iota += 1
	 ff1 = 100  //         iota += 1
	 gg1        // 100     iota += 1
	 hh1 = iota // 7, 恢复计数
	 ii1        // 8
     )

     const (
	 aaa = 1<<iota // 左移0位
	 bbb = 3<<iota // 3左移1位
	 ccc           // 3左移2位, 3*2*2
	 ddd           // 3左移3位, 3*2*2*2
     )
     println(aaa, bbb, ccc)

}
