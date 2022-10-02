word = input("Enter any word: ").lower()
a = word
opposite = word[::-1]
if a == opposite:
    print(word+" is PALINDROME")
else:
    print(word+" is not PALINDROME")