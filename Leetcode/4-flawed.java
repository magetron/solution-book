class Solution {
	public double findMedianSortedArrays(int[] nums1, int[] nums2) {
		ArrayList<Integer> merge = new ArrayList<>();
		int len1 = nums1.length;
		int len2 = nums2.length;
		int goal = (len1 + len2) / 2;
		//System.out.println(goal);
		int i = 0, j = 0;
		while (i < len1 && j < len2) {
			if (nums1[i] > nums2[j]) merge.add(nums2[j++]);
			else merge.add(nums1[i++]);
			if (merge.size() == (goal + 1)) break;
		}
		while (i < len1) {
			merge.add(nums1[i++]);
			if (merge.size() == (goal + 1)) break;
		}
		while (j < len2) {
			merge.add(nums2[j++]);
			if (merge.size() == (goal + 1)) break;
		}
		if ((len1 + len2) % 2 == 1) return merge.get(goal);
		else return (double)(merge.get(goal) + merge.get(goal - 1)) / 2;
	}
}
