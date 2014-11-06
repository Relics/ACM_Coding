import java.math.*;
import java.util.*;

public class contest {
	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		while(input.hasNext())
		{
			int n;
			n=input.nextInt();
			BigDecimal a=input.nextBigDecimal();
			a=a.pow(n);
			a=a.stripTrailingZeros();
			String str=a.toPlainString();
			if(str.startsWith("0."))
			{
				str=str.substring(1);
			}
			System.out.println(str);
		}
	}

}
