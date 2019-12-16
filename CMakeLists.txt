cmake_minimum_required(VERSION 3.14)
project(LeetCode)

set(CMAKE_CXX_STANDARD 14)
add_executable(main main.cpp)
ADD_SUBDIRECTORY(0-100/53._Maximum_Subarray)
#add_executable(LeetCode 0-100/53._Maximum_Subarray/766. Toeplitz Matrix.cpp)
#add_executable(LeetCode 0-100/54_Spiral_Matrix/766. Toeplitz Matrix.cpp)
add_executable(LeetCode 0-100/94_Binary_Tree_Inorder_Traversal/solution1.cpp "dynamic-programming/139. 单词拆分/solution.cpp" "dynamic-programming/152. 乘积最大子序列/solution.cpp" "dynamic-programming/198. 打家劫舍/solution.cpp" "dynamic-programming/213. 打家劫舍 II/solution.cpp")