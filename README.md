# Leetcode 刷题笔记！
## 基本策略
- 按照题解数量排序
- 选择题解数量大于200的中等题目
- 在其他类似仓库里搜刮更好的总结/题解少但值得刷的漏网之鱼

https://leetcode-cn.com/problemset/algorithms/?difficulty=%E4%B8%AD%E7%AD%89&status=%E6%9C%AA%E5%81%9A&topicSlugs=backtracking%2Cdynamic-programming%2Cdivide-and-conquer%2Cbinary-search%2Ctwo-pointers%2Crecursion%2Cbinary-search-tree%2Cgraph%2Cunion-find%2Cbreadth-first-search%2Cdepth-first-search%2Ctree%2Cbit-manipulation%2Csort

https://leetcode-cn.com/problemset/algorithms/?difficulty=%E4%B8%AD%E7%AD%89&status=%E6%9C%AA%E5%81%9A&topicSlugs=string%2Carray
在使用与数据结构有关的标签进行筛选并完成相关题目时，应侧重对数据结构的常见用法，相应容器的常用成员函数的熟悉和理解。

在使用与算法有关的标签进行筛选时，应使用相应的算法类型完成题目，并归纳总结该类题目的特性，共同点和类似的解答方法。

另外，一些与数组、链表、栈等线性数据结构有关的题目中有一些常用trick，不好想但是很好用，直接拿来背就完了。
## 分类方法
- 用使用到的/输入的数据结构类型对题目进行分类不太科学，算法题最重要的是思路/策略，而思路和策略是可枚举的，相互组合产生了各类题目
- 对于常见的各类算法，如排序、搜索、图遍历、二叉树遍历，直接背代码基本模板
- 对于常见的策略/trick也直接背代码，真的不是很多
# Tricks
- 前缀和：限制前缀和所对应的字串长度时，应反向索引，在某一元素可使用时再加入map或其他查询容器中
- 逆向思维：预设结果已知/反向搜索/反向迭代
- 下一个排列：寻找第一个下降对，反转之前的有序部分，再执行一次对换
- 区间类问题 通常可以考虑按照右端点优先排序
- LRU Cache：双向链表解决查找后移动到表头的功能 map解决结点的O（1）访问
- 原地哈希:有限范围的重复数字，将数字移动到arr[i]=i的位置上，达到O(n)的复杂度
# Strategies
# Data Structure
## Array&String(std::vector,std::string)(deprecated)
### Trie 字典树/前缀树
- map<string,_T>的特殊（高效）实现
- 也可实现前缀匹配
- 注意事项：is_word标志位是在查找结束后的哨兵节点中标识的，省去了last指针
直接背 具体代码见p211.cpp
## Stack(std::stack)
- 常规应用：150逆波兰表达式 71路径简化
- 单调栈：弹出比栈顶小的元素(下标)，来获得每个元素的下一个更大元素，739每日温度 剑指59II队列的最大值 503下一个更大元素
- 括号匹配及其变种 394字符串解码
- 括号匹配+算符优先级 227基本计算器
- **删除部分字符串问题**：不断清除逆序对中较大元素，可能需要添加更多规则 402移除k位数字 316去除重复字母
## LinkedList
TODO： 148排序链表 147链表插入排序 109有序链表转BST
**背代码**
- 反转 92
- 倒数第N个19 中点143
- 寻找分叉 环
- 插入 删除
- 分隔86 旋转61
- 在头部增加哨兵 方便遍历/插入/。。。
## Map(std::map， std::unordered_map)<br>Heap(std::priority_queue)
TODO： 767重构字符串 454四数相加II 659分隔数组为连续子序列
- 容器默认是按key升序排列，否则应传入is_less模板参数用于比较
- map用于缓存和查询 3无重复的最长子串 560和为K的字数组
- top K问题及其变种 215第K大的元素
- priority_queue/partition实现：结果是/否有序，过程中是否维护topK
- priority_queue可以为线性访问容器增加堆的功能
- 按value排序：使用priority_queue适配器? 347前K个高频单词
- key的问题：分类时如何为元素建立正确和有效的索引 49字母异位词分组 36有效的数独 973最接近原点的k个点438字母异位词
- **容器的迭代器构造**
## Binary (Search) Tree
### **背代码：四种遍历方法的迭代(有/无路径版本)**
- 基于队列的层次遍历 102层序遍历
- 基于两个stack的层次遍历 103锯齿形遍历
- 遍历过程中的路径维护
- 节点遍历的handler
- 路径深入的handler/条件判断(pruning)
- 路径回退的handler
---
TODO： **平衡二叉树的增删操作** 701插入 450删除 654最大二叉树
- 遍历过程中修改指针操作：注意是否影响遍历代码 114二叉树展开为链表
- BST与中序遍历 538BST转累加树 230BST中第K小的元素
- 平衡二叉树 高度 后序遍历 814二叉树剪枝 ???验证平衡二叉树
- 重建二叉树：以先/后序遍历为基础，在中序遍历中查找 105/106
- **基于stack的重建二叉树?**
- 左侧链
- 更新访问过的节点的值来完成算法 337打家劫舍III
- 二叉搜索树的迭代器 173迭代器
# Algorithm
## Bit Manipulation
- 基本操作的作用和用法
- 异或：统计出现奇数次的bit
- x=x&(x-1) 去除最右边的1 
- 进一步可以保留右边的1、统计1的次数
- 其他怪题：背代码
## Two Pointers
- 从容器两侧开始遍历
- 链表的快慢指针常规trick
- 18四数之和：排序+双指针
## Binary Search
TODO:300最长递增子序列：二分+贪心 29两数相除 162寻找峰值 454四数相加
- 基于下标中点查询值 标准二分查找/upper bound/lower bound
- 基本二分查找模板 34排序数组中查找 33搜索旋转排序数组 153搜索旋转排序数组最小值 81搜索旋转排序数组II（有重复值）
- 传入is_less参数指定排序规则 剑指45把数组排成最小的数
- 统计满二叉树的节点个数等其他变种 222完全二叉树的节点个数
- 基于值的中点查询下标：378有序矩阵的topK 74搜索二维矩阵 两个有序序列的中位数
### 滑动窗口
209长度最小的子数组 718最长重复子数组
## Sorting
- 九大排序的复杂度、原理、稳定性
- 常见排序的代码：归并、快排、插入
148排序链表 147链表的插入排序 1300转变数组后最接近目标值的数组和
### 区间类问题
57插入区间：左端点和右端点分别二分 

452用最少的箭引爆气球：右端点排序+贪心
 
56合并区间：排序后顺序合并
## Recursion/Divide&Conquer
- DFS/匹配/搜索问题
- 使用function<void()>类型做递归
- 局部变量代替递归函数参数
- 在内部递归调用前后手动更改变量值/栈的压入弹出：组合/组合II/组合III
- ！递归算法中的去重问题：所选元素应当有序，在上一个元素与当前元素相同时不递归 40组合总和II 491递增子序列
## Dynamic Programming
- 问题判定：最优子结构
- 边界条件/递归基
- 状态转移方程：预设子问题的解已知
- 空间优化：观察dp数组的引用，若只使用dp\[i-k](k是有限常数)可改为滚动数组
### 主要题型
- 一维dp
- 二维dp：维度含义相同（矩阵类问题）/维度含义不同（各类背包问题、硬币问题）
## Greedy Alogorithm
- 如何判定一个问题是否适用于贪心：反证法，能否找到一个令贪心算法无法得到最优解的用例
## Graph Algorithm
- 基本特征：基于“邻接”性质提出问题
- 图的表示：邻接矩阵、edge集合、char/int数组（默认上下左右是邻居）
- 为访问过的节点做标记：在原数据结构上修改，回退时复原or使用额外的vector（如沉岛法）
- 顺序：并查集、广度优先、深度优先、图
### 主要题型
- 连通分量统计（并查集）
- 有向无环图判定（拓扑排序）
- 最小生成树问题（Kruskal-稀疏图/Prim-稠密图）1584
### DFS
- 深度优先搜索，做**路径匹配**时是一种贪心策略，可附加剪枝策略
- 基于stack 
- 可以得到当前节点的**路径**
- 使用stack进行存储的路径可以叠加各类线性数据结构相关的trick，如单调栈、最大最小栈等，可加速“筛选指定类型路径”的dfs
- 根据路径做判断时需要手动缓存堆栈
- 一般是递归实现，主要用于完成与路径相关的、可附加剪枝策略的题目、以及**指数规模增长**的**生成类**题目
- 调用递归函数前后，若通过成员变量方式传参，应注意恢复变量值
- 若手动构造调用堆栈，应在调用递归函数前后严格遵守压入和弹出顺序
- 491 递增子序列 17电话号码字母组合 剑指12 矩阵中的路径
### BFS 
- 广度优先搜索，无路径信息
- 基于queue实现
- (多源)广度搜索：蔓延类问题、用蔓延/扩张方法解决最远距离问题
### UnionFind
TODO:399 除法求值 990 等式方程的可满足性  
- **背代码：并查集的class实现**
- 边查找边修改
- 可以使用额外数组存储指标，合并时维护。要求指标具有传递性且路径无关
- 索引问题：如何为图结点构造有效的索引（string->Hash/pair->i*cols+j）
- 一个节点只能有一个root
- 路径压缩、按秩合并
- 可维护的统计信息：连通分量的节点数（面积） 数量  
- 集合划分/合并问题 721账户合并 1202 交换字符串中元素 959 斜杠划分区域
- 连接类问题：684冗余连接 947移除同行列石头 
## Memorization/Backtracking
# Omitted Tags
- 树状数组
- 线段树
- 设计
- 极小化极大
- 拓扑排序
- 蓄水池抽样
- 几何
- 数学
- 脑筋急转弯
