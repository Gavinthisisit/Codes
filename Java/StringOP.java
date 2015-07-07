//StringOP.java

import java.util.*;
public class StringOP{
	public Vector getInput(String sArg,char cSep){
		Character chTmp = new Character(cSep);
		String sSep = chTmp.toString();
		int iIndex = -1;
		int iRet = 0;
		Vector vec = new Vector();
		while(true){
			iRet = sArg.indexOf(sSep,iIndex+1);
			if(iRet != -1){
				vec.addElement(sArg.substring(iIndex+1,iRet));
				iIndex = iRet;
			}
			else{
				vec.addElement(sArg.substring(iIndex+1));
				break;
			}
		}
		return vec;
	}
	public static void main(String args[]){
		StringOP obj = new StringOP();
		Vector v = obj.getInput("hello:this:is:what:I:can:say!",':');
		int iSize = v.size();
		for(int i=0;i<iSize;i++)
			System.out.println(v.elementAt(i));
	}
}