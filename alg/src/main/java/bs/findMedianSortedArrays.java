public class findMedianSortedArrays{
    public double solution(int[] nums1, int[] nums2) {
        int n1, n2, p = 0, q = 0, index = 0;
        if (nums1 == null) n1 = -1;
        else n1 = nums1.length - 1;
        if (nums2 == null) n2 = -1;
        else n2 = nums2.length - 1;
        int [] tmp = new int [n1 + n2 + 2];
        while (p <= n1 && q <= n2) {
            if (nums1[p] <= nums2[q]) tmp[index++] = nums1[p++];
            else tmp[index++] = nums2[q++];
        }
        if (p > n1){
            for (int i = q; i <= n2;) {
                tmp[index++] = nums2[i++];
            }
        } else {
            for (int i = p; i <= n1;) {
                tmp[index++] = nums1[i++];
            }
        }
        return (index % 2 == 1) ? (double)tmp[index/2] : (double)((tmp[index/2] + tmp[index/2 - 1]))/2;
        
    }
}