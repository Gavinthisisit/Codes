public class Caesar extends Cipher{
	public String encode(String word){
		StringBuffer result =  new StringBuffer();
		
		for(int k=0;k<word.length();k++){
			char ch = word.charAt(k);
			ch = (char)('a'+(ch-'a'+ 3)%26);
			result.append(ch);
		}
		return result.toString();
	}
	public String decode(String word){
		StringBuffer result = new StringBuffer();
		for(int k=0;k<word.length();k++){
			char ch = word.charAt(k);
			ch = (char)('a'+(ch-'a'+23)%26);
			result.append(ch);
		}
		return result.toString();
	}
}

 