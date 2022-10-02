values_store = {"A": 10, "B": 11, "C": 12, "D": 13, "E": 14, "F": 15}
hexadecimal = input(
    "Enter any Hexadecimal number that you wanna convert to Decimal: ")
hexa_list = list(hexadecimal)
n = len(hexa_list)-1
decimal = 0
for i in hexa_list:
    if i.isalpha():
        number = int(values_store[i])
    else:
        number = int(i)
    convert = number*16**n
    decimal = decimal+convert
    n = n-1
print("Decimal of ", hexadecimal, " is: ", decimal)