import threading
import multiprocessing
import time

def count(n):
    while n > 0:
        n -= 1

COUNT = 50_000_000  # 根据你电脑性能可调节大小

# 使用线程
def run_threads():
    t1 = threading.Thread(target=count, args=(COUNT,))
    t2 = threading.Thread(target=count, args=(COUNT,))
    start = time.time()
    t1.start()
    t2.start()
    t1.join()
    t2.join()
    print(f"线程耗时: {time.time() - start:.2f} 秒")

# 使用进程
def run_processes():
    p1 = multiprocessing.Process(target=count, args=(COUNT,))
    p2 = multiprocessing.Process(target=count, args=(COUNT,))
    start = time.time()
    p1.start()
    p2.start()
    p1.join()
    p2.join()
    print(f"进程耗时: {time.time() - start:.2f} 秒")

if __name__ == "__main__":
    print("=== 测试线程 ===")
    run_threads()
    print("=== 测试进程 ===")
    run_processes()
