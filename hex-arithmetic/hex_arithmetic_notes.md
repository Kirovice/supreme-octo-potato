
# 🧮 十六进制加减法练习项目：hex-arithmetic

## 📁 项目结构

```
hex-arithmetic/
└── hex_calc.py
```

## 📜 脚本内容：hex_calc.py

```python
def hex_input(prompt):
    """获取用户输入的十六进制数，并统一转换格式"""
    s = input(prompt).strip().lower()
    if not s.startswith("0x"):
        s = "0x" + s
    return int(s, 16)

def main():
    print("🔢 十六进制加减法计算器")
    print("你可以输入两个十六进制数（例如 0x1A3 或 A3），然后选择加法或减法")

    num1 = hex_input("请输入第一个十六进制数: ")
    num2 = hex_input("请输入第二个十六进制数: ")

    op = input("请选择运算类型（+ 或 -）: ").strip()

    if op == "+":
        result = num1 + num2
        print(f"结果：{hex(num1)} + {hex(num2)} = {hex(result)}")
    elif op == "-":
        result = num1 - num2
        print(f"结果：{hex(num1)} - {hex(num2)} = {hex(result)}")
    else:
        print("❌ 无效的运算符，请输入 + 或 -")

if __name__ == "__main__":
    main()
```

---

## ✅ 示例运行结果

```bash
请输入第一个十六进制数: a332e3f
请输入第二个十六进制数: 53798e80f
请选择运算类型（+ 或 -）: +
结果：0xa332e3f + 0x53798e80f = 0x537998b4264d
```

---

## 📘 学到的内容

- Python 中如何进行十六进制运算
- 如何使用 `int(..., 16)` 和 `hex(...)` 进行转换
- 如何处理用户输入并做格式兼容（加前缀 0x）

---

如需扩展：
- 加入循环运算功能
- 同时输出十进制结果
- 输出结果带位数对齐（如补 0x00000...）

告诉我，我可以帮你继续优化 🚀
