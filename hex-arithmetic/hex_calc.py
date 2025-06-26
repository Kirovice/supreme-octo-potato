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
        print("无效的运算符，请输入 + 或 -")

if __name__ == "__main__":
    main()
