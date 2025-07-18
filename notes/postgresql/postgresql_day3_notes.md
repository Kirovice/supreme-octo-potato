
# PostgreSQL 学习计划 Day 3：复杂查询（窗口函数）

---

## ✅ 今日目标

- 理解并使用窗口函数：`ROW_NUMBER()`、`RANK()`、`DENSE_RANK()`、`LAG()`、`LEAD()`
- 学会用 `PARTITION BY` 和 `ORDER BY` 控制分组与排序
- 实践分组编号、分组排名、上下行比较
- 认识窗口函数在数据分析中的实际用途

---

## 🧪 实操表结构

```sql
CREATE TABLE sales (
  id SERIAL PRIMARY KEY,
  employee TEXT NOT NULL,
  amount NUMERIC(10,2),
  sale_date DATE
);
```

---

## 🧪 插入测试数据

```sql
INSERT INTO sales (employee, amount, sale_date) VALUES
  ('Alice', 1000.00, '2024-01-01'),
  ('Bob', 2000.00, '2024-01-01'),
  ('Alice', 500.00, '2024-01-02'),
  ('Alice', 800.00, '2024-01-03'),
  ('Bob', 2000.00, '2024-01-02'),
  ('Bob', 2500.00, '2024-01-03'),
  ('Charlie', 700.00, '2024-01-01'),
  ('Charlie', 1000.00, '2024-01-02'),
  ('Charlie', 1200.00, '2024-01-03'),
  ('Alice', 800.00, '2024-01-04'),
  ('Alice', 800.00, '2024-01-05');
```

---

## 1️⃣ ROW_NUMBER(): 分组内唯一编号

```sql
SELECT
  employee,
  sale_date,
  amount,
  ROW_NUMBER() OVER (
    PARTITION BY employee
    ORDER BY sale_date
  ) AS sale_rank
FROM sales;
```

- 按员工分组
- 每组内部按日期排序
- 每行获得一个唯一递增编号

---

## 2️⃣ RANK() vs DENSE_RANK(): 分组排名

```sql
SELECT
  employee,
  amount,
  sale_date,
  RANK() OVER (
    PARTITION BY employee
    ORDER BY amount DESC
  ) AS rnk,
  DENSE_RANK() OVER (
    PARTITION BY employee
    ORDER BY amount DESC
  ) AS dense_rnk
FROM sales
WHERE employee = 'Alice';
```

- `RANK()`：跳名次（如 1,2,2,4）
- `DENSE_RANK()`：不跳名次（如 1,2,2,3）

---

## 3️⃣ LAG() 和 LEAD(): 上一行 / 下一行

```sql
SELECT
  employee,
  sale_date,
  amount,
  LAG(amount) OVER (
    PARTITION BY employee
    ORDER BY sale_date
  ) AS prev_amount,
  LEAD(amount) OVER (
    PARTITION BY employee
    ORDER BY sale_date
  ) AS next_amount
FROM sales
WHERE employee = 'Alice';
```

- `LAG()`：获取上一行的金额
- `LEAD()`：获取下一行的金额
- 可用于计算销售趋势、比较环比变化等

---

## 🧠 应用场景对比总结

| 函数         | 功能说明                   | 示例用途                     |
|--------------|----------------------------|------------------------------|
| ROW_NUMBER() | 分组内唯一递增编号         | 打标签、生成行号             |
| RANK()       | 分组内排序（有跳号）       | 成绩排名、销售额榜单         |
| DENSE_RANK() | 分组内排序（不跳号）       | 并列奖项、奖牌排名           |
| LAG()        | 获取前一行的某字段值       | 环比、增长率、变化检测       |
| LEAD()       | 获取后一行的某字段值       | 趋势预测、时间窗口分析       |

---

