

import json        
print("Assignment-5: \n")
file = "grades.txt"
students = {}

with open(file, "rt") as file:
    students = json.load(file)

while True:
    print("|[Student Grade Management]|\n")
    print("Input Keys: n | new, s | save, c | change grades \n")
    print("Input Keys: d | delete, p | print grades, e | exit\n")
    uInput = input("Choose an option: ")
    
    if uInput == "e":
        dec = input("WARNING: Unsaved data will be erased, continue? y/n: ")
        if dec == "y":
            print("[}----:End of Code:----{]")
            break;
        else:
            print("Program not exited")
    elif uInput == "p":
        s_name = input("Enter the Student's full name:")
        grade = students.get(s_name)
        if grade:
            print(f"{s_name}: {grade}")
        else:
            print(f"{s_name} not found \n")
    elif uInput == "n":
        name = input("Enter the Student's full name: ")
        grade = input("Enter the Student's grade: ")
        students[name] = grade
        print(f"New Student added, {name} : {grade}")
    elif uInput == "c":
        c_name = input("Enter the Student's full name: ")
        if(students.get(c_name)):
            grade = input("Enter the Student's new grade: ")
            students[c_name] = grade
        else:
            print(f"{c_name} not found \n")
    elif uInput == "d":
        d_name = input("Enter the Student's full name: ")
        if(students.get(d_name)):
            students.pop(d_name)
            print(f"{d_name} deleted from database \n")
        else:
            print(f"{d_name} not found \n")
    elif uInput == "s":
        with open("grades.txt", "w") as f:
            json.dump(students, f)  
        print("Data is saved. \n")
    elif uInput != ("e" or "n" or "s" or "d" or "p" or "c"):
            print("Invalid Input, please try again \n")
    

    
