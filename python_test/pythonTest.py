class Solution():
    def SumofDivisionThree(self, ceil, divisor):
        totalSum=0
        for num in range(divisor, ceil, divisor):
            totalSum+=num
        return totalSum

    def GetMergeList(self, n):
        arrs=[[]]
        #iterate n times:
        #   for each iteration, append a new array through: copy previous array and insert current value
        for ind in range(1,n+1):
            preArr=arrs[ind-1].copy()
            preArr.append(ind)
            arrs.append(preArr)
        arrs.pop(0)
        return arrs




if __name__=="__main__":
    sol=Solution()
    #1
    ret=sol.SumofDivisionThree(102030,3)
    print(ret)
    #2
    ret=sol.GetMergeList(0)
    print(ret)
    ret=sol.GetMergeList(1)
    print(ret)
    ret=sol.GetMergeList(2)
    print(ret)
    ret=sol.GetMergeList(3)
    print(ret)
    #corner case: negative int
    ret=sol.GetMergeList(-7)
    print(ret)