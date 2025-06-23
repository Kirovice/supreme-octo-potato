
# 🧵 Python 并发练习：多线程与多进程

本练习包含两个部分：

---

## 一、multi_thread_demo.py - 基础多线程演示

### 📄 源码

```python
import threading
import time

def worker(name):
    print(f"[线程{name}] 开始工作中...")
    for i in range(3):
        print(f"[线程{name}] 第 {i+1} 次工作中...")
        time.sleep(1)
    print(f"[线程{name}] 完成任务！")

print("主线程：开始两个子线程")
t1 = threading.Thread(target=worker, args=("A",))
t2 = threading.Thread(target=worker, args=("B",))
t1.start()
t2.start()
t1.join()
t2.join()
print("主线程：所有子线程执行完毕")
```

---

## 二、compare_thread_process.py - 多线程 vs 多进程性能比较

### 📄 源码

```python
import threading
import multiprocessing
import time

def count(n):
    while n > 0:
        n -= 1

COUNT = 50_000_000

def run_threads():
    t1 = threading.Thread(target=count, args=(COUNT,))
    t2 = threading.Thread(target=count, args=(COUNT,))
    start = time.time()
    t1.start()
    t2.start()
    t1.join()
    t2.join()
    print(f"线程耗时: {time.time() - start:.2f} 秒")

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
```

### ✅ 实验总结

- 多线程在 CPU 密集型任务中不具备并行优势（GIL 限制）；
- 多进程可实现真正并行运行，通常更快；
- Python 适合用线程处理 IO 密集型任务，用进程处理 CPU 密集型任务。

