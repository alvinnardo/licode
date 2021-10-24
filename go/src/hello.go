package main // 第一行非注释，指明这个文件属于哪个包
// 表示一个可独立执行的程序

import "fmt" // 引入包
// fmt包实现了格式化IO的函数

// main每个必须包含，先执行init()函数，若没有，执行main()

var ( // 声明多个变量时，采用因式分解的写法，一般用于声明全局变量
    na int
    bb bool
)
func main() {  // 不能放在单独的一行
	// my first code
	/* this is a note */
	fmt.Println("hello world") // 包含最后的换行符
	// fmt.Print("hello world\n")

        var num = 10
        var date = "2020-12-32"
	var pattern = "num = %d, date = %s\n"
        var res = fmt.Sprintf(pattern, num, date) // 将pattern格式化并输出
	fmt.Println(res)

        /* 
         * 变量的声明: var identifier type
         * 多个变量: var identifier, identifier2 type
         *
         * 变量声明后未被初始化，就默认初始化为零值
	 * 如int的零值为0，bool的零值为false
	 * string的零值为"", 其它类型的零值为nil
         */
	var b int
	fmt.Println(b)

	var c bool
	fmt.Println(c)

	/*
	 * 根据初始化自动确定类型
	 */
	var d = true
	fmt.Println(d)

	/*
	 * 初始化并赋值:= , 被称为初始化声明
	 * 如果已经声明，则再使用:=，就会出错
	 */
	 intVal := 1 // 只能在函数体中出现
	 // var intVal int
	 // intVal = 1 这两行等价于上面的:=

	/*
	 * 初始化多个变量
	 */
	 var name1, name2, name3 int
	 name1, name2, name3 = 1, 2, 3

	 // name1, name2, name3 := 1, 2, 3 等价于上面两行
}

/*
 * 若标识符以大写字母开头，如Car1，那么就可以被外部包的代码所使用
 * 前提是客户端程序需要先导入这个包，被称为导出（类似public）
 * 若标识符以小写字母开头，包外不可见，在整个包的内部是可见的并且可用（类似protected）
 */

/*
 * 数据类型的出现是为了把数据分成所需内存大小不同的数据
 * 如果需要用大数据的时候才需要申请大内存
 *
 * var b bool = true
 * Go支持整形和浮点形，支持复数，位的运算采用补码
 * 字符串的字节使用UTF-8编码
 * float32 是IEEE-754的32位浮点形
 * float64 是IEEE-754的64位浮点形
 * complex64 32位实数和虚数
 * complex128 64位实数和虚数
 */

