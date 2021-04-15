# Windows下配置C++开发环境
## VS Code
### 下载安装
1. 下载地址：[link](https://code.visualstudio.com/Download)
2. 安装：不断next即可
3. 设置中文环境
   1. 侧边栏点击扩展
   2. 搜索：language
   3. 选择中文简体
   4. 安装完成重启VS Code
4. 安装C/C++插件，安装完重启。
   

### 安装MinGW编译器[RefLink](https://blog.csdn.net/qq_34735535/article/details/53909183)
1. 运行
2. 选择All Packages，勾选
   1. mingw32-base bin，
   2. mingw32-gcc-g++ bin ，
   3. mingw32-pthreads-w32 dev
3. 选择 All Packages - MSYS，勾选
   1. msys-base bin
   2. msys-vim bin
4. apply changes


### 编写C++程序并运行[RefLink](https://zhuanlan.zhihu.com/p/77074009)
1. 打开一个文件夹（不要包含中文路径）
2. 菜单栏——查看——终端
3. 菜单栏——查看——命令面板：输入关键词"C/C++"，在弹出的诸命令中选择编辑配置 (UI)或者Edit Configurations (UI)。
4. 诸配置中最重要的是编译器路径和IntelliSense模式这两项，两者在右侧都有下拉三角。如果前面你正确配置了环境变量，路径的待选项中就会包含几个正确的编译器路径，编写C程序请选择gcc.exe，C++则选择g++.exe；模式选择gcc-x64。
5. 写一个简单C或C++程序，保存。
6. 第一次执行编译任务前，需要配置这个任务。选择菜单栏【终端】→【配置任务…】
7. 为了执行这个编译任务，先打开要编译的代码文件，然后选择菜单栏【终端】→【运行生成任务】
8. 在下方的终端输入`.\hello.exe`.