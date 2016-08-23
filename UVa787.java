import java.util.Scanner;
import java.math.BigInteger;



public class UVa787
{
	public static void main(String [] args)
	{
		Scanner sc = new Scanner(System.in);
		
		int [] arr = new int[105];
		int val;
		BigInteger max;
		BigInteger aux;
		
		while (sc.hasNext())
		{
			val = sc.nextInt();
			int idx = 0;
			while (val != -999999)
			{
				arr[idx] = val;
				++idx;
				val = sc.nextInt();
			}
			max = BigInteger.valueOf(arr[0]);
			for (int i = 0 ; i < idx; ++i)
			{
				aux = BigInteger.valueOf(1);
				for (int j = i; j < idx; ++j)
				{
					aux = aux.multiply(BigInteger.valueOf(arr[j]));
					
					if (max.compareTo(aux) == -1)
						max = aux;
				}
			}
			
			System.out.println(max);
			
		}
	}
}
