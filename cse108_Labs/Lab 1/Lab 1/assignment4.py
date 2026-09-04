class Scheduals:
        def __init__(self, dep, num, nme, crd, dys, stt, ndt, avg):
            self.dep = dep;
            self.num = num;
            self.nme = nme;
            self.crd = crd;
            self.dys = dys;
            self.stt = stt;
            self.ndt = ndt;
            self.avg = avg;
        def format(self,num):
            return(
                 f"COURSE {num}:{self.dep}{self.num}: {self.nme} \n"
                 f"Number of Credits: {self.crd} \n"
                 f"Days of Lecture: {self.dys}\n"
                 f"Lecture Time: {self.stt} - {self.ndt}\n"
                f"Stat: on average, students get {self.avg}% in this course\n"
            )
        def compCon(lines, num):
            num = int(lines[0].strip())
            schedual = []
            for i in range(num):
                 sln = 1 + i*8
                 course = Scheduals(
                      lines[sln].strip(),
                      lines[sln+1].strip(),
                      lines[sln+2].strip(),
                      lines[sln+3].strip(),
                      lines[sln+4].strip(),
                      lines[sln+5].strip(),
                      lines[sln+6].strip(),
                      lines[sln+7].strip(),
                 )
                 schedual.append(course)
            for i, course in enumerate(schedual, start = 1):
                print(course.format(i))
            return
                       
print("Assignment-4: \n")
pFile = "classesInput.txt"

with open(pFile, "rt") as f:
    lines = f.readlines()
num = int(lines[0].strip())
schedual = Scheduals
schedual.compCon(lines, num)

print("[}----:End of Code:----{]")
