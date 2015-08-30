import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        int n;
        BigInteger a,b;
        Scanner sc =  new Scanner(System.in);
        a=sc.nextBigInteger();
        b=sc.nextBigInteger();
        n=sc.nextInt();
        for(int i=2;i<n;i++) {
            BigInteger newI = b.pow(2).add(a);
            a=b;
            b=newI;
        }
        System.out.println(b.toString());
    }
}