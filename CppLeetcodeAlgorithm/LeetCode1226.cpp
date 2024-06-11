#include <bits/stdc++.h>
using namespace std;
// 限定就餐策略
// 资源分级算法（Hierarchical Resource Allocation Algorithm）
class DiningPhilosophers1 {
   public:
    DiningPhilosophers1() {}

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        int l = philosopher;
        int r = (philosopher + 1) % 5;
        if (philosopher % 2 == 0) {
            lock[r].lock();
            lock[l].lock();
            pickLeftFork();
            pickRightFork();
        } else {
            lock[l].lock();
            lock[r].lock();
            pickLeftFork();
            pickRightFork();
        }
        eat();
        putLeftFork();
        putRightFork();
        lock[l].unlock();
        lock[r].unlock();
    }

   private:
    std::mutex lock[5];
};
// 同时拿起左右叉子
class DiningPhilosophers2 {
   public:
    DiningPhilosophers2() {}

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        int l = philosopher;
        int r = (philosopher + 1) % 5;
        waiter.lock();
        lock[l].lock();
        lock[r].lock();
        pickLeftFork();
        pickRightFork();
        waiter.unlock();
        eat();
        putLeftFork();
        putRightFork();
        lock[l].unlock();
        lock[r].unlock();
    }

   private:
    std::mutex lock[5];
    std::mutex waiter;
};

// 限定哲学家就餐数量
class Semaphore {
   public:
    Semaphore(int count = 0) : count_(count) {}
    void Set(int count) { count_ = count; }
    void Signal() {
        std::unique_lock<std::mutex> lock(mutex_);
        ++count_;
        cv_.notify_one();
    }
    void Wait() {
        std::unique_lock<std::mutex> lock(mutex_);
        while (count_ <= 0) {
            cv_.wait(lock);
        }
        --count_;
    }

   private:
    std::mutex mutex_;
    std::condition_variable cv_;
    int count_;
};
class DiningPhilosophers3 {
   public:
    DiningPhilosophers3() { guid.Set(4); }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        int l = philosopher;
        int r = (philosopher + 1) % 5;
        guid.Wait();
        lock[l].lock();
        lock[r].lock();
        pickLeftFork();
        pickRightFork();
        eat();
        putRightFork();
        putLeftFork();
        lock[r].unlock();
        lock[l].unlock();
        guid.Signal();
    }

   private:
    std::mutex lock[5];
    Semaphore guid;
};

class DiningPhilosophers4 {
   public:
    DiningPhilosophers4() {}

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        int left = philosopher;
        int right = (philosopher + 1) % 5;
        lock[left].lock();
        pickLeftFork();
        if (lock[right].try_lock()) {
            pickRightFork();
            eat();
            lock[right].unlock();
            putRightFork();
        }
        lock[left].unlock();
        putLeftFork();
    }

   private:
    std::mutex lock[5];
};