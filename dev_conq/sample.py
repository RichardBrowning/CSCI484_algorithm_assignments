def findPeak(A, low, high):
	if low == high: 
		return low, A[low]
	
	mid = (low + high) // 2
	
	if A[mid] < A[mid+1]:
		return findPeak(A, mid+1, high)
	else:
		return findPeak(A, low, mid)

# Driver code
A = [1, 3, 7, 9, 8, 6, 3, 1] 

low = 0
high = len(A) - 1

peakIndex, peakValue = findPeak(A, low, high)

print(peakIndex, peakValue)