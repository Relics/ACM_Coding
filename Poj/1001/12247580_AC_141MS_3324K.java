
import java.util.*;
import java.math.*;

public class Main{
	public static void main(String [] args){
		Scanner scan=new Scanner(System.in);
		while(scan.hasNext())
		{
			BigDecimal a;
			a=scan.nextBigDecimal();
			int n;
			n=scan.nextInt();
			a=a.pow(n);
			a=a.stripTrailingZeros();
			String str=a.toPlainString();
			if(str.startsWith("0."))
				str=str.substring(1);
			System.out.println(str);
		}
	}
}
	