import java.util.*;

public class Main {
    static int n, m;
    static char[][] map;
    static int[][] landId;
    static int[] landSize;
    static int currentLandId = 0;
    static final int[] dx = {-1, 1, 0, 0};
    static final int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        m = in.nextInt();
        map = new char[n][m];
        landId = new int[n][m];
        for (int i = 0; i < n; i++) {
            map[i] = in.next().toCharArray();
        }

        // 记录陆地连通块
        landSize = new int[n * m + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == '#' && landId[i][j] == 0) {
                    currentLandId++;
                    landSize[currentLandId] = dfs(i, j, currentLandId);
                }
            }
        }

        // 计算初始最大陆地连通块大小
        int maxLandSize = 0;
        for (int i = 1; i <= currentLandId; i++) {
            maxLandSize = Math.max(maxLandSize, landSize[i]);
        }

        // 记录大海连通块
        boolean[][] visited = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == '.' && !visited[i][j]) {
                    int newLandSize = igniteSeaBlock(i, j, visited);
                    maxLandSize = Math.max(maxLandSize, newLandSize);
                }
            }
        }

        System.out.println(maxLandSize);
    }

    // 点燃一个海洋连通块并计算点燃后最大的陆地连通块大小
    private static int igniteSeaBlock(int x, int y, boolean[][] visited) {
        List<int[]> seaBlock = new ArrayList<>();
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{x, y});
        visited[x][y] = true;

        // 寻找整个海洋连通块
        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int cx = current[0], cy = current[1];
            seaBlock.add(current);
            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (isValid(nx, ny) && map[nx][ny] == '.' && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    queue.offer(new int[]{nx, ny});
                }
            }
        }

        // 统计与这个海洋连通块相邻的不同陆地连通块的大小
        Set<Integer> adjacentLands = new HashSet<>();
        int totalSize = seaBlock.size(); // 点燃海洋块后的最小陆地大小（海洋变为陆地）
        for (int[] seaCell : seaBlock) {
            int sx = seaCell[0], sy = seaCell[1];
            for (int i = 0; i < 4; i++) {
                int nx = sx + dx[i];
                int ny = sy + dy[i];
                if (isValid(nx, ny) && map[nx][ny] == '#') {
                    int landBlockId = landId[nx][ny];
                    if (!adjacentLands.contains(landBlockId)) {
                        totalSize += landSize[landBlockId];
                        adjacentLands.add(landBlockId);
                    }
                }
            }
        }

        return totalSize;
    }

    // 使用DFS计算陆地连通块的大小
    private static int dfs(int x, int y, int id) {
        Stack<int[]> stack = new Stack<>();
        stack.push(new int[]{x, y});
        landId[x][y] = id;
        int size = 0;
        while (!stack.isEmpty()) {
            int[] current = stack.pop();
            int cx = current[0], cy = current[1];
            size++;
            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if (isValid(nx, ny) && map[nx][ny] == '#' && landId[nx][ny] == 0) {
                    landId[nx][ny] = id;
                    stack.push(new int[]{nx, ny});
                }
            }
        }
        return size;
    }

    // 判断坐标是否合法
    private static boolean isValid(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
}