import collections

class Solution():
    def SumFibonacciEvenVals(self,totalCnt):
        first=1
        second=1
        cur=2
        count=0
        totalSum=0
        while(count<totalCnt):
            #do Fibonacci until count==100
            cur= first+second
            first=second
            second=cur
            if cur%2==0:
                count+=1
                totalSum+=cur
        return totalSum


    #two solutions, one is using counter 
    def FindMatch(self, arr1,arr2):
        counter =collections.Counter(arr1)
        counter&=collections.Counter(arr2)
        return list(counter)

    
    def FindMatch2(self, arr1,arr2):
        #iterate 2 arrays at the same time:
        #for each iteration:
        #   if p1.val==p2.val: find it
        #   if p1.val<p2.val: p1++ 
        #   if p1.val>p2.val: p2++ 
        ind1,ind2 = 0,0
        seen=set()
        while(ind1<len(arr1) and ind2<len(arr2)):
            if arr1[ind1]==arr2[ind2]:
                seen.add(arr1[ind1])
                ind1+=1
                ind2+=1
            elif arr1[ind1]<arr2[ind2]:
                ind1+=1
            else: 
                ind2+=1
        return list(seen)


    #solution1, using num%2 == 0 to decide has odd digits or not
    def NoOddDigits(self, num):
        
        hasNoOddDigit=True
        strNum=str(num)
        for digit in strNum:
            if int(digit)%2==1:
                hasNoOddDigit=False
                break
        return hasNoOddDigit    

    #solution2, using dict to find odd digits
    def NoOddDigits2(self, num):
        
        oddTable ={
            '1':'1',
            '3':'3',
            '5':'5',
            '7':'7',
            '9':'9'
        }
        hasNoOddDigit=True
        strNum=str(num)
        for digit in strNum:
            if oddTable.get(digit)!=None:
                hasNoOddDigit=False
                break
        return hasNoOddDigit  


    def GetCalculatedNum(self, num):
        if num!=0:
            #1+11+111+1111==1234
            return 1234*num
        else:
            return 0



if __name__=="__main__":
    solution=Solution()
    #1
    ret=solution.SumFibonacciEvenVals(100)
    print(ret)
    #2
    #corner case: repeated array
    arr1=[1,1,2,2,2,3,3,3,5,5,9]
    arr2=[2,2,2,3,3,3,4,5,6]
    ret=solution.FindMatch(arr1,arr2)
    print(ret)
    ret=solution.FindMatch2(arr1,arr2)
    print(ret)
    #3
    #assuming input is only positive integers 
    ret=solution.NoOddDigits(260)
    print(ret)
    ret=solution.NoOddDigits(5566)
    print(ret)
    #4
    ret=solution.GetCalculatedNum(1)
    print(ret)