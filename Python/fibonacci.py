series_range = int(input('Uptill where you wanna print fibonacci series : '))
a = 0
b = 1
while a <= series_range:
    print(a)
    c = a
    a = b
    b = b+c