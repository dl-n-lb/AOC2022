
def getIn():
    f = open("../in.txt", "r")
    return f

def getValue(a):
    if a == a.upper():
        return (ord(a) - ord('A') + 27)
    else:
        return (ord(a) - ord('a') + 1) 

def main():
    score = 0
    lines = [x.strip("\n") for x in getIn().readlines()]
    for i in range(0, len(lines), 3):
        line1 = set([x for x in lines[i]])
        line2 = set([x for x in lines[i + 1]])
        line3 = set([x for x in lines[i + 2]])
        c = ''.join(line1.intersection(line2.intersection(line3)))
        score += getValue(c)
        print(c, getValue(c))
         
    print(score)

if __name__ == "__main__":
    main()
