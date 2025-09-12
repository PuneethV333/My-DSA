def firstUniqChar(str1):
    
    for idx,ch in enumerate(str1):
        if(str1.count(ch) == 1):
            return idx
    return -1


res = firstUniqChar("aabb")
print(res)
