
# PostgreSQL 学习计划 Day 2：数据类型与约束机制

---

## ✅ 今日目标

- 掌握 PostgreSQL 支持的多种数据类型
- 理解约束条件（`NOT NULL`、`UNIQUE`、`CHECK`、`DEFAULT`）
- 实战操作：创建表 + 插入 + 查询
- 了解数组类型、JSONB、UUID 的实际用法
- 识别与系统底层（内存、对齐、结构体、存储）相关联的点

---

## 🧪 实操步骤

### 1. 登录数据库并切换到 `testdb`

```bash
sudo -i -u postgres
psql
\c testdb
```

---

### 2. 创建数据类型练习表

```sql
CREATE TABLE datatype_demo (
  id SERIAL PRIMARY KEY,
  name TEXT NOT NULL,
  age INTEGER CHECK (age >= 0),
  is_active BOOLEAN DEFAULT true,
  created_at TIMESTAMP DEFAULT now(),
  rating NUMERIC(3,1),
  tags TEXT[],
  profile JSONB,
  uuid_code UUID DEFAULT gen_random_uuid()
);
```

---

### 3. 插入测试数据

```sql
INSERT INTO datatype_demo (
  name, age, is_active, rating, tags, profile
) VALUES (
  '董翔宇', 27, true, 4.8,
  ARRAY['aws', 'postgresql', 'linux'],
  '{"job": "infra engineer", "location": "Tokyo"}'
);
```

---

### 4. 查询数据内容

```sql
SELECT * FROM datatype_demo;
```

---

### 5. JSONB 查询

```sql
SELECT profile->>'job' AS job_title FROM datatype_demo;
```

---

### 6. 数组包含值的查询

```sql
SELECT * FROM datatype_demo
WHERE 'postgresql' = ANY(tags);
```

---

## 🔍 字段说明总结

| 字段名      | 类型         | 特性与说明 |
|-------------|--------------|------------|
| id          | SERIAL       | 自增主键，自动创建序列 |
| name        | TEXT         | 非空字符串 |
| age         | INTEGER      | 带 CHECK 约束（不能为负） |
| is_active   | BOOLEAN      | 逻辑状态位，默认 true |
| created_at  | TIMESTAMP    | 自动记录当前时间 |
| rating      | NUMERIC(3,1) | 精确小数，3位数中保留1位小数 |
| tags        | TEXT[]       | 字符串数组，可通过 ANY 查询 |
| profile     | JSONB        | 二进制 JSON，可提取字段 |
| uuid_code   | UUID         | 自动生成唯一标识码 |

---

## 🧠 与系统基础知识关联

| PostgreSQL 概念 | 对应系统知识 |
|----------------|--------------|
| TEXT / INTEGER 类型 | C语言中 char* / int 的存储与对齐 |
| NULL 与 NOT NULL | 表示是否存在有效值，底层对应掩码位 |
| NUMERIC 精度控制 | 精确小数的存储方式避免浮点误差 |
| JSONB 与结构体 | 类似于 C 语言中的嵌套结构体与键值映射 |
| ARRAY 数组 | 类似于动态数组，支持遍历匹配 |
| UUID | 16字节唯一标识，适用于分布式系统 |
| DEFAULT now() | 当前时间由系统时间函数提供，与系统调用有关 |

---

## ✅ 小结

今天你掌握了 PostgreSQL 的类型系统与约束机制，并实际操作了复杂字段（JSONB、数组、UUID）。这些特性正是 PostgreSQL 相较于传统关系型数据库的一大优势。

