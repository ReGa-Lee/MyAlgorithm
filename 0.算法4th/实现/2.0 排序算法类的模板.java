/*
API - Example(sort)
*/

public class Example{
	public static void sort(Comparable[] a){}
	private static boolean less(Comparable v, Comparable w){ 
		return v.compareTo(w) < 0; 
	}
	private static void exch(Comparable[] a, int i, int j){ 
		Comparable t = a[i]; 
		a[i] = a[j];
		a[j] = t;
	}
	private static void show(Comparable[] a){
		for(int i = 0; i < a.length; i++)
			stdOut.print(a[i] + " ");
		stdOut.println();
	}
	
	public static boolean isSorted(Comparable[] a){
		for(int i = 0; i < a.length; i++)
			if(less(a[i], a[i-1]))
				return false;
		return true;
	}
	
	public static void main(String[] args){
		String[] a = In.readString();
		sort(a);
		assert isSorted(a);
		show(a);
	}
}

//	实现Comparable接口的(可比较的)数据类型 举例 Date
public class Date implements Comparable<Date>{
	private final int day;
	private final int month;
	private final int year;
	
	public Date(int d, int m, int y){
		day = d;
		month = m;
		year = y;
	}
	
	public int day(){ return day; }
	public int month(){ return month; }
	public int year(){ return year; }
	
	public int compareTo(Date that){
		if(this.year > that.year)
			return +1;
		if(this.year < that.year)
			return -1;
		if(this.month > that.month)
			return +1;
		if(this.month < that.month)
			return -1;
		if(this.day > that.day)
			return +1;
		if(this.day < that.day)
			return -1;
		return 0;
	}
	
	public String toString(){
		return month + "/" + day + "/" + year;
	}
}
