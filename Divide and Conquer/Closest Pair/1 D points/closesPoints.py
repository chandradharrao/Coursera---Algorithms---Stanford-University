#input an array of n points
def euclidDist(x,y):
    return (y**2 - x**2)**0.5

def main():
    print("\nEnter the 1D points\n")
    arr = [int(i) for i in input().split(" ")]
    print(arr)
    
    #sort the array -O(nlogn)
    arr.sort()
    #check for lowest adj pairs
    minPairDist = euclidDist(arr[0],arr[1])
    minPair = {"x1":arr[0],"x2":arr[1]}
    for i in range(1,len(arr)-1):
        currPairDist = euclidDist(arr[i],arr[i+1])
        if ( currPairDist < minPairDist):
            minPairDist = currPairDist
            minPair["x1"] = arr[i]
            minPair["x2"] = arr[i+1]
    print("\nThe minimum pair are {x1} and {x2}\n".format(x1 = minPair["x1"],x2 = minPair["x2"]))

if (__name__ == "__main__"):
    main()


