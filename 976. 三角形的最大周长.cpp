class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        for(int i = A.size() / 2 - 1; i >= 0; i--) {
            adjustheap(A, i, A.size() - 1);
        }
        for(int i = A.size() - 1; i >= 0; i--) {
            swap(A[0], A[i]);
            adjustheap(A, 0, i - 1);
            if(i < A.size() - 2 && i >= 0 &&
                A[i] + A[i + 1] > A[i + 2]) {
                    return A[i] + A[i + 1] + A[i + 2];
            }
        }
        return 0;
    }


    void adjustheap(vector<int>& A, int start, int end) {
        int parent = start;
        int son = 2 * start + 1;
        while(son <= end) {
            //注意son+1<=end的条件
            if(son + 1 <= end && A[son] < A[son + 1]) son++;
            if(A[parent] >= A[son]) break;
            else if(A[parent] < A[son]) {
                swap(A[parent], A[son]);
                parent = son;
                son = parent * 2 + 1;
            }
        }
    }
};