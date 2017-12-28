import math

def menu():
    print"Vector Calculation Menu"
    print("""
    1. Add Vectors
    2. Subtract Vectors
    3. Dot Product of Two Vectors
    4. Cross Product of Two Vectors
    5. Quit
    """)
    ans=raw_input("What would you like to do? ")
    if ans=="1":
        addVectors();
    elif ans=="2":
        print("poop")
    elif ans=="3":
        print("poop")
    elif ans=="4":
        print("poop")
    elif ans=="5":
        print("\nGoodbye!")

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
