/***********************************************************************************************************************
 * Created by caffe on 2019/11/21.
 * 769. 最多能完成排序的块
 * 数组arr是[0, 1, ..., arr.length - 1]的一种排列，我们将这个数组分割成几个“块”，并将这些块分别进行排序。之后再连接起来，使得连接的结果和按升序排序后的原数组相同。

    我们最多能将数组分成多少块？

    示例 1:

    输入: arr = [4,3,2,1,0]
    输出: 1
    解释:
    将数组分成2块或者更多块，都无法得到所需的结果。
    例如，分成 [4, 3], [2, 1, 0] 的结果是 [3, 4, 0, 1, 2]，这不是有序的数组。

    示例 2:

    输入: arr = [1,0,2,3,4]
    输出: 4
    解释:
    我们可以把它分成两块，例如 [1, 0], [2, 3, 4]。
    然而，分成 [1, 0], [2], [3], [4] 可以得到最多的块数。

    注意:

        arr 的长度在 [1, 10] 之间。
        arr[i]是 [0, 1, ..., arr.length - 1]的一种排列。
 **********************************************************************************************************************/
/**
 * solution 1 : 双指针法
 * 可以分块的区域必然具备以下特点，当前区间的最大值小于其后面区间的最小值。只有这样才能够保证在前面区间排序完成之后是小于后面区间的。
 * 具体的实现方法是：
 * 1）用指针pleft和pright指向当前区间
 * 2）在当前区间搜索最大值max，在后面区间搜索最小值min，如果max<=min则该区间可以被划分出去，计数器加一，重置pleft和pright。否则pright向右移动直到数组尾部。
 * 时间复杂度： O（n）
 * 空间复杂度： O（1）
 */
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if(arr.size()==1) return 1;
        int pleft=0,pright;
        int count=0;
        while(pleft<arr.size()){
            pright=pleft;
            while(pright<arr.size()){
                int cur_max=INT_MIN;
                for(int i=pleft;i<=pright;++i) cur_max=max(cur_max,arr[i]);
                int next_min=INT_MAX;
                for(int i=pright+1;i<arr.size();++i) next_min=min(next_min,arr[i]);
                if(cur_max<=next_min){
                    count++;
                    pleft=pright+1;
                    break;
                }else pright++;
            }
        }
        return count;
    }
};