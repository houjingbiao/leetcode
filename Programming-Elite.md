##chapter 03 发现群组##

### 1. 分级聚类（Hierarchical Clustering） ###

**分级聚类（Hierarchical Clustering）：**通过连续不断地将最为相似的组件两两合并，来构造出一个群组的层级结构。

**树状图(dendrogram):**

**聚类的紧致程度**

    1.生成的树状图使用起来比较麻烦，仍然需要在树状图中进行查找
    2.每次都要计算两个向量之间的距离，计算量太大

### 2. 列聚类(column clustering) ###

**列聚类(column clustering)：**就是每个单词作为节点聚类


### 3. k-均值聚类(k-means clustering) ###
**k-均值聚类(k-means clustering)：**


##chapter 04 搜索引擎的组成##

**搜集文档**
为文档建立索引
返回一个经过排序的文档列表
真正的奥妙在于结果的排列方式
基于网页内容的度量方法：单词频度
基于网页外部信息的度量方法：Pangerank


**神经网络**


## chapter 05 optimization 优化 ##
### **1. 结果表达** ###

### **2. 代价函数** ###

### **3. 优化方法：** ###
就是建立一个循环的过程，在这个过程中使得结果越来越好。循环的结束条件是什么？每次循环更新的部分是什么？能否找到全局最优解

**随机搜索：**没有考虑空间内点与点之间的关系

**爬山法hillclimb：**局部相似性（连续），但是容易陷入局部最优

**模拟退火anealing：**局部相似性，但是按照一定的概率来避免陷入局部最优

**遗传算法：**局部相似性，同时向多个不同的方向进化。




## chapter 06文档过滤document filtering ##

本质上是文档的分类问题

**分类器：**一个分类器包含特征，类别，以及特征和类别之间的联系

**朴素的贝叶斯方法naivebayes:**
训练过程主要是统计各个特征值与分类之间的关系，相当于建立一个二维的关系表，每行对应一个关键字，每列对应一个分类，训练的过程就是统计每个关键字对应的每个级别有多少个文档。


**费舍尔方法fisher:**

    Pr(category|feature)=具有指定特征且属于该分类的文档数/具有指定特征的文档总数
具体的计算方法如下:
属于某分类的概率clf=Pr(feature|category)

属于所有分类的概率freqsum=Pr(feature|category)

cprob=clf/(clf+nclf)

combining the Probabilities:
假设：各个特征之间是独立同分布的，因此服从对数卡方分布




## chapter 07决策树建模 ##

dafd 
dfasdfdsafdsf 
fdsaf


adfadsfdsf

## chapter 08构建价格模型 ##

## chapter 09高阶分类：核方法与SVM ##


## chapter 10寻找独立特征 ##

## chapter 11智能进化 ##

## chapter 12算法总结 ##





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
