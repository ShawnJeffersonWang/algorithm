import java.util.Scanner;

public class Main {
    static int n, m; // 关卡数量、英桀数量
    static int[] c; // 每个英桀的额外奖励
    static int[][] rewards; // 每个关卡的三个奖励的能力值
    static int[][] sources; // 每个关卡的三个奖励对应的英桀来源
    static int[] chosen; // 记录每个英桀被选择的次数
    static int maxResult = 0; // 记录最大的能力值

    // 回溯法函数，用于探索所有可能的奖励选择路径
    public static void dfs(int level, int currentSum) {
        if (level == n) {
            // 已经完成了所有关卡，计算最终的能力值
            int extraBonus = 0;
            for (int i = 0; i < m; i++) {
                if (chosen[i] >= 3) {
                    extraBonus += c[i]; // 加上额外奖励
                }
            }
            maxResult = Math.max(maxResult, currentSum + extraBonus); // 更新最大值
            return;
        }

        // 尝试选择每个关卡的三个奖励之一
        for (int i = 0; i < 3; i++) {
            int rewardValue = rewards[level][i];
            int rewardSource = sources[level][i] - 1; // 英桀编号从 1 开始，转换为 0 开始
            chosen[rewardSource]++;
            dfs(level + 1, currentSum + rewardValue); // 继续处理下一个关卡
            chosen[rewardSource]--; // 回溯撤销选择
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        // 输入关卡数量和英桀数量
        n = in.nextInt();
        m = in.nextInt();

        // 输入每位英桀的额外奖励
        c = new int[m];
        for (int i = 0; i < m; i++) {
            c[i] = in.nextInt();
        }

        // 初始化关卡的奖励和来源
        rewards = new int[n][3];
        sources = new int[n][3];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                rewards[i][j] = in.nextInt(); // 奖励的能力值
            }
            for (int j = 0; j < 3; j++) {
                sources[i][j] = in.nextInt(); // 奖励的来源英桀
            }
        }

        // 初始化被选择次数的数组
        chosen = new int[m];

        // 使用回溯算法搜索所有可能的选择组合
        dfs(0, 0);

        // 输出最大结果
        System.out.println(maxResult);

        in.close();
    }
}