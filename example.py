string=input()
string=string.casefold()
vowels=""
if "a" in string:
    vowels=vowels+"a"
if "e" in string:
    vowels=vowels+"e"
if "i" in string:
    vowels=vowels+"i"
if "o" in string:
    vowels=vowels+"o"
if "u" in string:
    vowels=vowels+"u"

if(len(vowels)!=0):
    print(vowels)
else:
    print("none")