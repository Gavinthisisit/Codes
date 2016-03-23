 class CalcAverage{
	public double avgFirstN(int N){
		int sum = 0;
		if(N<=0)
		throw new IllegalArgumentException("ERROR: Illegal arugument");
		for(int k=1;k<=N;k++)
			sum+=k;
		return sum/N;
	}
}
public class CalcAvgTest{
	public static void main(String args){
		try{
			CalcAverage ca = new CalcAverage();
			System.out.println("AVG+ "+ca.avgFirstN(0));
		}
		catch(IllegalArgumentException e){
			System.out.println(e.getMessage());
			e.printStackTrace();
			System.exit(0);
		}
	}
}