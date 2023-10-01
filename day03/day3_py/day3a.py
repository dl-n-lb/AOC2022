
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
    for line in getIn().readlines():
        line = line.strip("\n")
        h = len(line) // 2
        lh = set([x for x in line[:h]])
        rh = set([x for x in line[h:]])
        c = ''.join(lh.intersection(rh))
        score += getValue(c)
        print(c, getValue(c))
         
    print(score)

if __name__ == "__main__":
    main()
