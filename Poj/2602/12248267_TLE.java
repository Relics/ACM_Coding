import java.util.*;
import java.math.*;

public class Main{
	static int a[]=new int[1000010];
	static int b[]=new int[1000010];
	public static void main(String [] args){
		Scanner scan=new Scanner(System.in);
		int len=scan.nextInt();
		for(int i=1;i<=len;++i)
		{
			a[i]=scan.nextInt();
			b[i]=scan.nextInt();
		}
		BigInteger c=BigInteger.ZERO,d=BigInteger.ZERO;
		for(int i=1;i<=len;++i){
			c=c.multiply(BigInteger.TEN);
			c=c.add(BigInteger.valueOf(a[i]));
			d=d.multiply(BigInteger.TEN);
			d=d.add(BigInteger.valueOf(b[i]));
		}
		c=c.add(d);
		String s=c.toString();
		int chazhi=len-s.length();
		for(int i=1;i<=chazhi;++i)
			System.out.print("0");
		System.out.println(s);
	}
}
	