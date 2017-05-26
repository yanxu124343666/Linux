# Linux

Assignment为最终作业
(由于代码要接受检查及Makefile的关系，就把.c文件都传了上来)
Assignment中部分文件的解读：

libDataType.a：一个静态库，包含栈、队列、树、图四种数据结构

include:包含四种数据结构的.h头文件

test：用libDataType.a库编译好的文件，可运行

a.out:用Makefile编译好的文件，可运行

main.c：测试文件，其中栈和队列测试数据为自动输入，树和图的测试数据为手动输入

input_test：树和图的输入测试数据
