# androidGRPC

项目搞得仓促，但是也能用，不过手续比较复杂

+ 1.先脱dex,dumpDexToPC
+ 2.dump code_item ,会形成一个修复文件
+ 3.用baksmali 将dex和修复文件一起调用，会反编译为经过修复的smali工程
+ 4.用smali将smali工程回编译为dex

写时候需要一个类一个类的搞，可能有点费劲，也可以自己写遍历
grpc用9091端口通讯，只能同时打开1个apk,不能开两个，端口占用会崩溃
不用测试grpc本身，debug的dex好像有优化容易出错。
目前只是类加载脱壳哦，不是函数主动调用，比fart差一点的

确实不够优雅，准备用c++重写android 端，优化调用框架，重开一个c++语言分支