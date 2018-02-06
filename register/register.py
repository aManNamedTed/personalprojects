import datetime

def menu():
    now = datetime.datetime.now()
    print("David's Universal POS")
    print("""
        A: Sale
        B: Return
        C: Close Register
        D: Duplicate Receipt
        C: Post Void
        E: No Sale
        F: Employee Sale
        G: Employee Return
        H: Loans
        I: Price Check
        J: Inquires
        K: Opening Balance
        L: Closing Counts
        M: Gift Receipt
    """)
    ans=input("Selection: ")
    if ans == "1":
        sale()
        input("")
    elif ans == "2":
        subtractVectors()
        input("")
    else:
        input("Wrong option selection. Enter any key to try again...")

    return True

loop = True
while loop:
    loop = menu()
