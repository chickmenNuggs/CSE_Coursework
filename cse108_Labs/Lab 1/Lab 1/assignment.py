
#[}--------------------{[Assignment 1 Code]}-------------------{}]

def calcSum():
    uInput = input("Please enter two or more numbers: ")
    nums = uInput.split()
    if len(nums)< 2:
        print("ERROR: Please enter two or more integers \n")
        exit();
    
    sum = 0.0
    for i in nums:
        try:
             sum += float(i)
        except: 
            print("ERROR: Input must an int or a float. \n")
            exit();    
    print(f"{sum}")


#[}-------------------{[Driver Code]}-------------------{}]

print("Assignment-1: ")
calcSum()
print("[}----:End of Code:----{]")
