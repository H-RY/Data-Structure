# Data Structure
数据结构大纲

算法的定义：狭义的算法是与数据的存储方式密切相关，广义的算法是与数据的存储方式无关
泛型的定义：利用某种技术达到的效果就是：不同的存储方式，执行的操作是一样的

内存是线性的，是一维的空间。

如何学算法

1、流程（步骤）

2、每个语句的功能

3、试数（识数）？

重点是看懂答案后敲答案，不断错，不断敲


递归：一个函数自己直接或间接调用自己


A函数是如何调用B函数的？

当在一个函数运行期间，调用另一个函数时，在运行被调用函数之前，系统需要先完成三件事

1、将所有的实参返回地址等信息，传递给被调用函数保存

2、被调用函数的局部变量分配存储区

3、将控制转移到被调函数的入口

而从被调函数返回给调用函数之前，系统也会完成三件事

1、保存被调函数的计算结果

2、释放被调函数的数据区

3、依照被调函数保存的返回值地址，将控制权限转移给调用函数

当有多个函数构成嵌套调用时，按照"后调用先返回"，上述函数之间的传递和控制转移必须借助栈来实现，即系统将整个程序运行所需的数据空间安排在一个栈中，
每当调用一个函数时，就为他在栈顶分配一个存储区，每当一个函数退出时，就释放他的存储区。则当前正运行的函数的数据区必须在栈顶。


排序算法一定要注意边界值的设定

1、考虑有无哨兵

2、序号还是下标

3、长度还是末尾元素序号或下标