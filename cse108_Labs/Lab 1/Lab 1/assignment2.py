
def autoPun():
    frase = str(input("Enter the punishment frase: "))
    reps = int(input("Please enter the amount of reps: "))
    
    with open("CompletedPunishment.txt", "wt") as f: 
        for i in range(reps):
            if (i == reps - 1):
                f.write(frase)
            elif (i < reps):
                f.write(frase + "\n")



print("Assignment-2: \n");
autoPun();
print("[}----:End of Code:----{]")
