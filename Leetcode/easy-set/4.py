def checkIfPangram(str1):
    abc = set('qwertyuiopasdfghjklzxcvbnm')
    strlower = str1.lower()
    str2 = set(strlower)
    return abc.issubset(str2)
