class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        dic = ["IV","IX","XL","XC","CD","CM"]
        symbol = ['I','V','X','L','C','D','M']
        result = 0
        for i in range(0, len(s)):
            pos = symbol.index(s[i])
            if pos % 2 == 1:
                result+=int(5*pow(10,int(pos/2)))
                print(result)
            else:
                result+=int(1*pow(10,int(pos/2)))
                print(result)
        for j in range(0, len(dic)):
            if s.find(dic[j])!=-1:
                print("below ",j)
                result-=int(2*pow(10,int(j/2)))
        return result
