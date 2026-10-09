# C++ 算法练习

> 使用 C++20 与 Visual Studio 2026 编写的算法与数据结构练习项目，涵盖常见排序算法、二叉树与二叉搜索树、单链表等基础实现。

![C++](https://img.shields.io/badge/C%2B%2B-20-00599C?logo=cplusplus&logoColor=white)
![Visual Studio](https://img.shields.io/badge/Visual%20Studio-2026-5C2D91?logo=visualstudio&logoColor=white)
![Platform](https://img.shields.io/badge/platform-Windows%20x64-0078D4)

## 项目简介

本项目把学习过程中实现的常用算法和数据结构集中在一个控制台工程里，方便对照复习、逐步补充。代码保持最朴素的写法，重点是把每一种算法和结构的思路写清楚，而不是追求最短或最快的实现。

## 目录结构

```text
cpp-algorithms/
├── README.md
├── .gitignore
├── c++算法.slnx                      # VS2026 解决方案（x64 / x86）
└── c++算法/
    ├── c++算法.cpp                   # 算法与数据结构实现
    ├── c++算法.vcxproj               # 项目文件（PlatformToolset v145，C++20）
    └── c++算法.vcxproj.filters       # 项目筛选器
```

## 功能一览

### 排序算法

| 算法 | 类名 | 平均时间复杂度 | 最坏时间复杂度 | 额外空间 | 是否稳定 |
| --- | --- | --- | --- | --- | --- |
| 插入排序 | `InsertionSort` | O(n²) | O(n²) | O(1) | 稳定 |
| 希尔排序 | `shellSort` | 约 O(n^1.3) | O(n²) | O(1) | 不稳定 |
| 归并排序 | `MergeSort` | O(n log n) | O(n log n) | O(n) | 稳定 |
| 快速排序 | `QuickSort` | O(n log n) | O(n²) | O(log n) | 不稳定 |
| 堆排序 | `HeapifySort` | O(n log n) | O(n log n) | O(1) | 不稳定 |
| 计数排序 | `CountSort` | O(n + k) | O(n + k) | O(k) | 稳定 |
| 桶排序 | `BucketSort` | O(n + k) | O(n²) | O(n + k) | 取决于桶内排序 |
| 基数排序 | `RadixSort` | O(d(n + 10)) | O(d(n + 10)) | O(n + 10) | 稳定 |

说明：`n` 为数据量，`k` 为数据取值范围，`d` 为最大数的位数。

### 数据结构

| 结构 | 类名 | 已实现操作 |
| --- | --- | --- |
| 二叉树 | `BinaryTree` | 按前序序列建树（`-1` 表示空节点）、前序 / 中序 / 后序遍历、层序遍历、析构释放节点 |
| 二叉搜索树 | `TreeNode` | 插入节点、查找最小节点、删除节点（删除含两个子节点的情况待完善） |
| 单链表 | `Node` | 创建节点、头插、尾插、指定位置插入、打印、释放 |

## 快速开始

### 使用 Visual Studio 2026

1. 克隆仓库：

   ```bat
   git clone https://github.com/hhhj0/cpp-algorithms.git
   ```

2. 打开解决方案文件 `c++算法.slnx`。
3. 选择配置 `Debug` 与平台 `x64`。
4. 按 `Ctrl + F5` 编译并运行。

项目使用 `PlatformToolset v145`、C++ 语言标准 `stdcpp20`，目标 Windows SDK 版本为 `10.0`。

### 使用命令行

在 Visual Studio 开发者命令提示符中执行：

```bat
cl /std:c++20 /EHsc "c++算法\c++算法.cpp"
```

## 示例输出

`main` 中演示的是插入排序，输入数组为 `{11, 13, 9, 5, 12, 19, 14}`，排序后输出：

```text
5 9 11 12 13 14 19
```

## 实现说明

- 所有算法与数据结构都集中在 `c++算法/c++算法.cpp` 中，按“排序算法 → 二叉树 → 二叉搜索树 → 单链表”的顺序排列。
- 排序算法统一以 `vector<int>` 作为输入，直接原地排序或返回排序结果。
- 二叉树通过前序序列建树，遇到 `-1` 视为空节点，便于用一行数据描述整棵树。
- 二叉树的析构函数会递归释放所有节点，避免练习代码常见的内存泄漏。

## 已知问题与改进方向

- `deleteNode` 在删除有两个子节点的节点时尚未完成，目前会走到函数末尾而没有返回值，实际使用前需要补充“用中序后继替换并递归删除”的逻辑。
- `RadixSort` 按十进制位处理，只适用于非负整数；如需支持负数，应先分离正负号或统一加上偏移量。
- `BucketSort` 固定使用 `n` 个桶，数据分布极不均匀时性能会下降，可改为按数据范围动态划分桶。
- `main` 目前只演示插入排序，其他排序算法和数据结构可以按需补充测试代码。

## 说明

本项目用于 C++ 与算法基础练习，代码以学习和记录实现过程为主。
