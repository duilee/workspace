### _**NOTES**_

- for DFS, BFS need to define when to stop and what action to take before or at return. recursion stem and return step  
> the following function takes recursion step and append desired output before return.  

    def letterCombinations(self, digits: str) -> List[str]:
        letter_dict = {
            "2" : "abc",
            "3" : "def",
            "4" : "ghi",
            "5" : "jkl",
            "6" : "mno",
            "7" : "pqrs",
            "8" : "tuv",
            "9" : "wxyz"
        }
        
        comb_list = []
        
        def dfs(index, path):
            if len(path) == len(digits):
                comb_list.append(path)
                return 
            for j in letter_dict[digits[index]]:
                dfs(index + 1, path+j)
        
        if not digits:
            return []
        
        dfs(0, "")
        return comb_list
