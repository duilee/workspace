class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        stylist = [word for word in re.sub(r'[^\w]', ' ', paragraph).lower().split() if word not in banned]
        counts_dict = collections.Counter(stylist)

        return counts_dict.most_common()[0][0]