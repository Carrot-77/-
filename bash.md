# bash

## 通配符

### ？*

* `?` 任意个单个字符

* `*`任意几个任意字符

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200314224506798.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNDEzMzY5,size_16,color_FFFFFF,t_70)

## 任务管理

* `&`
  在命令后加上&表示后台执行
* `;`
  在命令之间以;相连，表示顺序执行
* `&&`
  前面的命令执行成功，后面的才会执行
* `||`
  如果前一个命令执行失败，则执行第二个命令
* ` ' ' `
  命令中如果包含另一个命令，则用' '把他们括起来，在执行的时候系统优先执行' '中的子命令，然后将其结果代入父命令继续执行
* `ctrl + z`
  挂起
* `bg`
  将挂起的命令后台运行
* `fg`
  后台执行转为前台执行
* `jobs`
  查看所有在后台执行和挂起的任务及任务编号

## 管道 重定向

* `>`
  重新定向符 ctrl + d结束

* `>>`
  追加

* `<`
  文件到命令的重定向

* `<<`

> cat >> a.log << EOF
>
> >a
> >b
> >c
> >EOF#读到EOF的时候停止

### 转义符

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200314232748721.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNDEzMzY5,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200314232844952.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNDEzMzY5,size_16,color_FFFFFF,t_70)

## 系统信息的

##### 	uptime

* `uptime` 打印系统运行时长和平均负载

##### w

* `w` 当前登录用户列表及正在执行的任务

##### who

* `who` 显示当前登录系统的用户信息

  > -H #显示各栏的标题信息列
  > -u #显示空置时间
  > -q #只显示登入系统的用户名和总人数

##### whoami

* `whoami` 打印当前有效的用户名称

  > id -un
  > id -root

##### last

* `last` 显示用户最近登录信息

  > -f #指定记录文件
  >
  > -n #指定输出记录数
  >
  > -x #显示系统关机，重新关机等信息

##### uname

* `uname` 打印当前系统信息

  > -a #全部类型
  >
  > -m #电脑类型
  >
  > -n #网络上主机名称
  >
  > -v #os版本
  >
  > -p #处理器类型
  >
  > -i #硬件平台
  >
  > -o #操作系统名称

##### data

* `data` 显示或设置系统时间与日期

  > date +"%H:%M:%S"
  > #输出当前格式日期
  >
  > -d "string" #显示字符所指日期
  >
  > data -d "1000 year ago"

##### cal

* `cal` 显示日历

## 目录

##### cd

* `cd`切换当前工作目录

  > cd /etc #直接切换到/etc目录
  >
  > cd .. #切换到上层目录
  >
  > cd . #切换到当前目录
  >
  > cd - #回到上次工作目录

##### pwd

* `pwd`打印当前工作目录

  > L #显示逻辑工作目录
  >
  > P #显示物理工作目录

##### `mkdir`创建目录

> -p #自动创建父目录
>
> -m #设置权限

##### `rmdir`删除目录

> p #删除祖先

## 文件与目录管理

##### `ls`显示文件及目录信息

##### `cp`拷贝

> -i #若文件存在，询问用户
>
> -r #递归复制

##### `rm`删除

> -i #互动模式
>
> -r #递归删除
>
> -f #强制删除
>
> -rf #慎用

##### `mv`移动

> -i #互动模式
>
> -f #强制
>
> -u #源文件更新才会移动

##### `basename`取文件名

##### `dirname`取目录名

## 文件内容查阅

##### `cat`正向连续读

> -v #列出看不出的字符
>
> -E #显示断行符为$
>
> -T #显示TAB为^I
>
> -b #列出行号
>
> -n #列出行号，连同空行也编号

##### `tac`反向连续读

从最后一行开始一行一行读

##### `nl`输出行号显示文件

##### `more`一页一页的显示文件内容

> more file
>
> > /string #向下查找string关键字
> >
> > :f #显示文件名称和当前显示的行数
> >
> > q #离开

##### `less`与more相似

但可以上下翻看

> less file
>
> > /string #向下查找
> >
> > > n #继续向下查找
> >
> > /?string #反向查找
> >
> > > N #继续反向查找

##### `head`只看头几行

> head [-n num] <file>
>
> > -n num #显示前num行
> >
> > -n -num #除了num行后外，其他的都显示

##### `tail`只看末尾几行

> tail [-n num] <file>
>
> > -n num #显示文件后num行
> >
> > -n +num #除了前num行，其他都显示

例如：显示a.log文件第10到20行

> cat a.log | nl | tail -n +10 | head -n 20

##### `od`以二进制方式查看文件内容



### 修改文件时间与新建文件

##### `mtime`

内容数据改动时才更新这个时间

##### `ctime`

文件的权限、属性改动时更新这个时间

##### `atime`

文件的内容被取用access时，更新这个时间


> ls -l --time=ctime
> #查看所有文件的创建时间
> ls -l --time=ctime a.cpp
> #查看a.cpp的创建时间

```bash
[root@localhost Linux]# ls -l --time=ctime
总用量 24
drwxr-xr-x. 2 root root   34 3月  14 14:44 314
-rw-r--r--. 1 root root 8157 3月  14 20:53 a.log
-rw-r--r--. 1 root root  122 3月  14 15:06 git.md
-rw-r--r--. 1 root root  662 3月  14 14:59 prime_1.sh
-rw-r--r--. 1 root root  733 3月  14 13:56 prime.sh
-rw-r--r--. 1 root root 3502 3月  15 14:11 ShellMake.md
[root@localhost Linux]# ls -l --time=atime
总用量 24
drwxr-xr-x. 2 root root   34 3月  14 16:26 314
-rw-r--r--. 1 root root 8157 3月  14 20:53 a.log
-rw-r--r--. 1 root root  122 3月  14 15:10 git.md
-rw-r--r--. 1 root root  662 3月  14 14:59 prime_1.sh
-rw-r--r--. 1 root root  733 3月  14 15:02 prime.sh
-rw-r--r--. 1 root root 3502 3月  15 14:12 ShellMake.md

```

##### `touch`创建 修改

> touch [-acdmt] <file>
>
> > -a #仅修改访问时间
> >
> > -c #仅修改文件的时间，若文件不存在，不新建
> >
> > -d #修改文件日期
> >
> > -m #仅修改mtime
> >
> > -t #修改文件时间

##### `chattr` 文件隐藏属性

> chattr [+-=] [ASacdistu] <file_or_dir>
>
> >A #不修改atime
> >
> >S #同步写入
> >
> >a #只能增加数据
> >
> >c #自动压缩，解压
> >
> >d #不会被dump程序备份
> >
> >i #不能删除、修改、建立连接
> >
> >s #文件删除时，直接从磁盘删除
> >
> >u #文件删除时，数据内容存在磁盘中

##### `lsattr`打印隐藏属性

> lsattr [-adR] <file_or_dir>
>
> > -a #打印隐藏文件的隐藏属性
> >
> > -d #如果是目录，仅打印目录信息
> >
> > -R #递归


 ###  文件的特殊权限

##### `set_uid`

作用对象：二进制程序文件，非脚本
效果：用户在执行程序时获取程序所有者权限
如：修改密码

##### `set_git`

作用对象：目录和二进制程序文件
效果：用户在该目录里，有效组变为目录所属组

##### `sticky Bit`

作用对象：目录
 效果：在该目录下，用户只能删除自己创建的内容

### 命令与文件的查询

##### `which`

查找PATH路径下所有可执行文件

##### `whereis`查找特定文件

> whereis [-bmsu] <file_or_dir>
>
> > -b #只查找二进制文件
> > -m #只查找manual路径下的文件
> > -s #只查找source源文件
> > -u #查找其他文件

##### `locate`模糊定位

（需要安装）

> locate [-ir] keyword
>
> > -i #忽略大小写
> >
> > -r #后面可接正则表达式

##### `find`高级查找

> find [PATH] [option] [action]
>
> > #与文件权限及名称有关的参数
> >
> > -name filename #文件名为filename
> > -size [+-] SIZE #查找比SIZE大或小的
> > -type TYPE #f b c d l s p
> > -perm mode #mode刚好等于的文件
> > -perm -mode #全部包含mode的文件
> >
> > #与时间相关的参数
> >
> > -mitime n #n天前的“一天之内”修改的文件
> > -mtime +n #n天之前，不包括n，修改过的文件
> > -mtime -n #n天之内，包括n，修改过的文件
> > -newer file #比file还要新的文件
> >
> > #与用户或用户组相关的参数
> >
> > -uid n #用户UID为n
> > -gid n #群组Gid为n
> > -user name #用户名为name
> > -group name #群组名为name
> > -nousr #文件所有者不存在
> > -nogroup #文件所有组不存在



### 数据提取操作

##### `cut`切分

> -d c #以c字符分割
> -f num #显示num字段的内容
> -b num #字节
> -c num #字符

##### `grep`检索

> grep [-acinv] <string> <file>
>
> > -a #将二进制文件以普通文件的形式搜寻数据
> > -c #统计搜寻到的次数
> > -i #忽略大小写
> > -n #顺序输出行号
> > -v #反向输出（输出没找到的）

grep '^$' #检索空行
grep [&$] #检索全部

##### `sort`排序

> sort [-fbMnrtuk] <file_or_stdio>
>
> > -f #忽略大小写
> > -b #忽略最前面的空格符
> > -M #以月份名称排序
> > -n #以存数字方式排序
> > -r #反向排序
> > -t #分隔符，默认[TAB]
> > -k #以那个区间排序
> >
> > -u #uniq

##### `wc`统计字符字数行数

> wc [-lwm] <file_or_stdin>
>
> > -l #仅列出行号
> >
> > -w #仅列出多少字
> >
> > -m #仅列出多少字符

##### `uniq`去重

> -i #忽略大小写字符的不同
>
> -c #进行计数

##### `tee`双向重导向

> tee [-a] file
>
> > -a #append

##### `split`文件切分

> -b SIZE #切分为SIZE大小的文件
> -l num #以num行为大小切分

##### `xargs`参数代换

> xargs [-0pne] <command>
>
> > -0 #将特殊字符还原为普通字符
> > -eEOF #当xargs读到EOF时停止
> > -p #执行指令前询问
> >
> > -n num #每次执行command时需要的参数个数

> cat a.log | tr -s -c [a-z] ' ' | tr ' ' '\n' | sort | uniq -c | sort -n -r | head -n 20
> #输出a.log里面出现的单词频率最高的20个单词

##### `tr`替换压缩删除

对标准输入的字符替换、压缩、删除

> tr [cdst] <字符集> <字符集>
>
> > c #取代所有不属于第一字符集的字符
> >
> > d # 删除所有属于第一字符集的字符
> >
> > s #将连续重复的字符以单独一个字符表示
> >
> > t #先删除第一字符集较第二字符集多出的字符


