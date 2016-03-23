

public class Search
{
	private String buff;
	public Search()
	{
		
	}
	public String KeyWordSearch(String s,String keyWord){
		String resultStr = "";
		int count = 0;
		int ptr = s.indexOf(keyWord);
		while(ptr != -1)
		{
			++count;
			resultStr = resultStr+ptr+" ";
			ptr = s.indexOf(keyWord,ptr+1);
		}
		resultStr = count+":"+resultStr;
		
		return resultStr;
	}
	public static void main(String args[])
	{
		String s1 = "this is what i have done";
		String s2 = "What thing are you talking about!";
		String s3 = "I belive I can fly";
		Search try1;
		System.out.println(try1.KeyWordSearch(s1,"is"));
		System.out.println(try1.KeyWordSearch(s2,"ing"));
		System.out.println(try1.KeyWordSearch(s3,"are"));
	}
} 