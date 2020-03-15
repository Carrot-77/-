输出
```bash
echo 'Hello World'
#输出
```
变量的定义

```bash
#变量定义
a=12
a=HelloWorld
a='pwd' #‘变量替换符
a=$a:a
#$变量添加
#局部变量
local a=12
```
特殊变量
```bash
$0 #获取当前执行shell脚本的文件名，包括路径
$n #获取当前执行脚本的第n个参数
$* #获取当前shell的所有参数，将所有命令行参数视为单个字符，相当于$1$2...
$# #得到执行当前脚本的参数个数
$@ #获取这个程序的所有参数，并保留参数之间的任何留白，相当于$1 $2 $3
```
状态变量

```bash
$? #判断上一指令是否成功执行，0为成功
$$ #取当前进程的PID
$! #上一个指令的PID
```

### 自增自减
【方式一】declare -i来声明整数变量


```bash
root@localhost:~# declare -i x=1
root@localhost:~# x+=1
root@localhost:~# echo $x
2
```

【方式二】使用let命令

```bash
root@localhost:~# i=1
root@localhost:~# let i+=1
root@localhost:~# echo $i
2
root@localhost:~# i=1
root@localhost:~# let i=$i+1
root@localhost:~# echo $i
2
root@localhost:~# i=1
root@localhost:~# let i++
root@localhost:~# echo $i
2
root@localhost:~# i=1
root@localhost:~# let ++i
root@localhost:~# echo $i
2
```

【方式三】使用(())

```bash
root@localhost:~# i=1
root@localhost:~# ((++i))
root@localhost:~# echo $i
2
root@localhost:~# i=1
root@localhost:~# ((i++))
root@localhost:~# echo $i
2
```

【方式四】使用expr命令

```bash
root@localhost:~# i=1
root@localhost:~# i=`expr $i + 1`
root@localhost:~# echo $i
2
root@localhost:~# i=1
root@localhost:~# i=$(expr $i + 1)
root@localhost:~# echo $i
2
```

【方式五】使用$(())

```bash
root@localhost:~# i=1
root@localhost:~# i=$(($i + 1))
root@localhost:~# echo $i
2
```

【方式六】使用$[]

```bash
root@localhost:~# i=1
root@localhost:~# i=$[$i + 1]
root@localhost:~# echo $i
```

![在这里插入图片描述](https://img-blog.csdnimg.cn/20200312194818517.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNDEzMzY5,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200312195141358.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNDEzMzY5,size_16,color_FFFFFF,t_70)
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200312195959209.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNDEzMzY5,size_16,color_FFFFFF,t_70)
-a -d -n -p -t -s

printf
```bash
printf "Hello %s!" "A"
#Hello A!
```
**函数使用方法**

```bash
#方法1
_name_() {

}
#方法2
function _name_() {

}

#使用的时候
_name_ 
```

**流程控制IF**

```bash
#1
if [[ condition ]]; then
fi

#2
if [[ condition ]]; then
	else
fi

#3
if [[ condition ]]; then
elif [[ condition ]]; then
	else
fi

```
**test表达式**
手册命令 man test

**流程控制FOR**

```bash
#1
for i in words; do
	#statements
done

#2
for (( i = 0; i < 10; i++ )); do
	#statements
done
```
**流程控制WHILE**

```bash
while [[ condition ]]; do
	#statements
done
```
**流程控制CASE**

```bash
case word in
	contidion )
		#statements
		;;
	contidion )
		#statements
		;;
esac
```
**数组**

```bash
declare -a a
	name[sub]=value
	name=(value1 value2...)
#数组
#输出数组内容
${arry[*]}
${arry[@]}

#确定数组元素个数
${#arry[@]}

#找到数组下标
${!arry[@]}

#数组追加
arry+=(a b c)

#删除数组与元素
unset
```


