def decimal_to_hex():
    dec = int(input("输入十进制数: "))
    print(f"十六进制为: {hex(dec)}")

def hex_to_decimal():
    hex_str = input("输入十六进制数（例如 0x1A3 或 1A3）: ")
    if not hex_str.startswith("0x"):
        hex_str = "0x" + hex_str
    print(f"十进制为: {int(hex_str, 16)}")

def binary_to_hex():
    bin_str = input("输入二进制数（例如 0b1010 或 1010）: ")
    if not bin_str.startswith("0b"):
        bin_str = "0b" + bin_str
    dec = int(bin_str, 2)
    print(f"十六进制为: {hex(dec)}")

def hex_to_binary():
    hex_str = input("输入十六进制数（例如 0x1A3 或 1A3）: ")
    if not hex_str.startswith("0x"):
        hex_str = "0x" + hex_str
    dec = int(hex_str, 16)
    print(f"二进制为: {bin(dec)}")

def main():
    print("请选择要进行的转换：")
    print("1. 十进制 → 十六进制")
    print("2. 十六进制 → 十进制")
    print("3. 二进制 → 十六进制")
    print("4. 十六进制 → 二进制")

    choice = input("输入数字 1-4: ")

    if choice == "1":
        decimal_to_hex()
    elif choice == "2":
        hex_to_decimal()
    elif choice == "3":
        binary_to_hex()
    elif choice == "4":
        hex_to_binary()
    else:
        print("无效选择，请输入 1~4 之间的数字。")

if __name__ == "__main__":
    main()
