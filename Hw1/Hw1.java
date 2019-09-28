import java.util.Scanner;
import java.util.Arrays;


public class Hw1 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println(""+args[0]);									
		String str = args[0];											//turn argument to string


		str = str.replaceAll("[^a-zA-Z]","");							//only letters can be left
		str = str.toLowerCase();										//transfer uppercase to lowercase
		
		int cnt=0;
		char[] array = str.toCharArray();								//transfer string to array
		int len = array.length;

		for( int i=0; i<array.length/2; i++,len-- ) {					//check whether front and back sides are same
			if( array[i] == array[len-1] )
				cnt++;	
			else
				break;
		}
		
		if( cnt == array.length/2 )
			System.out.println("this string is palindrome");
		else
			System.out.println("this string is not palindrome");	
	}
}
