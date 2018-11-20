# This is a simple python script that converts a base 10 number to roman numerals

i = int(input("Enter and integer: "))

if i < 1 or i > 3999:
    print("Input must be between 1 and 3999")
else:
    romans = ""
    if i >= 1000:
        romans += (i // 1000) * 'M'
        while i >= 1000:
            i -= 1000
    if i >= 100:
        if i < 400:
            romans += (i // 100) * "C"
        elif 400 <= i < 500:
            romans += "CD"
        elif i == 500:
            romans += "D"
        elif 500 < i < 900:
            romans += "D" + ((i - 500)//100) * "C"
        else:
            romans += "CM"
        i -= 100 * (i // 100)
    if i >= 10:
        if i < 40:
            romans += (i // 10) * "X"
        elif 40 <= i < 50:
            romans += "XL"
        elif i == 50:
            romans += "L"
        elif 50 < i < 90:
            romans += "L" + ((i - 50)//10) * "X"
        else:
            romans += "XC"
        i -= 10 * (i // 10)
    if i >= 1:
        if i < 4:
            romans += (i // 1) * "I"
        elif 4 <= i < 5:
            romans += "IV"
        elif i == 5:
            romans += "V"
        elif 5 < i < 9:
            romans += "V" + (i - 5) * "I"
        else:
            romans += "IX"
    i -= 1 * (i // 1)
    print(romans)
