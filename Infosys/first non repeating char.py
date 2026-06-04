def Uniqchar(s: str) ->int:
    frequency_map = {}

    #First pass: build the frequency map
    for char in s:
        frequency_map[char] = frequency_map.get(char , 0) +1

    #Second pass find the char and increase the count with 1
    for index in range(len(s)):
        if frequency_map[s[index]] == 1:
            #Adjusinting 0 based index to 1-based index
            return index + 1
    return -1

#Test case
print(Uniqchar("statistics"))

print(Uniqchar("KAKAROTO"))


