'''
Write a Python program to store 10th class percentage of students in an array. Write
function for sorting array of floating point numbers in ascending order using radix sort and
display top five scores
Stud_Marks(name, total_marks) Result(Roll,Name, Class)
'''
def RadixSort(arr):
    MaxElement = max(arr)
    place = 1
    while MaxElement//place > 0:
        countingSort(arr,place)
        place = place * 10

def countingSort(arr,place):
    n = len(arr)
    result = [0]*n
    count = [0] *10
    #calculating the count of elements based on digits place
    i = 0
    for i in range(n):
        index = int(arr[i]) // place
        count[index % 10] += 1
        
    for i in range(1, 10):
        count[i] = count[i]+count[i - 1]
    #placing the elements in sorted order
    i = n - 1
    while i >= 0:
        index = int(arr[i]) // place
        result[count[index % 10] - 1] = arr[i]
        count[index % 10] -= 1
        i = i-1
    #placing back the sorted elements in original
    for i in range(0, n):
        array[i] = result[i]
#Driver Code
print("\nHow many students are there?")
n = int(input())
array = []
i=0
for i in range(n):
    print("\n Enter percentage marks")
    item = float(input())
    array.append(item)

print("You have entered following scores...\n")
print(array)

RadixSort(array)
print("\n The sorted Scores are...")
print(array)

print("Top Five Scores are...")
for i in range (len(array)-1,1,-1):
    print(array[i])
