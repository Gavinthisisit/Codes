
public class TestSort{
	public static int MAXSIZE = 25;
	public void sort(Comparable[] arr){
		Comparable temp;
		for(int k=1;k<arr.length;k++){
			temp = arr[k];
			int i;
			for(i = k-1;i>=0&&arr[i].compareTo(temp)>0;i--)
				arr[i+1] = arr[i];
			arr[i+1] = temp;
		}
	}
	public void print(Comparable arr[]){
		for(int k=0;k<arr.length;k++){
			if(k%5 == 0)
				System.out.println();
			System.out.print(arr[k].toString()+" ");
		} 	
		System.out.println();
	}
	public static void main(String args[]){
		Integer iArr[] = new Integer[TestSort.MAXSIZE];
		Float fArr[] = new Float[TestSort.MAXSIZE];
		for(int k=0;k<TestSort.MAXSIZE;k++){
			iArr[k] = new Integer((int)(Math.random()*10000));
			fArr[k] = new Float(Math.random()*10000);
		}
		TestSort test = new TestSort();
		test.sort(iArr);
		test.print(iArr);
		test.sort(fArr);
		test.print(fArr);
	}
}

/*这里所讲的多态有点像C++中的模板*/