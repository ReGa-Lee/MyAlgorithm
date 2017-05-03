/*
描述：原地排序(只用了很小的辅助栈)，且是线性对数时间复杂度，
实现：使用随机输入(改变数组的方式)防止出现最坏情况并使运行时间可以预计，递归地将(子)数组划分为 左<右
*/
public class Quick{
	public static void sort(Comparable[] a){
		StdRandom.shuffle(a);	//	消除为输入的依赖
		sort(a, 0, a.length - 1);
	}
	
	private static void sort(Comparable[] a, int left, int right){
		if(left >= right)
			return;
		
		int index = partition(a, left, right);
		sort(a, left, index - 1);
		sort(a, index + 1, right);
	}
	//	less() exch() isSorted() main()方法见 2.0 排序算法类模板
}