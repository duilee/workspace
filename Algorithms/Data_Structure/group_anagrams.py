def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
    anagrams = {}
    for word in strs:
        sorted_word = ''.join([str(char) for char in sorted(word)])
        if sorted_word in anagrams.keys():
            anagrams[sorted_word] = anagrams[sorted_word].append(word)
        else:
            anagrams[sorted_word] = [word]

    return anagrams.values()

"""
def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
    anagrams = collections.defaultdict(list)
    
    for word in strs:
        anagarms[''.join(sorted(word))].append(word)
    return anagarms.values()
"""