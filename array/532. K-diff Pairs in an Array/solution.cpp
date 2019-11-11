/***********************************************************************************************************************
 * Created by caffe on 2019/11/7.
 *532. K-diff Pairs in an Array
 *  Given an array of integers and an integer k, you need to find the number of unique k-diff pairs in the array. Here a k-diff pair is defined as an integer pair (i, j), where i and j are both numbers in the array and their absolute difference is k.

    Example 1:

    Input: [3, 1, 4, 1, 5], k = 2
    Output: 2
    Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
    Although we have two 1s in the input, we should only return the number of unique pairs.

    Example 2:

    Input:[1, 2, 3, 4, 5], k = 1
    Output: 4
    Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).

    Example 3:

    Input: [1, 3, 1, 5, 4], k = 0
    Output: 1
    Explanation: There is one 0-diff pair in the array, (1, 1).

    Note:

        The pairs (i, j) and (j, i) count as the same pair.
        The length of the array won't exceed 10,000.
        All the integers in the given input belong to the range: [-1e7, 1e7].
 **********************************************************************************************************************/
/**
 * solution 1 ： set法
 * 遍历数组，对于nums[i]，如果k-nums[i]没有出现在set中，则把该元素加入map，否则，计数器加一。
 * 这样一来，记录的都是后面出现的元素，因此也不会出现重复的情况。
 * 时间复杂度：O（n）
 * 空间复杂度：O（n）
 */