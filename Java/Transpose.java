public class Transpose extends Cipher{
	public String encode(String word){
		StringBuffer result = new StringBuffer(word);
		return result.reverse().toString();
	}
	
	public String decode(String word){
		return encode(word);
	}
}