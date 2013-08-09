1. 大规模系统设计的问题，比如load balancing, server communication, data 
consistence等等，而且他会一直深入细节，让你设计一些出错处理什么之类的.
2. 每个任务之间有dependency，怎么安排任务顺序，使得执行任务i的时候，所有被
depend的任务已经执行过了。
3. 用Java设计一个餐馆。有厨师，服务生，客户等等类。设计时我太注意细节了，忘
了考虑多线程。最后在面试管提醒下大致说了一下多线程实现的方案。
4. udp和tcp的区别，什么时候用tcp，什么时候用udp。tcp是否允许接受重复packet。
cookie是什么在进行操作，一个网站最多有几个cookie。
5. 做一个search engine, 每次搜索到的url肯定会有大量重复。怎么解决?
6. 实现这个search engine, 你的设备是联在一起的100台电脑，它们可以同时工作。
可能整个工作过程的某个时段这台机器得到的url set跟另一台机器得到的url set不一
样，我们又不希望重复劳动。怎么办？
7. 一个非常sparse的matrix，2^64 × 2^64, 设计一个class，内有get(int x, int y
), set(int x, int y, int value)。 用什么数据结构存储它？有哪些选择，各自的
get啊, set的complexity是什么。
8. Design a class library for writing card games.
9. 然后让我设计一个分布式文件系统，给定
path name，可以读写文件。具体的system design这里就不提了。其中一个细节是，给
定path name，怎么知道哪个node拥有这个文件。我提出需要实现一个lookup function
，它可以是一个hash function，也可以是一个lookup table。如果是lookup table，
为了让所有client sync，可以考虑额外做一个lookup cluster。然后Interviewer很纠
结，既然可以用hash function，为什么还搞得那么复杂。我就告诉他hash function的
缺点。假定一开始有N个node，hash function把M个文件uniformly distribute到N个
node上。某天发现capacity不够，加了一个node。首先，要通知所有的client machine
，configuration 改变了。如果不想重启client machine的process，这不是一个
trivial job。其次，文件到node的mapping也变了。比如，本来按照hash function，
一个文件是放在node 1。加了一个node 后，它可能就map到node 2了。平均来说，N/(N
+1)的文件需要move到新的node。这个data migration还是很大的。然后我就提出一些
hash function的design，可以减少data migration。

最后他提了一个问题，说要实现一个function，要统计distributed file system所有
目录的大小。前提是，一个目录下的文件可能放在不同的node上。我说这个不就是在每
个node上统计，然后发到一个merge吗。他说对，但是又问用什么data structure来表
示。我说这就是hash table，key就是directory name，value就是大小。因为
directory本身是树结构，这个hash table的key可以用tree来组织。最后让我实现一个
function，把我说得这个data structure serialize成byte array。因为这个byte
array就是网络传输的data。我用了depth first traverse。不过等我程序写完，才发
现，用breath first traverse会更方便，code也会很简洁。

10. 他是要我用pthread实现thread pool，以及thread job management。先是
define class interface，然后用pthread的mutex和semaphore实现了consumer/
producer queue。这个queue允许users（producers)加入thread jobs，thread
managers(consumers)拿出thread jobs，并执行。

11. Consider you are constructing a system for data synchronization, what
problem will you face, and how you solve it? (I did not do well on this
question, since for my understanding, the data synchronization is normally
among process, or among different users, like the one in source code version
control (Git/repo). I finally understand after 15 mins, he wants to know
about multi-threads synchronization.

12.  
然后栽在一道large scale的设计题上。绝对不是所有的面试官都让你随意发挥，有的
人心里装了一个答案，问的很模糊，你不答到他那个答案他就是不满意。不知道如何解
决这种情况。大概问答过程如下：

He: how would you design a distributed key-value store
Me: DHT or just using clusters
He: details?
Me: we have a large number of machines. first we use a hash function to
retrieve machine ID from the key. Then we connect to the machine and use
another hash function to retrieve the address from the key. Then fetch data
from that address.

He (seems not satisfied): how much space do you need on the master machine?
Me: It depends. If we can use a hash function to derive the IP address of
the machine, we don't need extra space. Otherwise, we need a table to store
key-IP pairs which is XXX large.

He: say more about how you would get the value on one machine
Me: we have two levels of cache, then memory, then disk. We go down to lower
levels if we can't retrieve the value on higher levels. (seems like not
what he expected)

He: how would you fetch the value on the disk? Please fill in a function
char* getData(char *key) { ... }
Me: don't know what he asked is different from what I answered. Ask him a
lot of questions, but haven't got anything useful

He: Think about what the file system is like
Me: Talked about things I know about file systems. Ask him whether he would
like me to write that function based on file system or redesign everything.

He: should be based on file systems.
Me: go from "/", keep iteratively searching for the current directory using
the key, until we hit a file not a directory. Then open that file and read
value and return the value.

整个过程，感觉跟他预想的不一样，跟我预想的也不一样。一直觉得key-value pairs
应该是用分布式的no sql的DB来实现的，没想到要去读file。另外自己对于disk读取的
底层API也不了解，所以答题的时候基本凭想象来答，觉得怎样应该算是reasonable的
。这可能是导致杯具的原因。

有两点教训就是。一，不要觉得自己是new grad就可以只写code，答两道数学题，他们
真的什么都考，特别是这种large scale的，什么问题都可以问。二，两个面试之间一
定要take a break，就算不上厕所也要去一趟洗手间让大脑休息一下，我就是到最后两
个有些晕了，没答好杯具了。
 DHT B+ tree

 13. 固定时间内某网站只允许访问有限次，如何让index次数尽可能的少，又不错过更
新。

 14. Table reservation system. 并行的, 这个用semaphore或mutex tasking的算法
不行么?

 15. Design Patterns 
# 计算机科学是“数数”的科学 #



[0. 注意事项](#注意事项)  
[1. 数数](#数数)  
[2. 程序设计的训练方法](#程序设计的训练方法)  
[3. 代码结构](#代码结构)  
[3+1. 位操作](#位操作)  
[4. 数据结构](#数据结构)  
[5. 常用算法思想](#常用算法思想)  
[6. 一些常识](#一些常识)  
[7. 高级数据结构](#高级数据结构)  
[8. 参考文献](#参考文献)


<a name="注意事项"></a>
## 0. 注意事项 ##
**Powers of 2 table**  
7     128     
8     256  
10    1024   1 thousand    1 k  
16    65536  
20    1,048,576   1 million   1MB  
30    1,073,741,824    1 billion  
32    4,294,967,296    4 GB  
40    1,099,511,627,776   1 trillion  1TB  

**1. Ask Questions**: to make sure anything you don't understand fully  
**2. desgin algorithm**  
What are its space and time complexity?  
Waht happens if there is a lot of data?  
Does your design cause other issues? for example, if you're creating a modified version of a binary search tree, did your design impace the time for insert, find or delete?  
If there are other issues or limitations, did you make the right trade-off? For which scenarios might the trade-off be less optimal?  
If they gave you specific data (e.g., mentioned that the data is ages, or in sorted order), have your leveraged that information? Usually there's a reason that an interviewer gave you specific information.

**3. Pseudocode**  

**4. Code**  
You don't need to rush through your code; in fact, this will most hurt you. Just go at a nice, slow, methodical pace. Also, remember this advice:  
Use Data Structures Generously: where relevant, use a good structure or define your own.  
Don't Crowd your coding: 

**5. Test**  
Extreme cases:  0, negative, null, maximums, minimums  
User error: what happens if the user passes in null or a negative value?  
General cases: test the normal case  

if the algorithm is complicated or highly numerical (bit shifting, arithmetic, etc.), consider testing while you're writing the code rather than just at the end.  


1. exemplify
2. Pattern Matching: Under the Pattern Matching approach, we consider what problems the algorithm is similar to and try to modify the solution to the related problem to develop an algorithm for this problem.
3. simplify and generalize
4. Base case and build
5. Data Structure Brainstorm

good code:
1. correct
2. efficient
3. simple
4. readable
5. maintainable

use data structure gnenrously  
Appropriate code reuse  
Modular  
Flexible and Robust: using variables or using templates/generics to solve a problem  
Error Checking: assumptions about the input,   


**概述**  
写完一段代码之后，自己先检查错误，不要完全指望IDE  

**循环**    
While循环中经常忘记增加计数变量   

脚标与边界处理  
哪些变量循环内部的，哪些是循环外部的？

**指针**  
要判断是否为空

**链表**  
注意判断条件是用p == NULL，还是p->next == NULL

**C函数与STL版本**  
STL中各种容器，函数等要掌握的很好  
Vector:  
insert  
用数组做参数构造vector  

**能抓住事物本质，从自然语言世界到程序语言世界**  
每个算法，结构或者关键词，都有一个最最朴素的本质，这个概念朴素到可以用一句话表述。比如：  
数组最小值：数组前半部分的最小值和后半部分的最小值  
直方图的内接矩形：以数组中每个点为高度的矩形的面积  
每个题目中的概念是如何在程序中进行表达的？  

**算法题目的临界点**  
指针为NULL  
只有一个元素  

**算法题目常见的推广点**  
重复元素的处理  
是否顺序敏感  

**代码能力**  
基本的常用代码的实现，极其重要呀
二分查找的实现
快排实现
应该能达到不依赖于测试用例和调试的程度
提取共用的部分，或者公共的部分

**阅读代码**不是从头到尾扫一遍，而是要看逻辑，排查其中的错误  


**其他**  
**线性结构的遍历**  
**计算下标的方法：**用乘不用除，抽象表  
**数组遍历**，当扫描过去的时候，看所求解的问题（或者操作）是否依赖于其后面尚未扫描到的部分，如果是，那就要暂存了，否则就没有必要。（从信息论的角度怎么样解释呢？）


<a name="数数"></a>
## 1. 数数 ##
**数“数”:**就是在被数事物和自然数之间建立映射。  
自然数：充当计数器，可以实现递推关系的一系列符号。  
被数事物：可以是简单的数，也可以是各种各样的结构，模式（pattern）  
常见的数数：循环，遍历

**计数器：**能够被数的事物就可以作为计数器。  
计数器：是一种符号，它的相邻两个状态之间具有递推关系，不能有环路的存在，并且不能重复  
简单递推：循环就能搞定  
复杂递推：整个的构造过程不一致，前n的构造方法与后面的不同，甚至递推的过程中前后依赖。
所求空间是特殊点的集合  
线性空间可以使用夹逼的方法：类似快排，或者其他两头用两个指针进行搜索

**常见计数器：**  
整数（自然数）：下标，index，指针  
多个计数器：快排（一头一尾），链表查环（一快一慢），指针之间的依赖关系  
复杂计数器：栈的使用，其他数据结构的使用

**构造复杂计数器**  
两个问题：存雨水和快排，它们都使用了两个指针降低了时间复杂度，为什么能够？  
能用两个指针的条件：  
用一个指针的话，至少要遍历2遍  
用两个指针能够降低复杂度的条件是：两个指针之间有相互依赖，比如一个指针一定要再另外一个指针的前面。

**被数事物：**构成了一个搜索空间  
搜索的空间：有限vs无限，可数vs不可数  
空间的结构：线性，树，图  
空间内每个点可以被访问的形式：random access， iterator， etc
常见空间：数组，字母集，字符集，自然数，字符串  
求数组的最大值：一次遍历  
对应每种空间，都有一些常见的建立映射的方法：比如自然数上的“二分搜索”  
在简单空间上构造复杂空间：  
求数组的两两之和的最大值：遍历所有的pair，这个空间是在另外一个简单空间上构造出来的
有的题目之间计算就可以得出结果，有的需要构造出来新的空间  

**建立映射的策略**取决搜索空间的特征
空间的特征  
内容类型：数组，字母集，字符集，自然数，字符串  
空间的结构：线性，树，图  
空间维度的性质：在空间的每一维度上都是有方向的，向上或者向下。比如，树的高度，数组的长度等都是空间
空间可能是递归的
信息空间：方向
左移vs右移
加法vs加法
乘法vs除法
在程序中为了实现上的方便或者为了效率常常在两个方向之间替换
例子：将一个数组循环左/右移k个位置

**常见问题**  

数目，最大值，最小值，特定值

**程序设计：**就是建立一个好的数数模型。  
找到被数事物：恰到好处的描述了问题的目标。  
机器学习：用有限来推测无限。

<a name="程序设计的训练方法"></a>
## 2. 程序设计的训练方法 ##
**画图：**人的大脑对有形的事物更有感觉  

一个很好的方法是画出图来，从图上看，问题有几个维度，从不同的维度开始解题


**一个基本的做题步骤**  

写出程序就能判断正确性，而不是仅仅依赖于测试用例

**当你成功完成一个算法的时候，不妨再思考一下**  
这个算法为什么是在这里是可行的，  
这个实现是最简单的吗？还有其他实现方法吗？  
这种算法的复杂度  
题目能否推广？  
每道题目的实际应用场景  

1. try to solve the problem on your own. I mean, really try to solve it. Many questions are designed to be tough - that's ok! When you're solving a problem, make sure to think about the space and time efficiency. Ask yourself if you could improve the time efficiency by reducing the space efficiency, or vice versa.
2. Write the code for the algorithm on paper. 
3. Test you code-on paper. This means testing the general cases, base cases, error cases, and so on. You'll need to do this during your interview, so it's best to practice this in advance.
4. Type your papaer code as-is into a computer. You will probably make a bunch of mistake. Start a list of all the error you make so that you can keep these in mind in the real interview.

<a name="代码结构"></a>
## 3. 代码结构 ##
**概述**  
代码结构具有多尺度的特性  
按照结构来看代码，在关键的结构内，看其中的细节
要讲的东西列出来表达
抽出经常重复的可能出错的部分
与所使用的数据结构紧密相关

**循环**就是找到周期，然后选择周期的起始点，做成循环  
循环不变式  
结束条件  
是否显式计数  
循环之前做何种处理？  
循环之后做何种处理？计数器是定义在循环之内还是之外
在每个循环内需要做什么？更新什么  

**高级语言的三种循环**三者之间如何选择  
有没有计数器，计数变量的处理，
For: the loop in which updating counter in a regularity.
While: users can update the counter more freely
do… while()  


<a name="位操作"></a>
## 3+1. 位操作 ##
该部分主要选在matrix67　　　
本质上讲，每一位能表达的信息量和一个bool变量是一样的，只不过在计算机语言中提供了大量的bit序列操作，这些操作使得程序更加高效。  
**基本位运算**  

1. and运算：通常用于二进制取位操作，例如判断奇偶数
2. or运算：通常用于二进制特定位的无条件赋值
3. xor运算：通常用于对二进制特定一位进行取反操作，异或0都不变，异或1则取反，xor是自己的逆操作，例如加密，swap
4. not运算：取反，整数的话要注意符号
5. shl运算：左移操作后面补零
6. shr运算：右移操作前面补零


**复合位操作的威力**  
    功能               |           示例            |    位运算  
----------------------+---------------------------+--------------------  
去掉最后一位 　　| (101101->10110)　|　x shr 1  
在最后加一个0　　| (101101->1011010)　|　x shl 1  
在最后加一个1　　| (101101->1011011)　|　x shl 1+1  
把最后一位变成1　| (101100->101101)          |　x or 1  
把最后一位变成0　| (101101->101100)          | x or 1-1  
最后一位取反　　　| (101101->101100)          | x xor 1  
把右数第k位变成1　| (101001->101101,k=3)      | x or (1 shl (k-1))  
把右数第k位变成0　| (101101->101001,k=3)      | x and not (1 shl (k-1))  
右数第k位取反　　| (101001->101101,k=3)      | x xor (1 shl (k-1))  
取末三位　　　　　| (1101101->101)            | x and 7  
取末k位　　　　　| (1101101->1101,k=5)       | x and (1 shl k-1)  
取右数第k位　　　| (1101101->1,k=4)          | x shr (k-1) and 1  
把末k位变成1　　| (101001->101111,k=4)      | x or (1 shl k-1)  
末k位取反　　　　| (101001->100110,k=4)      | x xor (1 shl k-1)  
把右边连续的1变成0　　| (100101111->100100000)    | x and (x+1)  
把右起第一个0变成1　| (100101111->100111111)    | x or (x+1)  
把右边连续的0变成1　| (11011000->11011111)      | x or (x-1)  
取右边连续的1　　　　| (100101111->1111)         | (x xor (x+1)) shr 1  
去掉右起第一个1的左边　| (100101000->1000)         | x and (x xor (x-1))  


**常见例题**　　

1. 二进制中的1有奇数个还是偶数个：　　
	2. 循环方法  
	2. 分治（归并）
    <pre>var
       x:longint;
    begin
       readln(x);
       x:=x xor (x shr 1);
       x:=x xor (x shr 2);
       x:=x xor (x shr 4);
       x:=x xor (x shr 8);
       x:=x xor (x shr 16);
       writeln(x and 1);
    end.</pre>

2. 计算二进制中的1的个数:分治（归并）
	<pre>x := (x and $55555555) + ((x shr 1) and $55555555); 
x := (x and $33333333) + ((x shr 2) and $33333333); 
x := (x and $0F0F0F0F) + ((x shr 4) and $0F0F0F0F); 
x := (x and $00FF00FF) + ((x shr 8) and $00FF00FF); 
x := (x and $0000FFFF) + ((x shr 16) and $0000FFFF); </pre>

3. 二分查找32位整数的前导0个数:二分
	<pre>int nlz(unsigned x)
{
   int n;
   if (x == 0) return(32);
   n = 1;
   if ((x >> 16) == 0) {n = n +16; x = x <<16;}
   if ((x >> 24) == 0) {n = n + 8; x = x << 8;}
   if ((x >> 28) == 0) {n = n + 4; x = x << 4;}
   if ((x >> 30) == 0) {n = n + 2; x = x << 2;}
   n = n - (x >> 31);
   return n;
}
</pre>

4. 只用位运算来取绝对值  
答案：假设x为32位整数，则x xor (not (x shr 31) + 1) + x shr 31的结果是x的绝对值

5. 高低位交换
	<pre>
var
   n:dword;
begin
   readln( n );
   writeln( (n shr 16) or (n  shl 16) );
end.</pre>

6. 二进制逆序
	<pre>
var
   x:dword;
begin
   readln(x);
   x := (x and $55555555) shl  1 or (x and $AAAAAAAA) shr  1;
   x := (x and $33333333) shl  2 or (x and $CCCCCCCC) shr  2;
   x := (x and $0F0F0F0F) shl  4 or (x and $F0F0F0F0) shr  4;
   x := (x and $00FF00FF) shl  8 or (x and $FF00FF00) shr  8;
   x := (x and $0000FFFF) shl 16 or (x and $FFFF0000) shr 16;
   writeln(x);
end.</pre>

**高级题目**


1. n皇后问题位运算版  
	pascal version:

	<pre>
procedure test(row,ld,rd:longint);
var
      pos,p:longint;
begin
{ 1}  if row<>upperlim then
{ 2}  begin
{ 3}     pos:=upperlim and not (row or ld or rd);
{ 4}     while pos<>0 do
{ 5}     begin
{ 6}        p:=pos and -pos;
{ 7}        pos:=pos-p;
{ 8}        test(row+p,(ld+p)shl 1,(rd+p)shr 1);
{ 9}     end;
{10}  end
{11}  else inc(sum);
end;</pre>

	c++ version  
	<pre>int upperlim = 8;
	int num = 0;
	int sum = 0;
	void test(int row, int ld, int rd){
		int pos = 0;
		if(row != upperlim){
			pos = upperlim&(~(row|ld|rd));
			while(pos != 0){
				int p = pos & (-pos);
				test(row+p, (ld+p)<<1, (rd+p)>>1);
				pos = pos - p;
			}
		}
		else sum++;
	}</pre>

2.Gray码：  
**翻转对折的特性**  
	000  
	001  
	011  
	010  ↑  
	……对称线   
	110  ↓  
	111  
	101  
	100  

**两个映射：**  

- n阶的Gray码相当于在n维立方体上的Hamilton回路，因为沿着立方体上的边走一步，n维坐标中只会有一个值改变。  
- Gray码和Hanoi塔问题等价。Gray码改变的是第几个数，Hanoi塔就该移动哪个盘子。比如，3阶的Gray码每次改变的元素所在位置依次为1-2-1-3-1-2-1，这正好是3阶Hanoi塔每次移动盘子编号。

**从二进制数到gray码的转换**：x xor (x shr 1)  
二进制数   Gray码  
   000       000   
   001       001   
   010       011   
   011       010   
   100       110   
   101       111  
   110       101  
   111       100  

   从二进制数的角度看，“镜像”位置上的数即是对原数进行not运算后的结果。比如，第3个数010和倒数第3个数101的每一位都正好相反。假设这两个数分别为x和y，那么x xor (x shr 1)和y xor (y shr 1)的结果只有一点不同：后者的首位是1，前者的首位是0。而这正好是Gray码的生成方法。这就说明了，Gray码的第n个数确实是n xor (n shr 1)。  
另外一个观点，从二进制变换到gray码，每位bit变与不变取决于其前（左）一位的bit是否为1，如果为1则变，否则不变。反过来，从gray码变换到二进制数，每一bit位是否变化，则取决于该位左边1的个数，或者说是从左边第一个为1的位置的右边开始到第二个1位取反，其他为保持不变。

从当前gray码到下一个gray码的变换：不知道是否有解。

(x xor (x shr 1)) xor (not x xor (not x shr 1)) = 01111111

把0到2^(n+m)-1的数写成2^n * 2^m的矩阵，使得位置相邻两数的二进制表示只有一位之差。答案其实很简单，所有数都是由m位的Gray码和n位Gray码拼接而成，需要用左移操作和or运算完成。
	<pre>
var
   x,y,m,n,u:longint;
begin
   readln(m,n);
   for x:=0 to 1 shl m-1 do begin
      u:=(x xor (x shr 1)) shl n; //输出数的左边是一个m位的Gray码
      for y:=0 to 1 shl n-1 do
         write(u or (y xor (y shr 1)),' '); //并上一个n位Gray码
      writeln;
   end;
end.
</pre>


**综合运用**  
1问题描述  
    你玩过“拉灯”游戏吗？25盏灯排成一个5x5的方形。每一个灯都有一个开关，游戏者可以改变它的状态。每一步，游戏者可以改变某一个灯的状态。游戏者改变一个灯的状态会产生连锁反应：和这个灯上下左右相邻的灯也要相应地改变其状态。  
2问题描述  
    花园设计强调，简单就是美。Matrix67常去的花园有着非常简单的布局：花园的所有景点的位置都是“对齐”了的，这些景点可以看作是平面坐标上的格点。相邻的景点之间有小路相连，这些小路全部平行于坐标轴。景点和小路组成了一个“不完整的网格”。  
    一个典型的花园布局如左图所示。花园布局在6行4列的网格上，花园的16个景点的位置用红色标注在了图中。黑色线条表示景点间的小路，其余灰色部分实际并不存在。  
    Matrix67 的生日那天，他要带着他的MM在花园里游玩。Matrix67不会带MM两次经过同一个景点，因此每个景点最多被游览一次。他和他的MM边走边聊，他们是如此的投入以致于他们从不会“主动地拐弯”。也就是说，除非前方已没有景点或是前方的景点已经访问过，否则他们会一直往前走下去。当前方景点不存在或已游览过时，Matrix67会带MM另选一个方向继续前进。由于景点个数有限，访问过的景点将越来越多，迟早会出现不能再走的情况（即四个方向上的相邻景点都访问过了），此时他们将结束花园的游览。Matrix67希望知道以这种方式游览花园是否有可能遍历所有的景点。Matrix67可以选择从任意一个景点开始游览，以任意一个景点结束。  
3问题描述  
    农夫约翰购买了一处肥沃的矩形牧场，分成M*N(1<=M<=12; 1<=N<=12)个格子。他想在那里的一些格子中种植美味的玉米。遗憾的是，有些格子区域的土地是贫瘠的，不能耕种。
    精明的约翰知道奶牛们进食时不喜欢和别的牛相邻，所以一旦在一个格子中种植玉米，那么他就不会在相邻的格子中种植，即没有两个被选中的格子拥有公共边。他还没有最终确定哪些格子要选择种植玉米。
    作为一个思想开明的人，农夫约翰希望考虑所有可行的选择格子种植方案。由于太开明，他还考虑一个格子都不选择的种植方案！请帮助农夫约翰确定种植方案总数。


<a name="数据结构"></a>
## 4. 数据结构 ##
For each of the topic below, make sure you understand how to use and implement them and, where applicable, what the space and time complexity is.
For the data structures and algorithms, be sure to practice implementing them from scratch. You might be asked to implement one directly, or you might be asked to implement a modification of one. Either way, the more comfortable you are with implementations, the better.
### data structure ###
- Linked Lists
- Binary Trees
- Tries
- Stacks
- Queues
- Vectors/Arraylists
- Hash Tables
### algorithms ###
- Breadth First Search
- Depth First Search
- Binary Search
- Merge Sort
- Quick Sort
- Tree Insert / Find / e.t.c
### concepts ###
- Bit manipulation
- Singleton Design Pattern
- Factory Design Pattern
- Memory (stack vs heap)
- Recursion
- Big-O time

**基本数据结构**  
能够快速实现堆，栈等基本数据结构，而不是依赖于STL
需要对每种数据结构的特点有很深的认识，很熟练的操作
有几种实现方法
把最常用的几种烂熟于心
树遍历，查找，几种排序，dfs，bfs，最小生成树
总结每种数据结构的用途
堆、栈到底能帮助我们做什么？
栈：能帮助我们实现对称的结构的检测，比如数组中的元素的处理依赖于其前面元素的内容  

**北大暑期课程的内容**  
数据结构（一）：线段树，树状数组，二维线段树
数学题：组合数学，数论等
数据结构（二）：并查集，DFA，Trie树，Trie图等
若干图论问题：最小生成树，最短路径，强连通分量，桥和割点等
计算几何：线与线求交，线与面求交，求凸包，半平面求交等
搜索：深搜，广搜，剪枝，IDA*算法
动态规划：状态压缩，树形动规，平行四边形法则
网络流算法：基本的网络流算法，Dinic算法，带上下界的网络流，最小费用流
图

<a name="常用算法思想"></a>
## 5. 常用算法思想 ##
**算法**  
什么是算法？  
两个算法不同是什么不同？  
算法的细节固然重要，但是更重要的是如何表达问题，比如，为了解决一个问题，需要用新的辅助空间吗？如果需要的话，应该申请什么样的空间呢？
所谓算法的不同就是这些空间的不同


**概述**  
算法本身的思想比较简单，关键是如何使用其他的数据结构做辅助。  
实际上一个算法分为两部分，一是做准备的部分，一是处理的部分。尽管处理部分看上去似乎是最重要的，但是准备的部分是框架的限定，就像在定义模型，一切处理都是在准备好的前提下进行的。  


**预处理**有时候为了方便应用一个算法需要对原始的数据做一些预处理，比如：  
排序  
添加一个元素  
消除重复元素  



**分治**  

**动归**  


**启发**  
放板子
Astar algorithm
常用方法：动态规划
状态方程
状态方程的物理意义
从图和表的方向来理解
几种类型的dp
树形DP
状态压缩DP

**二分查找**  
怎么分？
下次的方向？  

**LRU算法**  

**dfs**  

<a name="一些常识"></a>
## 6. 一些常识 ##
字母和数字的ASCII码  
整型数：范围  
整型与string间的转换  

**C++中的%对附属运算结果**  
<pre><code>-4%-5 ==-4;
-4%-4 ==0;  
-4%-3 ==-1;  
-4%-2 ==0;  
-4%-1 ==0;  
-4%1 ==0;  
-4%2 ==0;  
-4%3 ==-1;  
-4%-4 ==0;  
-4%5 ==-4;</code></pre>

<a name="高级数据结构"></a>
## 7. 高级数据结构 ##
### 1. 千姿百态的树 ###
建树，插入，删除，查找，合并  
#### 1. 二叉树 ####
二叉树  
二叉查找树  
笛卡尔树
Top Tree
T树

#### 2. 自平衡二叉查找树 ####
AA树  
AVL树  
红黑树  
伸展树  
树堆  
节点大小平衡树

#### 3. B树 ####
B树  
B+树  
B*树  
B×树  
UB树  
2-3树  
2-3-4树  
(a,b)-树  
Dancing Tree  
H树  
#### 4. Trie ####
前缀树  
后缀树  
基数树  

#### 5. 空间划分树 ####

四叉树  
八叉树  
k-d树  
vp-树  
R树  
R*树  
R+树  
X树  
M树  
线段树    
希尔伯特树  
优先树
#### 6. 非二叉树 ####
exponential树  
fusion树  
区间树  
PQ树  
Range树  
SPQR树  
Van Emde Boas tree

#### 7. 其他类型 ####
堆  
散列树  
finger树  
metric树  
Cover树  
BK-树  
Doubly-chained tree  
iDistance  
Link-cut Tree  
树状数组  


**大（小）顶堆**  
**B树(四叉树)**  
**二项式树：**把二项展开式中的系数作为树每层节点的数目来组织整个树的，换言之，就是讲使得树具有了二项式的一些特性。其中最重要的两点是：整个树的节点数目，根节点度数就是树的高度。  
**二项式堆：**把链表的性质和二项式树的性质做了一个组合，这样的话任意个节点数都可以用二项式堆来表示，当插入新的节点的时候，可以根据情况做调整，很方便。其中，每棵树都是一个大顶堆或者小顶堆
主要操作：插入新元素，合并两个二项式堆。  
**斐波那契堆：**斐波那契堆是一种松散的二项堆，与二项堆的主要区别在于构成斐波那契堆得树可以不是二项树，并且这些树的根排列是无顺序的。斐波那契堆得优势在于它对建堆、插入、抽取最小关键字、联合等操作能在O(1)的时间内完成。  
这是对二项堆效率的巨大改善。但由于斐波那契堆得常数因子以及程序设计上的复杂度，使它不如通常的二项式堆合适。因此，它的价值仅存在于理论意义上。   
**左偏树：**1左偏树(Leftist Tree)是一种可并堆(Mergeable Heap) ，它除了支持优先队列的三个基本操作（插入，删除，取最小节点），还支持一个很特殊的操作——合并操作。   
2左偏树是一棵堆有序(Heap Ordered)二叉树。 3左偏树满足左偏性质(Leftist Property)。    
[性质1] 节点的键值小于或等于它的左右子节点的键值。   
[性质2] 节点的左子节点的距离不小于右子节点的距离。 [性质3] 节点的左子节点右子节点也是一颗左偏树。  
**二叉平衡(查找)树:**  
**AVL树**  
**红黑树(red-black tree)**   
**伸展树(spray tree)**  自适应查找树，是一种用于保存有序集合的简单高效的数据结构。伸展树实质上是一个二叉查找树。  
允许查找，插入，删除，删除最小，删除最大，分割，合并等许多操作，这些操作的时间复杂度为O(logN)。由于伸展树可以适应需求序列，因此他们的性能在实际应用中更优秀。  
伸展树支持所有的二叉树操作。伸展树不保证最坏情况下的时间复杂度为O(logN)。伸展树的时间复杂度边界是均摊的。尽管一个单独的操作可能很耗时，但对于一个任意的操作序列，时间复杂度可以保证为O(logN)。   

**区间树(interval tree)线段树**线段树是一棵二叉树，树中的每一个结点表示了一个区间[a,b]。a,b通常是整数。每一个叶子节点表示了一个单位区间。对于每一个非叶结点所表示的结点[a,b]，其左儿子表示的区间为[a,(a+b)/2]，右儿子表示的区间为[(a+b)/2,b](除法去尾取整）。 
线段树的基本用途：线段树适用于和区间统计有关的问题。比如某些数据可以按区间进行划分，按区间动态进行修改，而且还需要按区间多次进行查询，那么使用线段树可以达到较快查询速度。最简单的应用就是记录线段有否被覆盖，并随时查询当前被覆盖线段的总长度。那么此时可以在结点结构中加入一个变量int count；代表当前结点代表的子树中被覆盖的线段长度和。这样就要在插入（删除）当中维护这个count值，于是当前的覆盖总值就是根节点的count值了。 Lazy思想：对整个结点进行的操作，先在结点上做标记，而并非真正执行，直到根据查询操作的需要分成两部分。
    
**前缀树(字典树,Trie树):**查询某个单词（前缀）在所有单词中出现次数的一种数据结构,查询和插入时间复杂度都是O(n)，是一种以空间换时间的方法。  
**跳跃表**  
**伸展树(spray tree)**


<a name="参考文献"></a>
## 8. 参考文献 ##
1.程序员数学  
2.尹一通组合数学  
3.leetcode  
4.http://www.matrix67.com/blog/archives/263  

<a name="My Header"></a>
## My Header ##
This is some content in my first section.


## 欢迎使用 MarkdownPad 2 ##

**MarkdownPad** 是 Windows 平台上一个功能完善的 Markdown 编辑器。

### 专为 Markdown 打造 ###

提供了语法高亮和方便的快捷键功能，给您最好的 Markdown 编写体验。

来试一下：

- **粗体** (`Ctrl+B`) and *斜体* (`Ctrl+I`)
- 引用 (`Ctrl+Q`)
- 代码块 (`Ctrl+K`)
- 标题 1, 2, 3 (`Ctrl+1`, `Ctrl+2`, `Ctrl+3`)
- 列表 (`Ctrl+U` and `Ctrl+Shift+O`)

### 实时预览，所见即所得 ###

无需猜测您的 [语法](http://markdownpad.com) 是否正确；每当您敲击键盘，实时预览功能都会立刻准确呈现出文档的显示效果。

### 自由定制 ###
 
100% 可自定义的字体、配色、布局和样式，让您可以将 MarkdownPad 配置的得心应手。

### 为高级用户而设计的稳定的 Markdown 编辑器 ###
 
 MarkdownPad 支持多种 Markdown 解析引擎，包括 标准 Markdown 、 Markdown 扩展 (包括表格支持) 以及 GitHub 风格 Markdown 。
 
 有了标签式多文档界面、PDF 导出、内置的图片上传工具、会话管理、拼写检查、自动保存、语法高亮以及内置的 CSS 管理器，您可以随心所欲地使用 MarkdownPad。
