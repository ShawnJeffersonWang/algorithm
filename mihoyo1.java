import java.util.Scanner;

public class Main {
    // 计算一个数字中4和6的数量
    public static int countFourAndSix(int num) {
        int count = 0;
        while (num > 0) {
            int digit = num % 10;
            if (digit == 4 || digit == 6) {
                count++;
            }
            num /= 10;
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        // 读取输入
        int n = in.nextInt();
        int m = in.nextInt();

        // 记录最大4和6的数量以及对应的数字
        int maxCount = -1;
        int result = n;

        // 遍历n到m范围内的所有数字
        for (int i = n; i <= m; i++) {
            int count = countFourAndSix(i);

            // 如果找到更多的4和6的数量，或者相同数量时取较大的数字
            if (count > maxCount || (count == maxCount && i > result)) {
                maxCount = count;
                result = i;
            }
        }

        // 输出结果
        System.out.println(result);
    }
}