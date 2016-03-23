public class Sort{
	public void InsertionSort(int arr[]){
		int temp;
		for(int i=0;i<arr.length;i++){
			int k;
			temp = arr[i];
			for(k=i-1;k>=0 && arr[k]<=temp;k--)
				arr[k+1] = arr[k];
			arr[k+1] = temp;
		}
	}
	public void swap(int arr[]){
		int temp;
		for(int i=0;i<arr.length;i++){
			int k;
			int flag;
			temp = arr[i];
			flag = i;
			for(k=i;k<arr.length;k++)
				if(arr[k]<temp){
					temp = arr[k];
					flag = k;
				}
			arr[flag] = arr[i];
			arr[i] = temp;
		}
	}
	public void print(int arr[]){
		for(int i=0;i<arr.length;i++)
			System.out.print(arr[i]+" ");
		System.out.println();
	}
	public static void main(String args[]){
		int intArr[] = {10,5,18,65,33,3,8,18};
		Sort soter = new Sort();
		soter.print(intArr);
		soter.InsertionSort(intArr);
		soter.print(intArr);
	}
	
}
/*
	int temp;
	for(int i=0;i<arr.length;i++){
		temp = arr[i];
		for(int k=i-1;k>=0 && arr[k]>temp;k--)
			arr[k+1] = arr[k];
		arr[k+1] = temp;			//注意for循环执行规则，因此此处应该是arr[k+1] = temp;
	}
*/