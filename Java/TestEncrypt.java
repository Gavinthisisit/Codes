public class TestEncrypt{
	public static void main(String args[]){
		Caesar caesar = new Caesar();
		String plain = "this is the secret message";
		String secret = caesar.encrypt(plain);
		
		System.out.println("*************Caesar Cipher Encryption*******");
		System.out.println("PlainText: "+plain);
		System.out.println("Encrypted: "+secret);
		System.out.println("Decrypted: "+caesar.decrypt(secret));
		
		Transpose transpose = new Transpose();
		secret = transpose.encrypt(plain);
		System.out.println("\n   **************  Transpose Cipher Encryption ************");
		System.out.println("PlainText: "+plain);
		System.out.println("Encrypted: "+secret);
		System.out.println("Decrypted: "+transpose.decrypt(secret));
		System.out.println("PlainText : "+secret);
	}
}