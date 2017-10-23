import math

def menu():
    print"Vector Calculation Menu"
    print"1. Add Vectors"
    print"2. Subtract Vectors"
    print"3. Option 3"
    print"4. Option 4"
    print"5. Exit"

def addVectors():
    print("Addition of two Vectors")
    #U Vector
    u1 = raw_input("Enter u1: ")
    while not u1.isdigit():
        u1 = raw_input("Float input only. Enter u1:");

    u2 = raw_input("Enter vu: ")
    while not u2.isdigit():
        u1 = raw_input("Float input only. Enter u1:");

    uVec = [u1, u2]

    #V Vector
    v1 = raw_input("Enter v1: ")
    while not v1.isdigit():
        v1 = raw_input("Float input only. Enter v1:");

    v2 = raw_input("Enter v2: ")
    while not v2.isdigit():
        v1 = raw_input("Float input only. Enter v1:");

    vVec = [v1, v2]

    print("u = <%s,%s>, v = <%s,%s>" % (uVec[0], uVec[1], vVec[0], vVec[1]))

    magn = math.sqrt(((float(uVec[1]) - float(uVec[0])))**2 + (float(vVec[1]) - float(vVec[0]))**2)
    print(magn)

    return


loop = True
while loop:
    menu()

    choice = "a"
    while (choice.isdigit()):
        choice = raw_input("Enter your choice[1-5]: ")

    if choice==1:
        addVectors()
        ## You can add your code or functions here
    elif choice==2:
        print "Menu 2 has been selected"
        ## You can add your code or functions here
    elif choice==3:
        print "Menu 3 has been selected"
        ## You can add your code or functions here
    elif choice==4:
        print "Menu 4 has been selected"
        ## You can add your code or functions here
    elif choice==5:
        print "Menu 5 has been selected"
        ## You can add your code or functions here
        loop=False # This will make the while loop to end as not value of loop is set to False
    else:
        # Any integer inputs other than values 1-5 we print an error message
        raw_input("Wrong option selection. Enter any key to try again..")


"""
vector1 = [v1, v2]
vector1 = [(v1 = raw_input("Enter v1: ")), (v2 = raw_input("Enter v2:"))]
"""




"""
tupleAmount = raw_input("Enter how many entries in are in your tuple: ")
type(tupleAmount)

print(tupleAmount)

aList = ['cool', 'awesome', 'new']

def printme(str):
    "this prints a string passed"
    print str;
    return

"""

"""

printme("poop")

for i in range(100):
    print(i)

while True:
    try:
        score = int(input("Enter your score: "))
        break
    except ValueError:
        print("Int, please.")


str = "123456";  # Only digit in this string
print str.isdigit()

str = "this is string example....wow!!!";
print str.isdigit()

while not str.isdigit():
    str = raw_input("Enter a number: ");
    """
