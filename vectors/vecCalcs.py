import math


def addVectors():
    print("Addition of two vectors")
    #U Vector
    u1 = input("Enter u1: ")
    while not u1.isdigit():
        u1 = input("Float input only. Enter u1:");

    u2 = input("Enter u2: ")
    while not u2.isdigit():
        u2 = input("Float input only. Enter u2:");

    u3 = input("Enter u3: ")
    while not u3.isdigit():
        u3 = input("Float input only. Enter u3:");

    uVec = [float(u1), float(u2), float(u3)]

    #V Vector
    v1 = input("Enter v1: ")
    while not v1.isdigit():
        v1 = input("Float input only. Enter v1:");

    v2 = input("Enter v2: ")
    while not v2.isdigit():
        v2 = input("Float input only. Enter v2:");

    v3 = input("Enter v3: ")
    while not v3.isdigit():
        v3 = input("Float input only. Enter v3:");

    vVec = [float(v1), float(v2), float(v3)]

    #W Vector (added vectors)
    w0 = uVec[0] + vVec[0]
    w1 = uVec[1] + vVec[1]
    w2 = uVec[2] + vVec[2]
    wVec = [float(w0), float(w1), float(w2)]

    print("u = {}".format(uVec))
    print("v = {}".format(vVec))
    print("u + v = {}".format(wVec))
    return

def subtractVectors():
    print("Subtraction of two vectors")
    #U Vector
    u1 = input("Enter u1: ")
    while not u1.isdigit():
        u1 = input("Float input only. Enter u1:");

    u2 = input("Enter u2: ")
    while not u2.isdigit():
        u2 = input("Float input only. Enter u2:");

    u3 = input("Enter u3: ")
    while not u3.isdigit():
        u3 = input("Float input only. Enter u3:");

    uVec = [float(u1), float(u2), float(u3)]

    #V Vector
    v1 = input("Enter v1: ")
    while not v1.isdigit():
        v1 = input("Float input only. Enter v1:");

    v2 = input("Enter v2: ")
    while not v2.isdigit():
        v2 = input("Float input only. Enter v2:");

    v3 = input("Enter v3: ")
    while not v3.isdigit():
        v3 = input("Float input only. Enter v3:");

    vVec = [float(v1), float(v2), float(v3)]

    #W Vector (subtracted vectors)
    w0 = uVec[0] - vVec[0]
    w1 = uVec[1] - vVec[1]
    w2 = uVec[2] - vVec[2]
    wVec = [float(w0), float(w1), float(w2)]

    print("u = {}".format(uVec))
    print("v = {}".format(vVec))
    print("u - v = {}".format(wVec))
    return

def dotProduct():
    print("Dot product of two vectors")
    #U Vector
    u1 = input("Enter u1: ")
    while not u1.isdigit():
        u1 = input("Float input only. Enter u1:");

    u2 = input("Enter u2: ")
    while not u2.isdigit():
        u2 = input("Float input only. Enter u2:");

    u3 = input("Enter u3: ")
    while not u3.isdigit():
        u3 = input("Float input only. Enter u3:");

    uVec = [float(u1), float(u2), float(u3)]

    #V Vector
    v1 = input("Enter v1: ")
    while not v1.isdigit():
        v1 = input("Float input only. Enter v1:");

    v2 = input("Enter v2: ")
    while not v2.isdigit():
        v2 = input("Float input only. Enter v2:");

    v3 = input("Enter v3: ")
    while not v3.isdigit():
        v3 = input("Float input only. Enter v3:");

    vVec = [float(v1), float(v2), float(v3)]

    #Dot Product calculation
    dotPro = (uVec[0] * vVec[0]) + (uVec[1] * vVec[1]) + (uVec[2] * vVec[2])

    print("u = {}".format(uVec))
    print("v = {}".format(vVec))
    print("Dot Product = {}".format(dotPro))
    return

def crossProduct():
    print("Cross product of two vectors")
    #U Vector
    u1 = input("Enter u1: ")
    while not u1.isdigit():
        u1 = input("Float input only. Enter u1:");

    u2 = input("Enter u2: ")
    while not u2.isdigit():
        u2 = input("Float input only. Enter u2:");

    u3 = input("Enter u3: ")
    while not u3.isdigit():
        u3 = input("Float input only. Enter u3:");

    uVec = [float(u1), float(u2), float(u3)]

    #V Vector
    v1 = input("Enter v1: ")
    while not v1.isdigit():
        v1 = input("Float input only. Enter v1:");

    v2 = input("Enter v2: ")
    while not v2.isdigit():
        v2 = input("Float input only. Enter v2:");

    v3 = input("Enter v3: ")
    while not v3.isdigit():
        v3 = input("Float input only. Enter v3:");

    vVec = [float(v1), float(v2), float(v3)]

    #W Vector (cross product of u and v)
    w0 = uVec[1] * vVec[2] - uVec[2] * vVec[1]
    w1 = uVec[0] * vVec[2] - uVec[2] * vVec[0]
    w2 = uVec[0] * vVec[1] - uVec[1] * vVec[0]
    wVec = [float(w0), float(w1), float(w2)]

    print("u = {}".format(uVec))
    print("v = {}".format(vVec))
    print("u x v = {}".format(wVec))
    return

def menu():
    print("Vector Calculation Menu")
    print("""
        1. Add Vectors
        2. Subtract Vectors
        3. Dot Product of Two Vectors
        4. Cross Product of Two Vectors
        5. Quit
    """)
    ans=input("What would you like to do? ")
    if ans == "1":
        addVectors()
        input("")
    elif ans == "2":
        subtractVectors()
        input("")
    elif ans == "3":
        dotProduct()
        input("")
    elif ans == "4":
        crossProduct()
        input("")
    elif ans == "5":
        print("\nGoodbye!")
        return False
    else:
        input("Wrong option selection. Enter any key to try again...")

    return True

loop = True
while loop:
    loop = menu()
