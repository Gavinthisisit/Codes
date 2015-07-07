

public class StringUse
{
	private String buff;
	public StringUse()
	{
		
	}
	public String KeyWordSearch(String s,String keyWord){
		StringBuffer resultStr = new StringBuffer();		//使用StringBuffer
		int count = 0;
		int ptr = s.indexOf(keyWord);
		while(ptr != -1)
		{
			++count;
			resultStr.append(ptr+" ");						//append拼接方法
			ptr = s.indexOf(keyWord,ptr+1);
		}
		resultStr.insert(0,count+":");						//插入方法
		
		return resultStr.toString();						//toString方法
	}
	public static void main(String args[])
	{
		String s1 = "this is what i have done";
		String s2 = "What thing are you talking about!";
		String s3 = "I belive I can fly";
		String s = "abcdefghijklmnopqrstuvwxyz";
		Search try1 = new StringUse();
		System.out.println(try1.KeyWordSearch(s1,"is"));
		System.out.println(try1.KeyWordSearch(s2,"ing"));
		System.out.println(try1.KeyWordSearch(s3,"are"));
		System.out.println(s.substring(20,s.length()));
		System.out.println(s.substring(s.indexOf('s')));
	}
} 