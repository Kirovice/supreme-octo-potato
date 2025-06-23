import threading
import time

# 定义一个线程要执行的任务
def worker(name, delay):
    for i in range(3):
        print(f"[{name}] 第 {i+1} 次工作中...")
        time.sleep(delay)
    print(f"[{name}] 完成任务！")

# 创建两个线程，每个线程执行 worker 函数
t1 = threading.Thread(target=worker, args=("线程A", 1))
t2 = threading.Thread(target=worker, args=("线程B", 0.5))

print("主线程：开始两个子线程")
t1.start()
t2.start()

# 等待两个线程执行完毕
t1.join()
t2.join()

print("主线程：所有子线程执行完毕")
