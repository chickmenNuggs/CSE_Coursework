
def wordCount(file):
    found = 0
    target=str(input("Please enter a word."))
    with open (file) as f:
        for line in f:
            words = line.split()
            for word in words:
                wLen = len(word)
                lChar = word[wLen-1];
                if(lChar.isalpha() == False):
                    word = word[0:wLen-1]
                if (target.upper() in word.upper()):
                    found = found + 1
    print(f"The word {target} occurs {found} times.\n")
    return


print("Assignment-3: ");
pFile = "PythonSummary.txt"
wordCount(pFile);

print("[}----:End of Code:----{]")
