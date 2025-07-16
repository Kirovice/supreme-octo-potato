
# PostgreSQL 学习计划 Day 1：环境确认与基础操作

---

## ✅ 今日目标

- 安装并确认 PostgreSQL 服务
- 使用 `psql` 创建数据库与表
- 完成基本的增删改查操作
- 查找 PostgreSQL 的实际物理数据存储路径
- 了解与《深入理解计算机系统》相关的系统底层关联点

---

## 🧪 实操步骤

### 1. 登录 PostgreSQL

```bash
sudo -i -u postgres
psql
```

### 2. 创建数据库并连接

```sql
CREATE DATABASE testdb;
\c testdb
```

### 3. 创建表并插入数据

```sql
CREATE TABLE users (
  id SERIAL PRIMARY KEY,
  name TEXT NOT NULL,
  email TEXT UNIQUE
);

| 字段名 | 数据类型 | 约束条件         | 作用说明                     |
|--------|----------|------------------|------------------------------|
| `id`   | SERIAL   | PRIMARY KEY      | 自增主键，唯一标识一行数据   |
| `name` | TEXT     | NOT NULL         | 用户名，不能为空             |
| `email`| TEXT     | UNIQUE           | 邮箱，必须唯一               |

INSERT INTO users (name, email) VALUES ('Kirovice', 'kirovice@gmail.com');
SELECT * FROM users;
```

### 4. 更新与删除

```sql
UPDATE users SET email = 'kirovice@example.com' WHERE name = 'Kirovice';
DELETE FROM users WHERE name = 'Kirovice';
SELECT * FROM users;
```

### 5. 查看数据目录（退出 psql 后）

```bash
exit
sudo find /var/lib/postgresql -name base
ls -l /var/lib/postgresql/16/main/base
```

---

## 🧠 与计算机系统基础关联

| PostgreSQL 概念         | 对应系统基础内容                           |
|------------------------|--------------------------------------------|
| 数据库 = 目录          | Unix 文件系统结构                          |
| 表 = 数据文件（heap）  | 磁盘块、页缓存、文件系统页结构             |
| INSERT/UPDATE/DELETE   | 文件写入、页缓冲写入、后台 I/O 操作       |
| SQL 命令/CLI 工具使用   | Shell 命令执行过程，涉及系统调用（execve） |
| 用户权限               | Linux 用户系统、进程权限                   |

---

## 📌 小结

Day 1 完成 PostgreSQL 基础环境搭建与数据操作，对数据库物理存储机制有了初步了解，为后续深入事务管理与查询优化打下基础。

